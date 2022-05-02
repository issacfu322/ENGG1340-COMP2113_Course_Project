//Description: Do roll two dice game, returning a bool

#include "roll_dice.h"

bool roll_dice()
{
    cout << "Time for rolling dice!\n";
    cout << "Try to get larger than ten!\n\n";
    cout << "Press [enter] to roll dice..." << endl;
    while(cin.get() != '\n'); // Pause for player response
    srand(time(0));           // seed for random number generation
    int die_1, die_2 = 0;
    die_1 = rand() % 6 + 1;   // die number between 1 to 6
    die_2 = rand() % 6 + 1;

    cout << "The first die is " << die_1 << ".\n";
    cout << "The second die is " << die_2 << ".\n\n";

    if(die_1 + die_2 >= 10)
    {
        cout << "You win!\n";
        cout << "You did a lot of damage!\n\n";
        return true;
    }
    else
    {
        cout << "You lose!\n";
        cout << "The attack seems to be ineffective...\n\n";
        return false;
    }
}

