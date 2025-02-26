#ifndef SENSOR_H
#define SENSOR_H

#include "mbed.h"

class Sensor {
public:
    AnalogIn sensor;

    Sensor(PinName pin);
    float read();
};

#endif