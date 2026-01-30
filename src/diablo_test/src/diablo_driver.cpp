#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>
#include <nav_msgs/msg/odometry.hpp>          
#include <tf2/LinearMath/Quaternion.h>     
#include <tf2_ros/transform_broadcaster.h>  

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp> 
#include <webots/Lidar.hpp>

#include <algorithm>
#include <vector>
#include <memory>
#include <cmath>

using std::placeholders::_1;

// Parámetros del robot Diablo
const double WHEEL_RADIUS = 0.10;
const double TRACK_WIDTH = 0.5805; // Ajustado para la simulación mediante tunning

class DiabloDriver : public rclcpp::Node
{
public:
    DiabloDriver() : Node("diablo_driver_node")
    {
        // Inicializar Webots
        robot_ = std::make_unique<webots::Robot>();
        time_step_ = (int)robot_->getBasicTimeStep();

        // Inicializar Broadcaster de TF
        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

        // Motores Ruedas y Sensores de Posición
        left_wheel_ = robot_->getMotor("left_j3");
        right_wheel_ = robot_->getMotor("right_j3");
        
        // Configurar Encoders
        left_sensor_ = robot_->getPositionSensor("left_j3_sensor");
        right_sensor_ = robot_->getPositionSensor("right_j3_sensor");

        if (left_wheel_ && right_wheel_) {
            left_wheel_->setPosition(INFINITY);
            right_wheel_->setPosition(INFINITY);
            left_wheel_->setVelocity(0.0);
            right_wheel_->setVelocity(0.0);
        }

        if (left_sensor_ && right_sensor_) {
            left_sensor_->enable(time_step_);
            right_sensor_->enable(time_step_);
        } else {
            RCLCPP_ERROR(this->get_logger(), "¡ERROR! No encuentro los sensores de posición (encoders).");
        }

        // Motores Patas (Bloqueo)
        const char* leg_motors[] = {"left_j1", "left_j4", "right_j1", "right_j4"};
        for (const char* name : leg_motors) {
            webots::Motor* motor = robot_->getMotor(name);
            if (motor) {
                motor->setPosition(0.0);
                motor->setVelocity(2.0);
            }
        }

        // LiDAR
        lidar_ = robot_->getLidar("lidar");
        if (lidar_) {
            lidar_->enable(time_step_);
            lidar_->enablePointCloud();
        }

        // Suscriptores y Publicadores
        cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10, std::bind(&DiabloDriver::cmd_vel_callback, this, _1));
        
        scan_pub_ = this->create_publisher<sensor_msgs::msg::LaserScan>("/scan", 10);
        odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("/odom", 10); // <--- NUEVO

        RCLCPP_INFO(this->get_logger(), "DRIVER: Odometría + LiDAR + Motores activos.");
    }

    int step() {
        int ret = robot_->step(time_step_);
        if (ret != -1) {
            // Tomo el tiempo simulado de Webots y lo mando a las funciones para que funcione RViz
            double sim_time = robot_->getTime();
            
            rclcpp::Time current_time(
                (int32_t)sim_time, 
                (uint32_t)((sim_time - (int32_t)sim_time) * 1e9)
            );

            update_odometry(current_time);
            publish_lidar(current_time);
        }
        return ret;
    }

