// Generated by gencpp from file chusa_msgs/StartArduinoResponse.msg
// DO NOT EDIT!


#ifndef CHUSA_MSGS_MESSAGE_STARTARDUINORESPONSE_H
#define CHUSA_MSGS_MESSAGE_STARTARDUINORESPONSE_H


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
struct StartArduinoResponse_
{
  typedef StartArduinoResponse_<ContainerAllocator> Type;

  StartArduinoResponse_()
    : rx_signal(false)  {
    }
  StartArduinoResponse_(const ContainerAllocator& _alloc)
    : rx_signal(false)  {
  (void)_alloc;
    }



   typedef uint8_t _rx_signal_type;
  _rx_signal_type rx_signal;





  typedef boost::shared_ptr< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> const> ConstPtr;

}; // struct StartArduinoResponse_

typedef ::chusa_msgs::StartArduinoResponse_<std::allocator<void> > StartArduinoResponse;

typedef boost::shared_ptr< ::chusa_msgs::StartArduinoResponse > StartArduinoResponsePtr;
typedef boost::shared_ptr< ::chusa_msgs::StartArduinoResponse const> StartArduinoResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace chusa_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'chusa_msgs': ['/home/jaeho/ros_code/src/chusa_odom/chusa_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b681db55aabf43c10d03f94a707c66ee";
  }

  static const char* value(const ::chusa_msgs::StartArduinoResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb681db55aabf43c1ULL;
  static const uint64_t static_value2 = 0x0d03f94a707c66eeULL;
};

template<class ContainerAllocator>
struct DataType< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "chusa_msgs/StartArduinoResponse";
  }

  static const char* value(const ::chusa_msgs::StartArduinoResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool rx_signal\n"
;
  }

  static const char* value(const ::chusa_msgs::StartArduinoResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.rx_signal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct StartArduinoResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::chusa_msgs::StartArduinoResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::chusa_msgs::StartArduinoResponse_<ContainerAllocator>& v)
  {
    s << indent << "rx_signal: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.rx_signal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CHUSA_MSGS_MESSAGE_STARTARDUINORESPONSE_H
