// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motion_msgs:msg/MotionCtrl.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__STRUCT_H_
#define MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'value'
#include "motion_msgs/msg/detail/movement_ctrl_data__struct.h"
// Member 'mode'
#include "motion_msgs/msg/detail/movement_ctrl_mode__struct.h"

/// Struct defined in msg/MotionCtrl in the package motion_msgs.
typedef struct motion_msgs__msg__MotionCtrl
{
  bool mode_mark;
  motion_msgs__msg__MovementCtrlData value;
  motion_msgs__msg__MovementCtrlMode mode;
} motion_msgs__msg__MotionCtrl;

// Struct for a sequence of motion_msgs__msg__MotionCtrl.
typedef struct motion_msgs__msg__MotionCtrl__Sequence
{
  motion_msgs__msg__MotionCtrl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_msgs__msg__MotionCtrl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__STRUCT_H_
