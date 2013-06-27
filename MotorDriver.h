#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <stdint.h>

typedef enum {
  FORWARD,
  REVERSE,
  STOP,
  BRAKE,
}DRIVE_MODE;

class MotorDriver{
 private:
  int8_t motor_pin1,motor_pin2,pwm_pin;

 public:
  MotorDriver();
  MotorDriver(int8_t,int8_t,int8_t = -1);
  void init(int8_t,int8_t,int8_t = -1);
  void drive(DRIVE_MODE,uint8_t = 255);
  void forward(uint8_t = 255);
  void reverse(uint8_t = 255);
  void stop();
  void brake();
};

#endif
