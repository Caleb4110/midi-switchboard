#ifndef CALEBIO_H
#define CALEBIO_H

#include <stdint.h>
#include <Arduino.h>

class Pot {
  private:
  uint8_t pin;
  uint8_t val;

  public:
  Pot(uint8_t pin);
  uint8_t read();
  void update();
};

#endif //CALEBIO_H