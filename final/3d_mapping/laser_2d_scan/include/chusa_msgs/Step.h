// Generated by gencpp from file chusa_msgs/Step.msg
// DO NOT EDIT!


#ifndef CHUSA_MSGS_MESSAGE_STEP_H
#define CHUSA_MSGS_MESSAGE_STEP_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace chusa_msgs
{
template <class ContainerAllocator>
struct Step_
{
  typedef Step_<ContainerAllocator> Type;

  Step_()
    : left_direction(false)
    , right_direction(false)
    , left_tick(0)
    , right_tick(0)  {
    }
  Step_(const ContainerAllocator& _alloc)
    : left_direction(false)
    , right_direction(false)
    , left_tick(0)
    , right_tick(0)  {
  (void)_alloc;
    }



   typedef uint8_t _left_direction_type;
  _left_direction_type left_direction;

   typedef uint8_t _right_direction_type;
  _right_direction_type right_direction;

   typedef int32_t _left_tick_type;
  _left_tick_type left_tick;

   typedef int32_t _right_tick_type;
  _right_tick_type right_tick;





  typedef boost::shared_ptr< ::chusa_msgs::Step_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::chusa_msgs::Step_<ContainerAllocator> const> ConstPtr;

}; // struct Step_

typedef ::chusa_msgs::Step_<std::allocator<void> > Step;

typedef boost::shared_ptr< ::chusa_msgs::Step > StepPtr;
typedef boost::shared_ptr< ::chusa_msgs::Step const> StepConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::chusa_msgs::Step_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::chusa_msgs::Step_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace chusa_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'chusa_msgs': ['/home/jaeho/clear/src/chusa_msgs/msg', '/home/jaeho/clear/src/chusa_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::chusa_msgs::Step_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::chusa_msgs::Step_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::chusa_msgs::Step_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::chusa_msgs::Step_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::chusa_msgs::Step_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::chusa_msgs::Step_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::chusa_msgs::Step_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3c83b4c05239125c562cc3ff37f7c899";
  }

  static const char* value(const ::chusa_msgs::Step_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3c83b4c05239125cULL;
  static const uint64_t static_value2 = 0x562cc3ff37f7c899ULL;
};

template<class ContainerAllocator>
struct DataType< ::chusa_msgs::Step_<ContainerAllocator> >
{
  static const char* value()
  {
    return "chusa_msgs/Step";
  }

  static const char* value(const ::chusa_msgs::Step_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::chusa_msgs::Step_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool left_direction\n"
"bool right_direction\n"
"int32 left_tick\n"
"int32 right_tick\n"
;
  }

  static const char* value(const ::chusa_msgs::Step_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::chusa_msgs::Step_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.left_direction);
      stream.next(m.right_direction);
      stream.next(m.left_tick);
      stream.next(m.right_tick);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Step_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::chusa_msgs::Step_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::chusa_msgs::Step_<ContainerAllocator>& v)
  {
    s << indent << "left_direction: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.left_direction);
    s << indent << "right_direction: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.right_direction);
    s << indent << "left_tick: ";
    Printer<int32_t>::stream(s, indent + "  ", v.left_tick);
    s << indent << "right_tick: ";
    Printer<int32_t>::stream(s, indent + "  ", v.right_tick);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CHUSA_MSGS_MESSAGE_STEP_H
