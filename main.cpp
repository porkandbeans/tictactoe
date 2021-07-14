#include <iostream>
#include <string>
#include <cstring>

#include "GameBoard.hpp"

using namespace std;

char getPlayerChar();

int main()
{
    GameBoard board;
    cout << "~~~ Tic Tac Toe ~~~\n";

    cout << "~~ PLAYER ONE ~~\n";
    char pchar1 = getPlayerChar();
    cout << "~~ PLAYER TWO ~~\n";
    char pchar2 = getPlayerChar();

    while (pchar2 == pchar1)
    {
        cout << "Sorry player two, you can't pick the same character as player 1. Try again.\n";
        pchar2 = getPlayerChar();
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
// === END OF INT.MAIN ==

/*  getPlayerChar() -
    Gets first character from input and returns it */
char getPlayerChar()
{
    string pstring;
    bool getPlayerChar = false;
    while (getPlayerChar == false)
    {
        cout << "Player character: ";
        getline(cin, pstring);

        if(pstring.length() != 1){
            cout << "Please input only one character.\n";
        }else{
            getPlayerChar = true;
        }
    }

    char returnme = pstring[0];
    return returnme;
}

/*
    TODO:
        >more than 2 players
        >player names (if I care enough)
        >scale the board based on player input (new branch)
        >tie game when full board

    BUGS:
        >int inputs for X and Y are still a little buggy, but better

*/