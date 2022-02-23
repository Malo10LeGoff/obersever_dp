#include <ostream>
#ifndef _OBSERVER_
#define _OBSERVER_

class Observer
{
public:
    bool state;
    const char *type;
    virtual void update() = 0;
    bool isOn() const;
    bool _isOn;
    bool isSubscribed;
};

std::ostream &operator<<(std::ostream &flot, Observer const &obs);
// We overloaded the << operator to have an easy and fast mean of
// checking if an object of class Observer is On or Off

#endif