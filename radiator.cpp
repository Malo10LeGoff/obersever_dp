#include "radiator.h"
#include <iostream>

Radiator::Radiator(bool state_obs)
{
	this->_isOn = state_obs;
	this->type = "R";
}

Radiator::~Radiator()
{
}

void Radiator::update()
{
	this->_isOn = !this->_isOn;
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
