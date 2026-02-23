// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ception_msgs:msg/IMUEuler.idl
// generated code does not contain a copyright notice

#ifndef CEPTION_MSGS__MSG__DETAIL__IMU_EULER__TRAITS_HPP_
#define CEPTION_MSGS__MSG__DETAIL__IMU_EULER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ception_msgs/msg/detail/imu_euler__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace ception_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const IMUEuler & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
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

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IMUEuler & msg,
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

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IMUEuler & msg, bool use_flow_style = false)
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

}  // namespace ception_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ception_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ception_msgs::msg::IMUEuler & msg,
  std::ostream & out, size_t indentation = 0)
{
  ception_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ception_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ception_msgs::msg::IMUEuler & msg)
{
  return ception_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ception_msgs::msg::IMUEuler>()
{
  return "ception_msgs::msg::IMUEuler";
}

template<>
inline const char * name<ception_msgs::msg::IMUEuler>()
{
  return "ception_msgs/msg/IMUEuler";
}

template<>
struct has_fixed_size<ception_msgs::msg::IMUEuler>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<ception_msgs::msg::IMUEuler>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<ception_msgs::msg::IMUEuler>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CEPTION_MSGS__MSG__DETAIL__IMU_EULER__TRAITS_HPP_
