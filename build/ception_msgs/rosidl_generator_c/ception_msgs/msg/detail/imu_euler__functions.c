// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ception_msgs:msg/IMUEuler.idl
// generated code does not contain a copyright notice
#include "ception_msgs/msg/detail/imu_euler__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
ception_msgs__msg__IMUEuler__init(ception_msgs__msg__IMUEuler * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ception_msgs__msg__IMUEuler__fini(msg);
    return false;
  }
  // roll
  // pitch
  // yaw
  return true;
}

void
ception_msgs__msg__IMUEuler__fini(ception_msgs__msg__IMUEuler * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // roll
  // pitch
  // yaw
}

bool
ception_msgs__msg__IMUEuler__are_equal(const ception_msgs__msg__IMUEuler * lhs, const ception_msgs__msg__IMUEuler * rhs)
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
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
ception_msgs__msg__IMUEuler__copy(
  const ception_msgs__msg__IMUEuler * input,
  ception_msgs__msg__IMUEuler * output)
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
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  return true;
}

ception_msgs__msg__IMUEuler *
ception_msgs__msg__IMUEuler__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ception_msgs__msg__IMUEuler * msg = (ception_msgs__msg__IMUEuler *)allocator.allocate(sizeof(ception_msgs__msg__IMUEuler), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ception_msgs__msg__IMUEuler));
  bool success = ception_msgs__msg__IMUEuler__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ception_msgs__msg__IMUEuler__destroy(ception_msgs__msg__IMUEuler * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ception_msgs__msg__IMUEuler__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ception_msgs__msg__IMUEuler__Sequence__init(ception_msgs__msg__IMUEuler__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ception_msgs__msg__IMUEuler * data = NULL;

  if (size) {
    data = (ception_msgs__msg__IMUEuler *)allocator.zero_allocate(size, sizeof(ception_msgs__msg__IMUEuler), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ception_msgs__msg__IMUEuler__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ception_msgs__msg__IMUEuler__fini(&data[i - 1]);
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
ception_msgs__msg__IMUEuler__Sequence__fini(ception_msgs__msg__IMUEuler__Sequence * array)
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
      ception_msgs__msg__IMUEuler__fini(&array->data[i]);
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

ception_msgs__msg__IMUEuler__Sequence *
ception_msgs__msg__IMUEuler__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ception_msgs__msg__IMUEuler__Sequence * array = (ception_msgs__msg__IMUEuler__Sequence *)allocator.allocate(sizeof(ception_msgs__msg__IMUEuler__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ception_msgs__msg__IMUEuler__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ception_msgs__msg__IMUEuler__Sequence__destroy(ception_msgs__msg__IMUEuler__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ception_msgs__msg__IMUEuler__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ception_msgs__msg__IMUEuler__Sequence__are_equal(const ception_msgs__msg__IMUEuler__Sequence * lhs, const ception_msgs__msg__IMUEuler__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ception_msgs__msg__IMUEuler__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ception_msgs__msg__IMUEuler__Sequence__copy(
  const ception_msgs__msg__IMUEuler__Sequence * input,
  ception_msgs__msg__IMUEuler__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ception_msgs__msg__IMUEuler);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ception_msgs__msg__IMUEuler * data =
      (ception_msgs__msg__IMUEuler *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ception_msgs__msg__IMUEuler__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ception_msgs__msg__IMUEuler__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ception_msgs__msg__IMUEuler__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
