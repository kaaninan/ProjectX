// Generated by gencpp from file projectx/MotorInArray.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_MOTORINARRAY_H
#define PROJECTX_MESSAGE_MOTORINARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace projectx
{
template <class ContainerAllocator>
struct MotorInArray_
{
  typedef MotorInArray_<ContainerAllocator> Type;

  MotorInArray_()
    : temp()
    , voltage()
    , pos()  {
    }
  MotorInArray_(const ContainerAllocator& _alloc)
    : temp(_alloc)
    , voltage(_alloc)
    , pos(_alloc)  {
    }



   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _temp_type;
  _temp_type temp;

   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _voltage_type;
  _voltage_type voltage;

   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _pos_type;
  _pos_type pos;




  typedef boost::shared_ptr< ::projectx::MotorInArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::MotorInArray_<ContainerAllocator> const> ConstPtr;

}; // struct MotorInArray_

typedef ::projectx::MotorInArray_<std::allocator<void> > MotorInArray;

typedef boost::shared_ptr< ::projectx::MotorInArray > MotorInArrayPtr;
typedef boost::shared_ptr< ::projectx::MotorInArray const> MotorInArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::MotorInArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::MotorInArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace projectx

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'projectx': ['/home/kaaninan/ProjectX/ROS/src/projectx/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::projectx::MotorInArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::MotorInArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::MotorInArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::MotorInArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::MotorInArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::MotorInArray_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::MotorInArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ac25f9cd141042ee871f32a69a144670";
  }

  static const char* value(const ::projectx::MotorInArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xac25f9cd141042eeULL;
  static const uint64_t static_value2 = 0x871f32a69a144670ULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::MotorInArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/MotorInArray";
  }

  static const char* value(const ::projectx::MotorInArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::MotorInArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64[] temp\n\
int64[] voltage\n\
int64[] pos\n\
";
  }

  static const char* value(const ::projectx::MotorInArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::MotorInArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.temp);
      stream.next(m.voltage);
      stream.next(m.pos);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct MotorInArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::MotorInArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::MotorInArray_<ContainerAllocator>& v)
  {
    s << indent << "temp[]" << std::endl;
    for (size_t i = 0; i < v.temp.size(); ++i)
    {
      s << indent << "  temp[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.temp[i]);
    }
    s << indent << "voltage[]" << std::endl;
    for (size_t i = 0; i < v.voltage.size(); ++i)
    {
      s << indent << "  voltage[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.voltage[i]);
    }
    s << indent << "pos[]" << std::endl;
    for (size_t i = 0; i < v.pos.size(); ++i)
    {
      s << indent << "  pos[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.pos[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_MOTORINARRAY_H
