// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motion_msgs:msg/LegMotors.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__STRUCT_HPP_
#define MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__STRUCT_HPP_

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
# define DEPRECATED__motion_msgs__msg__LegMotors __attribute__((deprecated))
#else
# define DEPRECATED__motion_msgs__msg__LegMotors __declspec(deprecated)
#endif

namespace motion_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LegMotors_
{
  using Type = LegMotors_<ContainerAllocator>;

  explicit LegMotors_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_hip_enc_rev = 0l;
      this->left_hip_pos = 0.0;
      this->left_hip_vel = 0.0;
      this->left_hip_iq = 0.0;
      this->left_knee_enc_rev = 0l;
      this->left_knee_pos = 0.0;
      this->left_knee_vel = 0.0;
      this->left_knee_iq = 0.0;
      this->left_wheel_enc_rev = 0l;
      this->left_wheel_pos = 0.0;
      this->left_wheel_vel = 0.0;
      this->left_wheel_iq = 0.0;
      this->right_hip_enc_rev = 0l;
      this->right_hip_pos = 0.0;
      this->right_hip_vel = 0.0;
      this->right_hip_iq = 0.0;
      this->right_knee_enc_rev = 0l;
      this->right_knee_pos = 0.0;
      this->right_knee_vel = 0.0;
      this->right_knee_iq = 0.0;
      this->right_wheel_enc_rev = 0l;
      this->right_wheel_pos = 0.0;
      this->right_wheel_vel = 0.0;
      this->right_wheel_iq = 0.0;
      this->left_leg_length = 0.0;
      this->right_leg_length = 0.0;
    }
  }

  explicit LegMotors_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_hip_enc_rev = 0l;
      this->left_hip_pos = 0.0;
      this->left_hip_vel = 0.0;
      this->left_hip_iq = 0.0;
      this->left_knee_enc_rev = 0l;
      this->left_knee_pos = 0.0;
      this->left_knee_vel = 0.0;
      this->left_knee_iq = 0.0;
      this->left_wheel_enc_rev = 0l;
      this->left_wheel_pos = 0.0;
      this->left_wheel_vel = 0.0;
      this->left_wheel_iq = 0.0;
      this->right_hip_enc_rev = 0l;
      this->right_hip_pos = 0.0;
      this->right_hip_vel = 0.0;
      this->right_hip_iq = 0.0;
      this->right_knee_enc_rev = 0l;
      this->right_knee_pos = 0.0;
      this->right_knee_vel = 0.0;
      this->right_knee_iq = 0.0;
      this->right_wheel_enc_rev = 0l;
      this->right_wheel_pos = 0.0;
      this->right_wheel_vel = 0.0;
      this->right_wheel_iq = 0.0;
      this->left_leg_length = 0.0;
      this->right_leg_length = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _left_hip_enc_rev_type =
    int32_t;
  _left_hip_enc_rev_type left_hip_enc_rev;
  using _left_hip_pos_type =
    double;
  _left_hip_pos_type left_hip_pos;
  using _left_hip_vel_type =
    double;
  _left_hip_vel_type left_hip_vel;
  using _left_hip_iq_type =
    double;
  _left_hip_iq_type left_hip_iq;
  using _left_knee_enc_rev_type =
    int32_t;
  _left_knee_enc_rev_type left_knee_enc_rev;
  using _left_knee_pos_type =
    double;
  _left_knee_pos_type left_knee_pos;
  using _left_knee_vel_type =
    double;
  _left_knee_vel_type left_knee_vel;
  using _left_knee_iq_type =
    double;
  _left_knee_iq_type left_knee_iq;
  using _left_wheel_enc_rev_type =
    int32_t;
  _left_wheel_enc_rev_type left_wheel_enc_rev;
  using _left_wheel_pos_type =
    double;
  _left_wheel_pos_type left_wheel_pos;
  using _left_wheel_vel_type =
    double;
  _left_wheel_vel_type left_wheel_vel;
  using _left_wheel_iq_type =
    double;
  _left_wheel_iq_type left_wheel_iq;
  using _right_hip_enc_rev_type =
    int32_t;
  _right_hip_enc_rev_type right_hip_enc_rev;
  using _right_hip_pos_type =
    double;
  _right_hip_pos_type right_hip_pos;
  using _right_hip_vel_type =
    double;
  _right_hip_vel_type right_hip_vel;
  using _right_hip_iq_type =
    double;
  _right_hip_iq_type right_hip_iq;
  using _right_knee_enc_rev_type =
    int32_t;
  _right_knee_enc_rev_type right_knee_enc_rev;
  using _right_knee_pos_type =
    double;
  _right_knee_pos_type right_knee_pos;
  using _right_knee_vel_type =
    double;
  _right_knee_vel_type right_knee_vel;
  using _right_knee_iq_type =
    double;
  _right_knee_iq_type right_knee_iq;
  using _right_wheel_enc_rev_type =
    int32_t;
  _right_wheel_enc_rev_type right_wheel_enc_rev;
  using _right_wheel_pos_type =
    double;
  _right_wheel_pos_type right_wheel_pos;
  using _right_wheel_vel_type =
    double;
  _right_wheel_vel_type right_wheel_vel;
  using _right_wheel_iq_type =
    double;
  _right_wheel_iq_type right_wheel_iq;
  using _left_leg_length_type =
    double;
  _left_leg_length_type left_leg_length;
  using _right_leg_length_type =
    double;
  _right_leg_length_type right_leg_length;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__left_hip_enc_rev(
    const int32_t & _arg)
  {
    this->left_hip_enc_rev = _arg;
    return *this;
  }
  Type & set__left_hip_pos(
    const double & _arg)
  {
    this->left_hip_pos = _arg;
    return *this;
  }
  Type & set__left_hip_vel(
    const double & _arg)
  {
    this->left_hip_vel = _arg;
    return *this;
  }
  Type & set__left_hip_iq(
    const double & _arg)
  {
    this->left_hip_iq = _arg;
    return *this;
  }
  Type & set__left_knee_enc_rev(
    const int32_t & _arg)
  {
    this->left_knee_enc_rev = _arg;
    return *this;
  }
  Type & set__left_knee_pos(
    const double & _arg)
  {
    this->left_knee_pos = _arg;
    return *this;
  }
  Type & set__left_knee_vel(
    const double & _arg)
  {
    this->left_knee_vel = _arg;
    return *this;
  }
  Type & set__left_knee_iq(
    const double & _arg)
  {
    this->left_knee_iq = _arg;
    return *this;
  }
  Type & set__left_wheel_enc_rev(
    const int32_t & _arg)
  {
    this->left_wheel_enc_rev = _arg;
    return *this;
  }
  Type & set__left_wheel_pos(
    const double & _arg)
  {
    this->left_wheel_pos = _arg;
    return *this;
  }
  Type & set__left_wheel_vel(
    const double & _arg)
  {
    this->left_wheel_vel = _arg;
    return *this;
  }
  Type & set__left_wheel_iq(
    const double & _arg)
  {
    this->left_wheel_iq = _arg;
    return *this;
  }
  Type & set__right_hip_enc_rev(
    const int32_t & _arg)
  {
    this->right_hip_enc_rev = _arg;
    return *this;
  }
  Type & set__right_hip_pos(
    const double & _arg)
  {
    this->right_hip_pos = _arg;
    return *this;
  }
  Type & set__right_hip_vel(
    const double & _arg)
  {
    this->right_hip_vel = _arg;
    return *this;
  }
  Type & set__right_hip_iq(
    const double & _arg)
  {
    this->right_hip_iq = _arg;
    return *this;
  }
  Type & set__right_knee_enc_rev(
    const int32_t & _arg)
  {
    this->right_knee_enc_rev = _arg;
    return *this;
  }
  Type & set__right_knee_pos(
    const double & _arg)
  {
    this->right_knee_pos = _arg;
    return *this;
  }
  Type & set__right_knee_vel(
    const double & _arg)
  {
    this->right_knee_vel = _arg;
    return *this;
  }
  Type & set__right_knee_iq(
    const double & _arg)
  {
    this->right_knee_iq = _arg;
    return *this;
  }
  Type & set__right_wheel_enc_rev(
    const int32_t & _arg)
  {
    this->right_wheel_enc_rev = _arg;
    return *this;
  }
  Type & set__right_wheel_pos(
    const double & _arg)
  {
    this->right_wheel_pos = _arg;
    return *this;
  }
  Type & set__right_wheel_vel(
    const double & _arg)
  {
    this->right_wheel_vel = _arg;
    return *this;
  }
  Type & set__right_wheel_iq(
    const double & _arg)
  {
    this->right_wheel_iq = _arg;
    return *this;
  }
  Type & set__left_leg_length(
    const double & _arg)
  {
    this->left_leg_length = _arg;
    return *this;
  }
  Type & set__right_leg_length(
    const double & _arg)
  {
    this->right_leg_length = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motion_msgs::msg::LegMotors_<ContainerAllocator> *;
  using ConstRawPtr =
    const motion_msgs::msg::LegMotors_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motion_msgs::msg::LegMotors_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motion_msgs::msg::LegMotors_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::LegMotors_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::LegMotors_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motion_msgs::msg::LegMotors_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motion_msgs::msg::LegMotors_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motion_msgs::msg::LegMotors_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motion_msgs::msg::LegMotors_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motion_msgs__msg__LegMotors
    std::shared_ptr<motion_msgs::msg::LegMotors_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motion_msgs__msg__LegMotors
    std::shared_ptr<motion_msgs::msg::LegMotors_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LegMotors_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->left_hip_enc_rev != other.left_hip_enc_rev) {
      return false;
    }
    if (this->left_hip_pos != other.left_hip_pos) {
      return false;
    }
    if (this->left_hip_vel != other.left_hip_vel) {
      return false;
    }
    if (this->left_hip_iq != other.left_hip_iq) {
      return false;
    }
    if (this->left_knee_enc_rev != other.left_knee_enc_rev) {
      return false;
    }
    if (this->left_knee_pos != other.left_knee_pos) {
      return false;
    }
    if (this->left_knee_vel != other.left_knee_vel) {
      return false;
    }
    if (this->left_knee_iq != other.left_knee_iq) {
      return false;
    }
    if (this->left_wheel_enc_rev != other.left_wheel_enc_rev) {
      return false;
    }
    if (this->left_wheel_pos != other.left_wheel_pos) {
      return false;
    }
    if (this->left_wheel_vel != other.left_wheel_vel) {
      return false;
    }
    if (this->left_wheel_iq != other.left_wheel_iq) {
      return false;
    }
    if (this->right_hip_enc_rev != other.right_hip_enc_rev) {
      return false;
    }
    if (this->right_hip_pos != other.right_hip_pos) {
      return false;
    }
    if (this->right_hip_vel != other.right_hip_vel) {
      return false;
    }
    if (this->right_hip_iq != other.right_hip_iq) {
      return false;
    }
    if (this->right_knee_enc_rev != other.right_knee_enc_rev) {
      return false;
    }
    if (this->right_knee_pos != other.right_knee_pos) {
      return false;
    }
    if (this->right_knee_vel != other.right_knee_vel) {
      return false;
    }
    if (this->right_knee_iq != other.right_knee_iq) {
      return false;
    }
    if (this->right_wheel_enc_rev != other.right_wheel_enc_rev) {
      return false;
    }
    if (this->right_wheel_pos != other.right_wheel_pos) {
      return false;
    }
    if (this->right_wheel_vel != other.right_wheel_vel) {
      return false;
    }
    if (this->right_wheel_iq != other.right_wheel_iq) {
      return false;
    }
    if (this->left_leg_length != other.left_leg_length) {
      return false;
    }
    if (this->right_leg_length != other.right_leg_length) {
      return false;
    }
    return true;
  }
  bool operator!=(const LegMotors_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LegMotors_

// alias to use template instance with default allocator
using LegMotors =
  motion_msgs::msg::LegMotors_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__STRUCT_HPP_
