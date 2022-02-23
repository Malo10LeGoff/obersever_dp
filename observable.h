#ifndef _OBSERVABLE_
#define _OBSERVABLE_
#include "observer.h"
#include <vector>
// We use the vector class of STL because it's more intuitive to
// manipulate than the other alternatives like the list templates

class Observable
{
public:
	int Tconsigne;
	int Tmeasured;
	std::vector<Observer *> observer_list;
	virtual ~Observable(){};
	virtual void measure(int T) = 0;
	virtual void notify() = 0;
};

#endif