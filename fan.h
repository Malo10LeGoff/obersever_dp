#include "observer.h"
#include <ostream>

class Fan : public Observer
{
public:
	Fan(bool state_obs);
	~Fan();
	void update() override final;
	void subscribe();
	void unsubscribe();
	bool isOn() const;
};

std::ostream &operator<<(std::ostream &flot, Fan const &fan);