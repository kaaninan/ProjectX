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
      int64_t speed;
      int64_t torque;
      int64_t rw;
      int64_t action;

    MotorOut():
      id(0),
      pos(0),
      speed(0),
      torque(0),
      rw(0),
      action(0)
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
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_speed.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_speed.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_speed.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_speed.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->speed);
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
      union {
        int64_t real;
        uint64_t base;
      } u_rw;
      u_rw.real = this->rw;
      *(outbuffer + offset + 0) = (u_rw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rw);
      union {
        int64_t real;
        uint64_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_action.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_action.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_action.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_action.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_action.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_action.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_action.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->action);
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
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
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
      union {
        int64_t real;
        uint64_t base;
      } u_rw;
      u_rw.base = 0;
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rw = u_rw.real;
      offset += sizeof(this->rw);
      union {
        int64_t real;
        uint64_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_action.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_action.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_action.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_action.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_action.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_action.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_action.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->action = u_action.real;
      offset += sizeof(this->action);
     return offset;
    }

    const char * getType(){ return "projectx/MotorOut"; };
    const char * getMD5(){ return "1c569e6a2d73436766c3b4d4f657523e"; };

  };

}
#endif