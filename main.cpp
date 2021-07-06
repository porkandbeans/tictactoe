#include <iostream>
#include <string>

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

    char pchar1;
    char pchar2;
    cout << "~~~ Tic Tac Toe ~~~\n";

    cout << "Player 1 character: ";
    cin >> pchar1;
    cout << "Player 2 character: ";
    cin >> pchar2;

    static char _pchars[2]{pchar1, pchar2};

    // these will become inputs later
    static char board[3][3];
    int cells = 3, turn = 0;

    // init the board
    for (int y = 0; y < cells; y++)
    {
        for (int x = 0; x < cells; x++)
        {
            board[y][x] = ' ';
        }
    }

    // start looping for the game
    bool gameOver = false;
    int _x, _y;

    cout << "~~ GAME BEGINS ~~\n";
    while (!gameOver)
    {
        // == X INDEX ==
        cout << " |";
        for (int i = 0; i < cells; i++)
        {
            cout << ' ' << i + 1 << " |";
        }
        // end of row
        cout << endl
             << "--";

        for (int i = 0; i < cells; i++)
        {
            cout << "----";
        }
        cout << endl;

        for (int y = 0; y < cells; y++)
        {
            // == Y INDEX ==
            cout << y + 1 << '|';
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

        // change the cell by input
        cout << "Player " << turn + 1 << " X co-ordinate: ";
        cin >> _x;
        cout << "Player " << turn + 1 << " Y co-ordinate: ";
        cin >> _y;

        board[_y - 1][_x - 1] = _pchars[turn];

        //swap turn
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
        reformat
        more than 2 players
        player names
        watch the rest of the video lol
    
    for the love of god, I will get this to perform exactly the same as the one at the start
*/