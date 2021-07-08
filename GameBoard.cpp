#include <iostream>
#include "GameBoard.hpp"

using namespace std;

GameBoard::GameBoard()
{
    int cells = 3; // each board is always a cells x cells grid
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

void GameBoard::clearBoard()
{
}