// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from motion_msgs:msg/MotionCtrl.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "motion_msgs/msg/detail/motion_ctrl__rosidl_typesupport_introspection_c.h"
#include "motion_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "motion_msgs/msg/detail/motion_ctrl__functions.h"
#include "motion_msgs/msg/detail/motion_ctrl__struct.h"


// Include directives for member types
// Member `value`
#include "motion_msgs/msg/movement_ctrl_data.h"
// Member `value`
#include "motion_msgs/msg/detail/movement_ctrl_data__rosidl_typesupport_introspection_c.h"
// Member `mode`
#include "motion_msgs/msg/movement_ctrl_mode.h"
// Member `mode`
#include "motion_msgs/msg/detail/movement_ctrl_mode__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  motion_msgs__msg__MotionCtrl__init(message_memory);
}

void motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_fini_function(void * message_memory)
{
  motion_msgs__msg__MotionCtrl__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_member_array[3] = {
  {
    "mode_mark",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MotionCtrl, mode_mark),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MotionCtrl, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MotionCtrl, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_members = {
  "motion_msgs__msg",  // message namespace
  "MotionCtrl",  // message name
  3,  // number of fields
  sizeof(motion_msgs__msg__MotionCtrl),
  motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_member_array,  // message members
  motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_init_function,  // function to initialize message memory (memory has to be allocated)
  motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_type_support_handle = {
  0,
  &motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_motion_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motion_msgs, msg, MotionCtrl)() {
  motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motion_msgs, msg, MovementCtrlData)();
  motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motion_msgs, msg, MovementCtrlMode)();
  if (!motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_type_support_handle.typesupport_identifier) {
    motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &motion_msgs__msg__MotionCtrl__rosidl_typesupport_introspection_c__MotionCtrl_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
