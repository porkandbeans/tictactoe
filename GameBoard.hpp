#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#pragma once

class GameBoard
{
public:
	GameBoard();

	void drawBoard();
	void clearBoard();

private:
	char board[3][3];
};
#endif