#include "observer.h"
#include <iostream>

std::ostream &operator<<(std::ostream &flot, Observer const &obs)
{
    flot << "Observer super-method";
    return flot;
}

bool Observer::isOn() const
{
    return this->_isOn;
}
