#ifndef _ROS_SERVICE_SetPhysicsProperties_h
#define _ROS_SERVICE_SetPhysicsProperties_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "gazebo_msgs/ODEPhysics.h"

namespace gazebo_msgs
{

static const char SETPHYSICSPROPERTIES[] = "gazebo_msgs/SetPhysicsProperties";

  class SetPhysicsPropertiesRequest : public ros::Msg
  {
    public:
      double time_step;
      double max_update_rate;
      geometry_msgs::Vector3 gravity;
      gazebo_msgs::ODEPhysics ode_config;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_time_step;
      u_time_step.real = this->time_step;
      *(outbuffer + offset + 0) = (u_time_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_step.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_step.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_step.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_time_step.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_time_step.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_time_step.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_time_step.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->time_step);
      union {
        double real;
        uint64_t base;
      } u_max_update_rate;
      u_max_update_rate.real = this->max_update_rate;
      *(outbuffer + offset + 0) = (u_max_update_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_update_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_update_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_update_rate.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_update_rate.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_update_rate.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_update_rate.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_update_rate.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_update_rate);
      offset += this->gravity.serialize(outbuffer + offset);
      offset += this->ode_config.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_time_step;
      u_time_step.base = 0;
      u_time_step.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_step.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_step.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_step.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_time_step.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_time_step.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_time_step.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_time_step.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->time_step = u_time_step.real;
      offset += sizeof(this->time_step);
      union {
        double real;
        uint64_t base;
      } u_max_update_rate;
      u_max_update_rate.base = 0;
      u_max_update_rate.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_update_rate.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_update_rate.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_update_rate.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_update_rate.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_update_rate.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_update_rate.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_update_rate.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_update_rate = u_max_update_rate.real;
      offset += sizeof(this->max_update_rate);
      offset += this->gravity.deserialize(inbuffer + offset);
      offset += this->ode_config.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETPHYSICSPROPERTIES; };
    const char * getMD5(){ return "abd9f82732b52b92e9d6bb36e6a82452"; };

  };

  class SetPhysicsPropertiesResponse : public ros::Msg
  {
    public:
      bool success;
      const char* status_message;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_status_message = strlen(this->status_message);
      memcpy(outbuffer + offset, &length_status_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_status_message);
      offset += length_status_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status_message;
      memcpy(&length_status_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_message-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_status_message;
     return offset;
    }

    const char * getType(){ return SETPHYSICSPROPERTIES; };
    const char * getMD5(){ return "2ec6f3eff0161f4257b808b12bc830c2"; };

  };

  class SetPhysicsProperties {
    public:
    typedef SetPhysicsPropertiesRequest Request;
    typedef SetPhysicsPropertiesResponse Response;
  };

}
#endif
