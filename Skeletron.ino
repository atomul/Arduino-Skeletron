/*
 Name:		Skeletron.ino
 Created:	6/14/2018 8:54:11 PM
 Author:	Petre-Daniel
*/

// the setup function runs once when you press reset or power the board

#include <Servo.h>
#include <Arduino.h>

#include "src/Core/Components/Lights/LED.h"
#include "src/Skeleton.h"

Skeleton* k_skeleton;
LED* k_led;

Servo* k_myServo;
const uint8_t potPin = A0;
int potVal;

void setup() {
	Serial.begin(9600);
	k_skeleton = new Skeleton();
	
	k_myServo = new Servo();
}

// the loop function runs over and over again until power down or reset
void loop() {
	k_skeleton->Update();

	//pinMode(potPin, OUTPUT);
	//potVal = analogRead(potPin);

	//int angle = map(potVal, 0, 1023, 0, 179);
	//Serial.print("angle: ");
	//Serial.println(angle);

	//k_myServo->attach(3);
	//k_myServo->write(angle);
	//delay(15);
}
