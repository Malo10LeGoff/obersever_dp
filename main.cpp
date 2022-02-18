#include <iostream>
#include "radiator.h"
#include "fan.h"
#include "thermometer.h"

int main(int argc, char **argv)
{

	std::cout << "Start the demo" << std::endl;

	int T1 = 24;
	std::list<Observer *> obs_list;

	for (int i = 0; i < 10; i++)
	{
		bool state_rad = false;
		Radiator observer_1 = Radiator(state_rad);
		obs_list.push_back(observer_1);
	}

	Thermometer therm1 = Thermometer(T1, obs_list);

	return 0;
}