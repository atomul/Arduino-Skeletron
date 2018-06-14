#pragma once

#include <stdint.h>

class ILightSource
{
public:
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
};