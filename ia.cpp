#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ia.h"

using namespace std;

ia::ia() {
}

char ia::isGameWin(char tabMorpion[]) {
	if (this->checkVerticalWin(tabMorpion) != 'E') {
		return this->checkVerticalWin(tabMorpion);
	}
	if (this->checkHorizontalWin(tabMorpion) != 'E') {
		return this->checkHorizontalWin(tabMorpion);
	}
	if (this->checkDiagonaleWin(tabMorpion) != 'E') {
		return this->checkDiagonaleWin(tabMorpion);
	}
	return 'c';
}

char ia::checkVerticalWin(char tabMorpion[]) {
	for (int i(0); i < 9; i += 3) {
		if ((tabMorpion[i] == 'X') && (tabMorpion[i+3] == 'X') && (tabMorpion[i + 6] == 'X')) {
			return 'X';
		}
		if ((tabMorpion[i] == 'O') && (tabMorpion[i + 3] == 'O') && (tabMorpion[i + 6] == 'O')) {
			return 'O';
		}
	}
	return 'E';
}

char ia::checkHorizontalWin(char tabMorpion[]) {
	for (int i(0); i < 9; i += 3) {
		if ((tabMorpion[i] == 'X') && (tabMorpion[i + 1] == 'X') && (tabMorpion[i + 2] == 'X')) {
			return 'X';
		}
		if ((tabMorpion[i] == 'O') && (tabMorpion[i + 1] == 'O') && (tabMorpion[i + 2] == 'O')) {
			return 'O';
		}
	}
	return 'E';
}

char ia::checkDiagonaleWin(char tabMorpion[]) {
		if ((tabMorpion[0] == 'X') && (tabMorpion[4] == 'X') && (tabMorpion[8] == 'X')) {
			return 'X';
		}
		if ((tabMorpion[2] == 'X') && (tabMorpion[4] == 'X') && (tabMorpion[6] == 'X')) {
			return 'X';
		}
		if ((tabMorpion[0] == 'O') && (tabMorpion[4] == 'O') && (tabMorpion[8] == 'O')) {
			return 'O';
		}
		if ((tabMorpion[2] == 'O') && (tabMorpion[4] == 'O') && (tabMorpion[6] == 'O')) {
			return 'O';
		}
		return 'E';
}

bool ia::isGameOver(char tabMorpion[]) {
	int nbFreeCase(0);
	for (int i(0); i < 9; i += 1) {
		if (tabMorpion[i] == ' ') {
			nbFreeCase++;
		}
	}
	if (nbFreeCase == 0) {
		return true;
	}
	else {
		return false;
	}
	
}

char ia::gameStateCheck(char tabMorpion[]) {
	if (this->isGameWin(tabMorpion) == 'c' && this->isGameOver(tabMorpion)) {
		return 'd';
	}
	else if(this->isGameWin(tabMorpion) == 'c' && !this->isGameOver(tabMorpion)) {
		return 'c';
	}
	else {
		return this->isGameWin(tabMorpion);
	}
}

bool ia::isCenterFree(char tabMorpion[]) {
	if (tabMorpion[4]==' ') {
		tabMorpion[4] = 'O';
		return true;
	}
	return false;
}

int ia::randomNumber(int max) {
	int randomNb(0);
	srand(time(0));
	randomNb = rand() % max;
	return randomNb;
}

void ia::iaRandomPlay(char tabMorpion[]) {
	bool play(false);
	int nbRandom(this->randomNumber(8));
	while (!play) {
		if (tabMorpion[nbRandom] == ' ') {
			tabMorpion[nbRandom] = 'O';
			play = true;
		}else{
			nbRandom=this->randomNumber(8);
		}
	}
}

bool ia::iaPlaytoWin(char tabMorpion[]) {
	if (this->checkVerticaleWin(tabMorpion, 'O', 'O')) {
		return true;
	}
	else if (this->checkHorizontaleWin(tabMorpion, 'O', 'O')) {
		return true;
	}
	else if (this->checkDiagonalWin(tabMorpion, 'O', 'O')) {
		return true;
	}
	return false;
}

bool ia::iaPlaytoDefend(char tabMorpion[]) {
	if (this->checkVerticaleWin(tabMorpion,'X','O')) {
		return true;
	}
	else if (this->checkHorizontaleWin(tabMorpion,'X','O')) {
		return true;
	}
	else if (this->checkDiagonalWin(tabMorpion,'X','O')) {
		return true;
	}
	return false;
}

void ia::iaPlay(char tabMorpion[]) {
		if(this->iaPlaytoWin(tabMorpion)) {
		}
		else if (this->iaPlaytoDefend(tabMorpion)) {
		}
		else if (this->isCenterFree(tabMorpion)) {
		}
		else {
			this->iaRandomPlay(tabMorpion);
		}
}

bool ia::checkVerticaleWin(char tabMorpion[], char verif, char saisie) {
	for (int i(0); i < 3; i++) {
		if ((tabMorpion[i] == verif) && (tabMorpion[i + 3] == verif) && (tabMorpion[i + 6] == ' ')) {
			tabMorpion[i + 6] = saisie;
			return true;
		}
		else if ((tabMorpion[i] == ' ') && (tabMorpion[i + 3] == verif) && (tabMorpion[i + 6] == verif)) {
			tabMorpion[i] = saisie;
			return true;
		}
		else if ((tabMorpion[i] == verif) && (tabMorpion[i + 3] == ' ') && (tabMorpion[i + 6] == verif)) {
			tabMorpion[i + 3] = saisie;
			return true;
		}
	}
	return 0;
}

bool ia::checkHorizontaleWin(char tabMorpion[], char verif, char saisie) {
	for (int i(0); i < 9; i+=3) {
		if ((tabMorpion[i] == verif) && (tabMorpion[i + 1] == verif) && (tabMorpion[i + 2] == ' ')) {
			tabMorpion[i + 2] = saisie;
			return true;
		}
		else if ((tabMorpion[i] == ' ') && (tabMorpion[i + 1] == verif) && (tabMorpion[i + 2] == verif)) {
			tabMorpion[i] = saisie;
			return true;
		}
		else if ((tabMorpion[i] == verif) && (tabMorpion[i + 1] == ' ') && (tabMorpion[i + 2] == verif)) {
			tabMorpion[i + 1] = saisie;
			return true;
		}
	}
	return 0;
}

bool ia::checkDiagonalWin(char tabMorpion[], char verif, char saisie) {
		if ((tabMorpion[0] == verif) && (tabMorpion[4] == verif) && (tabMorpion[8] == ' ')) {
			tabMorpion[8] = saisie;
			return true;
		}
		if ((tabMorpion[0] == ' ') && (tabMorpion[4] == verif) && (tabMorpion[8] == verif)) {
			tabMorpion[0] = saisie;
			return true;
		}
		if ((tabMorpion[0] == verif) && (tabMorpion[4] == ' ') && (tabMorpion[8] == verif)) {
			tabMorpion[4] = saisie;
			return true;
		}
		if ((tabMorpion[2] == verif) && (tabMorpion[4] == verif) && (tabMorpion[6] == ' ')) {
			tabMorpion[6] = saisie;
			return true;
		}
		if ((tabMorpion[2] == ' ') && (tabMorpion[4] == verif) && (tabMorpion[6] == verif)) {
			tabMorpion[2] = saisie;
			return true;
		}
		if ((tabMorpion[2] == verif) && (tabMorpion[4] == ' ') && (tabMorpion[6] == verif)) {
			tabMorpion[4] = saisie;
			return true;
		}
		return 0;
}