// Generated by gencpp from file projectx/PinResponse.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_PINRESPONSE_H
#define PROJECTX_MESSAGE_PINRESPONSE_H


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
struct PinResponse_
{
  typedef PinResponse_<ContainerAllocator> Type;

  PinResponse_()
    : pin(0)  {
    }
  PinResponse_(const ContainerAllocator& _alloc)
    : pin(0)  {
    }



   typedef int64_t _pin_type;
  _pin_type pin;




  typedef boost::shared_ptr< ::projectx::PinResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::PinResponse_<ContainerAllocator> const> ConstPtr;

}; // struct PinResponse_

typedef ::projectx::PinResponse_<std::allocator<void> > PinResponse;

typedef boost::shared_ptr< ::projectx::PinResponse > PinResponsePtr;
typedef boost::shared_ptr< ::projectx::PinResponse const> PinResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::PinResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::PinResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace projectx

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'projectx': ['/home/rock/ProjectX/ROS/src/projectx/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::projectx::PinResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::PinResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::PinResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::PinResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::PinResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::PinResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::PinResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "13ce2e1fd6796d00dec37deecb854c69";
  }

  static const char* value(const ::projectx::PinResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x13ce2e1fd6796d00ULL;
  static const uint64_t static_value2 = 0xdec37deecb854c69ULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::PinResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/PinResponse";
  }

  static const char* value(const ::projectx::PinResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::PinResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 pin\n\
";
  }

  static const char* value(const ::projectx::PinResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::PinResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pin);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct PinResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::PinResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::PinResponse_<ContainerAllocator>& v)
  {
    s << indent << "pin: ";
    Printer<int64_t>::stream(s, indent + "  ", v.pin);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_PINRESPONSE_H