private:
    void update_odometry(rclcpp::Time timestamp)
    {
        if (!left_sensor_ || !right_sensor_) return;

        // Leer valores actuales de los encoders (radianes)
        double left_pos = left_sensor_->getValue();
        double right_pos = right_sensor_->getValue();

        // Manejar la primera ejecución (para no tener saltos gigantes)
        if (std::isnan(last_left_pos_) || std::isnan(last_right_pos_)) {
            last_left_pos_ = left_pos;
            last_right_pos_ = right_pos;
            return;
        }

        // Calcular desplazamiento de cada rueda (delta)
        double d_left = (left_pos - last_left_pos_) * WHEEL_RADIUS;
        double d_right = (right_pos - last_right_pos_) * WHEEL_RADIUS;

        // Guardar para el siguiente ciclo
        last_left_pos_ = left_pos;
        last_right_pos_ = right_pos;

        // Cinemática Diferencial (Cuánto nos hemos movido en el centro)
        double d_center = (d_right + d_left) / 2.0;       // Avance lineal
        double d_theta = (d_right - d_left) / TRACK_WIDTH; // Giro

        // Integrar posición
        // Usamos el ángulo medio para mayor precisión (Runge-Kutta orden 2 simple)
        x_ += d_center * cos(theta_ + d_theta / 2.0);
        y_ += d_center * sin(theta_ + d_theta / 2.0);
        theta_ += d_theta;

        // Crear Cuaternio para la orientación
        tf2::Quaternion q;
        q.setRPY(0, 0, theta_);

        // PUBLICAR TF (Transformada odom -> base_link)
        geometry_msgs::msg::TransformStamped odom_tf;
        odom_tf.header.stamp = timestamp;
        odom_tf.header.frame_id = "odom";
        odom_tf.child_frame_id = "base_link";

        odom_tf.transform.translation.x = x_;
        odom_tf.transform.translation.y = y_;
        odom_tf.transform.translation.z = 0.0;
        odom_tf.transform.rotation.x = q.x();
        odom_tf.transform.rotation.y = q.y();
        odom_tf.transform.rotation.z = q.z();
        odom_tf.transform.rotation.w = q.w();

        tf_broadcaster_->sendTransform(odom_tf);

        // PUBLICAR MENSAJE /odom (Para Nav2)
        auto odom_msg = nav_msgs::msg::Odometry();
        odom_msg.header.stamp = timestamp;
        odom_msg.header.frame_id = "odom";
        odom_msg.child_frame_id = "base_link";

        // Posición
        odom_msg.pose.pose.position.x = x_;
        odom_msg.pose.pose.position.y = y_;
        odom_msg.pose.pose.orientation = odom_tf.transform.rotation;

        // Velocidad
        double dt = time_step_ / 1000.0;
        if (dt > 0) {
            odom_msg.twist.twist.linear.x = d_center / dt;
            odom_msg.twist.twist.angular.z = d_theta / dt;
        }

        odom_pub_->publish(odom_msg);
    }

    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        if (!left_wheel_ || !right_wheel_) return;
        double linear_x = msg->linear.x;
        double angular_z = msg->angular.z;
        
        double left_target = (linear_x - (angular_z * TRACK_WIDTH / 2.0)) / WHEEL_RADIUS;
        double right_target = (linear_x + (angular_z * TRACK_WIDTH / 2.0)) / WHEEL_RADIUS;
        
        left_wheel_->setVelocity(std::clamp(left_target, -20.0, 20.0));
        right_wheel_->setVelocity(std::clamp(right_target, -20.0, 20.0));
    }

    void publish_lidar(rclcpp::Time timestamp)
    {
        if (!lidar_) return; // No hay LiDAR
        
        // Vector para almacenar los rangos
        auto scan_msg = sensor_msgs::msg::LaserScan();

        // Vector temporal del Header
        scan_msg.header.stamp = timestamp;
        scan_msg.header.frame_id = "lidar_link";

        // Rellenar los campos del mensaje LaserScan con configuración geométrica del LiDAR
        scan_msg.angle_min = 0;
        scan_msg.angle_max = 2 * M_PI;

        // Calculo incremento angular
        scan_msg.angle_increment = 2 * M_PI / lidar_->getHorizontalResolution();

        // Otros parámetros
        scan_msg.time_increment = (double)time_step_ / 1000.0 / lidar_->getHorizontalResolution();
        scan_msg.scan_time = (double)time_step_ / 1000.0;
        scan_msg.range_min = lidar_->getMinRange();
        scan_msg.range_max = lidar_->getMaxRange();

        // Obtener la imagen de rangos desde Webots
        const float *range_image = lidar_->getRangeImage();

        if (range_image) {
            // Copiamos los rangos del puntero a un vector
            std::vector<float> ranges_vec(range_image, range_image + lidar_->getHorizontalResolution());  

            // Invertimos los rangos para evitar que RViz los interprete al revés
            std::reverse(ranges_vec.begin(), ranges_vec.end());

            // Guardamos datos corregidos en el mensaje
            scan_msg.ranges = ranges_vec;

            // Rellenamos el array de intensidad con valor 1.0 para que RViz funcione
            scan_msg.intensities.resize(lidar_->getHorizontalResolution(), 1.0f);
        }
        scan_pub_->publish(scan_msg);
    }

    // Punteros Webots
    std::unique_ptr<webots::Robot> robot_;
    webots::Motor *left_wheel_ = nullptr;
    webots::Motor *right_wheel_ = nullptr;
    webots::PositionSensor *left_sensor_ = nullptr;
    webots::PositionSensor *right_sensor_ = nullptr;
    webots::Lidar *lidar_ = nullptr;
    
    int time_step_;

    // Variables de Odometría
    double x_ = 0.0;
    double y_ = 0.0;
    double theta_ = 0.0;
    double last_left_pos_ = NAN; // NAN para detectar el primer ciclo
    double last_right_pos_ = NAN;

    // Publicadores y Suscriptores
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr scan_pub_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DiabloDriver>();
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    while (rclcpp::ok()) {
        executor.spin_once(std::chrono::milliseconds(0));
        if (node->step() == -1) break;
    }
    rclcpp::shutdown();
    return 0;
}