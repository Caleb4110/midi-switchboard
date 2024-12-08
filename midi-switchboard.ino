#include "calebIO.h"
#include <stdint.h>
#include <MIDI.h>
#include "common.h"
#include <EncoderButton.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// Initialise potentiometers
Pot pots[4] = {
  Pot(A0, 73),
  Pot(A1, 75),
  Pot(A2, 77),
  Pot(A3, 79),
};


EncoderButton preset_enc(2, 3, 4);

void on_encoder_change(EncoderButton& eb) {
  Serial.print("preset incremented by: ");
  Serial.println(eb.increment());
  Serial.print("preset position is: ");
  Serial.println(eb.position());
}

// Update all controls at once
void update() {
  pots[character].update();
  pots[movement].update();
  pots[diffusion].update();
  pots[texture].update();
  preset_enc.update();
}

void send_cc(uint8_t control_num, uint8_t val) {
  MIDI.sendControlChange(control_num, val, MIDI_CHANNEL);
}

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
  preset_enc.setEncoderHandler(on_encoder_change);

  Serial.begin(9600);
  while (!Serial);

  // MIDI.begin(MIDI_CHANNEL);
  Serial.println("MIDI controller ready");
}

void loop() {
  // Update all control values
  update();

  // Send appropriate MIDI signals
}
