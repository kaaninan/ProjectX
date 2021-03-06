// Generated by gencpp from file projectx/DataControl.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_DATACONTROL_H
#define PROJECTX_MESSAGE_DATACONTROL_H


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
struct DataControl_
{
  typedef DataControl_<ContainerAllocator> Type;

  DataControl_()
    : data()
    , value()  {
    }
  DataControl_(const ContainerAllocator& _alloc)
    : data(_alloc)
    , value(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _data_type;
  _data_type data;

   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _value_type;
  _value_type value;




  typedef boost::shared_ptr< ::projectx::DataControl_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::DataControl_<ContainerAllocator> const> ConstPtr;

}; // struct DataControl_

typedef ::projectx::DataControl_<std::allocator<void> > DataControl;

typedef boost::shared_ptr< ::projectx::DataControl > DataControlPtr;
typedef boost::shared_ptr< ::projectx::DataControl const> DataControlConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::DataControl_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::DataControl_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::projectx::DataControl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::DataControl_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::DataControl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::DataControl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::DataControl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::DataControl_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::DataControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9ac12026f5dc300a479ba9f011cab4bf";
  }

  static const char* value(const ::projectx::DataControl_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9ac12026f5dc300aULL;
  static const uint64_t static_value2 = 0x479ba9f011cab4bfULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::DataControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/DataControl";
  }

  static const char* value(const ::projectx::DataControl_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::DataControl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string data\n\
int64[] value\n\
";
  }

  static const char* value(const ::projectx::DataControl_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::DataControl_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct DataControl_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::DataControl_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::DataControl_<ContainerAllocator>& v)
  {
    s << indent << "data: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.data);
    s << indent << "value[]" << std::endl;
    for (size_t i = 0; i < v.value.size(); ++i)
    {
      s << indent << "  value[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.value[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_DATACONTROL_H
