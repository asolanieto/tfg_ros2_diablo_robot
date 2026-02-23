# generated from rosidl_generator_py/resource/_idl.py.em
# with input from motion_msgs:msg/MovementCtrlMode.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MovementCtrlMode(type):
    """Metaclass of message 'MovementCtrlMode'."""

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
                'motion_msgs.msg.MovementCtrlMode')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__movement_ctrl_mode
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__movement_ctrl_mode
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__movement_ctrl_mode
            cls._TYPE_SUPPORT = module.type_support_msg__msg__movement_ctrl_mode
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__movement_ctrl_mode

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MovementCtrlMode(metaclass=Metaclass_MovementCtrlMode):
    """Message class 'MovementCtrlMode'."""

    __slots__ = [
        '_pitch_ctrl_mode',
        '_roll_ctrl_mode',
        '_height_ctrl_mode',
        '_stand_mode',
        '_jump_mode',
        '_split_mode',
    ]

    _fields_and_field_types = {
        'pitch_ctrl_mode': 'boolean',
        'roll_ctrl_mode': 'boolean',
        'height_ctrl_mode': 'boolean',
        'stand_mode': 'boolean',
        'jump_mode': 'boolean',
        'split_mode': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pitch_ctrl_mode = kwargs.get('pitch_ctrl_mode', bool())
        self.roll_ctrl_mode = kwargs.get('roll_ctrl_mode', bool())
        self.height_ctrl_mode = kwargs.get('height_ctrl_mode', bool())
        self.stand_mode = kwargs.get('stand_mode', bool())
        self.jump_mode = kwargs.get('jump_mode', bool())
        self.split_mode = kwargs.get('split_mode', bool())

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
        if self.pitch_ctrl_mode != other.pitch_ctrl_mode:
            return False
        if self.roll_ctrl_mode != other.roll_ctrl_mode:
            return False
        if self.height_ctrl_mode != other.height_ctrl_mode:
            return False
        if self.stand_mode != other.stand_mode:
            return False
        if self.jump_mode != other.jump_mode:
            return False
        if self.split_mode != other.split_mode:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pitch_ctrl_mode(self):
        """Message field 'pitch_ctrl_mode'."""
        return self._pitch_ctrl_mode

    @pitch_ctrl_mode.setter
    def pitch_ctrl_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'pitch_ctrl_mode' field must be of type 'bool'"
        self._pitch_ctrl_mode = value

    @builtins.property
    def roll_ctrl_mode(self):
        """Message field 'roll_ctrl_mode'."""
        return self._roll_ctrl_mode

    @roll_ctrl_mode.setter
    def roll_ctrl_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'roll_ctrl_mode' field must be of type 'bool'"
        self._roll_ctrl_mode = value

    @builtins.property
    def height_ctrl_mode(self):
        """Message field 'height_ctrl_mode'."""
        return self._height_ctrl_mode

    @height_ctrl_mode.setter
    def height_ctrl_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'height_ctrl_mode' field must be of type 'bool'"
        self._height_ctrl_mode = value

    @builtins.property
    def stand_mode(self):
        """Message field 'stand_mode'."""
        return self._stand_mode

    @stand_mode.setter
    def stand_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'stand_mode' field must be of type 'bool'"
        self._stand_mode = value

    @builtins.property
    def jump_mode(self):
        """Message field 'jump_mode'."""
        return self._jump_mode

    @jump_mode.setter
    def jump_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'jump_mode' field must be of type 'bool'"
        self._jump_mode = value

    @builtins.property
    def split_mode(self):
        """Message field 'split_mode'."""
        return self._split_mode

    @split_mode.setter
    def split_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'split_mode' field must be of type 'bool'"
        self._split_mode = value
