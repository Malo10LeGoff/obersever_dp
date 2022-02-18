#include "radiator.h"
#include <iostream>

Radiator::Radiator(bool state_obs)
{
	_isOn = false;
	std::cout << "Constructor called " << this << std::endl;
}

Radiator::~Radiator()
{
	std::cout << "Destructor called" << this << std::endl;
}

void Radiator::update()
{
	this->_isOn = !this->_isOn;
}

void Radiator::info()
{
	std::cout << "Information obtained" << this << std::endl;
}
