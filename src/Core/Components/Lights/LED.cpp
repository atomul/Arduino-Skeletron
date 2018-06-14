#include "LED.h"

#include <Arduino.h>

LED::LED(uint8_t powerPin)
	: m_powerPin(powerPin)
	, m_isTurnedOn(false)
{
	pinMode(m_powerPin, OUTPUT);
}

LED::~LED()
{
}

void LED::TurnOn()
{
	Serial.print("Button Pressed\n");
	digitalWrite(m_powerPin, 1);
	m_isTurnedOn = true;
}

void LED::TurnOff()
{
	digitalWrite(m_powerPin, 0);
	m_isTurnedOn = false;
}

bool LED::IsTurnedOn()
{
	return m_isTurnedOn;
}
