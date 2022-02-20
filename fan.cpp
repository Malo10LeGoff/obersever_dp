#include "fan.h"
#include <iostream>

Fan::Fan(bool state_obs)
{
	_isOn = state_obs;
	this->type = "F";
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

bool Fan::isOn() const
{
	return this->_isOn;
}

void Fan::info()
{
	std::cout << "Information obtained" << this << std::endl;
}

std::ostream &operator<<(std::ostream &flot, Fan const &fan)
{
	flot << "Fan is on:" << fan.isOn();
	return flot;
}