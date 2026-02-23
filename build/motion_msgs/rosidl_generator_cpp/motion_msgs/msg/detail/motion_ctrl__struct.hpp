// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motion_msgs:msg/MotionCtrl.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__STRUCT_HPP_
#define MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'value'
#include "motion_msgs/msg/detail/movement_ctrl_data__struct.hpp"
// Member 'mode'
#include "motion_msgs/msg/detail/movement_ctrl_mode__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__motion_msgs__msg__MotionCtrl __attribute__((deprecated))
#else
# define DEPRECATED__motion_msgs__msg__MotionCtrl __declspec(deprecated)
#endif

namespace motion_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotionCtrl_
{
  using Type = MotionCtrl_<ContainerAllocator>;

  explicit MotionCtrl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : value(_init),
    mode(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode_mark = false;
    }
  }

  explicit MotionCtrl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : value(_alloc, _init),
    mode(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode_mark = false;
    }
  }

  // field types and members
  using _mode_mark_type =
    bool;
  _mode_mark_type mode_mark;
  using _value_type =
    motion_msgs::msg::MovementCtrlData_<ContainerAllocator>;
  _value_type value;
  using _mode_type =
    motion_msgs::msg::MovementCtrlMode_<ContainerAllocator>;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__mode_mark(
    const bool & _arg)
  {
    this->mode_mark = _arg;
    return *this;
  }
  Type & set__value(
    const motion_msgs::msg::MovementCtrlData_<ContainerAllocator> & _arg)
  {
    this->value = _arg;
    return *this;
  }
  Type & set__mode(
    const motion_msgs::msg::MovementCtrlMode_<ContainerAllocator> & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motion_msgs::msg::MotionCtrl_<ContainerAllocator> *;
  using ConstRawPtr =
    const motion_msgs::msg::MotionCtrl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motion_msgs::msg::MotionCtrl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motion_msgs::msg::MotionCtrl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::MotionCtrl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::MotionCtrl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::MotionCtrl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::MotionCtrl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motion_msgs::msg::MotionCtrl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motion_msgs::msg::MotionCtrl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motion_msgs__msg__MotionCtrl
    std::shared_ptr<motion_msgs::msg::MotionCtrl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motion_msgs__msg__MotionCtrl
    std::shared_ptr<motion_msgs::msg::MotionCtrl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotionCtrl_ & other) const
  {
    if (this->mode_mark != other.mode_mark) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotionCtrl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotionCtrl_

// alias to use template instance with default allocator
using MotionCtrl =
  motion_msgs::msg::MotionCtrl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__MOTION_CTRL__STRUCT_HPP_
