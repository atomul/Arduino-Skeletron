#include "Skeleton.h"

#include "Core/Components/Lights/LED.h"
#include "Core/Components/Motors/HBridge.h"
#include "Core/Components/Motors/Motor.h"

#include <Arduino.h>
#include <Servo.h>

Servo* myServo;
Motor* k_motor;

const uint8_t k_pinBtnStartStop = 2;
const uint8_t k_pinBtnDecreaseSpeed = 7;
const uint8_t k_pinBtnIncreaseSpeed = 8;

Skeleton::Skeleton()
{
	m_delay= 150;
	m_isEnabled = false;

	SetupEyes();
	SetupMouth();
	SetupButtons();
}

void Skeleton::SetupEyes()
{

	m_LEDLeftEye_red = new LED(12);
	m_LEDRightEye_red = new LED(11);
	//m_LEDLeftEye_green = new LED(8);
	//m_LEDRightEye_green = new LED(4);

	myServo = new Servo();
	myServo->attach(3);
}

void Skeleton::SetupMouth()
{
	HBridge_L293D HBridge;

	// used to PWM the motor, change the speed
	HBridge.device1.enable = 11;

	/**
	* Used to change direction of the motor
	* These pins should be set as oposite from each other
	* If both pins are HIGH or LOW, the motor will stop spinning
	*/
	HBridge.device1.input1 = 10;
	HBridge.device1.input2 = 9;
	k_motor = new Motor();
	k_motor->AssignHBridge(HBridge.device1.enable, HBridge.device1.input1, HBridge.device1.input2);
	k_motor->SetSpeed(100);
	k_motor->Enable();
}

void Skeleton::SetupButtons()
{
	m_buttonDecreaseSpeed = new Button(k_pinBtnDecreaseSpeed);
	m_buttonIncreaseSpeed = new Button(k_pinBtnIncreaseSpeed);
	m_buttonStartStop = new SwitchButton(k_pinBtnStartStop);

	m_buttonDecreaseSpeed->RegisterGeneralObserver(this);
	m_buttonIncreaseSpeed->RegisterGeneralObserver(this);
	m_buttonStartStop->RegisterGeneralObserver(this);
	m_buttonStartStop->RegisterSwitchObserver(this);
}

Skeleton::~Skeleton()
{

}

void Skeleton::Update()
{
	m_buttonDecreaseSpeed->Update();
	m_buttonIncreaseSpeed->Update();
	m_buttonStartStop->Update();

	static bool red = true;
	static bool open = true;
	if (red)
	{
		TurnOffGreenEyes();
		TurnOnRedEyes();
	}
	else
	{
		TurnOffRedEyes();
		TurnOnGreenEyes();
	}

	//Serial.print(m_servoValue1);
	//Serial.print(" - ");
	//Serial.print(m_servoValue2);
	//Serial.println("");

	if (m_isEnabled)
	//if (true)
	{
		if (open)
		{
			myServo->write(80);
		}
		else
		{
			myServo->write(30);
		}
		open = !open;
	}
	else
	{

	}


	delay(m_delay);
	//delay(100);
}

void Skeleton::TurnOnRedEyes()
{
	m_LEDLeftEye_red->TurnOn();
	m_LEDRightEye_red->TurnOn();
}

void Skeleton::TurnOnGreenEyes()
{

	m_LEDLeftEye_green->TurnOn();
	m_LEDRightEye_green->TurnOn();
}

void Skeleton::TurnOffRedEyes()
{
	m_LEDLeftEye_red->TurnOff();
	m_LEDRightEye_red->TurnOff();
}

void Skeleton::TurnOffGreenEyes()
{

	m_LEDLeftEye_green->TurnOff();
	m_LEDRightEye_green->TurnOff();
}

void Skeleton::OnButtonClick(uint32_t buttonId)
{
	Serial.print(buttonId);
	if (buttonId == k_pinBtnDecreaseSpeed)
	{
		m_delay += 50;
	}
	else if (buttonId == k_pinBtnIncreaseSpeed)
	{
		if (m_delay >= 150)
		{
			m_delay -= 50;
		}
	}
}

void Skeleton::OnSwitchOn(uint32_t buttonId)
{
	Serial.print(buttonId);
	if (buttonId == k_pinBtnStartStop)
	{
		m_isEnabled = true;
	}
}

void Skeleton::OnSwitchOff(uint32_t buttonId)
{
	Serial.print(buttonId);
	if (buttonId == k_pinBtnStartStop)
	{
		m_isEnabled = false;
	}
}

void Skeleton::OnButtonDown(uint32_t buttonId)
{

}

void Skeleton::OnButtonHold(uint32_t buttonId)
{

}

void Skeleton::OnButtonUp(uint32_t buttonId)
{

}