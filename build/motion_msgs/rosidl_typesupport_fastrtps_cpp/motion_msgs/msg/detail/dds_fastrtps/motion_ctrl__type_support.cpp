// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from motion_msgs:msg/MotionCtrl.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/motion_ctrl__rosidl_typesupport_fastrtps_cpp.hpp"
#include "motion_msgs/msg/detail/motion_ctrl__struct.hpp"

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
bool cdr_serialize(
  const motion_msgs::msg::MovementCtrlData &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  motion_msgs::msg::MovementCtrlData &);
size_t get_serialized_size(
  const motion_msgs::msg::MovementCtrlData &,
  size_t current_alignment);
size_t
max_serialized_size_MovementCtrlData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace motion_msgs

namespace motion_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const motion_msgs::msg::MovementCtrlMode &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  motion_msgs::msg::MovementCtrlMode &);
size_t get_serialized_size(
  const motion_msgs::msg::MovementCtrlMode &,
  size_t current_alignment);
size_t
max_serialized_size_MovementCtrlMode(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace motion_msgs


namespace motion_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
cdr_serialize(
  const motion_msgs::msg::MotionCtrl & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mode_mark
  cdr << (ros_message.mode_mark ? true : false);
  // Member: value
  motion_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.value,
    cdr);
  // Member: mode
  motion_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.mode,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  motion_msgs::msg::MotionCtrl & ros_message)
{
  // Member: mode_mark
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.mode_mark = tmp ? true : false;
  }

  // Member: value
  motion_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.value);

  // Member: mode
  motion_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.mode);

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
get_serialized_size(
  const motion_msgs::msg::MotionCtrl & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: mode_mark
  {
    size_t item_size = sizeof(ros_message.mode_mark);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: value

  current_alignment +=
    motion_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.value, current_alignment);
  // Member: mode

  current_alignment +=
    motion_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.mode, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_motion_msgs
max_serialized_size_MotionCtrl(
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


  // Member: mode_mark
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: value
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        motion_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_MovementCtrlData(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: mode
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        motion_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_MovementCtrlMode(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = motion_msgs::msg::MotionCtrl;
    is_plain =
      (
      offsetof(DataType, mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _MotionCtrl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const motion_msgs::msg::MotionCtrl *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MotionCtrl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<motion_msgs::msg::MotionCtrl *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MotionCtrl__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const motion_msgs::msg::MotionCtrl *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MotionCtrl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MotionCtrl(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MotionCtrl__callbacks = {
  "motion_msgs::msg",
  "MotionCtrl",
  _MotionCtrl__cdr_serialize,
  _MotionCtrl__cdr_deserialize,
  _MotionCtrl__get_serialized_size,
  _MotionCtrl__max_serialized_size
};

static rosidl_message_type_support_t _MotionCtrl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MotionCtrl__callbacks,
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
get_message_type_support_handle<motion_msgs::msg::MotionCtrl>()
{
  return &motion_msgs::msg::typesupport_fastrtps_cpp::_MotionCtrl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, motion_msgs, msg, MotionCtrl)() {
  return &motion_msgs::msg::typesupport_fastrtps_cpp::_MotionCtrl__handle;
}

#ifdef __cplusplus
}
#endif
