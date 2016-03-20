// Generated by gencpp from file projectx/MotorBoostResponse.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_MOTORBOOSTRESPONSE_H
#define PROJECTX_MESSAGE_MOTORBOOSTRESPONSE_H


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
struct MotorBoostResponse_
{
  typedef MotorBoostResponse_<ContainerAllocator> Type;

  MotorBoostResponse_()
    : out_data()  {
    }
  MotorBoostResponse_(const ContainerAllocator& _alloc)
    : out_data(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _out_data_type;
  _out_data_type out_data;




  typedef boost::shared_ptr< ::projectx::MotorBoostResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::MotorBoostResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MotorBoostResponse_

typedef ::projectx::MotorBoostResponse_<std::allocator<void> > MotorBoostResponse;

typedef boost::shared_ptr< ::projectx::MotorBoostResponse > MotorBoostResponsePtr;
typedef boost::shared_ptr< ::projectx::MotorBoostResponse const> MotorBoostResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::MotorBoostResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::MotorBoostResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace projectx

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'projectx': ['/home/ubuntu/ProjectX/ROS/src/projectx/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::projectx::MotorBoostResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::MotorBoostResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::MotorBoostResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::MotorBoostResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::MotorBoostResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::MotorBoostResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::MotorBoostResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "616a79ae09e0166195481d0fb8b7b20c";
  }

  static const char* value(const ::projectx::MotorBoostResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x616a79ae09e01661ULL;
  static const uint64_t static_value2 = 0x95481d0fb8b7b20cULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::MotorBoostResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/MotorBoostResponse";
  }

  static const char* value(const ::projectx::MotorBoostResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::MotorBoostResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string out_data\n\
";
  }

  static const char* value(const ::projectx::MotorBoostResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::MotorBoostResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.out_data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct MotorBoostResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::MotorBoostResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::MotorBoostResponse_<ContainerAllocator>& v)
  {
    s << indent << "out_data: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.out_data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_MOTORBOOSTRESPONSE_H