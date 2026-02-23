// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motion_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define MOTION_MSGS__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motion_msgs/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motion_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_warning_msg
{
public:
  explicit Init_RobotStatus_warning_msg(::motion_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::motion_msgs::msg::RobotStatus warning_msg(::motion_msgs::msg::RobotStatus::_warning_msg_type arg)
  {
    msg_.warning_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_error_msg
{
public:
  explicit Init_RobotStatus_error_msg(::motion_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_warning_msg error_msg(::motion_msgs::msg::RobotStatus::_error_msg_type arg)
  {
    msg_.error_msg = std::move(arg);
    return Init_RobotStatus_warning_msg(msg_);
  }

private:
  ::motion_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_robot_mode_msg
{
public:
  explicit Init_RobotStatus_robot_mode_msg(::motion_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_error_msg robot_mode_msg(::motion_msgs::msg::RobotStatus::_robot_mode_msg_type arg)
  {
    msg_.robot_mode_msg = std::move(arg);
    return Init_RobotStatus_error_msg(msg_);
  }

private:
  ::motion_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_ctrl_mode_msg
{
public:
  explicit Init_RobotStatus_ctrl_mode_msg(::motion_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_robot_mode_msg ctrl_mode_msg(::motion_msgs::msg::RobotStatus::_ctrl_mode_msg_type arg)
  {
    msg_.ctrl_mode_msg = std::move(arg);
    return Init_RobotStatus_robot_mode_msg(msg_);
  }

private:
  ::motion_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_header
{
public:
  Init_RobotStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_ctrl_mode_msg header(::motion_msgs::msg::RobotStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RobotStatus_ctrl_mode_msg(msg_);
  }

private:
  ::motion_msgs::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_msgs::msg::RobotStatus>()
{
  return motion_msgs::msg::builder::Init_RobotStatus_header();
}

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
