// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motion_msgs:msg/MovementCtrlMode.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__STRUCT_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__motion_msgs__msg__MovementCtrlMode __attribute__((deprecated))
#else
# define DEPRECATED__motion_msgs__msg__MovementCtrlMode __declspec(deprecated)
#endif

namespace motion_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MovementCtrlMode_
{
  using Type = MovementCtrlMode_<ContainerAllocator>;

  explicit MovementCtrlMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pitch_ctrl_mode = false;
      this->roll_ctrl_mode = false;
      this->height_ctrl_mode = false;
      this->stand_mode = false;
      this->jump_mode = false;
      this->split_mode = false;
    }
  }

  explicit MovementCtrlMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pitch_ctrl_mode = false;
      this->roll_ctrl_mode = false;
      this->height_ctrl_mode = false;
      this->stand_mode = false;
      this->jump_mode = false;
      this->split_mode = false;
    }
  }

  // field types and members
  using _pitch_ctrl_mode_type =
    bool;
  _pitch_ctrl_mode_type pitch_ctrl_mode;
  using _roll_ctrl_mode_type =
    bool;
  _roll_ctrl_mode_type roll_ctrl_mode;
  using _height_ctrl_mode_type =
    bool;
  _height_ctrl_mode_type height_ctrl_mode;
  using _stand_mode_type =
    bool;
  _stand_mode_type stand_mode;
  using _jump_mode_type =
    bool;
  _jump_mode_type jump_mode;
  using _split_mode_type =
    bool;
  _split_mode_type split_mode;

  // setters for named parameter idiom
  Type & set__pitch_ctrl_mode(
    const bool & _arg)
  {
    this->pitch_ctrl_mode = _arg;
    return *this;
  }
  Type & set__roll_ctrl_mode(
    const bool & _arg)
  {
    this->roll_ctrl_mode = _arg;
    return *this;
  }
  Type & set__height_ctrl_mode(
    const bool & _arg)
  {
    this->height_ctrl_mode = _arg;
    return *this;
  }
  Type & set__stand_mode(
    const bool & _arg)
  {
    this->stand_mode = _arg;
    return *this;
  }
  Type & set__jump_mode(
    const bool & _arg)
  {
    this->jump_mode = _arg;
    return *this;
  }
  Type & set__split_mode(
    const bool & _arg)
  {
    this->split_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motion_msgs::msg::MovementCtrlMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const motion_msgs::msg::MovementCtrlMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motion_msgs::msg::MovementCtrlMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motion_msgs::msg::MovementCtrlMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::MovementCtrlMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::MovementCtrlMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::MovementCtrlMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::MovementCtrlMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motion_msgs::msg::MovementCtrlMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motion_msgs::msg::MovementCtrlMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motion_msgs__msg__MovementCtrlMode
    std::shared_ptr<motion_msgs::msg::MovementCtrlMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motion_msgs__msg__MovementCtrlMode
    std::shared_ptr<motion_msgs::msg::MovementCtrlMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MovementCtrlMode_ & other) const
  {
    if (this->pitch_ctrl_mode != other.pitch_ctrl_mode) {
      return false;
    }
    if (this->roll_ctrl_mode != other.roll_ctrl_mode) {
      return false;
    }
    if (this->height_ctrl_mode != other.height_ctrl_mode) {
      return false;
    }
    if (this->stand_mode != other.stand_mode) {
      return false;
    }
    if (this->jump_mode != other.jump_mode) {
      return false;
    }
    if (this->split_mode != other.split_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const MovementCtrlMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MovementCtrlMode_

// alias to use template instance with default allocator
using MovementCtrlMode =
  motion_msgs::msg::MovementCtrlMode_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_MODE__STRUCT_HPP_
