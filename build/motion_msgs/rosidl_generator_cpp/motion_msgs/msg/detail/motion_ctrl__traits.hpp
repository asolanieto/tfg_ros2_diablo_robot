// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motion_msgs:msg/MotionCtrl.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__TRAITS_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motion_msgs/msg/detail/motion_ctrl__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'value'
#include "motion_msgs/msg/detail/movement_ctrl_data__traits.hpp"
// Member 'mode'
#include "motion_msgs/msg/detail/movement_ctrl_mode__traits.hpp"

namespace motion_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotionCtrl & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode_mark
  {
    out << "mode_mark: ";
    rosidl_generator_traits::value_to_yaml(msg.mode_mark, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    to_flow_style_yaml(msg.value, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    to_flow_style_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotionCtrl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode_mark
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode_mark: ";
    rosidl_generator_traits::value_to_yaml(msg.mode_mark, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value:\n";
    to_block_style_yaml(msg.value, out, indentation + 2);
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode:\n";
    to_block_style_yaml(msg.mode, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotionCtrl & msg, bool use_flow_style = false)
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
  const motion_msgs::msg::MotionCtrl & msg,
  std::ostream & out, size_t indentation = 0)
{
  motion_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motion_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const motion_msgs::msg::MotionCtrl & msg)
{
  return motion_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motion_msgs::msg::MotionCtrl>()
{
  return "motion_msgs::msg::MotionCtrl";
}

template<>
inline const char * name<motion_msgs::msg::MotionCtrl>()
{
  return "motion_msgs/msg/MotionCtrl";
}

template<>
struct has_fixed_size<motion_msgs::msg::MotionCtrl>
  : std::integral_constant<bool, has_fixed_size<motion_msgs::msg::MovementCtrlData>::value && has_fixed_size<motion_msgs::msg::MovementCtrlMode>::value> {};

template<>
struct has_bounded_size<motion_msgs::msg::MotionCtrl>
  : std::integral_constant<bool, has_bounded_size<motion_msgs::msg::MovementCtrlData>::value && has_bounded_size<motion_msgs::msg::MovementCtrlMode>::value> {};

template<>
struct is_message<motion_msgs::msg::MotionCtrl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__TRAITS_HPP_
