#include <iostream>
#include "arbre.h"
#include "erable.h"
#include "sapin.h"


int main(int argc, char** argv) {
	std::cout << "Lancement du programme principal - méthodes virtuelles pure et typage dynamique" << std::endl;
	//Déclaration d'un arbre sur la pile 
	Arbre a; //NOK

	//Déclaration d'un pointeur de type Arbre*
	Arbre* pa; //OK 
	int type;

	//Création d'un objet dynamique sur le tas et affectation au pointeur pa
	std::cout << "Quel type d'arbre voulez vous créer (1=sapin, 2=erable) : " << std::endl;
	std::cin >> type;
	if (type == 1){
		//Création d'un arbre sur le tas
		pa = new Sapin();
	} else if (type == 2){
		//Création d'un érable sur le tas
		pa = new Erable();
	} else {
		std::cout << "type non reconnu : création d'un sapin" <<std::endl;
		pa = new Sapin();
	}

	//Appel d'une méthode à l'aide du pointeur
	pa->draw();
	pa->info();

	std::cout << "Fin du programme principal - Destruction des objets sur le tas" << std::endl;
	//destruction des objets sur le tas :
	delete pa;

	std::cout << "Fin du programme principal - Destruction des objets de la pile" << std::endl;
	return 0;
}