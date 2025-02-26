#ifndef MOTOR_H
#define MOTOR_H

#include "mbed.h"

class Motor {
public:
    PwmOut pwm;
    DigitalOut enable;

    Motor(PinName pwmPin, PinName enablePin);
    void setSpeed(float speed);
};

#endif