#include "calebIO.h"

Pot::Pot(uint8_t pin) {
  this->pin = pin;
}

uint8_t Pot::read() {
  return this->val;
}

void Pot::update() {
  this->val = analogRead(this->pin);
}