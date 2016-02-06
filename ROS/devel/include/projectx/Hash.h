// Generated by gencpp from file projectx/Hash.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_HASH_H
#define PROJECTX_MESSAGE_HASH_H


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
struct Hash_
{
  typedef Hash_<ContainerAllocator> Type;

  Hash_()
    : id(0)
    , deger(0)  {
    }
  Hash_(const ContainerAllocator& _alloc)
    : id(0)
    , deger(0)  {
    }



   typedef int64_t _id_type;
  _id_type id;

   typedef int64_t _deger_type;
  _deger_type deger;




  typedef boost::shared_ptr< ::projectx::Hash_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::Hash_<ContainerAllocator> const> ConstPtr;

}; // struct Hash_

typedef ::projectx::Hash_<std::allocator<void> > Hash;

typedef boost::shared_ptr< ::projectx::Hash > HashPtr;
typedef boost::shared_ptr< ::projectx::Hash const> HashConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::Hash_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::Hash_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::projectx::Hash_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::Hash_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::Hash_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::Hash_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::Hash_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::Hash_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::Hash_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c58586854baf73aa03696ec20686d5f2";
  }

  static const char* value(const ::projectx::Hash_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc58586854baf73aaULL;
  static const uint64_t static_value2 = 0x03696ec20686d5f2ULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::Hash_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/Hash";
  }

  static const char* value(const ::projectx::Hash_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::Hash_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 id\n\
int64 deger\n\
";
  }

  static const char* value(const ::projectx::Hash_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::Hash_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.deger);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Hash_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::Hash_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::Hash_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<int64_t>::stream(s, indent + "  ", v.id);
    s << indent << "deger: ";
    Printer<int64_t>::stream(s, indent + "  ", v.deger);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_HASH_H
