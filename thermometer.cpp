#include "thermometer.h"
#include "observer.h"
#include <iostream>
#include <vector>

Thermometer::Thermometer(
    int Tconsigne, std::vector<Observer *> list_observer)
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

void Thermometer::measure(int T)
{
    this->Tmeasured = T;
    std::cout << "Measure taken, changed to " << this->Tmeasured << std::endl;
}

void Thermometer::notify()
{
    std::cout << "Notifying the observers..." << std::endl;

    double delta_T = this->Tconsigne - this->Tmeasured;
    int nb_observers = this->observer_list.size();

    for (int i = 0; i < nb_observers; ++i)
    {
        if (this->observer_list[i]->type == "R")
        {
            if (delta_T > 0)
            {
                if (observer_list[i]->isOn() == false)
                {
                    observer_list[i]->update();
                }
            }
            if (delta_T < 0)
            {
                if (observer_list[i]->isOn() == true)
                {
                    observer_list[i]->update();
                }
            }
        }
        else
        {
            if (delta_T > 0)
            {
                if (observer_list[i]->isOn() == true)
                {
                    observer_list[i]->update();
                }
            }
            if (delta_T < 0)
            {
                if (observer_list[i]->isOn() == false)
                {
                    observer_list[i]->update();
                }
            }
        }
    }
}

void Thermometer::setConsigne(double Twanted)
{
    this->Tconsigne = Twanted;
}

std::vector<Observer *> Thermometer::getObservers()
{
    std::cout << "Cc" << std::endl;
    return this->observer_list;
}

int Thermometer::getConsigne()
{
    std::cout << this->Tconsigne << std::endl;
    return this->Tconsigne;
}
