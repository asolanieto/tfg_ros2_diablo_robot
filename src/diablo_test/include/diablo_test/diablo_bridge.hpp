#ifndef DIABLO_BRIDGE_HPP_
#define DIABLO_BRIDGE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>          
#include <tf2/LinearMath/Quaternion.h>     
#include <tf2_ros/transform_broadcaster.h>  

// Mensajes propietarios del fabricante
#include "motion_msgs/msg/motion_ctrl.hpp"
#include "motion_msgs/msg/leg_motors.hpp"
#include "ception_msgs/msg/imu_euler.hpp"

#include <cmath>

class DiabloBridge : public rclcpp::Node
{
public:
    DiabloBridge();

private:
    // Callbacks
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
    void motorsCallback(const motion_msgs::msg::LegMotors::SharedPtr msg);
    void imuCallback(const ception_msgs::msg::IMUEuler::SharedPtr msg);

    // Parámetros físicos
    const double WHEEL_RADIUS = 0.10;
    const double TRACK_WIDTH = 0.5805; // Ajustar empíricamente en el robot real

    // Variables de Estado de Odometría
    bool first_msg_received_ = false;
    double x_ = 0.0;
    double y_ = 0.0;
    double theta_ = 0.0;
    
    double last_left_angle_ = 0.0;
    double last_right_angle_ = 0.0;
    rclcpp::Time last_time_;

    // ROS 2 Interfaces
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    rclcpp::Subscription<motion_msgs::msg::LegMotors>::SharedPtr motors_sub_;
    rclcpp::Subscription<ception_msgs::msg::IMUEuler>::SharedPtr imu_sub_;

    
    rclcpp::Publisher<motion_msgs::msg::MotionCtrl>::SharedPtr diablo_cmd_pub_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

#endif // DIABLO_BRIDGE_HPP_