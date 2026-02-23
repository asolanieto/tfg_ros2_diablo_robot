// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motion_msgs:msg/MotionCtrl.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__BUILDER_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motion_msgs/msg/detail/motion_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motion_msgs
{

namespace msg
{

namespace builder
{

class Init_MotionCtrl_mode
{
public:
  explicit Init_MotionCtrl_mode(::motion_msgs::msg::MotionCtrl & msg)
  : msg_(msg)
  {}
  ::motion_msgs::msg::MotionCtrl mode(::motion_msgs::msg::MotionCtrl::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_msgs::msg::MotionCtrl msg_;
};

class Init_MotionCtrl_value
{
public:
  explicit Init_MotionCtrl_value(::motion_msgs::msg::MotionCtrl & msg)
  : msg_(msg)
  {}
  Init_MotionCtrl_mode value(::motion_msgs::msg::MotionCtrl::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_MotionCtrl_mode(msg_);
  }

private:
  ::motion_msgs::msg::MotionCtrl msg_;
};

class Init_MotionCtrl_mode_mark
{
public:
  Init_MotionCtrl_mode_mark()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotionCtrl_value mode_mark(::motion_msgs::msg::MotionCtrl::_mode_mark_type arg)
  {
    msg_.mode_mark = std::move(arg);
    return Init_MotionCtrl_value(msg_);
  }

private:
  ::motion_msgs::msg::MotionCtrl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_msgs::msg::MotionCtrl>()
{
  return motion_msgs::msg::builder::Init_MotionCtrl_mode_mark();
}

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__BUILDER_HPP_
