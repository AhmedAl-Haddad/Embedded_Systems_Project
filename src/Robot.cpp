#include "Robot.h"

Robot::Robot(float Kp, float Ki, float Kd, float baseSpeedL, float baseSpeedR, float dt) 
    : leftMotor(PC_7, PB_9), rightMotor(PA_9, PB_9),
      leftEncoder(PC_0, PC_4, 512), rightEncoder(PC_8, PA_10, 512),
      leftSensor(A4), leftSensor1(A3), middleSensor(A2), rightSensor(A1), rightSensor1(A0),
      pid(Kp, Ki, Kd, dt), bt(PA_11, PA_12),
      L1(PB_13), L2(PB_14), L3(PB_15), L4(PB_1), L5(PB_2), Bipolar1(PB_8), Bipolar2(PA_6),
      pc(USBTX, USBRX),
      baseSpeedL(baseSpeedL), baseSpeedR(baseSpeedR) {
    pc.baud(9600);
    bt.setCallback(callback(this, &Robot::btInterruptHandler));
}

void Robot::btInterruptHandler(char s) {
    pc.putc(s);
    if (s == '1') {
        enableMotors();
        leftMotor.setSpeed(0.7);
        rightMotor.setSpeed(0.15);
        wait(0.35);
        while (middleSensor.read() < 0.12) {
            leftMotor.setSpeed(0.7);
            rightMotor.setSpeed(0.15);
        }
        leftMotor.setSpeed(0.5);
        rightMotor.setSpeed(0.5);
    } else if (s == '0') {
        disableMotors();
    }
}

void Robot::enableMotors() {
    leftMotor.enable = 1;
    rightMotor.enable = 1;
}

void Robot::disableMotors() {
    leftMotor.enable = 0;
    rightMotor.enable = 0;
}

float Robot::calculateError(float left, float left1, float right, float right1) {
    return (left + left1) - (right + right1);
}

void Robot::run() {
    while (1) {
        float sLeft = leftSensor.read();
        float sLeft1 = leftSensor1.read();
        float sMiddle = middleSensor.read();
        float sRight = rightSensor.read();
        float sRight1 = rightSensor1.read();
        
        float error = calculateError(sLeft, sLeft1, sRight, sRight1);
        float pidOutput = pid.compute(0.0f, error);
        
        float leftSpeed = baseSpeedL - pidOutput;
        float rightSpeed = baseSpeedR + pidOutput;
        
        leftMotor.setSpeed(leftSpeed);
        rightMotor.setSpeed(rightSpeed);
        wait(pid.dt);
        leftEncoder.reset();
        rightEncoder.reset();
    }
}