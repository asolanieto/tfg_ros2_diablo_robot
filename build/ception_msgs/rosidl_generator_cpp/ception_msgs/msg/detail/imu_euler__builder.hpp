// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ception_msgs:msg/IMUEuler.idl
// generated code does not contain a copyright notice

#ifndef CEPTION_MSGS__MSG__DETAIL__IMU_EULER__BUILDER_HPP_
#define CEPTION_MSGS__MSG__DETAIL__IMU_EULER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ception_msgs/msg/detail/imu_euler__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ception_msgs
{

namespace msg
{

namespace builder
{

class Init_IMUEuler_yaw
{
public:
  explicit Init_IMUEuler_yaw(::ception_msgs::msg::IMUEuler & msg)
  : msg_(msg)
  {}
  ::ception_msgs::msg::IMUEuler yaw(::ception_msgs::msg::IMUEuler::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ception_msgs::msg::IMUEuler msg_;
};

class Init_IMUEuler_pitch
{
public:
  explicit Init_IMUEuler_pitch(::ception_msgs::msg::IMUEuler & msg)
  : msg_(msg)
  {}
  Init_IMUEuler_yaw pitch(::ception_msgs::msg::IMUEuler::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_IMUEuler_yaw(msg_);
  }

private:
  ::ception_msgs::msg::IMUEuler msg_;
};

class Init_IMUEuler_roll
{
public:
  explicit Init_IMUEuler_roll(::ception_msgs::msg::IMUEuler & msg)
  : msg_(msg)
  {}
  Init_IMUEuler_pitch roll(::ception_msgs::msg::IMUEuler::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_IMUEuler_pitch(msg_);
  }

private:
  ::ception_msgs::msg::IMUEuler msg_;
};

class Init_IMUEuler_header
{
public:
  Init_IMUEuler_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IMUEuler_roll header(::ception_msgs::msg::IMUEuler::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IMUEuler_roll(msg_);
  }

private:
  ::ception_msgs::msg::IMUEuler msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ception_msgs::msg::IMUEuler>()
{
  return ception_msgs::msg::builder::Init_IMUEuler_header();
}

}  // namespace ception_msgs

#endif  // CEPTION_MSGS__MSG__DETAIL__IMU_EULER__BUILDER_HPP_
