#include "Arduino.h"
#include "calebIO.h"

//=========== POTENTIOMETER CLASS ===========
Pot::Pot(uint8_t pin, uint8_t ccNum) {
  pin_ = pin;
  ccNum_ = ccNum;
  jitterFactor_ = 2;
  val_ = map(analogRead(pin_), 0, 255, 0, 127);
  hasChanged_ = true;
}

Pot::Pot(uint8_t pin, uint8_t ccNum, uint8_t jitterFactor) {
  pin_ = pin;
  ccNum_ = ccNum;
  jitterFactor_ = jitterFactor;
  val_ = map(analogRead(pin_), 0, 255, 0, 127);
  hasChanged_ = true;
}

uint8_t Pot::read() {
  return val_;
}

uint8_t Pot::getCcNum() {
  return ccNum_;
}

bool Pot::hasChanged() {
  return hasChanged_;
}

void Pot::update() {
  uint16_t read = analogRead(pin_);
  if (abs(read - rawVal_) > jitterFactor_) {
    rawVal_ = read;
    val_ = map(read, 0, 1024, 0, 127);
    hasChanged_ = true;
  } else {
    hasChanged_ = false;
  }
}
//===========================================

//============== SWITCH CLASS ===============
Switch::Switch(uint8_t pin, uint8_t ccNum) {
  pin_ = pin;
  ccNum_ = ccNum;
  lastValue_ = true;
  pinMode(pin_, INPUT_PULLUP);
  value_ = digitalRead(pin_);
}

uint8_t Switch::read() {
  return value_;
}

uint8_t Switch::getCcNum() {
  return ccNum_;
}

void Switch::update() {
  value_ = digitalRead(pin_);
}

Event Switch::readEvent() {
  update();

  Event event = NoEvent;

  if (lastValue_ != value_) {
    if (value_) {
      // Released
      if (!isLongPress_) {
        event = Click;
      }
    } else {
      // Pressed
      pressTimeMs_ = millis();
      isLongPress_ = false;
    }
    lastValue_ = value_;
  }

  if (
    // Currently pressed
    !value_ && 
    // Exceeded long press time
    (millis() - pressTimeMs_) > 500 && 
    // Not yet classified as a long press
    !isLongPress_) {
      isLongPress_ = true;
      event = LongPress;
  }

  return event;
}
//===========================================

//========== MODULE SWITCH CLASS ============
ModuleSwitch::ModuleSwitch(uint8_t pin, uint8_t ccNum)
  : Switch(pin, ccNum) {
  currEffect_ = 0; // Start with first effect
}

void ModuleSwitch::incrEffect() {
  currEffect_ = (currEffect_ + 1) % 6;
}

void ModuleSwitch::decrEffect() {
  if (currEffect_ == 0) {
    currEffect_ = 5;
  } else {
    currEffect_ = (currEffect_ - 1) % 6;
  }
}

uint8_t ModuleSwitch::getCurrEffect() {
  return currEffect_;
}
//===========================================




