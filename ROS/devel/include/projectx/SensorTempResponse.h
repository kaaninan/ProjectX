// Generated by gencpp from file projectx/SensorTempResponse.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_SENSORTEMPRESPONSE_H
#define PROJECTX_MESSAGE_SENSORTEMPRESPONSE_H


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
struct SensorTempResponse_
{
  typedef SensorTempResponse_<ContainerAllocator> Type;

  SensorTempResponse_()
    : temp1(0.0)
    , temp2(0.0)
    , nem(0.0)  {
    }
  SensorTempResponse_(const ContainerAllocator& _alloc)
    : temp1(0.0)
    , temp2(0.0)
    , nem(0.0)  {
    }



   typedef double _temp1_type;
  _temp1_type temp1;

   typedef double _temp2_type;
  _temp2_type temp2;

   typedef double _nem_type;
  _nem_type nem;




  typedef boost::shared_ptr< ::projectx::SensorTempResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::SensorTempResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SensorTempResponse_

typedef ::projectx::SensorTempResponse_<std::allocator<void> > SensorTempResponse;

typedef boost::shared_ptr< ::projectx::SensorTempResponse > SensorTempResponsePtr;
typedef boost::shared_ptr< ::projectx::SensorTempResponse const> SensorTempResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::SensorTempResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::SensorTempResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace projectx

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'projectx': ['/home/kaaninan/ProjectX/ROS/src/projectx/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::projectx::SensorTempResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::SensorTempResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::SensorTempResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::SensorTempResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::SensorTempResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::SensorTempResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::SensorTempResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "813b115f2598f32dc74cb170a02d630f";
  }

  static const char* value(const ::projectx::SensorTempResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x813b115f2598f32dULL;
  static const uint64_t static_value2 = 0xc74cb170a02d630fULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::SensorTempResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/SensorTempResponse";
  }

  static const char* value(const ::projectx::SensorTempResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::SensorTempResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 temp1\n\
float64 temp2\n\
float64 nem\n\
\n\
";
  }

  static const char* value(const ::projectx::SensorTempResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::SensorTempResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.temp1);
      stream.next(m.temp2);
      stream.next(m.nem);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct SensorTempResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::SensorTempResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::SensorTempResponse_<ContainerAllocator>& v)
  {
    s << indent << "temp1: ";
    Printer<double>::stream(s, indent + "  ", v.temp1);
    s << indent << "temp2: ";
    Printer<double>::stream(s, indent + "  ", v.temp2);
    s << indent << "nem: ";
    Printer<double>::stream(s, indent + "  ", v.nem);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_SENSORTEMPRESPONSE_H
