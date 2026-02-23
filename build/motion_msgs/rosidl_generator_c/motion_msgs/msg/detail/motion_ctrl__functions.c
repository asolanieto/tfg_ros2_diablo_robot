// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from motion_msgs:msg/MotionCtrl.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/motion_ctrl__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `value`
#include "motion_msgs/msg/detail/movement_ctrl_data__functions.h"
// Member `mode`
#include "motion_msgs/msg/detail/movement_ctrl_mode__functions.h"

bool
motion_msgs__msg__MotionCtrl__init(motion_msgs__msg__MotionCtrl * msg)
{
  if (!msg) {
    return false;
  }
  // mode_mark
  // value
  if (!motion_msgs__msg__MovementCtrlData__init(&msg->value)) {
    motion_msgs__msg__MotionCtrl__fini(msg);
    return false;
  }
  // mode
  if (!motion_msgs__msg__MovementCtrlMode__init(&msg->mode)) {
    motion_msgs__msg__MotionCtrl__fini(msg);
    return false;
  }
  return true;
}

void
motion_msgs__msg__MotionCtrl__fini(motion_msgs__msg__MotionCtrl * msg)
{
  if (!msg) {
    return;
  }
  // mode_mark
  // value
  motion_msgs__msg__MovementCtrlData__fini(&msg->value);
  // mode
  motion_msgs__msg__MovementCtrlMode__fini(&msg->mode);
}

bool
motion_msgs__msg__MotionCtrl__are_equal(const motion_msgs__msg__MotionCtrl * lhs, const motion_msgs__msg__MotionCtrl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode_mark
  if (lhs->mode_mark != rhs->mode_mark) {
    return false;
  }
  // value
  if (!motion_msgs__msg__MovementCtrlData__are_equal(
      &(lhs->value), &(rhs->value)))
  {
    return false;
  }
  // mode
  if (!motion_msgs__msg__MovementCtrlMode__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  return true;
}

bool
motion_msgs__msg__MotionCtrl__copy(
  const motion_msgs__msg__MotionCtrl * input,
  motion_msgs__msg__MotionCtrl * output)
{
  if (!input || !output) {
    return false;
  }
  // mode_mark
  output->mode_mark = input->mode_mark;
  // value
  if (!motion_msgs__msg__MovementCtrlData__copy(
      &(input->value), &(output->value)))
  {
    return false;
  }
  // mode
  if (!motion_msgs__msg__MovementCtrlMode__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  return true;
}

motion_msgs__msg__MotionCtrl *
motion_msgs__msg__MotionCtrl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__MotionCtrl * msg = (motion_msgs__msg__MotionCtrl *)allocator.allocate(sizeof(motion_msgs__msg__MotionCtrl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(motion_msgs__msg__MotionCtrl));
  bool success = motion_msgs__msg__MotionCtrl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
motion_msgs__msg__MotionCtrl__destroy(motion_msgs__msg__MotionCtrl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    motion_msgs__msg__MotionCtrl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
motion_msgs__msg__MotionCtrl__Sequence__init(motion_msgs__msg__MotionCtrl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__MotionCtrl * data = NULL;

  if (size) {
    data = (motion_msgs__msg__MotionCtrl *)allocator.zero_allocate(size, sizeof(motion_msgs__msg__MotionCtrl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = motion_msgs__msg__MotionCtrl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        motion_msgs__msg__MotionCtrl__fini(&data[i - 1]);
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
motion_msgs__msg__MotionCtrl__Sequence__fini(motion_msgs__msg__MotionCtrl__Sequence * array)
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
      motion_msgs__msg__MotionCtrl__fini(&array->data[i]);
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

motion_msgs__msg__MotionCtrl__Sequence *
motion_msgs__msg__MotionCtrl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__MotionCtrl__Sequence * array = (motion_msgs__msg__MotionCtrl__Sequence *)allocator.allocate(sizeof(motion_msgs__msg__MotionCtrl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = motion_msgs__msg__MotionCtrl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
motion_msgs__msg__MotionCtrl__Sequence__destroy(motion_msgs__msg__MotionCtrl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    motion_msgs__msg__MotionCtrl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
motion_msgs__msg__MotionCtrl__Sequence__are_equal(const motion_msgs__msg__MotionCtrl__Sequence * lhs, const motion_msgs__msg__MotionCtrl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!motion_msgs__msg__MotionCtrl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
motion_msgs__msg__MotionCtrl__Sequence__copy(
  const motion_msgs__msg__MotionCtrl__Sequence * input,
  motion_msgs__msg__MotionCtrl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(motion_msgs__msg__MotionCtrl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    motion_msgs__msg__MotionCtrl * data =
      (motion_msgs__msg__MotionCtrl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!motion_msgs__msg__MotionCtrl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          motion_msgs__msg__MotionCtrl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!motion_msgs__msg__MotionCtrl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
