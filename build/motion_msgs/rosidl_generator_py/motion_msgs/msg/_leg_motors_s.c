// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from motion_msgs:msg/LegMotors.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "motion_msgs/msg/detail/leg_motors__struct.h"
#include "motion_msgs/msg/detail/leg_motors__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool motion_msgs__msg__leg_motors__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("motion_msgs.msg._leg_motors.LegMotors", full_classname_dest, 37) == 0);
  }
  motion_msgs__msg__LegMotors * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // left_hip_enc_rev
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_hip_enc_rev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_hip_enc_rev = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // left_hip_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_hip_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_hip_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_hip_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_hip_vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_hip_vel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_hip_iq
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_hip_iq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_hip_iq = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_knee_enc_rev
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_knee_enc_rev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_knee_enc_rev = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // left_knee_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_knee_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_knee_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_knee_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_knee_vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_knee_vel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_knee_iq
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_knee_iq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_knee_iq = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_wheel_enc_rev
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_wheel_enc_rev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->left_wheel_enc_rev = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // left_wheel_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_wheel_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_wheel_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_wheel_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_wheel_vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_wheel_vel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_wheel_iq
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_wheel_iq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_wheel_iq = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_hip_enc_rev
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_hip_enc_rev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_hip_enc_rev = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // right_hip_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_hip_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_hip_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_hip_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_hip_vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_hip_vel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_hip_iq
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_hip_iq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_hip_iq = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_knee_enc_rev
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_knee_enc_rev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_knee_enc_rev = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // right_knee_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_knee_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_knee_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_knee_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_knee_vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_knee_vel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_knee_iq
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_knee_iq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_knee_iq = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_wheel_enc_rev
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_wheel_enc_rev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->right_wheel_enc_rev = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // right_wheel_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_wheel_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_wheel_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_wheel_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_wheel_vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_wheel_vel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_wheel_iq
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_wheel_iq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_wheel_iq = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left_leg_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "left_leg_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left_leg_length = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // right_leg_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "right_leg_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->right_leg_length = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * motion_msgs__msg__leg_motors__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LegMotors */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("motion_msgs.msg._leg_motors");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LegMotors");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  motion_msgs__msg__LegMotors * ros_message = (motion_msgs__msg__LegMotors *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_hip_enc_rev
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->left_hip_enc_rev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_hip_enc_rev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_hip_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_hip_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_hip_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_hip_vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_hip_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_hip_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_hip_iq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_hip_iq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_hip_iq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_knee_enc_rev
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->left_knee_enc_rev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_knee_enc_rev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_knee_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_knee_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_knee_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_knee_vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_knee_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_knee_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_knee_iq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_knee_iq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_knee_iq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_wheel_enc_rev
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->left_wheel_enc_rev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_wheel_enc_rev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_wheel_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_wheel_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_wheel_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_wheel_vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_wheel_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_wheel_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_wheel_iq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_wheel_iq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_wheel_iq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_hip_enc_rev
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->right_hip_enc_rev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_hip_enc_rev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_hip_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_hip_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_hip_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_hip_vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_hip_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_hip_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_hip_iq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_hip_iq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_hip_iq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_knee_enc_rev
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->right_knee_enc_rev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_knee_enc_rev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_knee_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_knee_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_knee_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_knee_vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_knee_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_knee_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_knee_iq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_knee_iq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_knee_iq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_wheel_enc_rev
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->right_wheel_enc_rev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_wheel_enc_rev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_wheel_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_wheel_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_wheel_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_wheel_vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_wheel_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_wheel_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_wheel_iq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_wheel_iq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_wheel_iq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left_leg_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left_leg_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left_leg_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // right_leg_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->right_leg_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "right_leg_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
