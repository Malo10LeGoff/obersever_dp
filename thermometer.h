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
	void notify() override final; // Notify if the observers must change their state according to the difference between T consigne and Tmeasured
	void info();				  // Display the number of observers On
	void check_subscriptions();	  // Check how many observers don't want to be subscribed anymore and remove them
};
