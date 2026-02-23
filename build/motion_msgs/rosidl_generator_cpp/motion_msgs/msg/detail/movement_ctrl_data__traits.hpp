// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motion_msgs:msg/MovementCtrlData.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__TRAITS_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motion_msgs/msg/detail/movement_ctrl_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace motion_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MovementCtrlData & msg,
  std::ostream & out)
{
  out << "{";
  // member: forward
  {
    out << "forward: ";
    rosidl_generator_traits::value_to_yaml(msg.forward, out);
    out << ", ";
  }

  // member: left
  {
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << ", ";
  }

  // member: up
  {
    out << "up: ";
    rosidl_generator_traits::value_to_yaml(msg.up, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: leg_split
  {
    out << "leg_split: ";
    rosidl_generator_traits::value_to_yaml(msg.leg_split, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MovementCtrlData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: forward
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "forward: ";
    rosidl_generator_traits::value_to_yaml(msg.forward, out);
    out << "\n";
  }

  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << "\n";
  }

  // member: up
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "up: ";
    rosidl_generator_traits::value_to_yaml(msg.up, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: leg_split
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "leg_split: ";
    rosidl_generator_traits::value_to_yaml(msg.leg_split, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MovementCtrlData & msg, bool use_flow_style = false)
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
  const motion_msgs::msg::MovementCtrlData & msg,
  std::ostream & out, size_t indentation = 0)
{
  motion_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motion_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const motion_msgs::msg::MovementCtrlData & msg)
{
  return motion_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motion_msgs::msg::MovementCtrlData>()
{
  return "motion_msgs::msg::MovementCtrlData";
}

template<>
inline const char * name<motion_msgs::msg::MovementCtrlData>()
{
  return "motion_msgs/msg/MovementCtrlData";
}

template<>
struct has_fixed_size<motion_msgs::msg::MovementCtrlData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<motion_msgs::msg::MovementCtrlData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<motion_msgs::msg::MovementCtrlData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__TRAITS_HPP_
