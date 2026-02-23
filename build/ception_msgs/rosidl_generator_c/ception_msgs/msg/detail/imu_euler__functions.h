// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ception_msgs:msg/IMUEuler.idl
// generated code does not contain a copyright notice

#ifndef CEPTION_MSGS__MSG__DETAIL__IMU_EULER__FUNCTIONS_H_
#define CEPTION_MSGS__MSG__DETAIL__IMU_EULER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ception_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ception_msgs/msg/detail/imu_euler__struct.h"

/// Initialize msg/IMUEuler message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ception_msgs__msg__IMUEuler
 * )) before or use
 * ception_msgs__msg__IMUEuler__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
bool
ception_msgs__msg__IMUEuler__init(ception_msgs__msg__IMUEuler * msg);

/// Finalize msg/IMUEuler message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
void
ception_msgs__msg__IMUEuler__fini(ception_msgs__msg__IMUEuler * msg);

/// Create msg/IMUEuler message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ception_msgs__msg__IMUEuler__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
ception_msgs__msg__IMUEuler *
ception_msgs__msg__IMUEuler__create();

/// Destroy msg/IMUEuler message.
/**
 * It calls
 * ception_msgs__msg__IMUEuler__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
void
ception_msgs__msg__IMUEuler__destroy(ception_msgs__msg__IMUEuler * msg);

/// Check for msg/IMUEuler message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
bool
ception_msgs__msg__IMUEuler__are_equal(const ception_msgs__msg__IMUEuler * lhs, const ception_msgs__msg__IMUEuler * rhs);

/// Copy a msg/IMUEuler message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
bool
ception_msgs__msg__IMUEuler__copy(
  const ception_msgs__msg__IMUEuler * input,
  ception_msgs__msg__IMUEuler * output);

/// Initialize array of msg/IMUEuler messages.
/**
 * It allocates the memory for the number of elements and calls
 * ception_msgs__msg__IMUEuler__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
bool
ception_msgs__msg__IMUEuler__Sequence__init(ception_msgs__msg__IMUEuler__Sequence * array, size_t size);

/// Finalize array of msg/IMUEuler messages.
/**
 * It calls
 * ception_msgs__msg__IMUEuler__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
void
ception_msgs__msg__IMUEuler__Sequence__fini(ception_msgs__msg__IMUEuler__Sequence * array);

/// Create array of msg/IMUEuler messages.
/**
 * It allocates the memory for the array and calls
 * ception_msgs__msg__IMUEuler__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
ception_msgs__msg__IMUEuler__Sequence *
ception_msgs__msg__IMUEuler__Sequence__create(size_t size);

/// Destroy array of msg/IMUEuler messages.
/**
 * It calls
 * ception_msgs__msg__IMUEuler__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
void
ception_msgs__msg__IMUEuler__Sequence__destroy(ception_msgs__msg__IMUEuler__Sequence * array);

/// Check for msg/IMUEuler message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
bool
ception_msgs__msg__IMUEuler__Sequence__are_equal(const ception_msgs__msg__IMUEuler__Sequence * lhs, const ception_msgs__msg__IMUEuler__Sequence * rhs);

/// Copy an array of msg/IMUEuler messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ception_msgs
bool
ception_msgs__msg__IMUEuler__Sequence__copy(
  const ception_msgs__msg__IMUEuler__Sequence * input,
  ception_msgs__msg__IMUEuler__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CEPTION_MSGS__MSG__DETAIL__IMU_EULER__FUNCTIONS_H_
