// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motion_msgs:msg/MovementCtrlMode.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__STRUCT_H_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MovementCtrlMode in the package motion_msgs.
typedef struct motion_msgs__msg__MovementCtrlMode
{
  bool pitch_ctrl_mode;
  bool roll_ctrl_mode;
  bool height_ctrl_mode;
  bool stand_mode;
  bool jump_mode;
  bool split_mode;
} motion_msgs__msg__MovementCtrlMode;

// Struct for a sequence of motion_msgs__msg__MovementCtrlMode.
typedef struct motion_msgs__msg__MovementCtrlMode__Sequence
{
  motion_msgs__msg__MovementCtrlMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_msgs__msg__MovementCtrlMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__STRUCT_H_
