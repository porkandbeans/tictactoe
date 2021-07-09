#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#pragma once

class GameBoard
{
public:
	GameBoard();
	void clearBoard();
	void drawBoard();
	void getMoves(char p1);
	bool placeMarker(int x, int y, char p);
	bool checkVictory();

private:
	char board[3][3];
	int cells = 3;
};
#endif