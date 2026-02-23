// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from motion_msgs:msg/MovementCtrlData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "motion_msgs/msg/detail/movement_ctrl_data__rosidl_typesupport_introspection_c.h"
#include "motion_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "motion_msgs/msg/detail/movement_ctrl_data__functions.h"
#include "motion_msgs/msg/detail/movement_ctrl_data__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  motion_msgs__msg__MovementCtrlData__init(message_memory);
}

void motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_fini_function(void * message_memory)
{
  motion_msgs__msg__MovementCtrlData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_message_member_array[6] = {
  {
    "forward",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlData, forward),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlData, left),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "up",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlData, up),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlData, roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlData, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "leg_split",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motion_msgs__msg__MovementCtrlData, leg_split),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_message_members = {
  "motion_msgs__msg",  // message namespace
  "MovementCtrlData",  // message name
  6,  // number of fields
  sizeof(motion_msgs__msg__MovementCtrlData),
  motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_message_member_array,  // message members
  motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_init_function,  // function to initialize message memory (memory has to be allocated)
  motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_message_type_support_handle = {
  0,
  &motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_motion_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, motion_msgs, msg, MovementCtrlData)() {
  if (!motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_message_type_support_handle.typesupport_identifier) {
    motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &motion_msgs__msg__MovementCtrlData__rosidl_typesupport_introspection_c__MovementCtrlData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
