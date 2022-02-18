#include "observer.h"

class Radiator : public Observer
{
public:
	Radiator();
	~Radiator();
	void update() override final;
	void info() override final;
};
