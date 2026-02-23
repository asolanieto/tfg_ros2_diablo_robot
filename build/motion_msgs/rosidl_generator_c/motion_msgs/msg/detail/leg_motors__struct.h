// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motion_msgs:msg/LegMotors.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__STRUCT_H_
#define MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__STRUCT_H_

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

/// Struct defined in msg/LegMotors in the package motion_msgs.
typedef struct motion_msgs__msg__LegMotors
{
  std_msgs__msg__Header header;
  int32_t left_hip_enc_rev;
  double left_hip_pos;
  double left_hip_vel;
  double left_hip_iq;
  int32_t left_knee_enc_rev;
  double left_knee_pos;
  double left_knee_vel;
  double left_knee_iq;
  int32_t left_wheel_enc_rev;
  double left_wheel_pos;
  double left_wheel_vel;
  double left_wheel_iq;
  int32_t right_hip_enc_rev;
  double right_hip_pos;
  double right_hip_vel;
  double right_hip_iq;
  int32_t right_knee_enc_rev;
  double right_knee_pos;
  double right_knee_vel;
  double right_knee_iq;
  int32_t right_wheel_enc_rev;
  double right_wheel_pos;
  double right_wheel_vel;
  double right_wheel_iq;
  double left_leg_length;
  double right_leg_length;
} motion_msgs__msg__LegMotors;

// Struct for a sequence of motion_msgs__msg__LegMotors.
typedef struct motion_msgs__msg__LegMotors__Sequence
{
  motion_msgs__msg__LegMotors * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_msgs__msg__LegMotors__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__STRUCT_H_
