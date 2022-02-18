#include "observer.h"

class Fan : public Observer
{
public:
	Fan();
	~Fan();
	void update() override final;
	void info() override final;
};
