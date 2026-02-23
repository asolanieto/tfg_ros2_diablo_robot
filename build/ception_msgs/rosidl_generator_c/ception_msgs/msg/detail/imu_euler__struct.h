// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ception_msgs:msg/IMUEuler.idl
// generated code does not contain a copyright notice

#ifndef CEPTION_MSGS__MSG__DETAIL__IMU_EULER__STRUCT_H_
#define CEPTION_MSGS__MSG__DETAIL__IMU_EULER__STRUCT_H_

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

/// Struct defined in msg/IMUEuler in the package ception_msgs.
typedef struct ception_msgs__msg__IMUEuler
{
  std_msgs__msg__Header header;
  double roll;
  double pitch;
  double yaw;
} ception_msgs__msg__IMUEuler;

// Struct for a sequence of ception_msgs__msg__IMUEuler.
typedef struct ception_msgs__msg__IMUEuler__Sequence
{
  ception_msgs__msg__IMUEuler * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ception_msgs__msg__IMUEuler__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CEPTION_MSGS__MSG__DETAIL__IMU_EULER__STRUCT_H_
