#pragma once
class display
{
public :
	display();
	void displayEmptyLine();
	void displaySplitLine();
	void displayEmptyGrid(char tabMorpion[]);
	void displayLine(int nb, char tabMorpion[]);
	void displayGrid(char tabMorpion[]);
	void updateTable(char tabMorpion[]);
	void updateTableEmpty(char tabMorpion[]);
	void displayEnd(char gameStateCheck);
	void userPlay(char tabMorpion[]);

	int displayQuestion();
	void displayError();
	void displayIaPlay();
	void displayMatchDraw();
	void displayMatchWin();
	void displayMatchLose();
private :
};

