#include "fan.h"
#include <iostream>

Fan::Fan()
{
	std::cout << "Constructor called " << this << std::endl;
}

Fan::~Fan()
{
	std::cout << "Destructor called" << this << std::endl;
}

void Fan::update()
{
	std::cout << "Fan updated" << std::endl;
}

void Fan::info()
{
	std::cout << "Information obtained" << this << std::endl;
}