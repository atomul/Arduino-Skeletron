#pragma once

#include "LightSource.h"

/**
 * Simplest type of LED
 */
class LED : ILightSource
{
public:
	LED(uint8_t powerPin);
	virtual ~LED();


	// inherited
	virtual void TurnOn() override;
	virtual void TurnOff() override;

	bool IsTurnedOn();

protected:
	uint8_t m_powerPin;
	bool m_isTurnedOn;
};