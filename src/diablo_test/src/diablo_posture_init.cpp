#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <memory>
#include <thread>
#include <csignal> 
#include "motion_msgs/msg/motion_ctrl.hpp" 

class DiabloPostureInit;
std::shared_ptr<DiabloPostureInit> g_node = nullptr;

class DiabloPostureInit : public rclcpp::Node
{
public:
    DiabloPostureInit() : Node("diablo_posture_init_node"), step_(0)
    {
        this->declare_parameter<double>("target_up", 0.85); 
        this->declare_parameter<double>("target_pitch", 0.5); // Velocidad del escalón
        // 1 step = 100ms. Un valor de 4 significa 400ms de pulso.
        this->declare_parameter<int>("pitch_duration_steps", 4); 

        publisher_ = this->create_publisher<motion_msgs::msg::MotionCtrl>("/diablo/MotionCmd", 10);

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&DiabloPostureInit::timer_callback, this));
            
        RCLCPP_INFO(this->get_logger(), "Iniciando bipedestacion e inclinacion...");
    }

    void sit_down()
    {
        RCLCPP_INFO(this->get_logger(), "Apagando: Descenso seguro...");
        auto msg = motion_msgs::msg::MotionCtrl();
        msg.mode.stand_mode = true;
        msg.mode.pitch_ctrl_mode = true;
        
        msg.mode_mark = false;
        msg.value.up = this->get_parameter("target_up").as_double();
        msg.value.pitch = 0.0;
        for(int i=0; i<5; i++) {
            publisher_->publish(msg);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

        msg.mode_mark = true;
        msg.mode.stand_mode = false;
        msg.mode.pitch_ctrl_mode = false;
        msg.value.up = 0.0;
        publisher_->publish(msg);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        msg.mode_mark = false;
        for(int i=0; i<10; i++) {
            publisher_->publish(msg);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }

private:
    void timer_callback()
    {
        auto msg = motion_msgs::msg::MotionCtrl();
        double target_up = this->get_parameter("target_up").as_double();
        double target_pitch = this->get_parameter("target_pitch").as_double();
        int duration = this->get_parameter("pitch_duration_steps").as_int();

        msg.mode.stand_mode = true;
        msg.mode.pitch_ctrl_mode = true;

        if (step_ == 0) 
        {
            msg.mode_mark = true; // Calibra el Cero
            msg.value.up = 0.0;
            msg.value.pitch = 0.0;
        }
        else if (step_ < 20) 
        {
            // FASE 1: Subir (2 segundos)
            msg.mode_mark = false;
            msg.value.up = target_up;
            msg.value.pitch = 0.0;
        }
        else if (step_ < 20 + duration) 
        {
            // FASE 2: El Escalón (Ej: 400 ms a velocidad 0.5)
            msg.mode_mark = false; 
            msg.value.up = target_up;
            msg.value.pitch = target_pitch; 
        }
        else if (step_ < 20 + duration + 5)
        {
            // FASE 3: LOS FRENOS (Obligatorio para parar el integrador)
            msg.mode_mark = false; 
            msg.value.up = target_up;
            msg.value.pitch = 0.0; 
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Postura estabilizada. Topic liberado.");
            timer_->cancel();
            return;
        }
        
        publisher_->publish(msg);
        step_++;
    }
    
    rclcpp::Publisher<motion_msgs::msg::MotionCtrl>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int step_;
};

void sigintHandler(int sig)
{
    (void)sig; 
    if (g_node) g_node->sit_down(); 
    rclcpp::shutdown(); 
}

int main(int argc, char * argv[])
{
    rclcpp::InitOptions init_options;
    init_options.shutdown_on_signal = false;
    rclcpp::init(argc, argv, init_options);
    
    g_node = std::make_shared<DiabloPostureInit>();
    signal(SIGINT, sigintHandler);
    rclcpp::spin(g_node);
    
    return 0;
}