// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motion_msgs:msg/MovementCtrlMode.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__TRAITS_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motion_msgs/msg/detail/movement_ctrl_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace motion_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MovementCtrlMode & msg,
  std::ostream & out)
{
  out << "{";
  // member: pitch_ctrl_mode
  {
    out << "pitch_ctrl_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_ctrl_mode, out);
    out << ", ";
  }

  // member: roll_ctrl_mode
  {
    out << "roll_ctrl_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_ctrl_mode, out);
    out << ", ";
  }

  // member: height_ctrl_mode
  {
    out << "height_ctrl_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.height_ctrl_mode, out);
    out << ", ";
  }

  // member: stand_mode
  {
    out << "stand_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.stand_mode, out);
    out << ", ";
  }

  // member: jump_mode
  {
    out << "jump_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.jump_mode, out);
    out << ", ";
  }

  // member: split_mode
  {
    out << "split_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.split_mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MovementCtrlMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pitch_ctrl_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_ctrl_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_ctrl_mode, out);
    out << "\n";
  }

  // member: roll_ctrl_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_ctrl_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_ctrl_mode, out);
    out << "\n";
  }

  // member: height_ctrl_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height_ctrl_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.height_ctrl_mode, out);
    out << "\n";
  }

  // member: stand_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stand_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.stand_mode, out);
    out << "\n";
  }

  // member: jump_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "jump_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.jump_mode, out);
    out << "\n";
  }

  // member: split_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "split_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.split_mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MovementCtrlMode & msg, bool use_flow_style = false)
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
  const motion_msgs::msg::MovementCtrlMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  motion_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motion_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const motion_msgs::msg::MovementCtrlMode & msg)
{
  return motion_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motion_msgs::msg::MovementCtrlMode>()
{
  return "motion_msgs::msg::MovementCtrlMode";
}

template<>
inline const char * name<motion_msgs::msg::MovementCtrlMode>()
{
  return "motion_msgs/msg/MovementCtrlMode";
}

template<>
struct has_fixed_size<motion_msgs::msg::MovementCtrlMode>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<motion_msgs::msg::MovementCtrlMode>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<motion_msgs::msg::MovementCtrlMode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__TRAITS_HPP_
