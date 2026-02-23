# generated from rosidl_generator_py/resource/_idl.py.em
# with input from motion_msgs:msg/LegMotors.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LegMotors(type):
    """Metaclass of message 'LegMotors'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('motion_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'motion_msgs.msg.LegMotors')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__leg_motors
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__leg_motors
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__leg_motors
            cls._TYPE_SUPPORT = module.type_support_msg__msg__leg_motors
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__leg_motors

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LegMotors(metaclass=Metaclass_LegMotors):
    """Message class 'LegMotors'."""

    __slots__ = [
        '_header',
        '_left_hip_enc_rev',
        '_left_hip_pos',
        '_left_hip_vel',
        '_left_hip_iq',
        '_left_knee_enc_rev',
        '_left_knee_pos',
        '_left_knee_vel',
        '_left_knee_iq',
        '_left_wheel_enc_rev',
        '_left_wheel_pos',
        '_left_wheel_vel',
        '_left_wheel_iq',
        '_right_hip_enc_rev',
        '_right_hip_pos',
        '_right_hip_vel',
        '_right_hip_iq',
        '_right_knee_enc_rev',
        '_right_knee_pos',
        '_right_knee_vel',
        '_right_knee_iq',
        '_right_wheel_enc_rev',
        '_right_wheel_pos',
        '_right_wheel_vel',
        '_right_wheel_iq',
        '_left_leg_length',
        '_right_leg_length',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'left_hip_enc_rev': 'int32',
        'left_hip_pos': 'double',
        'left_hip_vel': 'double',
        'left_hip_iq': 'double',
        'left_knee_enc_rev': 'int32',
        'left_knee_pos': 'double',
        'left_knee_vel': 'double',
        'left_knee_iq': 'double',
        'left_wheel_enc_rev': 'int32',
        'left_wheel_pos': 'double',
        'left_wheel_vel': 'double',
        'left_wheel_iq': 'double',
        'right_hip_enc_rev': 'int32',
        'right_hip_pos': 'double',
        'right_hip_vel': 'double',
        'right_hip_iq': 'double',
        'right_knee_enc_rev': 'int32',
        'right_knee_pos': 'double',
        'right_knee_vel': 'double',
        'right_knee_iq': 'double',
        'right_wheel_enc_rev': 'int32',
        'right_wheel_pos': 'double',
        'right_wheel_vel': 'double',
        'right_wheel_iq': 'double',
        'left_leg_length': 'double',
        'right_leg_length': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.left_hip_enc_rev = kwargs.get('left_hip_enc_rev', int())
        self.left_hip_pos = kwargs.get('left_hip_pos', float())
        self.left_hip_vel = kwargs.get('left_hip_vel', float())
        self.left_hip_iq = kwargs.get('left_hip_iq', float())
        self.left_knee_enc_rev = kwargs.get('left_knee_enc_rev', int())
        self.left_knee_pos = kwargs.get('left_knee_pos', float())
        self.left_knee_vel = kwargs.get('left_knee_vel', float())
        self.left_knee_iq = kwargs.get('left_knee_iq', float())
        self.left_wheel_enc_rev = kwargs.get('left_wheel_enc_rev', int())
        self.left_wheel_pos = kwargs.get('left_wheel_pos', float())
        self.left_wheel_vel = kwargs.get('left_wheel_vel', float())
        self.left_wheel_iq = kwargs.get('left_wheel_iq', float())
        self.right_hip_enc_rev = kwargs.get('right_hip_enc_rev', int())
        self.right_hip_pos = kwargs.get('right_hip_pos', float())
        self.right_hip_vel = kwargs.get('right_hip_vel', float())
        self.right_hip_iq = kwargs.get('right_hip_iq', float())
        self.right_knee_enc_rev = kwargs.get('right_knee_enc_rev', int())
        self.right_knee_pos = kwargs.get('right_knee_pos', float())
        self.right_knee_vel = kwargs.get('right_knee_vel', float())
        self.right_knee_iq = kwargs.get('right_knee_iq', float())
        self.right_wheel_enc_rev = kwargs.get('right_wheel_enc_rev', int())
        self.right_wheel_pos = kwargs.get('right_wheel_pos', float())
        self.right_wheel_vel = kwargs.get('right_wheel_vel', float())
        self.right_wheel_iq = kwargs.get('right_wheel_iq', float())
        self.left_leg_length = kwargs.get('left_leg_length', float())
        self.right_leg_length = kwargs.get('right_leg_length', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.left_hip_enc_rev != other.left_hip_enc_rev:
            return False
        if self.left_hip_pos != other.left_hip_pos:
            return False
        if self.left_hip_vel != other.left_hip_vel:
            return False
        if self.left_hip_iq != other.left_hip_iq:
            return False
        if self.left_knee_enc_rev != other.left_knee_enc_rev:
            return False
        if self.left_knee_pos != other.left_knee_pos:
            return False
        if self.left_knee_vel != other.left_knee_vel:
            return False
        if self.left_knee_iq != other.left_knee_iq:
            return False
        if self.left_wheel_enc_rev != other.left_wheel_enc_rev:
            return False
        if self.left_wheel_pos != other.left_wheel_pos:
            return False
        if self.left_wheel_vel != other.left_wheel_vel:
            return False
        if self.left_wheel_iq != other.left_wheel_iq:
            return False
        if self.right_hip_enc_rev != other.right_hip_enc_rev:
            return False
        if self.right_hip_pos != other.right_hip_pos:
            return False
        if self.right_hip_vel != other.right_hip_vel:
            return False
        if self.right_hip_iq != other.right_hip_iq:
            return False
        if self.right_knee_enc_rev != other.right_knee_enc_rev:
            return False
        if self.right_knee_pos != other.right_knee_pos:
            return False
        if self.right_knee_vel != other.right_knee_vel:
            return False
        if self.right_knee_iq != other.right_knee_iq:
            return False
        if self.right_wheel_enc_rev != other.right_wheel_enc_rev:
            return False
        if self.right_wheel_pos != other.right_wheel_pos:
            return False
        if self.right_wheel_vel != other.right_wheel_vel:
            return False
        if self.right_wheel_iq != other.right_wheel_iq:
            return False
        if self.left_leg_length != other.left_leg_length:
            return False
        if self.right_leg_length != other.right_leg_length:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def left_hip_enc_rev(self):
        """Message field 'left_hip_enc_rev'."""
        return self._left_hip_enc_rev

    @left_hip_enc_rev.setter
    def left_hip_enc_rev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'left_hip_enc_rev' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'left_hip_enc_rev' field must be an integer in [-2147483648, 2147483647]"
        self._left_hip_enc_rev = value

    @builtins.property
    def left_hip_pos(self):
        """Message field 'left_hip_pos'."""
        return self._left_hip_pos

    @left_hip_pos.setter
    def left_hip_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_hip_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_hip_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_hip_pos = value

    @builtins.property
    def left_hip_vel(self):
        """Message field 'left_hip_vel'."""
        return self._left_hip_vel

    @left_hip_vel.setter
    def left_hip_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_hip_vel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_hip_vel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_hip_vel = value

    @builtins.property
    def left_hip_iq(self):
        """Message field 'left_hip_iq'."""
        return self._left_hip_iq

    @left_hip_iq.setter
    def left_hip_iq(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_hip_iq' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_hip_iq' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_hip_iq = value

    @builtins.property
    def left_knee_enc_rev(self):
        """Message field 'left_knee_enc_rev'."""
        return self._left_knee_enc_rev

    @left_knee_enc_rev.setter
    def left_knee_enc_rev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'left_knee_enc_rev' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'left_knee_enc_rev' field must be an integer in [-2147483648, 2147483647]"
        self._left_knee_enc_rev = value

    @builtins.property
    def left_knee_pos(self):
        """Message field 'left_knee_pos'."""
        return self._left_knee_pos

    @left_knee_pos.setter
    def left_knee_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_knee_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_knee_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_knee_pos = value

    @builtins.property
    def left_knee_vel(self):
        """Message field 'left_knee_vel'."""
        return self._left_knee_vel

    @left_knee_vel.setter
    def left_knee_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_knee_vel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_knee_vel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_knee_vel = value

    @builtins.property
    def left_knee_iq(self):
        """Message field 'left_knee_iq'."""
        return self._left_knee_iq

    @left_knee_iq.setter
    def left_knee_iq(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_knee_iq' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_knee_iq' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_knee_iq = value

    @builtins.property
    def left_wheel_enc_rev(self):
        """Message field 'left_wheel_enc_rev'."""
        return self._left_wheel_enc_rev

    @left_wheel_enc_rev.setter
    def left_wheel_enc_rev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'left_wheel_enc_rev' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'left_wheel_enc_rev' field must be an integer in [-2147483648, 2147483647]"
        self._left_wheel_enc_rev = value

    @builtins.property
    def left_wheel_pos(self):
        """Message field 'left_wheel_pos'."""
        return self._left_wheel_pos

    @left_wheel_pos.setter
    def left_wheel_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_wheel_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_wheel_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_wheel_pos = value

    @builtins.property
    def left_wheel_vel(self):
        """Message field 'left_wheel_vel'."""
        return self._left_wheel_vel

    @left_wheel_vel.setter
    def left_wheel_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_wheel_vel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_wheel_vel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_wheel_vel = value

    @builtins.property
    def left_wheel_iq(self):
        """Message field 'left_wheel_iq'."""
        return self._left_wheel_iq

    @left_wheel_iq.setter
    def left_wheel_iq(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_wheel_iq' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_wheel_iq' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_wheel_iq = value

    @builtins.property
    def right_hip_enc_rev(self):
        """Message field 'right_hip_enc_rev'."""
        return self._right_hip_enc_rev

    @right_hip_enc_rev.setter
    def right_hip_enc_rev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'right_hip_enc_rev' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'right_hip_enc_rev' field must be an integer in [-2147483648, 2147483647]"
        self._right_hip_enc_rev = value

    @builtins.property
    def right_hip_pos(self):
        """Message field 'right_hip_pos'."""
        return self._right_hip_pos

    @right_hip_pos.setter
    def right_hip_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_hip_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_hip_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_hip_pos = value

    @builtins.property
    def right_hip_vel(self):
        """Message field 'right_hip_vel'."""
        return self._right_hip_vel

    @right_hip_vel.setter
    def right_hip_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_hip_vel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_hip_vel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_hip_vel = value

    @builtins.property
    def right_hip_iq(self):
        """Message field 'right_hip_iq'."""
        return self._right_hip_iq

    @right_hip_iq.setter
    def right_hip_iq(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_hip_iq' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_hip_iq' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_hip_iq = value

    @builtins.property
    def right_knee_enc_rev(self):
        """Message field 'right_knee_enc_rev'."""
        return self._right_knee_enc_rev

    @right_knee_enc_rev.setter
    def right_knee_enc_rev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'right_knee_enc_rev' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'right_knee_enc_rev' field must be an integer in [-2147483648, 2147483647]"
        self._right_knee_enc_rev = value

    @builtins.property
    def right_knee_pos(self):
        """Message field 'right_knee_pos'."""
        return self._right_knee_pos

    @right_knee_pos.setter
    def right_knee_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_knee_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_knee_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_knee_pos = value

    @builtins.property
    def right_knee_vel(self):
        """Message field 'right_knee_vel'."""
        return self._right_knee_vel

    @right_knee_vel.setter
    def right_knee_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_knee_vel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_knee_vel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_knee_vel = value

    @builtins.property
    def right_knee_iq(self):
        """Message field 'right_knee_iq'."""
        return self._right_knee_iq

    @right_knee_iq.setter
    def right_knee_iq(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_knee_iq' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_knee_iq' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_knee_iq = value

    @builtins.property
    def right_wheel_enc_rev(self):
        """Message field 'right_wheel_enc_rev'."""
        return self._right_wheel_enc_rev

    @right_wheel_enc_rev.setter
    def right_wheel_enc_rev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'right_wheel_enc_rev' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'right_wheel_enc_rev' field must be an integer in [-2147483648, 2147483647]"
        self._right_wheel_enc_rev = value

    @builtins.property
    def right_wheel_pos(self):
        """Message field 'right_wheel_pos'."""
        return self._right_wheel_pos

    @right_wheel_pos.setter
    def right_wheel_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_wheel_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_wheel_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_wheel_pos = value

    @builtins.property
    def right_wheel_vel(self):
        """Message field 'right_wheel_vel'."""
        return self._right_wheel_vel

    @right_wheel_vel.setter
    def right_wheel_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_wheel_vel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_wheel_vel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_wheel_vel = value

    @builtins.property
    def right_wheel_iq(self):
        """Message field 'right_wheel_iq'."""
        return self._right_wheel_iq

    @right_wheel_iq.setter
    def right_wheel_iq(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_wheel_iq' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_wheel_iq' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_wheel_iq = value

    @builtins.property
    def left_leg_length(self):
        """Message field 'left_leg_length'."""
        return self._left_leg_length

    @left_leg_length.setter
    def left_leg_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'left_leg_length' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'left_leg_length' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._left_leg_length = value

    @builtins.property
    def right_leg_length(self):
        """Message field 'right_leg_length'."""
        return self._right_leg_length

    @right_leg_length.setter
    def right_leg_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'right_leg_length' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'right_leg_length' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._right_leg_length = value
