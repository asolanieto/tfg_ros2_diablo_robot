// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motion_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define MOTION_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/RobotStatus in the package motion_msgs.
typedef struct motion_msgs__msg__RobotStatus
{
  std_msgs__msg__Header header;
  uint8_t ctrl_mode_msg;
  uint8_t robot_mode_msg;
  uint32_t error_msg;
  uint32_t warning_msg;
} motion_msgs__msg__RobotStatus;

// Struct for a sequence of motion_msgs__msg__RobotStatus.
typedef struct motion_msgs__msg__RobotStatus__Sequence
{
  motion_msgs__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_msgs__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTION_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
