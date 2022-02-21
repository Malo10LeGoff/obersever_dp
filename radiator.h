#include "observer.h"
#include <ostream>

class Radiator : public Observer
{
public:
	Radiator(bool state_obs);
	~Radiator();
	void update() override final;
	bool isOn() const;
};

std::ostream &operator<<(std::ostream &flot, Radiator const &rad);