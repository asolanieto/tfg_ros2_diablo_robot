#include "diablo_bridge.hpp"

DiabloBridge::DiabloBridge() : Node("diablo_bridge_node")
{
    // 1. Broadcaster para TF (odom -> base_link)
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    // 2. Suscriptores
    // Escucha a EasyNav
    cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
        "/cmd_vel", 10, std::bind(&DiabloBridge::cmdVelCallback, this, std::placeholders::_1));
    
    // Escucha a la telemetría del robot real
    motors_sub_ = this->create_subscription<motion_msgs::msg::LegMotors>(
        "/diablo/sensor/Motors", 10, std::bind(&DiabloBridge::motorsCallback, this, std::placeholders::_1));

    // 3. Publicadores
    // Envía comandos al robot real
    diablo_cmd_pub_ = this->create_publisher<motion_msgs::msg::MotionCtrl>("/diablo/MotionCmd", 10);
    
    // Envía odometría a EasyNav / Nav2
    odom_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("/odom", 10);

    RCLCPP_INFO(this->get_logger(), "Diablo Bridge Hardware INICIADO. Escuchando /cmd_vel y /diablo/sensor/Motors");
}

void DiabloBridge::cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
    auto diablo_msg = motion_msgs::msg::MotionCtrl();

    // Según el README del SDK, false significa "control directo", no cambio de modo
    diablo_msg.mode_mark = false; 

    // Mapeo directo: El SDK se encarga de calcular la velocidad de cada rueda por dentro.
    // Solo le pasamos la velocidad lineal y la velocidad de giro.
    diablo_msg.value.forward = msg->linear.x;
    diablo_msg.value.left = msg->angular.z;  // Radianes/s positivos giran a la izquierda

    // El resto de valores a 0 (no queremos cambiar postura, roll, ni pitch)
    diablo_msg.value.up = 0.0;
    diablo_msg.value.roll = 0.0;
    diablo_msg.value.pitch = 0.0;
    diablo_msg.value.leg_split = 0.0;

    diablo_cmd_pub_->publish(diablo_msg);
}

void DiabloBridge::motorsCallback(const motion_msgs::msg::LegMotors::SharedPtr msg)
{
    //rclcpp::Time current_time = msg->header.stamp;
    rclcpp::Time current_time = this->now();

    // Calcular el ángulo absoluto de cada rueda: (Revoluciones * 2Pi) + Posición en radianes
    double current_left_angle = (msg->left_wheel_enc_rev * 2.0 * M_PI) + msg->left_wheel_pos;
    double current_right_angle = (msg->right_wheel_enc_rev * 2.0 * M_PI) + msg->right_wheel_pos;

    // Inicialización en la primera lectura
    if (!first_msg_received_) {
        last_left_angle_ = current_left_angle;
        last_right_angle_ = current_right_angle;
        last_time_ = current_time;
        first_msg_received_ = true;
        return;
    }

    // Calcular deltas de ángulo
    double delta_left_angle = current_left_angle - last_left_angle_;
    double delta_right_angle = current_right_angle - last_right_angle_;

    // Actualizar variables para el próximo ciclo
    last_left_angle_ = current_left_angle;
    last_right_angle_ = current_right_angle;

    // Calcular distancia recorrida por cada rueda
    double d_left = delta_left_angle * WHEEL_RADIUS;
    double d_right = delta_right_angle * WHEEL_RADIUS;

    // Cinemática diferencial básica
    double d_center = (d_right + d_left) / 2.0;       
    double d_theta = (d_right - d_left) / TRACK_WIDTH; 

    // Integración de Odometría (Runge-Kutta orden 2 simple)
    x_ += d_center * cos(theta_ + d_theta / 2.0);
    y_ += d_center * sin(theta_ + d_theta / 2.0);
    theta_ += d_theta;

    // Cálculo de velocidades (v = d / dt)
    double dt = (current_time - last_time_).seconds();
    last_time_ = current_time;

    double v_linear = 0.0;
    double v_angular = 0.0;
    if (dt > 0.0001) { // Evitar división por cero
        v_linear = d_center / dt;
        v_angular = d_theta / dt;
    }

    // Cuaternio
    tf2::Quaternion q;
    q.setRPY(0, 0, theta_);

    // 1. PUBLICAR TF
    geometry_msgs::msg::TransformStamped odom_tf;
    odom_tf.header.stamp = current_time;
    odom_tf.header.frame_id = "odom";
    // odom_tf.child_frame_id = "base_link";
    odom_tf.child_frame_id = "base_footprint"; // Añadido para solucionar problema de sentido de odom
    odom_tf.transform.translation.x = x_;
    odom_tf.transform.translation.y = y_;
    odom_tf.transform.translation.z = 0.0;
    odom_tf.transform.rotation.x = q.x();
    odom_tf.transform.rotation.y = q.y();
    odom_tf.transform.rotation.z = q.z();
    odom_tf.transform.rotation.w = q.w();
    tf_broadcaster_->sendTransform(odom_tf);

    // 2. PUBLICAR /odom
    auto odom_msg = nav_msgs::msg::Odometry();
    odom_msg.header.stamp = current_time;
    odom_msg.header.frame_id = "odom";
    // odom_msg.child_frame_id = "base_link";
    odom_msg.child_frame_id = "base_footprint";

    odom_msg.pose.pose.position.x = x_;
    odom_msg.pose.pose.position.y = y_;
    odom_msg.pose.pose.position.z = 0.0;
    
    odom_msg.pose.pose.orientation.x = q.x();
    odom_msg.pose.pose.orientation.y = q.y();
    odom_msg.pose.pose.orientation.z = q.z();
    odom_msg.pose.pose.orientation.w = q.w();

    odom_msg.twist.twist.linear.x = v_linear;
    odom_msg.twist.twist.angular.z = v_angular;

    odom_pub_->publish(odom_msg);
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DiabloBridge>());
    rclcpp::shutdown();
    return 0;
}