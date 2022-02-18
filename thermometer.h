#include "observable.h"
#include "observer.h"

class Thermometer : public Observable
{
public:
	Thermometer(int Tconsigne, std::list<Observer *> list_observer);
	~Thermometer();
	std::list<Observer *> getObservers();
	int getConsigne();
	void setObservers(std::list<Observer *> observers_list);
	void setConsigne(double Twanted);
	void measure() override final;
	void notify() override final;
};
