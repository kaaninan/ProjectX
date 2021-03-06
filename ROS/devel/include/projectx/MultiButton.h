// Generated by gencpp from file projectx/MultiButton.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_MULTIBUTTON_H
#define PROJECTX_MESSAGE_MULTIBUTTON_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <projectx/CommonProperties.h>

namespace projectx
{
template <class ContainerAllocator>
struct MultiButton_
{
  typedef MultiButton_<ContainerAllocator> Type;

  MultiButton_()
    : header()
    , common()
    , dimension()
    , range()
    , values()
    , z(false)  {
      dimension.assign(0);

      range.assign(0.0);
  }
  MultiButton_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , common(_alloc)
    , dimension()
    , range()
    , values(_alloc)
    , z(false)  {
      dimension.assign(0);

      range.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::projectx::CommonProperties_<ContainerAllocator>  _common_type;
  _common_type common;

   typedef boost::array<uint16_t, 2>  _dimension_type;
  _dimension_type dimension;

   typedef boost::array<float, 2>  _range_type;
  _range_type range;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _values_type;
  _values_type values;

   typedef uint8_t _z_type;
  _z_type z;




  typedef boost::shared_ptr< ::projectx::MultiButton_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::MultiButton_<ContainerAllocator> const> ConstPtr;

}; // struct MultiButton_

typedef ::projectx::MultiButton_<std::allocator<void> > MultiButton;

typedef boost::shared_ptr< ::projectx::MultiButton > MultiButtonPtr;
typedef boost::shared_ptr< ::projectx::MultiButton const> MultiButtonConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::MultiButton_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::MultiButton_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace projectx

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'projectx': ['/home/ubuntu/ProjectX/ROS/src/projectx/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::projectx::MultiButton_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::MultiButton_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::MultiButton_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::MultiButton_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::MultiButton_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::MultiButton_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::MultiButton_<ContainerAllocator> >
{
  static const char* value()
  {
    return "880b03eb2c058ce5a9ec27c84df03870";
  }

  static const char* value(const ::projectx::MultiButton_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x880b03eb2c058ce5ULL;
  static const uint64_t static_value2 = 0xa9ec27c84df03870ULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::MultiButton_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/MultiButton";
  }

  static const char* value(const ::projectx::MultiButton_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::MultiButton_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# TouchOSC Multibutton Control\n\
\n\
Header header\n\
CommonProperties common\n\
uint16[2] dimension\n\
float32[2] range\n\
float32[] values\n\
bool z\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: projectx/CommonProperties\n\
# Common functionality to all TouchOSC controls\n\
\n\
string tabpage          # Control tabpage\n\
string name             # Control Name\n\
int16 x                 # X position of the control\n\
int16 y                 # Y position of the control\n\
uint16 width            # Width of the control\n\
uint16 height           # Height of the control\n\
string visible          # Visibility of the control\n\
\n\
# Possible colors are:\n\
# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"\n\
string color            # Color of the control\n\
";
  }

  static const char* value(const ::projectx::MultiButton_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::MultiButton_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.common);
      stream.next(m.dimension);
      stream.next(m.range);
      stream.next(m.values);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct MultiButton_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::MultiButton_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::MultiButton_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "common: ";
    s << std::endl;
    Printer< ::projectx::CommonProperties_<ContainerAllocator> >::stream(s, indent + "  ", v.common);
    s << indent << "dimension[]" << std::endl;
    for (size_t i = 0; i < v.dimension.size(); ++i)
    {
      s << indent << "  dimension[" << i << "]: ";
      Printer<uint16_t>::stream(s, indent + "  ", v.dimension[i]);
    }
    s << indent << "range[]" << std::endl;
    for (size_t i = 0; i < v.range.size(); ++i)
    {
      s << indent << "  range[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.range[i]);
    }
    s << indent << "values[]" << std::endl;
    for (size_t i = 0; i < v.values.size(); ++i)
    {
      s << indent << "  values[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.values[i]);
    }
    s << indent << "z: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_MULTIBUTTON_H
