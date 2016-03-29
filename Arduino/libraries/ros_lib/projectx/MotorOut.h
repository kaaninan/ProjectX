#ifndef _ROS_projectx_MotorOut_h
#define _ROS_projectx_MotorOut_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class MotorOut : public ros::Msg
  {
    public:
      int64_t id;
      int64_t pos;
      int64_t torque;

    MotorOut():
      id(0),
      pos(0),
      torque(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int64_t real;
        uint64_t base;
      } u_pos;
      u_pos.real = this->pos;
      *(outbuffer + offset + 0) = (u_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pos.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pos.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pos.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pos.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pos);
      union {
        int64_t real;
        uint64_t base;
      } u_torque;
      u_torque.real = this->torque;
      *(outbuffer + offset + 0) = (u_torque.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_torque.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_torque.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_torque.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_torque.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_torque.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_torque.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_torque.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->torque);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int64_t real;
        uint64_t base;
      } u_pos;
      u_pos.base = 0;
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pos = u_pos.real;
      offset += sizeof(this->pos);
      union {
        int64_t real;
        uint64_t base;
      } u_torque;
      u_torque.base = 0;
      u_torque.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_torque.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_torque.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_torque.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_torque.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_torque.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_torque.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_torque.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->torque = u_torque.real;
      offset += sizeof(this->torque);
     return offset;
    }

    const char * getType(){ return "projectx/MotorOut"; };
    const char * getMD5(){ return "5430fc9361c2337213e0d90db94db2ad"; };

  };

}
#endif