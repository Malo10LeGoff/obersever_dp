#include <iostream>
#include "radiator.h"
#include "fan.h"
#include "thermometer.h"
#include <vector>
#include "observer.h"

int main(int argc, char **argv)
{

	std::cout << "Start the demo" << std::endl;

	// Create 2 observers
	bool state_rad = false;
	Radiator *observer_1 = new Radiator(state_rad);
	bool state_fan = false;
	Fan *observer_2 = new Fan(state_fan);

	// Build the list of observers
	std::vector<Observer *> obs_list;
	obs_list.push_back(observer_1);
	obs_list.push_back(observer_2);

	// Build the thermometer
	int Tcons = 20;
	int T = 20;
	int nb_iterations = 20;
	Thermometer therm1 = Thermometer(Tcons, obs_list);
	therm1.measure(T);
	int temp_icrements[2] = {1, -1};

	/* observer_1->unsubscribe(); // If you want to remove one observer from the observer_list of the thermometer, follow this structure

	therm1.check_subscriptions();

	std::cout << therm1.observer_list.size() << std::endl; */

	for (int i = 0; i < nb_iterations; ++i)
	{
		// Set the new temperature
		int rand_inc = rand() % 2;
		T = T + temp_icrements[rand_inc];
		therm1.measure(T);

		// Notify the observers
		therm1.notify();

		// Display thermometer's info
		therm1.info();

		std::cout << "\n"
				  << std::endl;
	}
	return 0;
}