#include "radiator.h"
#include <iostream>

Radiator::Radiator(bool state_obs)
{
	this->_isOn = state_obs;
	this->type = "R";
	this->isSubscribed = true;
}

Radiator::~Radiator()
{
}

void Radiator::update()
{
	this->_isOn = !this->_isOn;
}

void Radiator::subscribe()
{
	this->isSubscribed = true;
}

void Radiator::unsubscribe()
{
	this->isSubscribed = false;
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
