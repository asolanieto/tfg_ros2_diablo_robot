// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motion_msgs:msg/CtrlPlot.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__TRAITS_HPP_
#define MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motion_msgs/msg/detail/ctrl_plot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace motion_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CtrlPlot & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CtrlPlot & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CtrlPlot & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace motion_msgs

namespace rosidl_generator_traits
{

[[deprecated("use motion_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const motion_msgs::msg::CtrlPlot & msg,
  std::ostream & out, size_t indentation = 0)
{
  motion_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motion_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const motion_msgs::msg::CtrlPlot & msg)
{
  return motion_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motion_msgs::msg::CtrlPlot>()
{
  return "motion_msgs::msg::CtrlPlot";
}

template<>
inline const char * name<motion_msgs::msg::CtrlPlot>()
{
  return "motion_msgs/msg/CtrlPlot";
}

template<>
struct has_fixed_size<motion_msgs::msg::CtrlPlot>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<motion_msgs::msg::CtrlPlot>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<motion_msgs::msg::CtrlPlot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__TRAITS_HPP_
