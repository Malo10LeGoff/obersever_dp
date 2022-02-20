#include "radiator.h"
#include <iostream>

Radiator::Radiator(bool state_obs)
{
	this->_isOn = state_obs;
	this->type = "R";
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

bool Radiator::isOn() const
{
	return this->_isOn;
}

std::ostream &operator<<(std::ostream &flot, Radiator const &rad)
{
	flot << "Radiator is on:" << rad.isOn();
	return flot;
}
