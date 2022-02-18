#include "observer.h"
#include <ostream>

class Fan : public Observer
{
public:
	Fan();
	~Fan();
	void update() override final;
	void info() override final;
	bool isOn() const;

private:
	bool _isOn;
};

std::ostream &operator<<(std::ostream &flot, const Fan &fan)
{
	flot << "Fan is on:" << fan.isOn();
	return flot;
}