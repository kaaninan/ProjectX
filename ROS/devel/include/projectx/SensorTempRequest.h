// Generated by gencpp from file projectx/SensorTempRequest.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_SENSORTEMPREQUEST_H
#define PROJECTX_MESSAGE_SENSORTEMPREQUEST_H


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
struct SensorTempRequest_
{
  typedef SensorTempRequest_<ContainerAllocator> Type;

  SensorTempRequest_()
    {
    }
  SensorTempRequest_(const ContainerAllocator& _alloc)
    {
    }






  typedef boost::shared_ptr< ::projectx::SensorTempRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::SensorTempRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SensorTempRequest_

typedef ::projectx::SensorTempRequest_<std::allocator<void> > SensorTempRequest;

typedef boost::shared_ptr< ::projectx::SensorTempRequest > SensorTempRequestPtr;
typedef boost::shared_ptr< ::projectx::SensorTempRequest const> SensorTempRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::SensorTempRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::SensorTempRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace projectx

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'projectx': ['/home/ubuntu/ProjectX/ROS/src/projectx/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::projectx::SensorTempRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::SensorTempRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::SensorTempRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::SensorTempRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::SensorTempRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::SensorTempRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::SensorTempRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::projectx::SensorTempRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::SensorTempRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/SensorTempRequest";
  }

  static const char* value(const ::projectx::SensorTempRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::SensorTempRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::projectx::SensorTempRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::SensorTempRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct SensorTempRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::SensorTempRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::projectx::SensorTempRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_SENSORTEMPREQUEST_H
