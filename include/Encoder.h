#ifndef ENCODER_H
#define ENCODER_H

#include "mbed.h"
#include "QEI.h"

class Encoder {
public:
    QEI qei;

    Encoder(PinName channelA, PinName channelB, int pulsesPerRev);
    int getPulses();
    void reset();
};

#endif