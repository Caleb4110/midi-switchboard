#ifndef CALEBIO_H
#define CALEBIO_H

#include <stdint.h>
#include <Arduino.h>

// Possible Switch events
enum Event {
  NoEvent,
  Click,
  LongPress,
};

// Effects list with associated CC numbers
const uint8_t effects[6] = {
  0,
  22,
  44,
  66,
  88,
  110,
};

//=========== POTENTIOMETER CLASS ===========
class Pot {
public:
  Pot(uint8_t pin, uint8_t ccNum);
  Pot(uint8_t pin, uint8_t ccNum, uint8_t jitterFactor);

  uint8_t read();
  uint8_t getCcNum();
  void update();

  bool hasChanged();

private:
  uint16_t rawVal_;        // Raw pot value
  uint8_t pin_;            // Arduino pin number
  uint8_t val_;            // Pot value
  uint8_t jitterFactor_;   // Jitter factor
  uint8_t ccNum_;          // MIDI CC number
  bool hasChanged_;        // Flag for value change
};
//===========================================

//============== SWITCH CLASS ===============
class Switch {
public:
  Switch(uint8_t pin, uint8_t ccNum);

  uint8_t read();
  uint8_t getCcNum();
  Event readEvent();

private:
  void update();

  uint8_t pin_;               // Arduino pin number
  bool value_;                // Switch current value
  bool lastValue_;            // Last switch value
  unsigned long pressTimeMs_; // Time of the current press
  bool isLongPress_;          // Flag for long press detection
  uint8_t ccNum_;             // MIDI CC number
};
//===========================================

//========== MODULE SWITCH CLASS ============
class ModuleSwitch : public Switch {
public:
  ModuleSwitch(uint8_t pin, uint8_t ccNum);

  void incrEffect(); // Next effect
  void decrEffect(); // Previous effect
  uint8_t getCurrEffect();

private:
  uint8_t currEffect_; // Current effect index
};
//===========================================

#endif // CALEBIO_H
