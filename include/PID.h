#ifndef PID_H
#define PID_H

class PID {
public:
    float Kp, Ki, Kd;
    float prevError, integral;
    float dt;
    
    PID(float Kp, float Ki, float Kd, float dt) : Kp(Kp), Ki(Ki), Kd(Kd), prevError(0.0f), integral(0.0f), dt(dt) {}
    
    float compute(float setpoint, float measured);
};

#endif