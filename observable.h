#ifndef _OBSERVABLE_
#define _OBSERVABLE_
#include "observer.h"
#include <vector>

class Observable
{
public:
	double Tconsigne;
	double Tmeasured;
	std::vector<Observer *> observer_list;
	virtual ~Observable(){};
	virtual void measure(int T) = 0;
	virtual void notify() = 0;
};

#endif