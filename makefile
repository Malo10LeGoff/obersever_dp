all: radiator.o fan.o thermometer.o main.o observer.o
	g++ -o main main.o radiator.o fan.o thermometer.o
main.o : thermometer.h radiator.h fan.h observer.h main.cpp 
	g++ -c -Wall --std=c++17 main.cpp
thermometer.o: observable.h thermometer.h thermometer.cpp
	g++ -c -Wall --std=c++17 thermometer.cpp
fan.o: observer.h fan.h fan.cpp 
	g++ -c -Wall --std=c++17 fan.cpp
radiator.o: observer.h radiator.h radiator.cpp
	g++ -c -Wall --std=c++17 radiator.cpp
observer.o: observer.h 
	g++ -c -Wall --std=c++17 observer.cpp
clean:
	rm -rf *.o main