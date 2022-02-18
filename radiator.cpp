#include "radiator.h"
#include <iostream>

Radiator::Radiator()
{
	std::cout << "Constructor called " << this << std::endl;
}

Radiator::~Radiator()
{
	std::cout << "Destructor called" << this << std::endl;
}

void Radiator::update()
{
	std::cout << "Radiator updated" << std::endl;
}

void Radiator::info()
{
	std::cout << "Information obtained" << this << std::endl;
}