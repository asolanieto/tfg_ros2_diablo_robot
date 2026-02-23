// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motion_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
#define MOTION_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__motion_msgs__msg__RobotStatus __attribute__((deprecated))
#else
# define DEPRECATED__motion_msgs__msg__RobotStatus __declspec(deprecated)
#endif

namespace motion_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotStatus_
{
  using Type = RobotStatus_<ContainerAllocator>;

  explicit RobotStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ctrl_mode_msg = 0;
      this->robot_mode_msg = 0;
      this->error_msg = 0ul;
      this->warning_msg = 0ul;
    }
  }

  explicit RobotStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ctrl_mode_msg = 0;
      this->robot_mode_msg = 0;
      this->error_msg = 0ul;
      this->warning_msg = 0ul;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _ctrl_mode_msg_type =
    uint8_t;
  _ctrl_mode_msg_type ctrl_mode_msg;
  using _robot_mode_msg_type =
    uint8_t;
  _robot_mode_msg_type robot_mode_msg;
  using _error_msg_type =
    uint32_t;
  _error_msg_type error_msg;
  using _warning_msg_type =
    uint32_t;
  _warning_msg_type warning_msg;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__ctrl_mode_msg(
    const uint8_t & _arg)
  {
    this->ctrl_mode_msg = _arg;
    return *this;
  }
  Type & set__robot_mode_msg(
    const uint8_t & _arg)
  {
    this->robot_mode_msg = _arg;
    return *this;
  }
  Type & set__error_msg(
    const uint32_t & _arg)
  {
    this->error_msg = _arg;
    return *this;
  }
  Type & set__warning_msg(
    const uint32_t & _arg)
  {
    this->warning_msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motion_msgs::msg::RobotStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const motion_msgs::msg::RobotStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motion_msgs::msg::RobotStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motion_msgs::msg::RobotStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::RobotStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::RobotStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::RobotStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::RobotStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motion_msgs::msg::RobotStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motion_msgs::msg::RobotStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motion_msgs__msg__RobotStatus
    std::shared_ptr<motion_msgs::msg::RobotStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motion_msgs__msg__RobotStatus
    std::shared_ptr<motion_msgs::msg::RobotStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->ctrl_mode_msg != other.ctrl_mode_msg) {
      return false;
    }
    if (this->robot_mode_msg != other.robot_mode_msg) {
      return false;
    }
    if (this->error_msg != other.error_msg) {
      return false;
    }
    if (this->warning_msg != other.warning_msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStatus_

// alias to use template instance with default allocator
using RobotStatus =
  motion_msgs::msg::RobotStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__ROBOT_STATUS__STRUCT_HPP_
