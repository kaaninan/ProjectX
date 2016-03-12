/* Auto-generated by genmsg_cpp for file /home/kaaninan/ProjectX/ROS/src/rososc/touchosc_msgs/msg/MultiButton.msg */
#ifndef TOUCHOSC_MSGS_MESSAGE_MULTIBUTTON_H
#define TOUCHOSC_MSGS_MESSAGE_MULTIBUTTON_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"
#include "touchosc_msgs/CommonProperties.h"

namespace touchosc_msgs
{
template <class ContainerAllocator>
struct MultiButton_ {
  typedef MultiButton_<ContainerAllocator> Type;

  MultiButton_()
  : header()
  , common()
  , dimension()
  , range()
  , values()
  , z(false)
  {
    dimension.assign(0);
    range.assign(0.0);
  }

  MultiButton_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , common(_alloc)
  , dimension()
  , range()
  , values(_alloc)
  , z(false)
  {
    dimension.assign(0);
    range.assign(0.0);
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef  ::touchosc_msgs::CommonProperties_<ContainerAllocator>  _common_type;
   ::touchosc_msgs::CommonProperties_<ContainerAllocator>  common;

  typedef boost::array<uint16_t, 2>  _dimension_type;
  boost::array<uint16_t, 2>  dimension;

  typedef boost::array<float, 2>  _range_type;
  boost::array<float, 2>  range;

  typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _values_type;
  std::vector<float, typename ContainerAllocator::template rebind<float>::other >  values;

  typedef uint8_t _z_type;
  uint8_t z;


  typedef boost::shared_ptr< ::touchosc_msgs::MultiButton_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::touchosc_msgs::MultiButton_<ContainerAllocator>  const> ConstPtr;
}; // struct MultiButton
typedef  ::touchosc_msgs::MultiButton_<std::allocator<void> > MultiButton;

typedef boost::shared_ptr< ::touchosc_msgs::MultiButton> MultiButtonPtr;
typedef boost::shared_ptr< ::touchosc_msgs::MultiButton const> MultiButtonConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::touchosc_msgs::MultiButton_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::touchosc_msgs::MultiButton_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace touchosc_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::touchosc_msgs::MultiButton_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::touchosc_msgs::MultiButton_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::touchosc_msgs::MultiButton_<ContainerAllocator> > {
  static const char* value() 
  {
    return "880b03eb2c058ce5a9ec27c84df03870";
  }

  static const char* value(const  ::touchosc_msgs::MultiButton_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x880b03eb2c058ce5ULL;
  static const uint64_t static_value2 = 0xa9ec27c84df03870ULL;
};

template<class ContainerAllocator>
struct DataType< ::touchosc_msgs::MultiButton_<ContainerAllocator> > {
  static const char* value() 
  {
    return "touchosc_msgs/MultiButton";
  }

  static const char* value(const  ::touchosc_msgs::MultiButton_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::touchosc_msgs::MultiButton_<ContainerAllocator> > {
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
MSG: touchosc_msgs/CommonProperties\n\
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
\n\
";
  }

  static const char* value(const  ::touchosc_msgs::MultiButton_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::touchosc_msgs::MultiButton_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::touchosc_msgs::MultiButton_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::touchosc_msgs::MultiButton_<ContainerAllocator> >
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
struct Printer< ::touchosc_msgs::MultiButton_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::touchosc_msgs::MultiButton_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "common: ";
s << std::endl;
    Printer< ::touchosc_msgs::CommonProperties_<ContainerAllocator> >::stream(s, indent + "  ", v.common);
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

#endif // TOUCHOSC_MSGS_MESSAGE_MULTIBUTTON_H

