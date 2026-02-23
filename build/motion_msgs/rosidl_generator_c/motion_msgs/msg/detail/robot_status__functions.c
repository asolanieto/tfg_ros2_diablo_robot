// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from motion_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/robot_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
motion_msgs__msg__RobotStatus__init(motion_msgs__msg__RobotStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    motion_msgs__msg__RobotStatus__fini(msg);
    return false;
  }
  // ctrl_mode_msg
  // robot_mode_msg
  // error_msg
  // warning_msg
  return true;
}

void
motion_msgs__msg__RobotStatus__fini(motion_msgs__msg__RobotStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // ctrl_mode_msg
  // robot_mode_msg
  // error_msg
  // warning_msg
}

bool
motion_msgs__msg__RobotStatus__are_equal(const motion_msgs__msg__RobotStatus * lhs, const motion_msgs__msg__RobotStatus * rhs)
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
  // ctrl_mode_msg
  if (lhs->ctrl_mode_msg != rhs->ctrl_mode_msg) {
    return false;
  }
  // robot_mode_msg
  if (lhs->robot_mode_msg != rhs->robot_mode_msg) {
    return false;
  }
  // error_msg
  if (lhs->error_msg != rhs->error_msg) {
    return false;
  }
  // warning_msg
  if (lhs->warning_msg != rhs->warning_msg) {
    return false;
  }
  return true;
}

bool
motion_msgs__msg__RobotStatus__copy(
  const motion_msgs__msg__RobotStatus * input,
  motion_msgs__msg__RobotStatus * output)
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
  // ctrl_mode_msg
  output->ctrl_mode_msg = input->ctrl_mode_msg;
  // robot_mode_msg
  output->robot_mode_msg = input->robot_mode_msg;
  // error_msg
  output->error_msg = input->error_msg;
  // warning_msg
  output->warning_msg = input->warning_msg;
  return true;
}

motion_msgs__msg__RobotStatus *
motion_msgs__msg__RobotStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__RobotStatus * msg = (motion_msgs__msg__RobotStatus *)allocator.allocate(sizeof(motion_msgs__msg__RobotStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(motion_msgs__msg__RobotStatus));
  bool success = motion_msgs__msg__RobotStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
motion_msgs__msg__RobotStatus__destroy(motion_msgs__msg__RobotStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    motion_msgs__msg__RobotStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
motion_msgs__msg__RobotStatus__Sequence__init(motion_msgs__msg__RobotStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__RobotStatus * data = NULL;

  if (size) {
    data = (motion_msgs__msg__RobotStatus *)allocator.zero_allocate(size, sizeof(motion_msgs__msg__RobotStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = motion_msgs__msg__RobotStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        motion_msgs__msg__RobotStatus__fini(&data[i - 1]);
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
motion_msgs__msg__RobotStatus__Sequence__fini(motion_msgs__msg__RobotStatus__Sequence * array)
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
      motion_msgs__msg__RobotStatus__fini(&array->data[i]);
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

motion_msgs__msg__RobotStatus__Sequence *
motion_msgs__msg__RobotStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__RobotStatus__Sequence * array = (motion_msgs__msg__RobotStatus__Sequence *)allocator.allocate(sizeof(motion_msgs__msg__RobotStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = motion_msgs__msg__RobotStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
motion_msgs__msg__RobotStatus__Sequence__destroy(motion_msgs__msg__RobotStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    motion_msgs__msg__RobotStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
motion_msgs__msg__RobotStatus__Sequence__are_equal(const motion_msgs__msg__RobotStatus__Sequence * lhs, const motion_msgs__msg__RobotStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!motion_msgs__msg__RobotStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
motion_msgs__msg__RobotStatus__Sequence__copy(
  const motion_msgs__msg__RobotStatus__Sequence * input,
  motion_msgs__msg__RobotStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(motion_msgs__msg__RobotStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    motion_msgs__msg__RobotStatus * data =
      (motion_msgs__msg__RobotStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!motion_msgs__msg__RobotStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          motion_msgs__msg__RobotStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!motion_msgs__msg__RobotStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
