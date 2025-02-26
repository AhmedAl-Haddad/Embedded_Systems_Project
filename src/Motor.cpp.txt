#include "Motor.h"

Motor::Motor(PinName pwmPin, PinName enablePin) : pwm(pwmPin), enable(enablePin) {
    pwm.period_us(50);
    enable = 1; // Enable motor by default
}

void Motor::setSpeed(float speed) {
    pwm.write(speed); // Set motor speed using PWM
}