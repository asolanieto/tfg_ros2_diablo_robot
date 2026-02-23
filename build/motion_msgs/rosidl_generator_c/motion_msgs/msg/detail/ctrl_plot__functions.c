// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from motion_msgs:msg/CtrlPlot.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/ctrl_plot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
motion_msgs__msg__CtrlPlot__init(motion_msgs__msg__CtrlPlot * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    motion_msgs__msg__CtrlPlot__fini(msg);
    return false;
  }
  // value
  return true;
}

void
motion_msgs__msg__CtrlPlot__fini(motion_msgs__msg__CtrlPlot * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // value
}

bool
motion_msgs__msg__CtrlPlot__are_equal(const motion_msgs__msg__CtrlPlot * lhs, const motion_msgs__msg__CtrlPlot * rhs)
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
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
motion_msgs__msg__CtrlPlot__copy(
  const motion_msgs__msg__CtrlPlot * input,
  motion_msgs__msg__CtrlPlot * output)
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
  // value
  output->value = input->value;
  return true;
}

motion_msgs__msg__CtrlPlot *
motion_msgs__msg__CtrlPlot__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__CtrlPlot * msg = (motion_msgs__msg__CtrlPlot *)allocator.allocate(sizeof(motion_msgs__msg__CtrlPlot), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(motion_msgs__msg__CtrlPlot));
  bool success = motion_msgs__msg__CtrlPlot__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
motion_msgs__msg__CtrlPlot__destroy(motion_msgs__msg__CtrlPlot * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    motion_msgs__msg__CtrlPlot__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
motion_msgs__msg__CtrlPlot__Sequence__init(motion_msgs__msg__CtrlPlot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__CtrlPlot * data = NULL;

  if (size) {
    data = (motion_msgs__msg__CtrlPlot *)allocator.zero_allocate(size, sizeof(motion_msgs__msg__CtrlPlot), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = motion_msgs__msg__CtrlPlot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        motion_msgs__msg__CtrlPlot__fini(&data[i - 1]);
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
motion_msgs__msg__CtrlPlot__Sequence__fini(motion_msgs__msg__CtrlPlot__Sequence * array)
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
      motion_msgs__msg__CtrlPlot__fini(&array->data[i]);
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

motion_msgs__msg__CtrlPlot__Sequence *
motion_msgs__msg__CtrlPlot__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__CtrlPlot__Sequence * array = (motion_msgs__msg__CtrlPlot__Sequence *)allocator.allocate(sizeof(motion_msgs__msg__CtrlPlot__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = motion_msgs__msg__CtrlPlot__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
motion_msgs__msg__CtrlPlot__Sequence__destroy(motion_msgs__msg__CtrlPlot__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    motion_msgs__msg__CtrlPlot__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
motion_msgs__msg__CtrlPlot__Sequence__are_equal(const motion_msgs__msg__CtrlPlot__Sequence * lhs, const motion_msgs__msg__CtrlPlot__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!motion_msgs__msg__CtrlPlot__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
motion_msgs__msg__CtrlPlot__Sequence__copy(
  const motion_msgs__msg__CtrlPlot__Sequence * input,
  motion_msgs__msg__CtrlPlot__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(motion_msgs__msg__CtrlPlot);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    motion_msgs__msg__CtrlPlot * data =
      (motion_msgs__msg__CtrlPlot *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!motion_msgs__msg__CtrlPlot__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          motion_msgs__msg__CtrlPlot__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!motion_msgs__msg__CtrlPlot__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
