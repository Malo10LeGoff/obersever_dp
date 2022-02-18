#include "thermometer.h"
#include "observer.h"
#include <iostream>

Thermometer::Thermometer()
{
    std::cout << "Constructor called " << this << std::endl;
}

Thermometer::~Thermometer()
{
    std::cout << "Destructor called" << this << std::endl;
}

void Thermometer::measure()
{
    std::cout << "Measure taken updated" << std::endl;
}

void Thermometer::notify()
{
    std::cout << "Information obtained" << this << std::endl;
}

void Thermometer::setConsigne(double Twanted)
{
    this->Tconsigne = Twanted;
}

void Thermometer::setObservers(std::list<Observer *> observers_list)
{
    this->observer_list = observers_list;
}

void Thermometer::getConsigne()
{
    std::cout << this->Tconsigne << std::endl;
}

void Thermometer::setObservers(std::list<Observer *> observers_list)
{
    this->observer_list = observers_list;
}