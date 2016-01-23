# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from projectx/MotorOutArray.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class MotorOutArray(genpy.Message):
  _md5sum = "b23b46468244cd9fc2bd0e16a8568772"
  _type = "projectx/MotorOutArray"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int64[] id
int64[] pos
int64[] speed
int64[] torque
int64[] rw
int64[] action
"""
  __slots__ = ['id','pos','speed','torque','rw','action']
  _slot_types = ['int64[]','int64[]','int64[]','int64[]','int64[]','int64[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       id,pos,speed,torque,rw,action

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(MotorOutArray, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.id is None:
        self.id = []
      if self.pos is None:
        self.pos = []
      if self.speed is None:
        self.speed = []
      if self.torque is None:
        self.torque = []
      if self.rw is None:
        self.rw = []
      if self.action is None:
        self.action = []
    else:
      self.id = []
      self.pos = []
      self.speed = []
      self.torque = []
      self.rw = []
      self.action = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.id)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(struct.pack(pattern, *self.id))
      length = len(self.pos)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(struct.pack(pattern, *self.pos))
      length = len(self.speed)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(struct.pack(pattern, *self.speed))
      length = len(self.torque)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(struct.pack(pattern, *self.torque))
      length = len(self.rw)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(struct.pack(pattern, *self.rw))
      length = len(self.action)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(struct.pack(pattern, *self.action))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.id = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.pos = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.speed = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.torque = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.rw = struct.unpack(pattern, str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.action = struct.unpack(pattern, str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.id)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(self.id.tostring())
      length = len(self.pos)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(self.pos.tostring())
      length = len(self.speed)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(self.speed.tostring())
      length = len(self.torque)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(self.torque.tostring())
      length = len(self.rw)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(self.rw.tostring())
      length = len(self.action)
      buff.write(_struct_I.pack(length))
      pattern = '<%sq'%length
      buff.write(self.action.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.id = numpy.frombuffer(str[start:end], dtype=numpy.int64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.pos = numpy.frombuffer(str[start:end], dtype=numpy.int64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.speed = numpy.frombuffer(str[start:end], dtype=numpy.int64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.torque = numpy.frombuffer(str[start:end], dtype=numpy.int64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.rw = numpy.frombuffer(str[start:end], dtype=numpy.int64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sq'%length
      start = end
      end += struct.calcsize(pattern)
      self.action = numpy.frombuffer(str[start:end], dtype=numpy.int64, count=length)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I