// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motion_msgs:msg/LegMotors.idl
// generated code does not contain a copyright notice

#ifndef MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__BUILDER_HPP_
#define MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motion_msgs/msg/detail/leg_motors__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motion_msgs
{

namespace msg
{

namespace builder
{

class Init_LegMotors_right_leg_length
{
public:
  explicit Init_LegMotors_right_leg_length(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  ::motion_msgs::msg::LegMotors right_leg_length(::motion_msgs::msg::LegMotors::_right_leg_length_type arg)
  {
    msg_.right_leg_length = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_leg_length
{
public:
  explicit Init_LegMotors_left_leg_length(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_leg_length left_leg_length(::motion_msgs::msg::LegMotors::_left_leg_length_type arg)
  {
    msg_.left_leg_length = std::move(arg);
    return Init_LegMotors_right_leg_length(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_wheel_iq
{
public:
  explicit Init_LegMotors_right_wheel_iq(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_leg_length right_wheel_iq(::motion_msgs::msg::LegMotors::_right_wheel_iq_type arg)
  {
    msg_.right_wheel_iq = std::move(arg);
    return Init_LegMotors_left_leg_length(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_wheel_vel
{
public:
  explicit Init_LegMotors_right_wheel_vel(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_wheel_iq right_wheel_vel(::motion_msgs::msg::LegMotors::_right_wheel_vel_type arg)
  {
    msg_.right_wheel_vel = std::move(arg);
    return Init_LegMotors_right_wheel_iq(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_wheel_pos
{
public:
  explicit Init_LegMotors_right_wheel_pos(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_wheel_vel right_wheel_pos(::motion_msgs::msg::LegMotors::_right_wheel_pos_type arg)
  {
    msg_.right_wheel_pos = std::move(arg);
    return Init_LegMotors_right_wheel_vel(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_wheel_enc_rev
{
public:
  explicit Init_LegMotors_right_wheel_enc_rev(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_wheel_pos right_wheel_enc_rev(::motion_msgs::msg::LegMotors::_right_wheel_enc_rev_type arg)
  {
    msg_.right_wheel_enc_rev = std::move(arg);
    return Init_LegMotors_right_wheel_pos(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_knee_iq
{
public:
  explicit Init_LegMotors_right_knee_iq(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_wheel_enc_rev right_knee_iq(::motion_msgs::msg::LegMotors::_right_knee_iq_type arg)
  {
    msg_.right_knee_iq = std::move(arg);
    return Init_LegMotors_right_wheel_enc_rev(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_knee_vel
{
public:
  explicit Init_LegMotors_right_knee_vel(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_knee_iq right_knee_vel(::motion_msgs::msg::LegMotors::_right_knee_vel_type arg)
  {
    msg_.right_knee_vel = std::move(arg);
    return Init_LegMotors_right_knee_iq(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_knee_pos
{
public:
  explicit Init_LegMotors_right_knee_pos(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_knee_vel right_knee_pos(::motion_msgs::msg::LegMotors::_right_knee_pos_type arg)
  {
    msg_.right_knee_pos = std::move(arg);
    return Init_LegMotors_right_knee_vel(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_knee_enc_rev
{
public:
  explicit Init_LegMotors_right_knee_enc_rev(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_knee_pos right_knee_enc_rev(::motion_msgs::msg::LegMotors::_right_knee_enc_rev_type arg)
  {
    msg_.right_knee_enc_rev = std::move(arg);
    return Init_LegMotors_right_knee_pos(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_hip_iq
{
public:
  explicit Init_LegMotors_right_hip_iq(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_knee_enc_rev right_hip_iq(::motion_msgs::msg::LegMotors::_right_hip_iq_type arg)
  {
    msg_.right_hip_iq = std::move(arg);
    return Init_LegMotors_right_knee_enc_rev(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_hip_vel
{
public:
  explicit Init_LegMotors_right_hip_vel(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_hip_iq right_hip_vel(::motion_msgs::msg::LegMotors::_right_hip_vel_type arg)
  {
    msg_.right_hip_vel = std::move(arg);
    return Init_LegMotors_right_hip_iq(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_hip_pos
{
public:
  explicit Init_LegMotors_right_hip_pos(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_hip_vel right_hip_pos(::motion_msgs::msg::LegMotors::_right_hip_pos_type arg)
  {
    msg_.right_hip_pos = std::move(arg);
    return Init_LegMotors_right_hip_vel(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_right_hip_enc_rev
{
public:
  explicit Init_LegMotors_right_hip_enc_rev(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_hip_pos right_hip_enc_rev(::motion_msgs::msg::LegMotors::_right_hip_enc_rev_type arg)
  {
    msg_.right_hip_enc_rev = std::move(arg);
    return Init_LegMotors_right_hip_pos(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_wheel_iq
{
public:
  explicit Init_LegMotors_left_wheel_iq(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_right_hip_enc_rev left_wheel_iq(::motion_msgs::msg::LegMotors::_left_wheel_iq_type arg)
  {
    msg_.left_wheel_iq = std::move(arg);
    return Init_LegMotors_right_hip_enc_rev(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_wheel_vel
{
public:
  explicit Init_LegMotors_left_wheel_vel(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_wheel_iq left_wheel_vel(::motion_msgs::msg::LegMotors::_left_wheel_vel_type arg)
  {
    msg_.left_wheel_vel = std::move(arg);
    return Init_LegMotors_left_wheel_iq(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_wheel_pos
{
public:
  explicit Init_LegMotors_left_wheel_pos(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_wheel_vel left_wheel_pos(::motion_msgs::msg::LegMotors::_left_wheel_pos_type arg)
  {
    msg_.left_wheel_pos = std::move(arg);
    return Init_LegMotors_left_wheel_vel(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_wheel_enc_rev
{
public:
  explicit Init_LegMotors_left_wheel_enc_rev(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_wheel_pos left_wheel_enc_rev(::motion_msgs::msg::LegMotors::_left_wheel_enc_rev_type arg)
  {
    msg_.left_wheel_enc_rev = std::move(arg);
    return Init_LegMotors_left_wheel_pos(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_knee_iq
{
public:
  explicit Init_LegMotors_left_knee_iq(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_wheel_enc_rev left_knee_iq(::motion_msgs::msg::LegMotors::_left_knee_iq_type arg)
  {
    msg_.left_knee_iq = std::move(arg);
    return Init_LegMotors_left_wheel_enc_rev(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_knee_vel
{
public:
  explicit Init_LegMotors_left_knee_vel(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_knee_iq left_knee_vel(::motion_msgs::msg::LegMotors::_left_knee_vel_type arg)
  {
    msg_.left_knee_vel = std::move(arg);
    return Init_LegMotors_left_knee_iq(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_knee_pos
{
public:
  explicit Init_LegMotors_left_knee_pos(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_knee_vel left_knee_pos(::motion_msgs::msg::LegMotors::_left_knee_pos_type arg)
  {
    msg_.left_knee_pos = std::move(arg);
    return Init_LegMotors_left_knee_vel(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_knee_enc_rev
{
public:
  explicit Init_LegMotors_left_knee_enc_rev(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_knee_pos left_knee_enc_rev(::motion_msgs::msg::LegMotors::_left_knee_enc_rev_type arg)
  {
    msg_.left_knee_enc_rev = std::move(arg);
    return Init_LegMotors_left_knee_pos(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_hip_iq
{
public:
  explicit Init_LegMotors_left_hip_iq(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_knee_enc_rev left_hip_iq(::motion_msgs::msg::LegMotors::_left_hip_iq_type arg)
  {
    msg_.left_hip_iq = std::move(arg);
    return Init_LegMotors_left_knee_enc_rev(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_hip_vel
{
public:
  explicit Init_LegMotors_left_hip_vel(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_hip_iq left_hip_vel(::motion_msgs::msg::LegMotors::_left_hip_vel_type arg)
  {
    msg_.left_hip_vel = std::move(arg);
    return Init_LegMotors_left_hip_iq(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_hip_pos
{
public:
  explicit Init_LegMotors_left_hip_pos(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_hip_vel left_hip_pos(::motion_msgs::msg::LegMotors::_left_hip_pos_type arg)
  {
    msg_.left_hip_pos = std::move(arg);
    return Init_LegMotors_left_hip_vel(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_left_hip_enc_rev
{
public:
  explicit Init_LegMotors_left_hip_enc_rev(::motion_msgs::msg::LegMotors & msg)
  : msg_(msg)
  {}
  Init_LegMotors_left_hip_pos left_hip_enc_rev(::motion_msgs::msg::LegMotors::_left_hip_enc_rev_type arg)
  {
    msg_.left_hip_enc_rev = std::move(arg);
    return Init_LegMotors_left_hip_pos(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

class Init_LegMotors_header
{
public:
  Init_LegMotors_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LegMotors_left_hip_enc_rev header(::motion_msgs::msg::LegMotors::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LegMotors_left_hip_enc_rev(msg_);
  }

private:
  ::motion_msgs::msg::LegMotors msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motion_msgs::msg::LegMotors>()
{
  return motion_msgs::msg::builder::Init_LegMotors_header();
}

}  // namespace motion_msgs

#endif  // MOTION_MSGS__MSG__DETAIL__LEG_MOTORS__BUILDER_HPP_
