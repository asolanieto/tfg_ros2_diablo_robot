// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motion_msgs:msg/MovementCtrlData.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__STRUCT_H_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MovementCtrlData in the package motion_msgs.
typedef struct motion_msgs__msg__MovementCtrlData
{
  double forward;
  double left;
  double up;
  double roll;
  double pitch;
  double leg_split;
} motion_msgs__msg__MovementCtrlData;

// Struct for a sequence of motion_msgs__msg__MovementCtrlData.
typedef struct motion_msgs__msg__MovementCtrlData__Sequence
{
  motion_msgs__msg__MovementCtrlData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motion_msgs__msg__MovementCtrlData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__STRUCT_H_
