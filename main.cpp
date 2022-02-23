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
	Fan *observer_3 = new Fan(state_fan);

	// Build the list of observers
	std::vector<Observer *> obs_list;
	// The above vector is made of the pointers of the parent type Observer so we can manipulate the 2 types of observers in the same vector without being worried about slicing
	obs_list.push_back(observer_1);
	obs_list.push_back(observer_2);
	obs_list.push_back(observer_3);

	// Build the thermometer
	int Tcons = 20;
	int T = 20;
	int nb_iterations = 20;
	Thermometer therm1 = Thermometer(Tcons, obs_list);
	therm1.measure(T);
	int temp_icrements[2] = {1, -1};

	for (int i = 0; i < nb_iterations; ++i)
	{
		// Set the new temperature
		int rand_inc = rand() % 2;
		T = T + temp_icrements[rand_inc];
		therm1.measure(T);

		// Notify the observers if needed
		therm1.notify();

		// Display thermometer's info
		therm1.info();

		std::cout << "\n"
				  << std::endl;
	}

	std::cout << "We can do the same with dynamic unsubscriptions/subscriptions from the observers. Press any to go to the next scenario : " << std::endl;

	do
	{
	} while (std::cin.get() != '\n');

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

		if (i == nb_iterations / 2)
		{
			observer_1->unsubscribe(); // We can remove dynamically observers by unsubscribing them from the thermometer
			observer_2->unsubscribe();
			std::cout << "The 2 first observers has been unsubscribed ! There is only one fan left" << std::endl;
			therm1.check_subscriptions();
			std::cout << "New number of observers subscribed to the thermometer : " << therm1.observer_list.size() << std::endl;
		}
	}

	return 0;
}