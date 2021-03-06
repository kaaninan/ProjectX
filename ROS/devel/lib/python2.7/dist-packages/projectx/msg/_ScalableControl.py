# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from projectx/ScalableControl.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import projectx.msg
import std_msgs.msg

class ScalableControl(genpy.Message):
  _md5sum = "4b6ef3bf63f615ec962c83cced2ac5dc"
  _type = "projectx/ScalableControl"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """# TouchOSC Scalable Control
# Push Button, Toggle Button, LED, Fader, Rotary

Header header
CommonProperties common
float32[2] range
float32 value
bool z

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: projectx/CommonProperties
# Common functionality to all TouchOSC controls

string tabpage          # Control tabpage
string name             # Control Name
int16 x                 # X position of the control
int16 y                 # Y position of the control
uint16 width            # Width of the control
uint16 height           # Height of the control
string visible          # Visibility of the control

# Possible colors are:
# "red", "green", "blue", "yellow", "orange", "purple", "gray"
string color            # Color of the control

"""
  __slots__ = ['header','common','range','value','z']
  _slot_types = ['std_msgs/Header','projectx/CommonProperties','float32[2]','float32','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,common,range,value,z

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ScalableControl, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.common is None:
        self.common = projectx.msg.CommonProperties()
      if self.range is None:
        self.range = [0.,0.]
      if self.value is None:
        self.value = 0.
      if self.z is None:
        self.z = False
    else:
      self.header = std_msgs.msg.Header()
      self.common = projectx.msg.CommonProperties()
      self.range = [0.,0.]
      self.value = 0.
      self.z = False

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
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.common.tabpage
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.common.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2h2H.pack(_x.common.x, _x.common.y, _x.common.width, _x.common.height))
      _x = self.common.visible
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.common.color
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_2f.pack(*self.range))
      _x = self
      buff.write(_struct_fB.pack(_x.value, _x.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.common is None:
        self.common = projectx.msg.CommonProperties()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.common.tabpage = str[start:end].decode('utf-8')
      else:
        self.common.tabpage = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.common.name = str[start:end].decode('utf-8')
      else:
        self.common.name = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.common.x, _x.common.y, _x.common.width, _x.common.height,) = _struct_2h2H.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.common.visible = str[start:end].decode('utf-8')
      else:
        self.common.visible = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.common.color = str[start:end].decode('utf-8')
      else:
        self.common.color = str[start:end]
      start = end
      end += 8
      self.range = _struct_2f.unpack(str[start:end])
      _x = self
      start = end
      end += 5
      (_x.value, _x.z,) = _struct_fB.unpack(str[start:end])
      self.z = bool(self.z)
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
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.common.tabpage
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.common.name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_2h2H.pack(_x.common.x, _x.common.y, _x.common.width, _x.common.height))
      _x = self.common.visible
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self.common.color
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(self.range.tostring())
      _x = self
      buff.write(_struct_fB.pack(_x.value, _x.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.common is None:
        self.common = projectx.msg.CommonProperties()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.common.tabpage = str[start:end].decode('utf-8')
      else:
        self.common.tabpage = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.common.name = str[start:end].decode('utf-8')
      else:
        self.common.name = str[start:end]
      _x = self
      start = end
      end += 8
      (_x.common.x, _x.common.y, _x.common.width, _x.common.height,) = _struct_2h2H.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.common.visible = str[start:end].decode('utf-8')
      else:
        self.common.visible = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.common.color = str[start:end].decode('utf-8')
      else:
        self.common.color = str[start:end]
      start = end
      end += 8
      self.range = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=2)
      _x = self
      start = end
      end += 5
      (_x.value, _x.z,) = _struct_fB.unpack(str[start:end])
      self.z = bool(self.z)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_fB = struct.Struct("<fB")
_struct_3I = struct.Struct("<3I")
_struct_2h2H = struct.Struct("<2h2H")
_struct_2f = struct.Struct("<2f")
