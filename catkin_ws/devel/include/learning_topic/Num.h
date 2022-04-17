// Generated by gencpp from file learning_topic/Num.msg
// DO NOT EDIT!


#ifndef LEARNING_TOPIC_MESSAGE_NUM_H
#define LEARNING_TOPIC_MESSAGE_NUM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace learning_topic
{
template <class ContainerAllocator>
struct Num_
{
  typedef Num_<ContainerAllocator> Type;

  Num_()
    : num(0)
    , first_name()
    , last_name()
    , age(0)
    , score(0)  {
    }
  Num_(const ContainerAllocator& _alloc)
    : num(0)
    , first_name(_alloc)
    , last_name(_alloc)
    , age(0)
    , score(0)  {
  (void)_alloc;
    }



   typedef int64_t _num_type;
  _num_type num;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _first_name_type;
  _first_name_type first_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _last_name_type;
  _last_name_type last_name;

   typedef uint8_t _age_type;
  _age_type age;

   typedef uint32_t _score_type;
  _score_type score;





  typedef boost::shared_ptr< ::learning_topic::Num_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::learning_topic::Num_<ContainerAllocator> const> ConstPtr;

}; // struct Num_

typedef ::learning_topic::Num_<std::allocator<void> > Num;

typedef boost::shared_ptr< ::learning_topic::Num > NumPtr;
typedef boost::shared_ptr< ::learning_topic::Num const> NumConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::learning_topic::Num_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::learning_topic::Num_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::learning_topic::Num_<ContainerAllocator1> & lhs, const ::learning_topic::Num_<ContainerAllocator2> & rhs)
{
  return lhs.num == rhs.num &&
    lhs.first_name == rhs.first_name &&
    lhs.last_name == rhs.last_name &&
    lhs.age == rhs.age &&
    lhs.score == rhs.score;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::learning_topic::Num_<ContainerAllocator1> & lhs, const ::learning_topic::Num_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace learning_topic

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::learning_topic::Num_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::learning_topic::Num_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_topic::Num_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::learning_topic::Num_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_topic::Num_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::learning_topic::Num_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::learning_topic::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "379cbe21d44c48c3d9a5a30aa0ddaafb";
  }

  static const char* value(const ::learning_topic::Num_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x379cbe21d44c48c3ULL;
  static const uint64_t static_value2 = 0xd9a5a30aa0ddaafbULL;
};

template<class ContainerAllocator>
struct DataType< ::learning_topic::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "learning_topic/Num";
  }

  static const char* value(const ::learning_topic::Num_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::learning_topic::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 num\n"
"string first_name\n"
"string last_name\n"
"uint8 age\n"
"uint32 score\n"
;
  }

  static const char* value(const ::learning_topic::Num_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::learning_topic::Num_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.num);
      stream.next(m.first_name);
      stream.next(m.last_name);
      stream.next(m.age);
      stream.next(m.score);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Num_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::learning_topic::Num_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::learning_topic::Num_<ContainerAllocator>& v)
  {
    s << indent << "num: ";
    Printer<int64_t>::stream(s, indent + "  ", v.num);
    s << indent << "first_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.first_name);
    s << indent << "last_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.last_name);
    s << indent << "age: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.age);
    s << indent << "score: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.score);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LEARNING_TOPIC_MESSAGE_NUM_H
