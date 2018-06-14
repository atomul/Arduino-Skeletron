/*
 Name:		Skeletron.ino
 Created:	6/14/2018 8:54:11 PM
 Author:	Petre-Daniel
*/

// the setup function runs once when you press reset or power the board

#include "src/Core/Components/Lights/LED.h"

LED* k_led;

void setup() {
	Serial.begin(9600);
	k_led = new LED(12);
}

// the loop function runs over and over again until power down or reset
void loop() {
	k_led->TurnOn();
	delay(5000);
	k_led->TurnOff();
}
