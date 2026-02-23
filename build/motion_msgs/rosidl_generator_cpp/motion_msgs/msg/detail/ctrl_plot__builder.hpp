// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motion_msgs:msg/CtrlPlot.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__BUILDER_HPP_
#define MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motion_msgs/msg/detail/ctrl_plot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motion_msgs
{

namespace msg
{

namespace builder
{

class Init_CtrlPlot_value
{
public:
  explicit Init_CtrlPlot_value(::motion_msgs::msg::CtrlPlot & msg)
  : msg_(msg)
  {}
  ::motion_msgs::msg::CtrlPlot value(::motion_msgs::msg::CtrlPlot::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_msgs::msg::CtrlPlot msg_;
};

class Init_CtrlPlot_header
{
public:
  Init_CtrlPlot_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CtrlPlot_value header(::motion_msgs::msg::CtrlPlot::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_CtrlPlot_value(msg_);
  }

private:
  ::motion_msgs::msg::CtrlPlot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_msgs::msg::CtrlPlot>()
{
  return motion_msgs::msg::builder::Init_CtrlPlot_header();
}

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__BUILDER_HPP_
