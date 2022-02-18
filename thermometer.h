#include "observable.h"
#include "observer.h"

class Thermometer : public Observable
{
public:
	Thermometer();
	~Thermometer();
	std::list<Observer *> getObservers();
	int getConsigne();
	std::list<Observer *> getObservers();
	void setObservers(std::list<Observer *> observers_list);
	void setConsigne(double Twanted);
	void measure() override final;
	void notify() override final;
};
