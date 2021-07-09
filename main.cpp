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

    board.drawBoard();
    while (!gameOver)
    {
        // passing the character based on turn
        board.getMoves(_pchars[turn]);

        board.drawBoard();

        // check for a victory
        if (board.checkVictory())
        {

            cout << "Player " << turn + 1 << " has won! Would you like to go again? Y/N: ";
            char goAgain = ' ';
            cin >> goAgain;
            if (goAgain == 'N')
            {
                gameOver = true;
            }
            else
            {
                board.clearBoard();
                board.drawBoard();
            }
        }

        if (turn == 0)
        {
            turn = 1;
        }
        else
        {
            turn = 0;
        }
    }
    return 0;
}

/*
    TODO:
        win condition
        more than 2 players
        player names

    BUGS:
        Input in X or Y co-ordinate that is not
        an integer will cause a crash

*/