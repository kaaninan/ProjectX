// Generated by gencpp from file projectx/Pin.msg
// DO NOT EDIT!


#ifndef PROJECTX_MESSAGE_PIN_H
#define PROJECTX_MESSAGE_PIN_H

#include <ros/service_traits.h>


#include <projectx/PinRequest.h>
#include <projectx/PinResponse.h>


namespace projectx
{

struct Pin
{

typedef PinRequest Request;
typedef PinResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Pin
} // namespace projectx


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::projectx::Pin > {
  static const char* value()
  {
    return "4c2da9f3044fef1a8aa9af34b73c7dbd";
  }

  static const char* value(const ::projectx::Pin&) { return value(); }
};

template<>
struct DataType< ::projectx::Pin > {
  static const char* value()
  {
    return "projectx/Pin";
  }

  static const char* value(const ::projectx::Pin&) { return value(); }
};


// service_traits::MD5Sum< ::projectx::PinRequest> should match 
// service_traits::MD5Sum< ::projectx::Pin > 
template<>
struct MD5Sum< ::projectx::PinRequest>
{
  static const char* value()
  {
    return MD5Sum< ::projectx::Pin >::value();
  }
  static const char* value(const ::projectx::PinRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::projectx::PinRequest> should match 
// service_traits::DataType< ::projectx::Pin > 
template<>
struct DataType< ::projectx::PinRequest>
{
  static const char* value()
  {
    return DataType< ::projectx::Pin >::value();
  }
  static const char* value(const ::projectx::PinRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::projectx::PinResponse> should match 
// service_traits::MD5Sum< ::projectx::Pin > 
template<>
struct MD5Sum< ::projectx::PinResponse>
{
  static const char* value()
  {
    return MD5Sum< ::projectx::Pin >::value();
  }
  static const char* value(const ::projectx::PinResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::projectx::PinResponse> should match 
// service_traits::DataType< ::projectx::Pin > 
template<>
struct DataType< ::projectx::PinResponse>
{
  static const char* value()
  {
    return DataType< ::projectx::Pin >::value();
  }
  static const char* value(const ::projectx::PinResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PROJECTX_MESSAGE_PIN_H