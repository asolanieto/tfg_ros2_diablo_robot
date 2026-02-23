// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from motion_msgs:msg/MovementCtrlData.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/movement_ctrl_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
motion_msgs__msg__MovementCtrlData__init(motion_msgs__msg__MovementCtrlData * msg)
{
  if (!msg) {
    return false;
  }
  // forward
  // left
  // up
  // roll
  // pitch
  // leg_split
  return true;
}

void
motion_msgs__msg__MovementCtrlData__fini(motion_msgs__msg__MovementCtrlData * msg)
{
  if (!msg) {
    return;
  }
  // forward
  // left
  // up
  // roll
  // pitch
  // leg_split
}

bool
motion_msgs__msg__MovementCtrlData__are_equal(const motion_msgs__msg__MovementCtrlData * lhs, const motion_msgs__msg__MovementCtrlData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // forward
  if (lhs->forward != rhs->forward) {
    return false;
  }
  // left
  if (lhs->left != rhs->left) {
    return false;
  }
  // up
  if (lhs->up != rhs->up) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // leg_split
  if (lhs->leg_split != rhs->leg_split) {
    return false;
  }
  return true;
}

bool
motion_msgs__msg__MovementCtrlData__copy(
  const motion_msgs__msg__MovementCtrlData * input,
  motion_msgs__msg__MovementCtrlData * output)
{
  if (!input || !output) {
    return false;
  }
  // forward
  output->forward = input->forward;
  // left
  output->left = input->left;
  // up
  output->up = input->up;
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // leg_split
  output->leg_split = input->leg_split;
  return true;
}

motion_msgs__msg__MovementCtrlData *
motion_msgs__msg__MovementCtrlData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__MovementCtrlData * msg = (motion_msgs__msg__MovementCtrlData *)allocator.allocate(sizeof(motion_msgs__msg__MovementCtrlData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(motion_msgs__msg__MovementCtrlData));
  bool success = motion_msgs__msg__MovementCtrlData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
motion_msgs__msg__MovementCtrlData__destroy(motion_msgs__msg__MovementCtrlData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    motion_msgs__msg__MovementCtrlData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
motion_msgs__msg__MovementCtrlData__Sequence__init(motion_msgs__msg__MovementCtrlData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__MovementCtrlData * data = NULL;

  if (size) {
    data = (motion_msgs__msg__MovementCtrlData *)allocator.zero_allocate(size, sizeof(motion_msgs__msg__MovementCtrlData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = motion_msgs__msg__MovementCtrlData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        motion_msgs__msg__MovementCtrlData__fini(&data[i - 1]);
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
motion_msgs__msg__MovementCtrlData__Sequence__fini(motion_msgs__msg__MovementCtrlData__Sequence * array)
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
      motion_msgs__msg__MovementCtrlData__fini(&array->data[i]);
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

motion_msgs__msg__MovementCtrlData__Sequence *
motion_msgs__msg__MovementCtrlData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__MovementCtrlData__Sequence * array = (motion_msgs__msg__MovementCtrlData__Sequence *)allocator.allocate(sizeof(motion_msgs__msg__MovementCtrlData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = motion_msgs__msg__MovementCtrlData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
motion_msgs__msg__MovementCtrlData__Sequence__destroy(motion_msgs__msg__MovementCtrlData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    motion_msgs__msg__MovementCtrlData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
motion_msgs__msg__MovementCtrlData__Sequence__are_equal(const motion_msgs__msg__MovementCtrlData__Sequence * lhs, const motion_msgs__msg__MovementCtrlData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!motion_msgs__msg__MovementCtrlData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
motion_msgs__msg__MovementCtrlData__Sequence__copy(
  const motion_msgs__msg__MovementCtrlData__Sequence * input,
  motion_msgs__msg__MovementCtrlData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(motion_msgs__msg__MovementCtrlData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    motion_msgs__msg__MovementCtrlData * data =
      (motion_msgs__msg__MovementCtrlData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!motion_msgs__msg__MovementCtrlData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          motion_msgs__msg__MovementCtrlData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!motion_msgs__msg__MovementCtrlData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
