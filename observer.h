#ifndef _OBSERVER_
#define _OBSERVER_

class Observer
{
public:
    bool state;
    virtual void update() = 0;
    virtual void info() = 0;
};

#endif