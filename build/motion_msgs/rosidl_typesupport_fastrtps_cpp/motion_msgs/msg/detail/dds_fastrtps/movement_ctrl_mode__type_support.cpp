// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from motion_msgs:msg/MovementCtrlMode.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/movement_ctrl_mode__rosidl_typesupport_fastrtps_cpp.hpp"
#include "motion_msgs/msg/detail/movement_ctrl_mode__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace motion_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
cdr_serialize(
  const motion_msgs::msg::MovementCtrlMode & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pitch_ctrl_mode
  cdr << (ros_message.pitch_ctrl_mode ? true : false);
  // Member: roll_ctrl_mode
  cdr << (ros_message.roll_ctrl_mode ? true : false);
  // Member: height_ctrl_mode
  cdr << (ros_message.height_ctrl_mode ? true : false);
  // Member: stand_mode
  cdr << (ros_message.stand_mode ? true : false);
  // Member: jump_mode
  cdr << (ros_message.jump_mode ? true : false);
  // Member: split_mode
  cdr << (ros_message.split_mode ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  motion_msgs::msg::MovementCtrlMode & ros_message)
{
  // Member: pitch_ctrl_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.pitch_ctrl_mode = tmp ? true : false;
  }

  // Member: roll_ctrl_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.roll_ctrl_mode = tmp ? true : false;
  }

  // Member: height_ctrl_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.height_ctrl_mode = tmp ? true : false;
  }

  // Member: stand_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.stand_mode = tmp ? true : false;
  }

  // Member: jump_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.jump_mode = tmp ? true : false;
  }

  // Member: split_mode
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.split_mode = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
get_serialized_size(
  const motion_msgs::msg::MovementCtrlMode & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pitch_ctrl_mode
  {
    size_t item_size = sizeof(ros_message.pitch_ctrl_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: roll_ctrl_mode
  {
    size_t item_size = sizeof(ros_message.roll_ctrl_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: height_ctrl_mode
  {
    size_t item_size = sizeof(ros_message.height_ctrl_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: stand_mode
  {
    size_t item_size = sizeof(ros_message.stand_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: jump_mode
  {
    size_t item_size = sizeof(ros_message.jump_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: split_mode
  {
    size_t item_size = sizeof(ros_message.split_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
max_serialized_size_MovementCtrlMode(
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


  // Member: pitch_ctrl_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: roll_ctrl_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: height_ctrl_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: stand_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: jump_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: split_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = motion_msgs::msg::MovementCtrlMode;
    is_plain =
      (
      offsetof(DataType, split_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _MovementCtrlMode__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const motion_msgs::msg::MovementCtrlMode *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MovementCtrlMode__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<motion_msgs::msg::MovementCtrlMode *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MovementCtrlMode__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const motion_msgs::msg::MovementCtrlMode *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MovementCtrlMode__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MovementCtrlMode(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MovementCtrlMode__callbacks = {
  "motion_msgs::msg",
  "MovementCtrlMode",
  _MovementCtrlMode__cdr_serialize,
  _MovementCtrlMode__cdr_deserialize,
  _MovementCtrlMode__get_serialized_size,
  _MovementCtrlMode__max_serialized_size
};

static rosidl_message_type_support_t _MovementCtrlMode__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MovementCtrlMode__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace motion_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_motion_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<motion_msgs::msg::MovementCtrlMode>()
{
  return &motion_msgs::msg::typesupport_fastrtps_cpp::_MovementCtrlMode__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, motion_msgs, msg, MovementCtrlMode)() {
  return &motion_msgs::msg::typesupport_fastrtps_cpp::_MovementCtrlMode__handle;
}

#ifdef __cplusplus
}
#endif
