#pragma once

#include <stdint.h>

/**
 * Simplest type of LED
 */
class LED
{
public:
	LED(uint8_t powerPin);
	virtual ~LED();


	// inherited
	void TurnOn();
	void TurnOff();

	bool IsTurnedOn();

protected:
	uint8_t m_powerPin;
	bool m_isTurnedOn;
};