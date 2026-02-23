// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from motion_msgs:msg/MovementCtrlData.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/movement_ctrl_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "motion_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "motion_msgs/msg/detail/movement_ctrl_data__struct.h"
#include "motion_msgs/msg/detail/movement_ctrl_data__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _MovementCtrlData__ros_msg_type = motion_msgs__msg__MovementCtrlData;

static bool _MovementCtrlData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MovementCtrlData__ros_msg_type * ros_message = static_cast<const _MovementCtrlData__ros_msg_type *>(untyped_ros_message);
  // Field name: forward
  {
    cdr << ros_message->forward;
  }

  // Field name: left
  {
    cdr << ros_message->left;
  }

  // Field name: up
  {
    cdr << ros_message->up;
  }

  // Field name: roll
  {
    cdr << ros_message->roll;
  }

  // Field name: pitch
  {
    cdr << ros_message->pitch;
  }

  // Field name: leg_split
  {
    cdr << ros_message->leg_split;
  }

  return true;
}

static bool _MovementCtrlData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MovementCtrlData__ros_msg_type * ros_message = static_cast<_MovementCtrlData__ros_msg_type *>(untyped_ros_message);
  // Field name: forward
  {
    cdr >> ros_message->forward;
  }

  // Field name: left
  {
    cdr >> ros_message->left;
  }

  // Field name: up
  {
    cdr >> ros_message->up;
  }

  // Field name: roll
  {
    cdr >> ros_message->roll;
  }

  // Field name: pitch
  {
    cdr >> ros_message->pitch;
  }

  // Field name: leg_split
  {
    cdr >> ros_message->leg_split;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_motion_msgs
size_t get_serialized_size_motion_msgs__msg__MovementCtrlData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MovementCtrlData__ros_msg_type * ros_message = static_cast<const _MovementCtrlData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name forward
  {
    size_t item_size = sizeof(ros_message->forward);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name left
  {
    size_t item_size = sizeof(ros_message->left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name up
  {
    size_t item_size = sizeof(ros_message->up);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name roll
  {
    size_t item_size = sizeof(ros_message->roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch
  {
    size_t item_size = sizeof(ros_message->pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leg_split
  {
    size_t item_size = sizeof(ros_message->leg_split);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MovementCtrlData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_motion_msgs__msg__MovementCtrlData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_motion_msgs
size_t max_serialized_size_motion_msgs__msg__MovementCtrlData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: forward
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: left
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: up
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: roll
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: leg_split
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = motion_msgs__msg__MovementCtrlData;
    is_plain =
      (
      offsetof(DataType, leg_split) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MovementCtrlData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_motion_msgs__msg__MovementCtrlData(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MovementCtrlData = {
  "motion_msgs::msg",
  "MovementCtrlData",
  _MovementCtrlData__cdr_serialize,
  _MovementCtrlData__cdr_deserialize,
  _MovementCtrlData__get_serialized_size,
  _MovementCtrlData__max_serialized_size
};

static rosidl_message_type_support_t _MovementCtrlData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MovementCtrlData,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, motion_msgs, msg, MovementCtrlData)() {
  return &_MovementCtrlData__type_support;
}

#if defined(__cplusplus)
}
#endif
