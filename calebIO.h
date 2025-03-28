#ifndef CALEBIO_H
#define CALEBIO_H

#include <stdint.h>
#include <Arduino.h>
#include "common.h"

class Pot {
public:
  uint8_t control_num; // MIDI CC control number

  Pot(uint8_t pin, uint8_t control_num);
  Pot(uint8_t pin, uint8_t control_num, uint8_t jitterFactor);
  uint8_t read(); 

  void update();

  bool has_changed();
  
private:
  uint16_t rawVal; // Raw pot value
  uint8_t pin; // arduino pin number
  uint8_t val; // pot value
  uint8_t jitterFactor; // Jitter factor
  bool hasChanged;
};

#endif //CALEBIO_H