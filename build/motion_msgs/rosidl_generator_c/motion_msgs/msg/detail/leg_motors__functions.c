// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from motion_msgs:msg/LegMotors.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/leg_motors__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
motion_msgs__msg__LegMotors__init(motion_msgs__msg__LegMotors * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    motion_msgs__msg__LegMotors__fini(msg);
    return false;
  }
  // left_hip_enc_rev
  // left_hip_pos
  // left_hip_vel
  // left_hip_iq
  // left_knee_enc_rev
  // left_knee_pos
  // left_knee_vel
  // left_knee_iq
  // left_wheel_enc_rev
  // left_wheel_pos
  // left_wheel_vel
  // left_wheel_iq
  // right_hip_enc_rev
  // right_hip_pos
  // right_hip_vel
  // right_hip_iq
  // right_knee_enc_rev
  // right_knee_pos
  // right_knee_vel
  // right_knee_iq
  // right_wheel_enc_rev
  // right_wheel_pos
  // right_wheel_vel
  // right_wheel_iq
  // left_leg_length
  // right_leg_length
  return true;
}

void
motion_msgs__msg__LegMotors__fini(motion_msgs__msg__LegMotors * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // left_hip_enc_rev
  // left_hip_pos
  // left_hip_vel
  // left_hip_iq
  // left_knee_enc_rev
  // left_knee_pos
  // left_knee_vel
  // left_knee_iq
  // left_wheel_enc_rev
  // left_wheel_pos
  // left_wheel_vel
  // left_wheel_iq
  // right_hip_enc_rev
  // right_hip_pos
  // right_hip_vel
  // right_hip_iq
  // right_knee_enc_rev
  // right_knee_pos
  // right_knee_vel
  // right_knee_iq
  // right_wheel_enc_rev
  // right_wheel_pos
  // right_wheel_vel
  // right_wheel_iq
  // left_leg_length
  // right_leg_length
}

bool
motion_msgs__msg__LegMotors__are_equal(const motion_msgs__msg__LegMotors * lhs, const motion_msgs__msg__LegMotors * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // left_hip_enc_rev
  if (lhs->left_hip_enc_rev != rhs->left_hip_enc_rev) {
    return false;
  }
  // left_hip_pos
  if (lhs->left_hip_pos != rhs->left_hip_pos) {
    return false;
  }
  // left_hip_vel
  if (lhs->left_hip_vel != rhs->left_hip_vel) {
    return false;
  }
  // left_hip_iq
  if (lhs->left_hip_iq != rhs->left_hip_iq) {
    return false;
  }
  // left_knee_enc_rev
  if (lhs->left_knee_enc_rev != rhs->left_knee_enc_rev) {
    return false;
  }
  // left_knee_pos
  if (lhs->left_knee_pos != rhs->left_knee_pos) {
    return false;
  }
  // left_knee_vel
  if (lhs->left_knee_vel != rhs->left_knee_vel) {
    return false;
  }
  // left_knee_iq
  if (lhs->left_knee_iq != rhs->left_knee_iq) {
    return false;
  }
  // left_wheel_enc_rev
  if (lhs->left_wheel_enc_rev != rhs->left_wheel_enc_rev) {
    return false;
  }
  // left_wheel_pos
  if (lhs->left_wheel_pos != rhs->left_wheel_pos) {
    return false;
  }
  // left_wheel_vel
  if (lhs->left_wheel_vel != rhs->left_wheel_vel) {
    return false;
  }
  // left_wheel_iq
  if (lhs->left_wheel_iq != rhs->left_wheel_iq) {
    return false;
  }
  // right_hip_enc_rev
  if (lhs->right_hip_enc_rev != rhs->right_hip_enc_rev) {
    return false;
  }
  // right_hip_pos
  if (lhs->right_hip_pos != rhs->right_hip_pos) {
    return false;
  }
  // right_hip_vel
  if (lhs->right_hip_vel != rhs->right_hip_vel) {
    return false;
  }
  // right_hip_iq
  if (lhs->right_hip_iq != rhs->right_hip_iq) {
    return false;
  }
  // right_knee_enc_rev
  if (lhs->right_knee_enc_rev != rhs->right_knee_enc_rev) {
    return false;
  }
  // right_knee_pos
  if (lhs->right_knee_pos != rhs->right_knee_pos) {
    return false;
  }
  // right_knee_vel
  if (lhs->right_knee_vel != rhs->right_knee_vel) {
    return false;
  }
  // right_knee_iq
  if (lhs->right_knee_iq != rhs->right_knee_iq) {
    return false;
  }
  // right_wheel_enc_rev
  if (lhs->right_wheel_enc_rev != rhs->right_wheel_enc_rev) {
    return false;
  }
  // right_wheel_pos
  if (lhs->right_wheel_pos != rhs->right_wheel_pos) {
    return false;
  }
  // right_wheel_vel
  if (lhs->right_wheel_vel != rhs->right_wheel_vel) {
    return false;
  }
  // right_wheel_iq
  if (lhs->right_wheel_iq != rhs->right_wheel_iq) {
    return false;
  }
  // left_leg_length
  if (lhs->left_leg_length != rhs->left_leg_length) {
    return false;
  }
  // right_leg_length
  if (lhs->right_leg_length != rhs->right_leg_length) {
    return false;
  }
  return true;
}

