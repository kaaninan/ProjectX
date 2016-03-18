// Generated by gencpp from file projectx/SpeechResponse.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_SPEECHRESPONSE_H
#define PROJECTX_MESSAGE_SPEECHRESPONSE_H


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
struct SpeechResponse_
{
  typedef SpeechResponse_<ContainerAllocator> Type;

  SpeechResponse_()
    : dondur()  {
    }
  SpeechResponse_(const ContainerAllocator& _alloc)
    : dondur(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _dondur_type;
  _dondur_type dondur;




  typedef boost::shared_ptr< ::projectx::SpeechResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::SpeechResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SpeechResponse_

typedef ::projectx::SpeechResponse_<std::allocator<void> > SpeechResponse;

typedef boost::shared_ptr< ::projectx::SpeechResponse > SpeechResponsePtr;
typedef boost::shared_ptr< ::projectx::SpeechResponse const> SpeechResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::SpeechResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::SpeechResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::projectx::SpeechResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::SpeechResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::SpeechResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::SpeechResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::SpeechResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::SpeechResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::SpeechResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a9aa7fd6202b23c0accb5c2e77ed20be";
  }

  static const char* value(const ::projectx::SpeechResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa9aa7fd6202b23c0ULL;
  static const uint64_t static_value2 = 0xaccb5c2e77ed20beULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::SpeechResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/SpeechResponse";
  }

  static const char* value(const ::projectx::SpeechResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::SpeechResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string dondur\n\
";
  }

  static const char* value(const ::projectx::SpeechResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::SpeechResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.dondur);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct SpeechResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::SpeechResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::SpeechResponse_<ContainerAllocator>& v)
  {
    s << indent << "dondur: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.dondur);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_SPEECHRESPONSE_H
