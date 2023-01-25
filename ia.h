#pragma once
class ia
{
public :
	ia();
	char isGameWin(char tabMorpion[]);
	bool isGameOver(char tabMorpion[]);
	char gameStateCheck(char tabMorpion[]);
	int randomNumber(int max);
	bool isCenterFree(char tabMorpion[]);
	void iaRandomPlay(char tabMorpion[]);
	bool iaPlaytoWin(char tabMorpion[]);
	bool iaPlaytoDefend(char tabMorpion[]);
	void iaPlay(char tabMorpion[]);
	bool checkVerticaleWin(char tabMorpion[], char verif, char saisie);
	bool checkHorizontaleWin(char tabMorpion[], char verif, char saisie);
	bool checkDiagonalWin(char tabMorpion[], char verif, char saisie);
private :
	char checkVerticalWin(char tabMorpion[]);
	char checkHorizontalWin(char tabMorpion[]);
	char checkDiagonaleWin(char tabMorpion[]);
};

