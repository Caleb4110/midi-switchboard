#include "calebIO.h"
#include <stdint.h>
#include "common.h"
#include <Encoder.h>

// Initialise potentiometers
/*
Pot pots[NUM_POTS] = {
  Pot(A0, 73),
  Pot(A1, 75),
  Pot(A2, 77),
  Pot(A3, 79),
};
*/
Pot charPot = Pot(A0, 73, 3);
// Initialise encoder switch


Encoder encoder(2, 3);

// Update all controls at once
void update() {
  /*
  pots[character].update();
  pots[movement].update();
  pots[diffusion].update();
  pots[texture].update();
  */
  charPot.update();
}

void update_encoder() {
  Serial.print("encoder changed: ");
  Serial.println(encoder.read());
}

void setup() {
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), update_encoder, CHANGE);

  Serial.begin(9600);
  while (!Serial);

  Serial.println("MIDI controller ready");
}

void loop() {
  // Update all control values
  update();
  /*
  // Send appropriate MIDI signals if value has changed
  for (uint8_t i = 0; i < NUM_POTS; i++) {
    if (pots[character].has_changed()) {
      Serial.println("changed");
    }
  }
  */
  if (charPot.has_changed()) {
    Serial.println(charPot.read());
  }
}
