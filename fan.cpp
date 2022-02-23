#include "fan.h"
#include <iostream>

Fan::Fan(bool state_obs)
{
	this->_isOn = state_obs;
	this->type = "F";
	this->isSubscribed = true;
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

void Fan::subscribe()
{
	this->isSubscribed = true;
}

void Fan::unsubscribe()
{
	this->isSubscribed = false;
}

std::ostream &operator<<(std::ostream &flot, Fan const &fan)
{
	flot << "Fan is on:" << fan.isOn();
	return flot;
}