// Generated by gencpp from file projectx/IntArray.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_INTARRAY_H
#define PROJECTX_MESSAGE_INTARRAY_H


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
struct IntArray_
{
  typedef IntArray_<ContainerAllocator> Type;

  IntArray_()
    : deger()  {
    }
  IntArray_(const ContainerAllocator& _alloc)
    : deger(_alloc)  {
    }



   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _deger_type;
  _deger_type deger;




  typedef boost::shared_ptr< ::projectx::IntArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::IntArray_<ContainerAllocator> const> ConstPtr;

}; // struct IntArray_

typedef ::projectx::IntArray_<std::allocator<void> > IntArray;

typedef boost::shared_ptr< ::projectx::IntArray > IntArrayPtr;
typedef boost::shared_ptr< ::projectx::IntArray const> IntArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::IntArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::IntArray_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::projectx::IntArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::IntArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::IntArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::IntArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::IntArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::IntArray_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::IntArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b33d02db9df612bb8d91e911852cbddb";
  }

  static const char* value(const ::projectx::IntArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb33d02db9df612bbULL;
  static const uint64_t static_value2 = 0x8d91e911852cbddbULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::IntArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/IntArray";
  }

  static const char* value(const ::projectx::IntArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::IntArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64[] deger\n\
";
  }

  static const char* value(const ::projectx::IntArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::IntArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.deger);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct IntArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::IntArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::IntArray_<ContainerAllocator>& v)
  {
    s << indent << "deger[]" << std::endl;
    for (size_t i = 0; i < v.deger.size(); ++i)
    {
      s << indent << "  deger[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.deger[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_INTARRAY_H
