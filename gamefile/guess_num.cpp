//Description: Do guess number game, returning a bool

#include "guess_num.h"

// double the capacity of an array
// array: input array
// size: original size of array, updated to new size of array
void grow_array( char * & array, int & size )
{
    if (array == NULL)
        return;

    int newSize = size * 2;

    // doubled the size of the array;
    char * tmp = new char [newSize];
    // copy original contents
    for (int i = 0; i < size; ++i)
        tmp[i] = array[i];

    delete [] array;

    array = tmp;
    size = newSize;
}

// get an input from the user
// all chars are store in a dynamic array
// user_in: char array that stores user input
// inSize: number of chars read from input
void get_input(char * & user_in, int & inSize)
{
    int arraysize = 32;
    user_in = new char [arraysize];
    char c;
    int charRead = 0;

    // read each digit as a character until a white space is hit
    c = cin.get();
    while (!isspace(c))
    {
        if (charRead >= arraysize)
            grow_array(user_in, arraysize);

        user_in[charRead] = c;
        charRead++;

        c = cin.get();
    }

    inSize = charRead;

}

bool guess_num()
{
    bool win = false;
    cout << "Time for guessing number!\n\n";
    cout << "Press [enter] to start..." << endl;
    while(cin.get() != '\n');  // Pause for player response
    srand(time(0));            // seed for random number generation
    int target;
    int chances = 3;
    target = rand() % 9 + 1;   // Number chosen between 1 to 9
    cout << "I have chosen a number, it is between 1 to 9.\n";
    cout << "Do you know what it is?\n";

    while(chances > 0)
    {
        cout << "Number: ";
        char * user_in = NULL;  // a dynamic array for storing the user input
        int inSize, val;
        string str;
        str.clear();
        get_input(user_in, inSize);

        if(inSize != 1)  // check array size
        {
            cout << "Invalid input.\n";
            --chances;
            cout << "You have " << chances << " chances left.\n\n";
        }
        else
        {
            if(isdigit(user_in[0]))  // check if input is number
            {
                str = str + user_in[0];
                val = atoi(str.c_str());
                if(val > target)
                {
                    cout << "Too large.\n";
                    --chances;
                    cout << "You have " << chances << " chances left.\n\n";
                }
                else if(val < target)
                {
                    cout << "Too small\n";
                    --chances;
                    cout << "You have " << chances << " chances left.\n\n";
                }
                else
                {
                    cout << "You are correct!\n";
                    cout << "You did a lot of damage!\n\n";
                    win = true;
                    chances = 0;  // end game
                }
            }
            else
            {
                cout << "Invalid input\n";
                --chances;
                cout << "You have " << chances << " chances left.\n\n";
            }
        }

        if(user_in != NULL)  // delete dynamic array
        {
            delete [] user_in;
        }
    }
    if(!win)
    {
        cout << "You lose!\n";
        cout << "The attack seems to be ineffective...\n\n";
    }
    return win;
}

