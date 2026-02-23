// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from motion_msgs:msg/MovementCtrlMode.idl
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
#include "motion_msgs/msg/detail/movement_ctrl_mode__struct.h"
#include "motion_msgs/msg/detail/movement_ctrl_mode__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool motion_msgs__msg__movement_ctrl_mode__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
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
    assert(strncmp("motion_msgs.msg._movement_ctrl_mode.MovementCtrlMode", full_classname_dest, 52) == 0);
  }
  motion_msgs__msg__MovementCtrlMode * ros_message = _ros_message;
  {  // pitch_ctrl_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch_ctrl_mode");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->pitch_ctrl_mode = (Py_True == field);
    Py_DECREF(field);
  }
  {  // roll_ctrl_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "roll_ctrl_mode");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->roll_ctrl_mode = (Py_True == field);
    Py_DECREF(field);
  }
  {  // height_ctrl_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "height_ctrl_mode");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->height_ctrl_mode = (Py_True == field);
    Py_DECREF(field);
  }
  {  // stand_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "stand_mode");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->stand_mode = (Py_True == field);
    Py_DECREF(field);
  }
  {  // jump_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "jump_mode");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->jump_mode = (Py_True == field);
    Py_DECREF(field);
  }
  {  // split_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "split_mode");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->split_mode = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * motion_msgs__msg__movement_ctrl_mode__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MovementCtrlMode */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("motion_msgs.msg._movement_ctrl_mode");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MovementCtrlMode");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  motion_msgs__msg__MovementCtrlMode * ros_message = (motion_msgs__msg__MovementCtrlMode *)raw_ros_message;
  {  // pitch_ctrl_mode
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->pitch_ctrl_mode ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch_ctrl_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // roll_ctrl_mode
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->roll_ctrl_mode ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "roll_ctrl_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // height_ctrl_mode
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->height_ctrl_mode ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "height_ctrl_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stand_mode
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->stand_mode ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "stand_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // jump_mode
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->jump_mode ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "jump_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // split_mode
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->split_mode ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "split_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
