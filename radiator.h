#include "observer.h"
#include <ostream>

class Radiator : public Observer
{
public:
	Radiator(bool state_obs);
	~Radiator();
	void update() override final;
	void info() override final;
	bool isOn() const;

private:
	bool _isOn;
};

std::ostream &operator<<(std::ostream &flot, const Radiator &rad)
{
	flot << "Radiator is on:" << rad.isOn();
	return flot;
}