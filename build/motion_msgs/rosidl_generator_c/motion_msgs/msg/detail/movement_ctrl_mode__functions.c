// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from motion_msgs:msg/MovementCtrlMode.idl
// generated code does not contain a copyright notice
#include "motion_msgs/msg/detail/movement_ctrl_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
motion_msgs__msg__MovementCtrlMode__init(motion_msgs__msg__MovementCtrlMode * msg)
{
  if (!msg) {
    return false;
  }
  // pitch_ctrl_mode
  // roll_ctrl_mode
  // height_ctrl_mode
  // stand_mode
  // jump_mode
  // split_mode
  return true;
}

void
motion_msgs__msg__MovementCtrlMode__fini(motion_msgs__msg__MovementCtrlMode * msg)
{
  if (!msg) {
    return;
  }
  // pitch_ctrl_mode
  // roll_ctrl_mode
  // height_ctrl_mode
  // stand_mode
  // jump_mode
  // split_mode
}

bool
motion_msgs__msg__MovementCtrlMode__are_equal(const motion_msgs__msg__MovementCtrlMode * lhs, const motion_msgs__msg__MovementCtrlMode * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pitch_ctrl_mode
  if (lhs->pitch_ctrl_mode != rhs->pitch_ctrl_mode) {
    return false;
  }
  // roll_ctrl_mode
  if (lhs->roll_ctrl_mode != rhs->roll_ctrl_mode) {
    return false;
  }
  // height_ctrl_mode
  if (lhs->height_ctrl_mode != rhs->height_ctrl_mode) {
    return false;
  }
  // stand_mode
  if (lhs->stand_mode != rhs->stand_mode) {
    return false;
  }
  // jump_mode
  if (lhs->jump_mode != rhs->jump_mode) {
    return false;
  }
  // split_mode
  if (lhs->split_mode != rhs->split_mode) {
    return false;
  }
  return true;
}

bool
motion_msgs__msg__MovementCtrlMode__copy(
  const motion_msgs__msg__MovementCtrlMode * input,
  motion_msgs__msg__MovementCtrlMode * output)
{
  if (!input || !output) {
    return false;
  }
  // pitch_ctrl_mode
  output->pitch_ctrl_mode = input->pitch_ctrl_mode;
  // roll_ctrl_mode
  output->roll_ctrl_mode = input->roll_ctrl_mode;
  // height_ctrl_mode
  output->height_ctrl_mode = input->height_ctrl_mode;
  // stand_mode
  output->stand_mode = input->stand_mode;
  // jump_mode
  output->jump_mode = input->jump_mode;
  // split_mode
  output->split_mode = input->split_mode;
  return true;
}

motion_msgs__msg__MovementCtrlMode *
motion_msgs__msg__MovementCtrlMode__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__MovementCtrlMode * msg = (motion_msgs__msg__MovementCtrlMode *)allocator.allocate(sizeof(motion_msgs__msg__MovementCtrlMode), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(motion_msgs__msg__MovementCtrlMode));
  bool success = motion_msgs__msg__MovementCtrlMode__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
motion_msgs__msg__MovementCtrlMode__destroy(motion_msgs__msg__MovementCtrlMode * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    motion_msgs__msg__MovementCtrlMode__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
motion_msgs__msg__MovementCtrlMode__Sequence__init(motion_msgs__msg__MovementCtrlMode__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__MovementCtrlMode * data = NULL;

  if (size) {
    data = (motion_msgs__msg__MovementCtrlMode *)allocator.zero_allocate(size, sizeof(motion_msgs__msg__MovementCtrlMode), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = motion_msgs__msg__MovementCtrlMode__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        motion_msgs__msg__MovementCtrlMode__fini(&data[i - 1]);
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
motion_msgs__msg__MovementCtrlMode__Sequence__fini(motion_msgs__msg__MovementCtrlMode__Sequence * array)
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
      motion_msgs__msg__MovementCtrlMode__fini(&array->data[i]);
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

motion_msgs__msg__MovementCtrlMode__Sequence *
motion_msgs__msg__MovementCtrlMode__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  motion_msgs__msg__MovementCtrlMode__Sequence * array = (motion_msgs__msg__MovementCtrlMode__Sequence *)allocator.allocate(sizeof(motion_msgs__msg__MovementCtrlMode__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = motion_msgs__msg__MovementCtrlMode__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
motion_msgs__msg__MovementCtrlMode__Sequence__destroy(motion_msgs__msg__MovementCtrlMode__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    motion_msgs__msg__MovementCtrlMode__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
motion_msgs__msg__MovementCtrlMode__Sequence__are_equal(const motion_msgs__msg__MovementCtrlMode__Sequence * lhs, const motion_msgs__msg__MovementCtrlMode__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!motion_msgs__msg__MovementCtrlMode__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
motion_msgs__msg__MovementCtrlMode__Sequence__copy(
  const motion_msgs__msg__MovementCtrlMode__Sequence * input,
  motion_msgs__msg__MovementCtrlMode__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(motion_msgs__msg__MovementCtrlMode);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    motion_msgs__msg__MovementCtrlMode * data =
      (motion_msgs__msg__MovementCtrlMode *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!motion_msgs__msg__MovementCtrlMode__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          motion_msgs__msg__MovementCtrlMode__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!motion_msgs__msg__MovementCtrlMode__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
