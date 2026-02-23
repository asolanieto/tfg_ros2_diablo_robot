// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motion_msgs:msg/MovementCtrlData.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__STRUCT_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__motion_msgs__msg__MovementCtrlData __attribute__((deprecated))
#else
# define DEPRECATED__motion_msgs__msg__MovementCtrlData __declspec(deprecated)
#endif

namespace motion_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MovementCtrlData_
{
  using Type = MovementCtrlData_<ContainerAllocator>;

  explicit MovementCtrlData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->forward = 0.0;
      this->left = 0.0;
      this->up = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->leg_split = 0.0;
    }
  }

  explicit MovementCtrlData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->forward = 0.0;
      this->left = 0.0;
      this->up = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->leg_split = 0.0;
    }
  }

  // field types and members
  using _forward_type =
    double;
  _forward_type forward;
  using _left_type =
    double;
  _left_type left;
  using _up_type =
    double;
  _up_type up;
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _leg_split_type =
    double;
  _leg_split_type leg_split;

  // setters for named parameter idiom
  Type & set__forward(
    const double & _arg)
  {
    this->forward = _arg;
    return *this;
  }
  Type & set__left(
    const double & _arg)
  {
    this->left = _arg;
    return *this;
  }
  Type & set__up(
    const double & _arg)
  {
    this->up = _arg;
    return *this;
  }
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__leg_split(
    const double & _arg)
  {
    this->leg_split = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motion_msgs::msg::MovementCtrlData_<ContainerAllocator> *;
  using ConstRawPtr =
    const motion_msgs::msg::MovementCtrlData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motion_msgs::msg::MovementCtrlData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motion_msgs::msg::MovementCtrlData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::MovementCtrlData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::MovementCtrlData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::MovementCtrlData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::MovementCtrlData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motion_msgs::msg::MovementCtrlData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motion_msgs::msg::MovementCtrlData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motion_msgs__msg__MovementCtrlData
    std::shared_ptr<motion_msgs::msg::MovementCtrlData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motion_msgs__msg__MovementCtrlData
    std::shared_ptr<motion_msgs::msg::MovementCtrlData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MovementCtrlData_ & other) const
  {
    if (this->forward != other.forward) {
      return false;
    }
    if (this->left != other.left) {
      return false;
    }
    if (this->up != other.up) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->leg_split != other.leg_split) {
      return false;
    }
    return true;
  }
  bool operator!=(const MovementCtrlData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MovementCtrlData_

// alias to use template instance with default allocator
using MovementCtrlData =
  motion_msgs::msg::MovementCtrlData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__MOVEMENT_CTRL_DATA__STRUCT_HPP_
