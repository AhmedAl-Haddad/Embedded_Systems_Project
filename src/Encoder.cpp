#include "Encoder.h"

Encoder::Encoder(PinName channelA, PinName channelB, int pulsesPerRev) 
    : qei(channelA, channelB, NC, pulsesPerRev) {}

int Encoder::getPulses() {
    return qei.getPulses(); // Return number of pulses counted
}

void Encoder::reset() {
    qei.reset(); // Reset encoder count
}