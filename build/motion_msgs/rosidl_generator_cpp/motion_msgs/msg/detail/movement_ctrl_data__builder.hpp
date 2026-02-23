// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motion_msgs:msg/MovementCtrlData.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__BUILDER_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motion_msgs/msg/detail/movement_ctrl_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motion_msgs
{

namespace msg
{

namespace builder
{

class Init_MovementCtrlData_leg_split
{
public:
  explicit Init_MovementCtrlData_leg_split(::motion_msgs::msg::MovementCtrlData & msg)
  : msg_(msg)
  {}
  ::motion_msgs::msg::MovementCtrlData leg_split(::motion_msgs::msg::MovementCtrlData::_leg_split_type arg)
  {
    msg_.leg_split = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlData msg_;
};

class Init_MovementCtrlData_pitch
{
public:
  explicit Init_MovementCtrlData_pitch(::motion_msgs::msg::MovementCtrlData & msg)
  : msg_(msg)
  {}
  Init_MovementCtrlData_leg_split pitch(::motion_msgs::msg::MovementCtrlData::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_MovementCtrlData_leg_split(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlData msg_;
};

class Init_MovementCtrlData_roll
{
public:
  explicit Init_MovementCtrlData_roll(::motion_msgs::msg::MovementCtrlData & msg)
  : msg_(msg)
  {}
  Init_MovementCtrlData_pitch roll(::motion_msgs::msg::MovementCtrlData::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_MovementCtrlData_pitch(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlData msg_;
};

class Init_MovementCtrlData_up
{
public:
  explicit Init_MovementCtrlData_up(::motion_msgs::msg::MovementCtrlData & msg)
  : msg_(msg)
  {}
  Init_MovementCtrlData_roll up(::motion_msgs::msg::MovementCtrlData::_up_type arg)
  {
    msg_.up = std::move(arg);
    return Init_MovementCtrlData_roll(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlData msg_;
};

class Init_MovementCtrlData_left
{
public:
  explicit Init_MovementCtrlData_left(::motion_msgs::msg::MovementCtrlData & msg)
  : msg_(msg)
  {}
  Init_MovementCtrlData_up left(::motion_msgs::msg::MovementCtrlData::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_MovementCtrlData_up(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlData msg_;
};

class Init_MovementCtrlData_forward
{
public:
  Init_MovementCtrlData_forward()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MovementCtrlData_left forward(::motion_msgs::msg::MovementCtrlData::_forward_type arg)
  {
    msg_.forward = std::move(arg);
    return Init_MovementCtrlData_left(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_msgs::msg::MovementCtrlData>()
{
  return motion_msgs::msg::builder::Init_MovementCtrlData_forward();
}

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__BUILDER_HPP_
