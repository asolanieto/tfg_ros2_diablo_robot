// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from motion_msgs:msg/MotionCtrl.idl
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
#include "motion_msgs/msg/detail/motion_ctrl__struct.h"
#include "motion_msgs/msg/detail/motion_ctrl__functions.h"

bool motion_msgs__msg__movement_ctrl_data__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * motion_msgs__msg__movement_ctrl_data__convert_to_py(void * raw_ros_message);
bool motion_msgs__msg__movement_ctrl_mode__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * motion_msgs__msg__movement_ctrl_mode__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool motion_msgs__msg__motion_ctrl__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
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
    assert(strncmp("motion_msgs.msg._motion_ctrl.MotionCtrl", full_classname_dest, 39) == 0);
  }
  motion_msgs__msg__MotionCtrl * ros_message = _ros_message;
  {  // mode_mark
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode_mark");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->mode_mark = (Py_True == field);
    Py_DECREF(field);
  }
  {  // value
    PyObject * field = PyObject_GetAttrString(_pymsg, "value");
    if (!field) {
      return false;
    }
    if (!motion_msgs__msg__movement_ctrl_data__convert_from_py(field, &ros_message->value)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    if (!motion_msgs__msg__movement_ctrl_mode__convert_from_py(field, &ros_message->mode)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * motion_msgs__msg__motion_ctrl__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MotionCtrl */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("motion_msgs.msg._motion_ctrl");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MotionCtrl");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  motion_msgs__msg__MotionCtrl * ros_message = (motion_msgs__msg__MotionCtrl *)raw_ros_message;
  {  // mode_mark
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->mode_mark ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode_mark", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // value
    PyObject * field = NULL;
    field = motion_msgs__msg__movement_ctrl_data__convert_to_py(&ros_message->value);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode
    PyObject * field = NULL;
    field = motion_msgs__msg__movement_ctrl_mode__convert_to_py(&ros_message->mode);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
