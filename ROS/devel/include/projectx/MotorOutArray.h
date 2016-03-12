// Generated by gencpp from file projectx/MotorOutArray.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_MOTOROUTARRAY_H
#define PROJECTX_MESSAGE_MOTOROUTARRAY_H


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
struct MotorOutArray_
{
  typedef MotorOutArray_<ContainerAllocator> Type;

  MotorOutArray_()
    : id()
    , pos()
    , speed()
    , torque()
    , rw()
    , action()  {
    }
  MotorOutArray_(const ContainerAllocator& _alloc)
    : id(_alloc)
    , pos(_alloc)
    , speed(_alloc)
    , torque(_alloc)
    , rw(_alloc)
    , action(_alloc)  {
    }



   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _id_type;
  _id_type id;

   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _pos_type;
  _pos_type pos;

   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _speed_type;
  _speed_type speed;

   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _torque_type;
  _torque_type torque;

   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _rw_type;
  _rw_type rw;

   typedef std::vector<int64_t, typename ContainerAllocator::template rebind<int64_t>::other >  _action_type;
  _action_type action;




  typedef boost::shared_ptr< ::projectx::MotorOutArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::projectx::MotorOutArray_<ContainerAllocator> const> ConstPtr;

}; // struct MotorOutArray_

typedef ::projectx::MotorOutArray_<std::allocator<void> > MotorOutArray;

typedef boost::shared_ptr< ::projectx::MotorOutArray > MotorOutArrayPtr;
typedef boost::shared_ptr< ::projectx::MotorOutArray const> MotorOutArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::projectx::MotorOutArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::projectx::MotorOutArray_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::projectx::MotorOutArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::projectx::MotorOutArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::MotorOutArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::projectx::MotorOutArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::MotorOutArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::projectx::MotorOutArray_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::projectx::MotorOutArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b23b46468244cd9fc2bd0e16a8568772";
  }

  static const char* value(const ::projectx::MotorOutArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb23b46468244cd9fULL;
  static const uint64_t static_value2 = 0xc2bd0e16a8568772ULL;
};

template<class ContainerAllocator>
struct DataType< ::projectx::MotorOutArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "projectx/MotorOutArray";
  }

  static const char* value(const ::projectx::MotorOutArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::projectx::MotorOutArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64[] id\n\
int64[] pos\n\
int64[] speed\n\
int64[] torque\n\
int64[] rw\n\
int64[] action\n\
";
  }

  static const char* value(const ::projectx::MotorOutArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::projectx::MotorOutArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.pos);
      stream.next(m.speed);
      stream.next(m.torque);
      stream.next(m.rw);
      stream.next(m.action);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct MotorOutArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::projectx::MotorOutArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::projectx::MotorOutArray_<ContainerAllocator>& v)
  {
    s << indent << "id[]" << std::endl;
    for (size_t i = 0; i < v.id.size(); ++i)
    {
      s << indent << "  id[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.id[i]);
    }
    s << indent << "pos[]" << std::endl;
    for (size_t i = 0; i < v.pos.size(); ++i)
    {
      s << indent << "  pos[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.pos[i]);
    }
    s << indent << "speed[]" << std::endl;
    for (size_t i = 0; i < v.speed.size(); ++i)
    {
      s << indent << "  speed[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.speed[i]);
    }
    s << indent << "torque[]" << std::endl;
    for (size_t i = 0; i < v.torque.size(); ++i)
    {
      s << indent << "  torque[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.torque[i]);
    }
    s << indent << "rw[]" << std::endl;
    for (size_t i = 0; i < v.rw.size(); ++i)
    {
      s << indent << "  rw[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.rw[i]);
    }
    s << indent << "action[]" << std::endl;
    for (size_t i = 0; i < v.action.size(); ++i)
    {
      s << indent << "  action[" << i << "]: ";
      Printer<int64_t>::stream(s, indent + "  ", v.action[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECTX_MESSAGE_MOTOROUTARRAY_H
