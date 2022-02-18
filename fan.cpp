#include "fan.h"
#include <iostream>

Fan::Fan()
{
	_isOn = true;
	std::cout << "Constructor called " << this << std::endl;
}

Fan::~Fan()
{
	std::cout << "Destructor called" << this << std::endl;
}

void Fan::update()
{
	this->_isOn = !this->_isOn;
}

void Fan::info()
{
	std::cout << "Information obtained" << this << std::endl;
}