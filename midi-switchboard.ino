#include "calebIO.h"
#include <stdint.h>
#include "common.h"
#include <Encoder.h>
#include <Wire.h>

// Initialise module switches
ModuleSwitch switches[NUM_MODULES] = {
  ModuleSwitch(CHAR_SW_PIN, CHAR_SW_CC),
  // ModuleSwitch(MOV_SW_PIN, MOV_SW_CC),
  // ModuleSwitch(DIFF_SW_PIN, DIFF_SW_CC),
  // ModuleSwitch(TEX_SW_PIN, TEX_SW_CC),
};

// Initialise potentiometers
Pot pots[NUM_MODULES] = {
  Pot(CHAR_VOL_PIN, CHAR_VOL_CC, 5),
  // Pot(MOV_VOL_PIN, MOV_VOL_CC),
  // Pot(DIFF_VOL_PIN, DIFF_VOL_CC),
  // Pot(TEX_VOL_PIN, TEX_VOL_CC),
};

// Update all pots at once
void updateControls() {
  for (uint8_t i = 0; i < NUM_MODULES; i++) {
    pots[i].update();
  }
}

// Send MIDI to the DIN connector
void sendMIDI(uint8_t type, uint8_t channel, uint8_t data1, uint8_t data2) {
  uint8_t status = 0x80 | (type << 4) | channel;

  Serial.write(status);
  Serial.write(data1);
  Serial.write(data2);
}

void setup() {
  Serial.begin(31250); // MIDI standard baud rate
}

void loop() {
  // Update all control values
  updateControls();

  // Loop through each effect module
  for (uint8_t i = 0; i < NUM_MODULES; i++) {
    // Send MIDI CC if pot value changed
    if (pots[i].hasChanged()) {
      sendMIDI(ControlChange, MIDI_CHANNEL, pots[i].getCcNum(), pots[i].read());
    }

    // Send MIDI CC if switch event occurred
    Event event = switches[i].readEvent();
    switch (event) {
      case NoEvent:
        break;

      case Click:
        switches[i].incrEffect();
        sendMIDI(ControlChange, MIDI_CHANNEL, switches[i].getCcNum(), effects[switches[i].getCurrEffect()]);
        break;

      case LongPress:
        switches[i].decrEffect();
        sendMIDI(ControlChange, MIDI_CHANNEL, switches[i].getCcNum(), effects[5]);
        break;

      default:
        break;
    }
  }
}

