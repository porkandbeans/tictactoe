#include <iostream>
#include "GameBoard.hpp"

using namespace std;

GameBoard::GameBoard()
{
    clearBoard();
}

void GameBoard::clearBoard()
{
    // each board is always a cells x cells grid
    // for now, board is a 2D array with 3 x 3 cells so cells must comply

    for (int y = 0; y < cells; y++)
    {
        for (int x = 0; x < cells; x++)
        {
            //initialize the board by setting all cells equal to a whitespace character
            board[y][x] = ' ';
        }
    }
}

// print the board to the terminal
void GameBoard::drawBoard()
{
    int cells = 3;

    /*
    OUTPUT:
         | 1 | 2 | 3 |
        --------------
        1|   |   |   |
        --------------
        2|   |   |   |
        --------------
        3|   |   |   |
        --------------
    */

    // beautify
    cout << "\n\n\n\n";

    // == X INDEX ==
    cout << " |";
    for (int i = 0; i < cells; i++)
    {
        // X index label
        cout << ' ' << i + 1 << " |";
    }
    // end of row
    cout << endl
         << "--";

    for (int i = 0; i < cells; i++)
    {
        // formatting
        cout << "----";
    }
    cout << endl;

    for (int y = 0; y < cells; y++)
    {
        // == Y INDEX ==
        cout << y + 1 << '|'; // Y index label
        for (int x = 0; x < cells; x++)
        {
            // == CELL ==
            cout << ' ' << board[y][x] << " |";
        }
        // end of row
        cout << endl
             << "--";
        for (int i = 0; i < cells; i++)
        {
            cout << "----";
        }
        cout << endl;
    }
}

int getXcoord();
int getYcoord();

void GameBoard::getMoves(char p1)
{
    char _p1 = p1;

    bool isDone = false;

    int x, y;
    while (isDone == false)
    {
        // subtract 1 so X and Y inputs line up
        // with the printed board
        cout << "Player " << p1 << " enter X co-ordinate: ";
        x = getXcoord() - 1;
        cout << "Player " << p1 << " enter X co-ordinate: ";
        y = getYcoord() - 1;

        if (placeMarker(x, y, p1))
        {
            isDone = true;
        }
        else
        {
            cout << "Either that cell is taken, or the co-ordinate is out of bounds. Please try again.\n";
        }
    }
}

int getXcoord()
{
    int x;
    cin >> x;
    return x;
}

int getYcoord()
{
    int y;
    cin >> y;
    return y;
}

bool GameBoard::placeMarker(int x, int y, char p)
{
    if (board[y][x] != ' ')
    {
        return false;
    }

    board[y][x] = p;
    return true;
}

bool GameBoard::checkVictory()
{
    // loop through rows
    for (int i = 0; i < cells; i++)
    {
        // check one row
        if (board[i][0] != ' ') // make sure you're not giving a victory to 3 whitespaces
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {

                return true;
            }
        }
    }

    // loop through columns
    for (int i = 0; i < cells; i++)
    {
        // check one column
        if (board[0][i] != ' ')
        {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {

                return true;
            }
        }
    }

    // check diagonals
    if (board[0][0] != ' ')
    {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            return true;
        }
    }

    if (board[0][2] != ' ')
    {
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            return true;
        }
    }

    // no rows or columns found yet
    return false;

    /*

    So how will this work for a scalable board? I have an idea

    > player puts down their piece
    > scan the surrounding squares (if player places a 
    piece on 0, 0 look at -1 -1, then -1 0, etc)
    > if you find a piece that matches 0:0, first check the
    opposite square (if found on -1,0 then look at +1,0)
    > if opposite square is clear, check further ahead
    (if found on -1,0, look at -2,0)

    this was what I was expecting to see rather than the brute force method
    that Ben implements in his tutorial, though I respect that he
    makes them for begginning learners and I'm primarily learning
    C++ syntax and low level concepts

    */
}