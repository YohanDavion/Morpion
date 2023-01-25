#include <iostream>
#include <iomanip>
#include "display.h"

using namespace std;

display::display() {

}

void display::displayEmptyLine() {
	cout << "   |   |   " << endl;
}

void display::displaySplitLine() {
	cout << "---+---+---" << endl;
}

void display::updateTableEmpty(char tabMorpion[]) {
	for (int i(0); i < 9; i++) {
			tabMorpion[i] = ' ';
	}
}

void display::displayEmptyGrid(char tabMorpion[]) {
	int x(0);
	this->updateTableEmpty(tabMorpion);
	for (int i(0); i < 9; i+=3) {
		this->displayEmptyLine();
		displayLine(i, tabMorpion);
		this->displayEmptyLine();
		if (x < 2) {
			displaySplitLine();
		}
		x++;
	}
}

void display::displayLine(int nb, char tabMorpion[]) {
	cout << setw(2) << tabMorpion[nb] << " |" << setw(2) << tabMorpion[nb + 1] << " |" << setw(2) << tabMorpion[nb + 2] << endl;
}

void display::displayGrid(char tabMorpion[]) {
	int x(0);
	for (int i(0); i < 9; i += 3) {
		this->displayEmptyLine();
		displayLine(i, tabMorpion);
		this->displayEmptyLine();
		if (x < 2) {
			displaySplitLine();
		}
		x++;
	}
}

int display::displayQuestion() {
	int reponse(-1);
	cout << "Dans quelle case souhaitez-jouer ? " << endl;
	cin >> reponse;
	return reponse;
}

void display::displayError() {
	cout << endl << "/! CETTE CASE EST DEJA REMPLIS !" << endl;
}

void display::displayIaPlay() {
	cout << endl << "L'ordinateur joue" << endl;
}

void display::displayMatchDraw() {
	cout << endl << "PARTIE TERMINE : MATCH NUL" << endl;
}

void display::displayMatchWin() {
	cout << endl << "PARTIE TERMINE : VOUS AVEZ GAGNE" << endl;
}

void display::displayMatchLose() {
	cout << endl << "PARTIE TERMINE : VOUS AVEZ PERDU" << endl;
}

void display::displayEnd(char gameStateCheck) {
	switch (gameStateCheck) {
	case 'c' :
		break;
	case 'd':
		this->displayMatchDraw();
		break;
	case 'X':
		this->displayMatchWin();
		break;
	case 'O':
		this->displayMatchLose();
		break;
	default:
		break;
	}
}

void display::userPlay(char tabMorpion[]) {
	int reponse(0);
	bool status(false);
	while (!status) {
		reponse = this->displayQuestion();
		if (tabMorpion[reponse] != ' ') {
			this->displayError();
		}
		else {
			status = true;
		}
	}
	tabMorpion[reponse] = 'X';
}