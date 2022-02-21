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
};

std::ostream &operator<<(std::ostream &flot, Observer const &obs);

#endif