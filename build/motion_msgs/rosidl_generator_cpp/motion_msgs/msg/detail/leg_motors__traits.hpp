// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motion_msgs:msg/LegMotors.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__TRAITS_HPP_
#define MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motion_msgs/msg/detail/leg_motors__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace motion_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LegMotors & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: left_hip_enc_rev
  {
    out << "left_hip_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.left_hip_enc_rev, out);
    out << ", ";
  }

  // member: left_hip_pos
  {
    out << "left_hip_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_hip_pos, out);
    out << ", ";
  }

  // member: left_hip_vel
  {
    out << "left_hip_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.left_hip_vel, out);
    out << ", ";
  }

  // member: left_hip_iq
  {
    out << "left_hip_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.left_hip_iq, out);
    out << ", ";
  }

  // member: left_knee_enc_rev
  {
    out << "left_knee_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.left_knee_enc_rev, out);
    out << ", ";
  }

  // member: left_knee_pos
  {
    out << "left_knee_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_knee_pos, out);
    out << ", ";
  }

  // member: left_knee_vel
  {
    out << "left_knee_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.left_knee_vel, out);
    out << ", ";
  }

  // member: left_knee_iq
  {
    out << "left_knee_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.left_knee_iq, out);
    out << ", ";
  }

  // member: left_wheel_enc_rev
  {
    out << "left_wheel_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_enc_rev, out);
    out << ", ";
  }

  // member: left_wheel_pos
  {
    out << "left_wheel_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_pos, out);
    out << ", ";
  }

  // member: left_wheel_vel
  {
    out << "left_wheel_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_vel, out);
    out << ", ";
  }

  // member: left_wheel_iq
  {
    out << "left_wheel_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_iq, out);
    out << ", ";
  }

  // member: right_hip_enc_rev
  {
    out << "right_hip_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.right_hip_enc_rev, out);
    out << ", ";
  }

  // member: right_hip_pos
  {
    out << "right_hip_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_hip_pos, out);
    out << ", ";
  }

  // member: right_hip_vel
  {
    out << "right_hip_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.right_hip_vel, out);
    out << ", ";
  }

  // member: right_hip_iq
  {
    out << "right_hip_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.right_hip_iq, out);
    out << ", ";
  }

  // member: right_knee_enc_rev
  {
    out << "right_knee_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.right_knee_enc_rev, out);
    out << ", ";
  }

  // member: right_knee_pos
  {
    out << "right_knee_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_knee_pos, out);
    out << ", ";
  }

  // member: right_knee_vel
  {
    out << "right_knee_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.right_knee_vel, out);
    out << ", ";
  }

  // member: right_knee_iq
  {
    out << "right_knee_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.right_knee_iq, out);
    out << ", ";
  }

  // member: right_wheel_enc_rev
  {
    out << "right_wheel_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_enc_rev, out);
    out << ", ";
  }

  // member: right_wheel_pos
  {
    out << "right_wheel_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_pos, out);
    out << ", ";
  }

  // member: right_wheel_vel
  {
    out << "right_wheel_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_vel, out);
    out << ", ";
  }

  // member: right_wheel_iq
  {
    out << "right_wheel_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_iq, out);
    out << ", ";
  }

  // member: left_leg_length
  {
    out << "left_leg_length: ";
    rosidl_generator_traits::value_to_yaml(msg.left_leg_length, out);
    out << ", ";
  }

  // member: right_leg_length
  {
    out << "right_leg_length: ";
    rosidl_generator_traits::value_to_yaml(msg.right_leg_length, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LegMotors & msg,
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

  // member: left_hip_enc_rev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_hip_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.left_hip_enc_rev, out);
    out << "\n";
  }

  // member: left_hip_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_hip_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_hip_pos, out);
    out << "\n";
  }

  // member: left_hip_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_hip_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.left_hip_vel, out);
    out << "\n";
  }

  // member: left_hip_iq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_hip_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.left_hip_iq, out);
    out << "\n";
  }

  // member: left_knee_enc_rev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_knee_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.left_knee_enc_rev, out);
    out << "\n";
  }

  // member: left_knee_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_knee_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_knee_pos, out);
    out << "\n";
  }

  // member: left_knee_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_knee_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.left_knee_vel, out);
    out << "\n";
  }

  // member: left_knee_iq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_knee_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.left_knee_iq, out);
    out << "\n";
  }

  // member: left_wheel_enc_rev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_wheel_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_enc_rev, out);
    out << "\n";
  }

  // member: left_wheel_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_wheel_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_pos, out);
    out << "\n";
  }

  // member: left_wheel_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_wheel_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_vel, out);
    out << "\n";
  }

  // member: left_wheel_iq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_wheel_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.left_wheel_iq, out);
    out << "\n";
  }

  // member: right_hip_enc_rev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_hip_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.right_hip_enc_rev, out);
    out << "\n";
  }

  // member: right_hip_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_hip_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_hip_pos, out);
    out << "\n";
  }

  // member: right_hip_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_hip_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.right_hip_vel, out);
    out << "\n";
  }

  // member: right_hip_iq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_hip_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.right_hip_iq, out);
    out << "\n";
  }

  // member: right_knee_enc_rev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_knee_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.right_knee_enc_rev, out);
    out << "\n";
  }

  // member: right_knee_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_knee_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_knee_pos, out);
    out << "\n";
  }

  // member: right_knee_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_knee_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.right_knee_vel, out);
    out << "\n";
  }

  // member: right_knee_iq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_knee_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.right_knee_iq, out);
    out << "\n";
  }

  // member: right_wheel_enc_rev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_wheel_enc_rev: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_enc_rev, out);
    out << "\n";
  }

  // member: right_wheel_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_wheel_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_pos, out);
    out << "\n";
  }

  // member: right_wheel_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_wheel_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_vel, out);
    out << "\n";
  }

  // member: right_wheel_iq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_wheel_iq: ";
    rosidl_generator_traits::value_to_yaml(msg.right_wheel_iq, out);
    out << "\n";
  }

  // member: left_leg_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_leg_length: ";
    rosidl_generator_traits::value_to_yaml(msg.left_leg_length, out);
    out << "\n";
  }

  // member: right_leg_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_leg_length: ";
    rosidl_generator_traits::value_to_yaml(msg.right_leg_length, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LegMotors & msg, bool use_flow_style = false)
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
  const motion_msgs::msg::LegMotors & msg,
  std::ostream & out, size_t indentation = 0)
{
  motion_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motion_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const motion_msgs::msg::LegMotors & msg)
{
  return motion_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motion_msgs::msg::LegMotors>()
{
  return "motion_msgs::msg::LegMotors";
}

template<>
inline const char * name<motion_msgs::msg::LegMotors>()
{
  return "motion_msgs/msg/LegMotors";
}

template<>
struct has_fixed_size<motion_msgs::msg::LegMotors>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<motion_msgs::msg::LegMotors>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<motion_msgs::msg::LegMotors>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__TRAITS_HPP_
