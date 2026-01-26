#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

/// Este nodo publica velocidades constantes para probar el robot

class DiabloPublisher : public rclcpp::Node
{
public:
  DiabloPublisher()
  : Node("diablo_test_publisher")
  {
    // Publicador de velocidades
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    
    timer_ = this->create_wall_timer(
      500ms, std::bind(&DiabloPublisher::timer_callback, this));
      
    RCLCPP_INFO(this->get_logger(), "Nodo Publicador de Diablo iniciado. Enviando comandos...");
  }

private:
  void timer_callback()
  {
    auto message = geometry_msgs::msg::Twist();

  
    message.linear.x = 0.5;  
    message.angular.z = 0.0; 

    // Publicar el mensaje
    RCLCPP_INFO(this->get_logger(), "Enviando velocidad -> Lineal: '%.2f', Angular: '%.2f'", 
                message.linear.x, message.angular.z);
    
    publisher_->publish(message);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DiabloPublisher>());
  rclcpp::shutdown();
  return 0;
}
