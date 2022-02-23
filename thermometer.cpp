#include "thermometer.h"
#include "observer.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string.h>

Thermometer::Thermometer(
    int Tconsigne, std::vector<Observer *> list_observer)
{
    this->Tconsigne = Tconsigne;
    this->observer_list = list_observer;
}

Thermometer::~Thermometer()
{
}

void Thermometer::measure(int T)
{
    this->Tmeasured = T;
    std::cout << "Measure taken, the temperature measured changed to " << this->Tmeasured << std::endl;
}

void Thermometer::notify()
{

    double delta_T = this->Tconsigne - this->Tmeasured;
    int nb_observers = this->observer_list.size();
    if (delta_T != 0) // If the temperature hasn't changed, there is no need to notify the observers
    {
        std::cout << "Notifying the observers..." << std::endl;
        for (int i = 0; i < nb_observers; ++i)
        {
            const char *type_obs = observer_list[i]->type;
            if (strcmp(type_obs, "R") == 0)
            {
                if (delta_T > 0)
                {
                    if (observer_list[i]->_isOn == false)
                    {
                        observer_list[i]->update();
                    }
                }
                if (delta_T < 0)
                {
                    if (observer_list[i]->_isOn == true)
                    {
                        observer_list[i]->update();
                    }
                }
            }
            else
            {
                if (delta_T > 0)
                {
                    if (observer_list[i]->_isOn == true)
                    {
                        observer_list[i]->update();
                    }
                }
                if (delta_T < 0)
                {
                    if (observer_list[i]->_isOn == false)
                    {
                        observer_list[i]->update();
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "No change of temperature, the observers need not to be notified" << std::endl;
    }
}

void Thermometer::info()
{

    int nb_observers = this->observer_list.size();
    int nb_rads_on = 0;
    int nb_fans_on = 0;

    for (int i = 0; i < nb_observers; ++i)
    {
        if (this->observer_list[i]->_isOn == true)
        {
            const char *type_obs = observer_list[i]->type;
            if (strcmp(type_obs, "R") == 0)
            {
                nb_rads_on = nb_rads_on + 1;
            }
            else
            {
                nb_fans_on = nb_fans_on + 1;
            }
        }
    }

    std::cout << "Number of Radiators on : " << nb_rads_on << std::endl;
    std::cout << "Number of Fans on : " << nb_fans_on << std::endl;
}

void Thermometer::setConsigne(double Twanted)
{
    this->Tconsigne = Twanted;
}

std::vector<Observer *> Thermometer::getObservers()
{
    return this->observer_list;
}

int Thermometer::getConsigne()
{
    return this->Tconsigne;
}

void Thermometer::check_subscriptions()
{
    int nb_observers = this->observer_list.size();
    std::vector<Observer *> new_obs_list;

    for (int i = 0; i < nb_observers; ++i)
    {
        if (this->observer_list[i]->isSubscribed == true)
        {
            new_obs_list.push_back(this->observer_list[i]);
        }
    }
    this->observer_list = new_obs_list;
}
