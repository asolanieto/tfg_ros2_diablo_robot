// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motion_msgs:msg/CtrlPlot.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__STRUCT_HPP_
#define MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__STRUCT_HPP_

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
# define DEPRECATED__motion_msgs__msg__CtrlPlot __attribute__((deprecated))
#else
# define DEPRECATED__motion_msgs__msg__CtrlPlot __declspec(deprecated)
#endif

namespace motion_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CtrlPlot_
{
  using Type = CtrlPlot_<ContainerAllocator>;

  explicit CtrlPlot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0.0;
    }
  }

  explicit CtrlPlot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _value_type =
    double;
  _value_type value;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__value(
    const double & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motion_msgs::msg::CtrlPlot_<ContainerAllocator> *;
  using ConstRawPtr =
    const motion_msgs::msg::CtrlPlot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motion_msgs::msg::CtrlPlot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motion_msgs::msg::CtrlPlot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::CtrlPlot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::CtrlPlot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::CtrlPlot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::CtrlPlot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motion_msgs::msg::CtrlPlot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motion_msgs::msg::CtrlPlot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motion_msgs__msg__CtrlPlot
    std::shared_ptr<motion_msgs::msg::CtrlPlot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motion_msgs__msg__CtrlPlot
    std::shared_ptr<motion_msgs::msg::CtrlPlot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CtrlPlot_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const CtrlPlot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CtrlPlot_

// alias to use template instance with default allocator
using CtrlPlot =
  motion_msgs::msg::CtrlPlot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__CTRL_PLOT__STRUCT_HPP_
