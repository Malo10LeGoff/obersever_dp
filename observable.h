#ifndef _OBSERVABLE_
#define _OBSERVABLE_
#include "observer.h"
#include <list>

class Observable
{
public:
	double Tconsigne;
	std::list<Observer *> observer_list;
	virtual ~Observable(){};
	virtual void measure() = 0;
	virtual void notify() = 0;
};

#endif