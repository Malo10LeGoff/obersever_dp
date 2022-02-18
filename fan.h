#include "observer.h"

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


inline std::ostream& operator<< (std::ostream& flot, const Fan& fan) {
	flot << "Fan is on:" << fan.isOn();
}