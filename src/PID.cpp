#include "PID.h"

float PID::compute(float setpoint, float measured) {
    float error = setpoint - measured;
    integral += error * dt;
    float derivative = (error - prevError) / dt;
    prevError = error;
    return (Kp * error) + (Ki * integral) + (Kd * derivative);
}