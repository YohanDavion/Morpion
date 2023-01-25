#include <iostream>
#include "display.h"
#include "ia.h"

using namespace std;

/*	Nom : Davion
##	Prenom : Yohan
##	Date : 25/01/2023
##	Fichier : main.cpp
##	Rôle : Coeur du programme, toutes les méthodes seront appelé ici pour le déroulement de la partie.
*/	

char tabMorpion[9];

int main()
{
	display display;
	ia ia;
	cout << "Jeu du Morpion :" << endl;
	display.displayEmptyGrid(tabMorpion);
	while (ia.gameStateCheck(tabMorpion) == 'c') {
		display.userPlay(tabMorpion);
		display.displayGrid(tabMorpion);
		if (ia.gameStateCheck(tabMorpion) == 'c') {
			display.displayIaPlay();
			ia.iaPlay(tabMorpion);
			display.displayGrid(tabMorpion);
		}
	}
	display.displayEnd(ia.gameStateCheck(tabMorpion));
}
