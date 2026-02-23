// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motion_msgs:msg/MovementCtrlMode.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__BUILDER_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motion_msgs/msg/detail/movement_ctrl_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motion_msgs
{

namespace msg
{

namespace builder
{

class Init_MovementCtrlMode_split_mode
{
public:
  explicit Init_MovementCtrlMode_split_mode(::motion_msgs::msg::MovementCtrlMode & msg)
  : msg_(msg)
  {}
  ::motion_msgs::msg::MovementCtrlMode split_mode(::motion_msgs::msg::MovementCtrlMode::_split_mode_type arg)
  {
    msg_.split_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlMode msg_;
};

class Init_MovementCtrlMode_jump_mode
{
public:
  explicit Init_MovementCtrlMode_jump_mode(::motion_msgs::msg::MovementCtrlMode & msg)
  : msg_(msg)
  {}
  Init_MovementCtrlMode_split_mode jump_mode(::motion_msgs::msg::MovementCtrlMode::_jump_mode_type arg)
  {
    msg_.jump_mode = std::move(arg);
    return Init_MovementCtrlMode_split_mode(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlMode msg_;
};

class Init_MovementCtrlMode_stand_mode
{
public:
  explicit Init_MovementCtrlMode_stand_mode(::motion_msgs::msg::MovementCtrlMode & msg)
  : msg_(msg)
  {}
  Init_MovementCtrlMode_jump_mode stand_mode(::motion_msgs::msg::MovementCtrlMode::_stand_mode_type arg)
  {
    msg_.stand_mode = std::move(arg);
    return Init_MovementCtrlMode_jump_mode(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlMode msg_;
};

class Init_MovementCtrlMode_height_ctrl_mode
{
public:
  explicit Init_MovementCtrlMode_height_ctrl_mode(::motion_msgs::msg::MovementCtrlMode & msg)
  : msg_(msg)
  {}
  Init_MovementCtrlMode_stand_mode height_ctrl_mode(::motion_msgs::msg::MovementCtrlMode::_height_ctrl_mode_type arg)
  {
    msg_.height_ctrl_mode = std::move(arg);
    return Init_MovementCtrlMode_stand_mode(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlMode msg_;
};

class Init_MovementCtrlMode_roll_ctrl_mode
{
public:
  explicit Init_MovementCtrlMode_roll_ctrl_mode(::motion_msgs::msg::MovementCtrlMode & msg)
  : msg_(msg)
  {}
  Init_MovementCtrlMode_height_ctrl_mode roll_ctrl_mode(::motion_msgs::msg::MovementCtrlMode::_roll_ctrl_mode_type arg)
  {
    msg_.roll_ctrl_mode = std::move(arg);
    return Init_MovementCtrlMode_height_ctrl_mode(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlMode msg_;
};

class Init_MovementCtrlMode_pitch_ctrl_mode
{
public:
  Init_MovementCtrlMode_pitch_ctrl_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MovementCtrlMode_roll_ctrl_mode pitch_ctrl_mode(::motion_msgs::msg::MovementCtrlMode::_pitch_ctrl_mode_type arg)
  {
    msg_.pitch_ctrl_mode = std::move(arg);
    return Init_MovementCtrlMode_roll_ctrl_mode(msg_);
  }

private:
  ::motion_msgs::msg::MovementCtrlMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_msgs::msg::MovementCtrlMode>()
{
  return motion_msgs::msg::builder::Init_MovementCtrlMode_pitch_ctrl_mode();
}

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__BUILDER_HPP_
