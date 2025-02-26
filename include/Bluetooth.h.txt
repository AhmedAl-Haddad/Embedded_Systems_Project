#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "mbed.h"
#include <functional>

class Bluetooth {
public:
    Serial bt;
    std::function<void(char)> callback;

    Bluetooth(PinName tx, PinName rx);
    void setCallback(std::function<void(char)> cb);
    void send(char data);

private:
    void interruptHandler();
};

#endif