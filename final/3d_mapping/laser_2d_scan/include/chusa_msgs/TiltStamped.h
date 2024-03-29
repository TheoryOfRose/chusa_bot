// Generated by gencpp from file chusa_msgs/TiltStamped.msg
// DO NOT EDIT!


#ifndef CHUSA_MSGS_MESSAGE_TILTSTAMPED_H
#define CHUSA_MSGS_MESSAGE_TILTSTAMPED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <chusa_msgs/Tilt.h>

namespace chusa_msgs
{
template <class ContainerAllocator>
struct TiltStamped_
{
  typedef TiltStamped_<ContainerAllocator> Type;

  TiltStamped_()
    : header()
    , tilt()  {
    }
  TiltStamped_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , tilt(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::chusa_msgs::Tilt_<ContainerAllocator>  _tilt_type;
  _tilt_type tilt;





  typedef boost::shared_ptr< ::chusa_msgs::TiltStamped_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::chusa_msgs::TiltStamped_<ContainerAllocator> const> ConstPtr;

}; // struct TiltStamped_

typedef ::chusa_msgs::TiltStamped_<std::allocator<void> > TiltStamped;

typedef boost::shared_ptr< ::chusa_msgs::TiltStamped > TiltStampedPtr;
typedef boost::shared_ptr< ::chusa_msgs::TiltStamped const> TiltStampedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::chusa_msgs::TiltStamped_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::chusa_msgs::TiltStamped_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace chusa_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'chusa_msgs': ['/home/jaeho/clear/src/chusa_msgs/msg', '/home/jaeho/clear/src/chusa_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::chusa_msgs::TiltStamped_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::chusa_msgs::TiltStamped_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::chusa_msgs::TiltStamped_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::chusa_msgs::TiltStamped_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::chusa_msgs::TiltStamped_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::chusa_msgs::TiltStamped_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::chusa_msgs::TiltStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "469c1168b448dffae3d094d23670e9af";
  }

  static const char* value(const ::chusa_msgs::TiltStamped_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x469c1168b448dffaULL;
  static const uint64_t static_value2 = 0xe3d094d23670e9afULL;
};

template<class ContainerAllocator>
struct DataType< ::chusa_msgs::TiltStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "chusa_msgs/TiltStamped";
  }

  static const char* value(const ::chusa_msgs::TiltStamped_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::chusa_msgs::TiltStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"Tilt tilt\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: chusa_msgs/Tilt\n"
"int32 tick\n"
;
  }

  static const char* value(const ::chusa_msgs::TiltStamped_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::chusa_msgs::TiltStamped_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.tilt);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TiltStamped_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::chusa_msgs::TiltStamped_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::chusa_msgs::TiltStamped_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "tilt: ";
    s << std::endl;
    Printer< ::chusa_msgs::Tilt_<ContainerAllocator> >::stream(s, indent + "  ", v.tilt);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CHUSA_MSGS_MESSAGE_TILTSTAMPED_H
