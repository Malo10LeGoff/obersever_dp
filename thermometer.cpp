#include "thermometer.h"
#include "observer.h"
#include <iostream>

Thermometer::Thermometer(
    int Tconsigne, std::list<Observer *> list_observer)
{
    this->Tconsigne = Tconsigne;
    this->observer_list = list_observer;
    std::cout
        << "Constructor called " << this << std::endl;
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

std::list<Observer *> Thermometer::getObservers()
{
    std::cout << "Cc" << std::endl;
    return this->observer_list;
}

int Thermometer::getConsigne()
{
    std::cout << this->Tconsigne << std::endl;
    return this->Tconsigne;
}
