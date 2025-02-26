#ifndef ROBOT_H
#define ROBOT_H

#include "mbed.h"
#include "PID.h"
#include "Bluetooth.h"
#include "Motor.h"
#include "Encoder.h"
#include "Sensor.h"

class Robot {
public:
    Motor leftMotor, rightMotor;
    Encoder leftEncoder, rightEncoder;
    Sensor leftSensor, leftSensor1, middleSensor, rightSensor, rightSensor1;
    PID pid;
    Bluetooth bt;
    DigitalOut L1, L2, L3, L4, L5, Bipolar1, Bipolar2;
    Serial pc;

    float baseSpeedL, baseSpeedR;
    const float maxSpeed = 0.95f, minSpeed = 0.6f;

    Robot(float Kp, float Ki, float Kd, float baseSpeedL = 0.825f, float baseSpeedR = 0.825f, float dt = 0.005f);
    void btInterruptHandler(char s);
    void enableMotors();
    void disableMotors();
    float calculateError(float left, float left1, float right, float right1);
    void run();
};

#endif