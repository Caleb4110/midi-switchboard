#include "calebIO.h"
#include <stdint.h>

int charVol = A3;
int cVolVal = 0;

Pot c_vol = new Pot(9);

void update() {
  c_vol.update();
}

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}	

void loop() {
  update();

	Serial.println(c_vol.read());
}
