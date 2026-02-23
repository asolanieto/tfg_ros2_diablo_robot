// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from motion_msgs:msg/MovementCtrlData.idl
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
#include "motion_msgs/msg/detail/movement_ctrl_data__struct.h"
#include "motion_msgs/msg/detail/movement_ctrl_data__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool motion_msgs__msg__movement_ctrl_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("motion_msgs.msg._movement_ctrl_data.MovementCtrlData", full_classname_dest, 52) == 0);
  }
  motion_msgs__msg__MovementCtrlData * ros_message = _ros_message;
  {  // forward
    PyObject * field = PyObject_GetAttrString(_pymsg, "forward");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->forward = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // left
    PyObject * field = PyObject_GetAttrString(_pymsg, "left");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->left = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // up
    PyObject * field = PyObject_GetAttrString(_pymsg, "up");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->up = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // roll
    PyObject * field = PyObject_GetAttrString(_pymsg, "roll");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->roll = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pitch
    PyObject * field = PyObject_GetAttrString(_pymsg, "pitch");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pitch = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // leg_split
    PyObject * field = PyObject_GetAttrString(_pymsg, "leg_split");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->leg_split = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * motion_msgs__msg__movement_ctrl_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MovementCtrlData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("motion_msgs.msg._movement_ctrl_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MovementCtrlData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  motion_msgs__msg__MovementCtrlData * ros_message = (motion_msgs__msg__MovementCtrlData *)raw_ros_message;
  {  // forward
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->forward);
    {
      int rc = PyObject_SetAttrString(_pymessage, "forward", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // left
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->left);
    {
      int rc = PyObject_SetAttrString(_pymessage, "left", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // up
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->up);
    {
      int rc = PyObject_SetAttrString(_pymessage, "up", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // roll
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->roll);
    {
      int rc = PyObject_SetAttrString(_pymessage, "roll", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pitch
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pitch);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pitch", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // leg_split
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->leg_split);
    {
      int rc = PyObject_SetAttrString(_pymessage, "leg_split", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
