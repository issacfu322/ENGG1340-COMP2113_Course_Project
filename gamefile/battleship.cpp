//Description: Do battleship game, returning a bool

#include "battleship.h"

// set the position of ship for empty board
void setship(int b[10][10])
{
    int direction, x, y = 0;
    direction = rand() % 2 + 1;  // random vertical or horizontal direction
    if(direction == 1)  // vertical
    {
        //set position
        x = rand() % 10;
        y = rand() % 6;
        for(int j = y; j < y + 5; ++j)
        {
            b[x][j] = 1;  // set ship position
        }
    }
    else if(direction == 2)  // horizontal
    {
        //set position
        x = rand() % 6;
        y = rand() % 10;
        for(int i = x; i < x + 5; ++i)
        {
            b[i][y] = 1;  // set ship position
        }
    }
    else
    {
        cout << "unexpected error in setship" << endl;
    }

}

// print board, b is the board, fixed size
void printBoard(int b[10][10])
{
    cout << "\n-----------------------------------------\n";  // boarder
    for(int j = 0; j < 10; ++j)
    {
        cout << "|";
        for(int i = 0; i < 10; ++i)
        {
            if(b[i][j] == 0 || b[i][j] == 1)  // sea or hidden shipbody
                cout << "   |";
            else if(b[i][j] == 2)  // hit
                cout << " X |";
            else if(b[i][j] == 3)  // missed
                cout << " O |";
            else
                cout << " ? |";    // error
        }
        cout << "\n-----------------------------------------\n";  // boarder
    }
}

// Determine the landing of shots
void boardcheck(int b[10][10], int x, int y)
{
    if(b[x][y] == 0 || b[x][y] == 3)  // Sea or missed
    {
        cout << "\n\nMissed!\n";
        b[x][y] = 3;
    }
    else if(b[x][y] == 1 || b[x][y] == 2)  // Hit or shipbody
    {
        cout << "\n\nHit!";
        b[x][y] = 2;
    }
    else
    {
        cout << "unexpected error in boardcheck\n";
    }
}

// Check if any ship remains
bool noremain(int b[10][10])
{
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            if(b[i][j] == 1)  // Shipbody
            {
                return false;
            }
        }
    }
    return true;
}

bool battleship()
{
    bool win = false;
    cout << "Time for battleship game!\n\n";
    cout << "Press [enter] to start..." << endl;
    while(cin.get() != '\n');  // Pause for player response
    srand(time(0));            // seed for random number generation

    /** Item values on board, will be used for many times
    *const int sea = 0;
    *const int shipbody = 1;
    *const int hit = 2;
    *const int missed = 3;
    */

    // Create board
    const int boardsize = 10;
    int board[boardsize][boardsize];  // Board is stored in 2D array
    for(int i = 0; i < boardsize; ++i)
    {
        for(int j = 0; j < boardsize; ++j)
        {
            board[i][j] = 0;  // Set each slot as sea
        }
    }

    setship(board);
    printBoard(board);
    int ammo = 25;
    cout << "Each side of board starts from 0 to 9 (rightward and downward).\n";
    cout << "The ship is five-blocks long.\n";
    cout << "You have " << ammo << " shots left.\n";
    cout << "Please enter the coordinates xy e.g.(01)\n";
    string pos = "";
    while(pos != "exit" && ammo > 0)
    {
        cout << "Coordinates: ";
        getline(cin, pos);     // get user input
        if(pos.length() == 2)  // check input size
        {
            int in_x = atoi(pos.c_str()) / 10;
            int in_y = atoi(pos.c_str()) % 10;
            if(in_x < 10 && in_x >= 0 && in_y < 10 && in_y >= 0)  // check coordinates
            {
                --ammo;
                boardcheck(board, in_x, in_y);
                printBoard(board);
                cout << "You have " << ammo << " shots left.\n";
                if(board[in_x][in_y] == 2 && noremain(board))  // check win condition
                {
                    win = true;
                    cout << "\nYou win!\n";
                    cout << "You did a lot of damage!\n\n";
                    ammo = 0;  // end game
                }
            }
            else
            {
                cout << "\n\nInvalid input, shot was missed.\n";
                --ammo;
                printBoard(board);
                cout << "You have " << ammo << " shots left.\n";
            }
        }
        else
        {
            cout << "\n\nInvalid input, shot was missed.\n";
            --ammo;
            printBoard(board);
            cout << "You have " << ammo << " shots left.\n";
        }
    }
    if(!win)
    {
        cout << "\nYou lose!\n";
        cout << "The attack seems to be ineffective...\n\n";
    }
    return win;
}

