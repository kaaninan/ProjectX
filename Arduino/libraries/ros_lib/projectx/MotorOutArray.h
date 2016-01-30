#ifndef _ROS_projectx_MotorOutArray_h
#define _ROS_projectx_MotorOutArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace projectx
{

  class MotorOutArray : public ros::Msg
  {
    public:
      uint8_t id_length;
      int64_t st_id;
      int64_t * id;
      uint8_t pos_length;
      int64_t st_pos;
      int64_t * pos;
      uint8_t speed_length;
      int64_t st_speed;
      int64_t * speed;
      uint8_t torque_length;
      int64_t st_torque;
      int64_t * torque;
      uint8_t rw_length;
      int64_t st_rw;
      int64_t * rw;
      uint8_t action_length;
      int64_t st_action;
      int64_t * action;

    MotorOutArray():
      id_length(0), id(NULL),
      pos_length(0), pos(NULL),
      speed_length(0), speed(NULL),
      torque_length(0), torque(NULL),
      rw_length(0), rw(NULL),
      action_length(0), action(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = id_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < id_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_idi;
      u_idi.real = this->id[i];
      *(outbuffer + offset + 0) = (u_idi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_idi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_idi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_idi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_idi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->id[i]);
      }
      *(outbuffer + offset++) = pos_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_posi;
      u_posi.real = this->pos[i];
      *(outbuffer + offset + 0) = (u_posi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_posi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_posi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_posi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_posi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_posi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_posi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_posi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pos[i]);
      }
      *(outbuffer + offset++) = speed_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < speed_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_speedi;
      u_speedi.real = this->speed[i];
      *(outbuffer + offset + 0) = (u_speedi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speedi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speedi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speedi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_speedi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_speedi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_speedi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_speedi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->speed[i]);
      }
      *(outbuffer + offset++) = torque_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < torque_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_torquei;
      u_torquei.real = this->torque[i];
      *(outbuffer + offset + 0) = (u_torquei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_torquei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_torquei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_torquei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_torquei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_torquei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_torquei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_torquei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->torque[i]);
      }
      *(outbuffer + offset++) = rw_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rw_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_rwi;
      u_rwi.real = this->rw[i];
      *(outbuffer + offset + 0) = (u_rwi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rwi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rwi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rwi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rwi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rwi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rwi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rwi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rw[i]);
      }
      *(outbuffer + offset++) = action_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < action_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_actioni;
      u_actioni.real = this->action[i];
      *(outbuffer + offset + 0) = (u_actioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_actioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_actioni.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_actioni.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_actioni.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_actioni.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_actioni.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->action[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t id_lengthT = *(inbuffer + offset++);
      if(id_lengthT > id_length)
        this->id = (int64_t*)realloc(this->id, id_lengthT * sizeof(int64_t));
      offset += 3;
      id_length = id_lengthT;
      for( uint8_t i = 0; i < id_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_id;
      u_st_id.base = 0;
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_id = u_st_id.real;
      offset += sizeof(this->st_id);
        memcpy( &(this->id[i]), &(this->st_id), sizeof(int64_t));
      }
      uint8_t pos_lengthT = *(inbuffer + offset++);
      if(pos_lengthT > pos_length)
        this->pos = (int64_t*)realloc(this->pos, pos_lengthT * sizeof(int64_t));
      offset += 3;
      pos_length = pos_lengthT;
      for( uint8_t i = 0; i < pos_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_pos;
      u_st_pos.base = 0;
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_pos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_pos = u_st_pos.real;
      offset += sizeof(this->st_pos);
        memcpy( &(this->pos[i]), &(this->st_pos), sizeof(int64_t));
      }
      uint8_t speed_lengthT = *(inbuffer + offset++);
      if(speed_lengthT > speed_length)
        this->speed = (int64_t*)realloc(this->speed, speed_lengthT * sizeof(int64_t));
      offset += 3;
      speed_length = speed_lengthT;
      for( uint8_t i = 0; i < speed_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_speed;
      u_st_speed.base = 0;
      u_st_speed.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_speed.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_speed.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_speed.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_speed.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_speed.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_speed.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_speed.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_speed = u_st_speed.real;
      offset += sizeof(this->st_speed);
        memcpy( &(this->speed[i]), &(this->st_speed), sizeof(int64_t));
      }
      uint8_t torque_lengthT = *(inbuffer + offset++);
      if(torque_lengthT > torque_length)
        this->torque = (int64_t*)realloc(this->torque, torque_lengthT * sizeof(int64_t));
      offset += 3;
      torque_length = torque_lengthT;
      for( uint8_t i = 0; i < torque_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_torque;
      u_st_torque.base = 0;
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_torque = u_st_torque.real;
      offset += sizeof(this->st_torque);
        memcpy( &(this->torque[i]), &(this->st_torque), sizeof(int64_t));
      }
      uint8_t rw_lengthT = *(inbuffer + offset++);
      if(rw_lengthT > rw_length)
        this->rw = (int64_t*)realloc(this->rw, rw_lengthT * sizeof(int64_t));
      offset += 3;
      rw_length = rw_lengthT;
      for( uint8_t i = 0; i < rw_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_rw;
      u_st_rw.base = 0;
      u_st_rw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_rw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_rw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_rw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_rw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_rw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_rw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_rw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_rw = u_st_rw.real;
      offset += sizeof(this->st_rw);
        memcpy( &(this->rw[i]), &(this->st_rw), sizeof(int64_t));
      }
      uint8_t action_lengthT = *(inbuffer + offset++);
      if(action_lengthT > action_length)
        this->action = (int64_t*)realloc(this->action, action_lengthT * sizeof(int64_t));
      offset += 3;
      action_length = action_lengthT;
      for( uint8_t i = 0; i < action_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_action;
      u_st_action.base = 0;
      u_st_action.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_action.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_action.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_action.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_action.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_action.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_action.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_action.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_action = u_st_action.real;
      offset += sizeof(this->st_action);
        memcpy( &(this->action[i]), &(this->st_action), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "projectx/MotorOutArray"; };
    const char * getMD5(){ return "b23b46468244cd9fc2bd0e16a8568772"; };

  };

}
#endif