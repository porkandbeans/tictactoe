#include <iostream>
#include <string>

#include "GameBoard.hpp"

using namespace std;

int main()
{
    /*
    previously I tried to recreate the program at its first appearance
    however this proved a bit too hard
    
    instead I am going to try to create a more linear game with a
    3x3 grid and 2 players, and then work to expand upon that until
    it is a complete recreation

    issues I ran into were getting multiple values to return from a function,
    and trying to pass a 2D array to a function

    this project is my second attempt and I am working from the ground up
    */

    GameBoard board;

    char pchar1;
    char pchar2;
    cout << "~~~ Tic Tac Toe ~~~\n";

    bool getPlayer1Char = false, getPlayer2Char = false;

    while (getPlayer1Char == false)
    {
        cout << "Player 1 character: ";
        cin >> pchar1;
        if (pchar1 != ' ')
        {
            getPlayer1Char = true;
        }
        else
        {
            cout << "Character cannot be whitespace, try again\n";
        }
    }

    while (getPlayer2Char == false)
    {
        cout << "Player 2 character: ";
        cin >> pchar2;
        if (pchar2 != ' ')
        {
            getPlayer2Char = true;
        }
        else
        {
            cout << "Character cannot be whitespace, try again\n";
        }
    }

    static char _pchars[2]{pchar1, pchar2};

    int cells = 3, turn = 0;

    // start looping for the game
    bool gameOver = false;
    int _x, _y;

    cout << "~~ GAME BEGINS ~~\n";
    while (!gameOver)
    {
        board.drawBoard();

        //check if someone won
        /*for (int y = 0; y < cells; y++)
        {
            char checkChars[cells];
            //horizontal
            for (int x = 0; x < cells; x++)
            {
                checkChars[x] = board[y][x];
            }

            // without access to high level stuff like .length() I've decided to use the cells
            // variable, since it will be the int I need anyway

            // previous character
            char prevchar = checkChars[0];

            // victory count
            int victCount = 0;

            for (int i = 0; i < cells; i++)
            {
                if (checkChars[i + 1] == prevchar)
                {
                    victCount++;
                }
            }

            if (victCount >= 3)
            {
                cout << "\n\n\nVICTORY\n\n\n";
            }
        }*/

        //get player moves
        /*bool playerInput = false;
        while (playerInput == false)
        {
            cout << "Player " << turn + 1 << " X co-ordinate: ";
            cin >> _x;
            cout << "Player " << turn + 1 << " Y co-ordinate: ";
            cin >> _y;

            if (board[_y - 1][_x - 1] != ' ')
            {
                cout << "That cell is either occupied or not available, try again\n";
            }
            else
            {
                board[_y - 1][_x - 1] = _pchars[turn];
                playerInput = true;
            }
        }*/

        //swap turn
        if (turn == 0)
        {
            turn = 1;
        }
        else
        {
            turn = 0;
        }

        char wait;
        cin >> wait; // jank, I know
    }
    return 0;
}

/*
    TODO:
        win condition
        prevent cell overwrites
        reformat
        more than 2 players
        player names
        watch the rest of the video lol
    
    for the love of god, I will get this to perform exactly the same as the one at the start
*/