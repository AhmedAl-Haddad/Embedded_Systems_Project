#include "Bluetooth.h"

Bluetooth::Bluetooth(PinName tx, PinName rx) : bt(tx, rx) {
    bt.baud(9600);
    bt.attach(callback(this, &Bluetooth::interruptHandler), Serial::RxIrq);
}

void Bluetooth::setCallback(std::function<void(char)> cb) {
    callback = cb;
}

void Bluetooth::send(char data) {
    bt.putc(data);
}

void Bluetooth::interruptHandler() {
    if (callback) {
        callback(bt.getc());
    }
}