// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ception_msgs:msg/IMUEuler.idl
// generated code does not contain a copyright notice

#ifndef CEPTION_MSGS__MSG__DETAIL__IMU_EULER__STRUCT_HPP_
#define CEPTION_MSGS__MSG__DETAIL__IMU_EULER__STRUCT_HPP_

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
# define DEPRECATED__ception_msgs__msg__IMUEuler __attribute__((deprecated))
#else
# define DEPRECATED__ception_msgs__msg__IMUEuler __declspec(deprecated)
#endif

namespace ception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IMUEuler_
{
  using Type = IMUEuler_<ContainerAllocator>;

  explicit IMUEuler_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  explicit IMUEuler_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
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
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ception_msgs::msg::IMUEuler_<ContainerAllocator> *;
  using ConstRawPtr =
    const ception_msgs::msg::IMUEuler_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ception_msgs::msg::IMUEuler_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ception_msgs::msg::IMUEuler_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ception_msgs::msg::IMUEuler_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ception_msgs::msg::IMUEuler_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ception_msgs::msg::IMUEuler_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ception_msgs::msg::IMUEuler_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ception_msgs::msg::IMUEuler_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ception_msgs::msg::IMUEuler_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ception_msgs__msg__IMUEuler
    std::shared_ptr<ception_msgs::msg::IMUEuler_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ception_msgs__msg__IMUEuler
    std::shared_ptr<ception_msgs::msg::IMUEuler_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IMUEuler_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const IMUEuler_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IMUEuler_

// alias to use template instance with default allocator
using IMUEuler =
  ception_msgs::msg::IMUEuler_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ception_msgs

#endif  // CEPTION_MSGS__MSG__DETAIL__IMU_EULER__STRUCT_HPP_
