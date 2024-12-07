#ifndef CALEBIO_H
#define CALEBIO_H

#include <stdint.h>
#include <Arduino.h>
#include "common.h"

class Pot {
  private:
  uint8_t pin; // arduino pin number
  uint8_t val; // pot value

  public:
  uint8_t control_num; // MIDI CC control number

  Pot(uint8_t pin, uint8_t control_num);
  uint8_t read();
  void update();
};

#endif //CALEBIO_H