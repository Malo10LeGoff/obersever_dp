#include "observable.h"
#include "observer.h"
#include <vector>

class Thermometer : public Observable
{
public:
	Thermometer(int Tconsigne, std::vector<Observer *> list_observer);
	~Thermometer();
	std::vector<Observer *> getObservers();
	int getConsigne();
	void setObservers(std::vector<Observer *> observers_list);
	void setConsigne(double Twanted);
	void measure(int T) override final;
	void notify() override final;
};
