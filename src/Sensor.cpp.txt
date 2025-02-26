#include "Sensor.h"

Sensor::Sensor(PinName pin) : sensor(pin) {}

float Sensor::read() {
    return 3.3f * sensor.read(); // Read sensor value and scale to voltage
}