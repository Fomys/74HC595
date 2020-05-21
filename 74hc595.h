#include <Arduino.h>

#ifndef _74HC595_H_
#define _74HC595_H_

class ShiftRegister {
public:
    ShiftRegister(int p_ser, int p_srclk, int p_rclk);

    void setup();

    void write(char data);

    void shift(bool next);

    void shift() { this->shift(false); };
private:
    // Pins
    int p_ser;
    int p_srclk;
    int p_rclk;
};

#endif //_74HC595_H_