bool
motion_msgs__msg__LegMotors__copy(
  const motion_msgs__msg__LegMotors * input,
  motion_msgs__msg__LegMotors * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // left_hip_enc_rev
  output->left_hip_enc_rev = input->left_hip_enc_rev;
  // left_hip_pos
  output->left_hip_pos = input->left_hip_pos;
  // left_hip_vel
  output->left_hip_vel = input->left_hip_vel;
  // left_hip_iq
  output->left_hip_iq = input->left_hip_iq;
  // left_knee_enc_rev
  output->left_knee_enc_rev = input->left_knee_enc_rev;
  // left_knee_pos
  output->left_knee_pos = input->left_knee_pos;
  // left_knee_vel
  output->left_knee_vel = input->left_knee_vel;
  // left_knee_iq
  output->left_knee_iq = input->left_knee_iq;
  // left_wheel_enc_rev
  output->left_wheel_enc_rev = input->left_wheel_enc_rev;
  // left_wheel_pos
  output->left_wheel_pos = input->left_wheel_pos;
  // left_wheel_vel
  output->left_wheel_vel = input->left_wheel_vel;
  // left_wheel_iq
  output->left_wheel_iq = input->left_wheel_iq;
  // right_hip_enc_rev
  output->right_hip_enc_rev = input->right_hip_enc_rev;
  // right_hip_pos
  output->right_hip_pos = input->right_hip_pos;
  // right_hip_vel
  output->right_hip_vel = input->right_hip_vel;
  // right_hip_iq
  output->right_hip_iq = input->right_hip_iq;
  // right_knee_enc_rev
  output->right_knee_enc_rev = input->right_knee_enc_rev;
  // right_knee_pos
  output->right_knee_pos = input->right_knee_pos;
  // right_knee_vel
  output->right_knee_vel = input->right_knee_vel;
  // right_knee_iq
  output->right_knee_iq = input->right_knee_iq;
  // right_wheel_enc_rev
  output->right_wheel_enc_rev = input->right_wheel_enc_rev;
  // right_wheel_pos
  output->right_wheel_pos = input->right_wheel_pos;
  // right_wheel_vel
  output->right_wheel_vel = input->right_wheel_vel;
  // right_wheel_iq
  output->right_wheel_iq = input->right_wheel_iq;
  // left_leg_length
  output->left_leg_length = input->left_leg_length;
  // right_leg_length
  output->right_leg_length = input->right_leg_length;
  return true;
}

motion_msgs__msg__LegMotors *
motion_msgs__msg__LegMotors__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__LegMotors * msg = (motion_msgs__msg__LegMotors *)allocator.allocate(sizeof(motion_msgs__msg__LegMotors), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(motion_msgs__msg__LegMotors));
  bool success = motion_msgs__msg__LegMotors__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
motion_msgs__msg__LegMotors__destroy(motion_msgs__msg__LegMotors * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    motion_msgs__msg__LegMotors__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
motion_msgs__msg__LegMotors__Sequence__init(motion_msgs__msg__LegMotors__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__LegMotors * data = NULL;

  if (size) {
    data = (motion_msgs__msg__LegMotors *)allocator.zero_allocate(size, sizeof(motion_msgs__msg__LegMotors), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = motion_msgs__msg__LegMotors__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        motion_msgs__msg__LegMotors__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
motion_msgs__msg__LegMotors__Sequence__fini(motion_msgs__msg__LegMotors__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      motion_msgs__msg__LegMotors__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

motion_msgs__msg__LegMotors__Sequence *
motion_msgs__msg__LegMotors__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__LegMotors__Sequence * array = (motion_msgs__msg__LegMotors__Sequence *)allocator.allocate(sizeof(motion_msgs__msg__LegMotors__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = motion_msgs__msg__LegMotors__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
motion_msgs__msg__LegMotors__Sequence__destroy(motion_msgs__msg__LegMotors__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    motion_msgs__msg__LegMotors__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
motion_msgs__msg__LegMotors__Sequence__are_equal(const motion_msgs__msg__LegMotors__Sequence * lhs, const motion_msgs__msg__LegMotors__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!motion_msgs__msg__LegMotors__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
motion_msgs__msg__LegMotors__Sequence__copy(
  const motion_msgs__msg__LegMotors__Sequence * input,
  motion_msgs__msg__LegMotors__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(motion_msgs__msg__LegMotors);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    motion_msgs__msg__LegMotors * data =
      (motion_msgs__msg__LegMotors *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!motion_msgs__msg__LegMotors__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          motion_msgs__msg__LegMotors__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!motion_msgs__msg__LegMotors__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
