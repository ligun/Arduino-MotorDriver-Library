#include<stdlib.h>
#include"arduino.h"
#include "MotorDriver.h"

MotorDriver::MotorDriver(){}

MotorDriver::MotorDriver(int8_t motor_pin1,int8_t motor_pin2,int8_t pwm_pin){
  init(motor_pin1,motor_pin2,pwm_pin);
}

void MotorDriver::init(int8_t motor_pin1,int8_t motor_pin2,int8_t pwm_pin){
  this -> motor_pin1 = motor_pin1;
  this -> motor_pin2 = motor_pin2;
  this -> pwm_pin = pwm_pin;

  pinMode(this -> motor_pin1,OUTPUT);
  pinMode(this -> motor_pin2,OUTPUT);
  if(this -> pwm_pin >= 0){
    pinMode(this -> pwm_pin,OUTPUT);
  }
}

void MotorDriver::drive(DRIVE_MODE mode,uint8_t speed){
  switch(mode){
    case FORWARD:
  	this -> forward(speed);
    break;
    case REVERSE:
  	this -> reverse(speed);
    break;
    case STOP:
  	this -> stop();
    break;
    case BRAKE:
  	this -> brake();
    break;
  }
  if(this -> pwm_pin >= 0){
    analogWrite(this -> pwm_pin,speed);
  }
}

void MotorDriver::forward(uint8_t speed){
  digitalWrite(this -> motor_pin1,HIGH);
  digitalWrite(this -> motor_pin2,LOW);
  if(this -> pwm_pin >= 0){
    analogWrite(this -> pwm_pin,speed);
  }
}

void MotorDriver::reverse(uint8_t speed){
  digitalWrite(this -> motor_pin1,LOW);
  digitalWrite(this -> motor_pin2,HIGH);
  if(this -> pwm_pin >= 0){
    analogWrite(this -> pwm_pin,speed);
  }
}

void MotorDriver::stop(){
  digitalWrite(this -> motor_pin1,LOW);
  digitalWrite(this -> motor_pin2,LOW);
}

void MotorDriver::brake(){
  digitalWrite(this -> motor_pin1,HIGH);
  digitalWrite(this -> motor_pin2,HIGH);
}
