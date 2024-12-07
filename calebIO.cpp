#include "Arduino.h"
#include "calebIO.h"

Pot::Pot(uint8_t pin, uint8_t control_num) {
  this->pin = pin;
  this->control_num = control_num;
}

uint8_t Pot::read() {
  return this->val;
}

// Normalise pot value from 0-127 (MIDI CC values are 0-127)
void Pot::update() {
  uint8_t read = analogRead(this->pin);
  this->val = map(read, 0, 255, 0, 127);
}