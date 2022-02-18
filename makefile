all: erable.o sapin.o main.o
	g++ -o main main.o erable.o sapin.o
main.o : arbre.h erable.h sapin.h main.cpp
	g++ -c -Wall --std=c++17 main.cpp
sapin.o: arbre.h sapin.h sapin.cpp
	g++ -c -Wall --std=c++17 sapin.cpp
erable.o: arbre.h erable.h erable.cpp
	g++ -c -Wall --std=c++17 erable.cpp
clean:
	rm -rf *.o main