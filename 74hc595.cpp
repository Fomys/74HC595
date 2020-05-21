#include "74hc595.h"


void ShiftRegister::setup() {
    pinMode(this->p_ser, OUTPUT);
    pinMode(this->p_rclk, OUTPUT);
    pinMode(this->p_srclk, OUTPUT);

}

// Envoi d'une donnée de 8 bits
void ShiftRegister::write(char data) {
    digitalWrite(this->p_rclk, LOW);
    uint8_t i;
    for (i = 0; i < 8; i++)  {
        this->shift((data & (1 << i)) != 0);
    }
    digitalWrite(this->p_rclk, HIGH);
}

void ShiftRegister::shift(bool next) {
    digitalWrite(this->p_srclk, LOW);
    digitalWrite(this->p_ser, next);
    digitalWrite(this->p_srclk, HIGH);
}

ShiftRegister::ShiftRegister(int p_ser, int p_srclk, int p_rclk): p_ser(p_ser), p_srclk(p_srclk), p_rclk(p_rclk) {

}
