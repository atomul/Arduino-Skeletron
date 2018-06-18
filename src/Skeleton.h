#pragma once

#include "Core/Components/Buttons/Button.h"
#include "Core/Components/Buttons/SwitchButton.h"

class LED;

class Skeleton
	: public IButtonObserver
	, public ISwitchButtonObserver
{
public:
	Skeleton();
	~Skeleton();

	void SetupEyes();
	void SetupMouth();
	void SetupButtons();

	void TurnOnRedEyes();
	void TurnOnGreenEyes();

	void TurnOffRedEyes();
	void TurnOffGreenEyes();

	void Update();
private:
	void OnButtonClick(uint32_t buttonId) override final;
	void OnButtonDown(uint32_t buttonId) override final;
	void OnButtonHold(uint32_t buttonId) override final;
	void OnButtonUp(uint32_t buttonId) override final;

	void OnSwitchOn(uint32_t buttonId) override final;
	void OnSwitchOff(uint32_t buttonId) override final;

private:
	uint8_t m_delay;
	bool m_isEnabled;

	LED* m_LEDLeftEye_red;
	LED* m_LEDLeftEye_green;
	LED* m_LEDRightEye_red;
	LED* m_LEDRightEye_green;

	Button* m_buttonIncreaseSpeed;
	Button* m_buttonDecreaseSpeed;
	SwitchButton* m_buttonStartStop;
};