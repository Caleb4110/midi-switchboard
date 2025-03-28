#include "Arduino.h"
#include "calebIO.h"

Pot::Pot(uint8_t pin, uint8_t control_num) {
  this->pin = pin;
  this->control_num = control_num;
  this->jitterFactor = 2;
  this->val = map(analogRead(this->pin), 0, 255, 0, 127);
  this->hasChanged = true;
}

Pot::Pot(uint8_t pin, uint8_t control_num, uint8_t jitterFactor) {
  this->pin = pin;
  this->control_num = control_num;
  this->jitterFactor = jitterFactor;
  this->val = map(analogRead(this->pin), 0, 255, 0, 127);
  this->hasChanged = true;
}

uint8_t Pot::read() {
  return this->val;
}

bool Pot::has_changed() {
  return hasChanged;
}

// Normalise pot value from 0-127 (MIDI CC values are 0-127)
void Pot::update() {
  uint16_t read = analogRead(pin);
  if (abs(read - rawVal) > jitterFactor) {
    Serial.print("OLD: ");
    Serial.println(rawVal);
    Serial.print("NEW: ");
    Serial.println(read);
    rawVal = read;
    val = map(read, 0, 1024, 0, 127);
    hasChanged = true;
  } else {
    hasChanged = false;
  }
}