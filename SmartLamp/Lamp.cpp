#include "pch.h"
#include "Lamp.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>


const int MIN_REGUL = 0;
const int MAX_REGUL = 100;
const int MAX_TEMPERATURE = 100;


void Lamp::setOff()
{
	if (m_power)
	{
		m_power = false;
		m_temperature = 25;
		m_signal = false;
	}
}


void Lamp::manualMode(int c)
{
	m_power = 1;

	std::cout << "regulator - ";
	std::cin >> m_regulation;
	
	temperatureCalculation(25);
	overheating();
}


void Lamp::autoMode(int lum, int c)
{
	if (m_power)
	{
		m_regulation = 1.0 / (lum / 5000.0 + 0.01);
		temperatureCalculation(25);
		overheating();
	}
}


void Lamp::changeRegulator(int c)
{
	if (m_power)
	{
		std::cout << "position of regulator - ";
		std::cin >> m_regulation;

		temperatureCalculation(25);
		overheating();
	}
}


void Lamp::temperatureCalculation(int celsius)
{
	int timeWork;
	std::cout << "put the time work - ";
	std::cin >> timeWork;

	m_temperature = celsius * (1 + m_regulation / 100.0) + m_regulation / 3 * tanh((timeWork - 30.0) / 30);
}


void Lamp::overheating()
{
    m_temperature >= MAX_TEMPERATURE ? m_signal = 1 : m_signal = 0;
}