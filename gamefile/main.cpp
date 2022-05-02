//Description: The main program of the game

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include "roll_dice.h"             // roll_dice();
#include "guess_num.h"             // guess_num();
#include "battleship.h"            // battleship();
#include "blackjack.h"             // blackjack();
#include "commonsensequestions.h"  // commonsensequestions();
#include "rockpaperscissors.h"     // rockpaperscissors();
using namespace std;

vector<string> ingame_status;  // Dynamic array for storing game progress

// get string input
string str_input()
{
    string str;
    char * user_input = NULL;           // a dynamic array for storing the user input
    int input_size;
    get_input(user_input, input_size);  // function from guess_num.h
    for(int i = 0; i < input_size; ++i)
    {
        str = str + user_input[i];
    }
    if(user_input != NULL)  // delete dynamic array
    {
        delete [] user_input;
    }
    return str;
}

// do game save in save.txt
void gameSave()
{
    string data = "";
    for(int i = 0; i < ingame_status.size(); ++i)
    {
        data = data + ingame_status[i] + ",";
    }
    
    ofstream fout ("save.txt");
    if(fout.is_open())
    {
        fout << data << endl;
        fout.close();
        cout << "Game progress is saved.\n";
    }
    else
    {
        cout << "Unable to open/create file\n";
        cout << "Game progress is not saved.\n";
    }
}

// Auto game save
void autoSave()
{
    cout << "Autosaving...Please wait...\n\n";
    gameSave();
}

// do game load by reading from save.txt
string gameLoad()
{
    string data;
    ifstream fin ("save.txt");
    if(fin.is_open())
    {
        string line;
        while(getline(fin, line))
        {
            data = data + line;
        }
        fin.close();
        cout << "Game progress is loaded.\n";
    }
    else
    {
        cout << "Unable to load game save\n";
        data = "";
    }
    return data;
}

//randomly pick a game
bool pickGame()
{
    srand(time(0));
    int game_code;
    bool winstate = false;
    game_code = rand() % 6 + 1; // games from 1 to 6
    if(game_code == 1)
    {
        winstate = roll_dice();
    }
    else if(game_code == 2)
    {
        winstate = guess_num();
    }
    else if(game_code == 3)
    {
        winstate = battleship();
    }
    else if(game_code == 4)
    {
        winstate = blackjack();
    }
    else if(game_code == 5)
    {
        winstate = commonsensequestions();
    }
    else if(game_code == 6)
    {
        winstate = rockpaperscissors();
    }
    return winstate;
}

vector<string> house_type {"straw", "wood", "brick"};  // options for user to choose

void printHouse()  // print house remaining
{
    for(int i = 0; i < house_type.size(); ++i)
    {
        cout << i + 1 << ":" << house_type[i] << " house  ";
    }
    cout << endl;
}

void delHouse(string h)  // remove house that was chosen
{
    for(int i = 0; i < house_type.size(); ++i)
    {
        if(house_type[i] == h)
        {
            house_type.erase(house_type.begin() + i);
        }
    }
}

string winorlose(bool WinOrLose)
{
  if ( WinOrLose )
  {
    return "win";
  }
  return "lose";
}

int main()
{
    // Start Game
    cout << "THE ADVENTURE OF WOLF\n\n";
    cout << "created by Ken and Issac.\n\n";
    cout << "Press [enter] to start..." << endl;
    while(cin.get() != '\n');  // Pause for player response

    string load_status = "0,";  // For loading game
    string tmp = "";
    string house = "";
    int gameLevel = 0;
    int read_start = 0;
    string user_input = "";
    int defense;
    int battle = 0;
    bool WinOrLose;
    cout << "Do you want to load game?(y/n)\n";  // Load game option
    user_input = str_input();                    // Get user input
    while(user_input != "y" && user_input != "Y" && user_input != "n" && user_input != "N")
    {
        user_input = str_input();
    }
    if(user_input == "y" || user_input == "Y")
    {
        load_status = gameLoad();
        if(load_status != "")
        {
            // Read load_status
            for(int i = 0; i < load_status.size(); ++i)
            {
                if(load_status[i] == ',')
                {
                    tmp = load_status.substr(read_start, i - read_start);
                    ingame_status.push_back(tmp);
                    read_start = i + 1;
                }
            }
            
            // Assign values
            gameLevel = atoi(ingame_status[0].c_str());   // Read game level
            battle = atoi(ingame_status[1].c_str());   // Read game level
            int _i = 2;
            while(_i < ingame_status.size())
            {
                delHouse(ingame_status[_i]);
                house = ingame_status[_i];
                _i += 2;
            }
        }
        else
        {
            ingame_status.push_back("0");  // game level
            ingame_status.push_back("0");  // battle
        }
    }
    else
    {
        ingame_status.push_back("0");  // game level
        ingame_status.push_back("0");  // battle
    }

    bool gameEnd = false;
    while(!gameEnd)
    {
        WinOrLose = false;
        // cout << gameLevel << endl;  // for checking
        if(gameLevel == 0)
        {
            // Story time 1, progress and choices can be save
            // in status using (,) or by index range
            cout << "The story starts in a grassland.\n";
            cout << "You are a wolf and you feel very very hungry.\n";
            cout << "Is there anything to eat?\n\n";
            cout << "Press [enter] to search..." << endl;
            while(cin.get() != '\n');                      // Pause for player response
            cout << "You found three houses in the grassland.\n";
            cout << "Each house has a juicy pig inside.\n";
            cout << "They must be delicious!\n\n";
            cout << "Which house would you break in first?\n";
            printHouse();
            cout << "Your choice: ";
            house = str_input();

            if(house == "1" || house == "straw")
            {
                delHouse("straw");
                house = "straw";
            }
            else if(house == "2" || house == "wood")
            {
                delHouse("wood");
                house = "wood";
            }
            else if(house == "3" || house == "brick")
            {
                delHouse("brick");
                house = "brick";
            }
            else
            {
                cout << "Invalid input, you randomly chose a house.\n";
                cout << "It was a " << house_type[0] << " house.\n";
                house = house_type[0];
                delHouse(house_type[0]);
            }

            ingame_status[0] = "1";
            ingame_status[1] = to_string(battle);
            ingame_status.push_back(house);
            autoSave();
        }
        else if(gameLevel == 1)
        {
            // First Battle, store battle result in status
            if ( house == "straw" )
            {
                defense = 1;
                if ( pickGame() )
                {
                    defense -= 1;
                }
                if ( defense == 0 )
                {
                    battle += 1;
                }
            }
            if ( house == "wood" )
            {
                defense = 2;
                for ( int i = 0; i < 2; i++ )
                {
                    if ( pickGame() )
                    {
                        defense -= 1;
                        WinOrLose = true;
                    }
                }
                if ( defense == 0 )
                {
                    battle += 1;
                    WinOrLose = true;
                }
            }
            if ( house == "brick" )
            {
                defense = 3;
                for ( int i = 0; i < 3; i++ )
                {
                    if ( pickGame() )
                    {
                        defense -= 1;
                    }
                    if ( defense == 0 )
                    {
                        battle += 1;
                        WinOrLose = true;
                    }
                }
            }


            ingame_status[0] = "2";
            ingame_status[1] = to_string(battle);
            ingame_status.push_back(winorlose(WinOrLose));
            autoSave();
        }
        else if(gameLevel == 2)
        {
            // Story time 2, progress and choices can be save
            // in status using (,) or by index range
            cout << "Press [enter] to continue searching..." << endl;
            while(cin.get() != '\n');                      // Pause for player response
            cout << "There are no other houses, only two choices left, which one would you pick?\n";
            printHouse();
            cout << "Your choice: ";
            house = str_input();

            if(house == "1")
            {
                house = house_type[0];
                delHouse(house_type[0]);
            }
            else if(house == "2")
            {
                house = house_type[0];
                delHouse(house_type[0]);
            }
            else
            {
                cout << "Invalid input, you randomly chose a house.\n";
                cout << "It was a " << house_type[0] << " house.\n";
                house = house_type[0];
                delHouse(house_type[0]);
            }

            ingame_status[0] = "3";
            ingame_status[1] = to_string(battle);
            ingame_status.push_back(house);
            autoSave();
        }
        else if(gameLevel == 3)
        {
            // Second Battle, store battle result in status
            if ( house == "straw" )
            {
                defense = 1;
                if ( pickGame() )
                {
                    defense -= 1;
                }
                if ( defense == 0 )
                {
                    battle += 1;
                    WinOrLose = true;
                }
            }
            if ( house == "wood" )
            {
                defense = 3;
                for ( int i = 0; i < 3; i++ )
                {
                    if ( pickGame() )
                    {
                        defense -= 1;
                    }
                }
                if ( defense == 0 )
                {
                    battle += 1;
                    WinOrLose = true;
                }
            }
            if ( house == "brick" )
            {
                defense = 4;
                for ( int i = 0; i < 4; i++ )
                {
                    if ( pickGame() )
                    {
                        defense -= 1;
                    }
                    if ( defense == 0 )
                    {
                        battle += 1;
                        WinOrLose = true;
                    }
                }
            }


            ingame_status[0] = "4";
            ingame_status[1] = to_string(battle);
            ingame_status.push_back(winorlose(WinOrLose));
            autoSave();
        }
        else if(gameLevel == 4)
        {
            // Story time 3, progress and choices can be save
            // in status using (,) or by index range
            cout << "It seems there is only one choice left.\n";
            printHouse();
            cout << "There is no need for choosing.\n";
            cout << "Press [enter] to continue..." << endl;
            while(cin.get() != '\n');  // Pause for player response
            house = house_type[0];
            delHouse(house_type[0]);

            ingame_status[0] = "5";
            ingame_status.push_back(house);
            autoSave();
        }
        else if(gameLevel == 5)
        {
            // Third Battle, store battle result in status
            if ( house == "straw" )
            {
                defense = 2;
                for ( int i = 0; i < 2; i++ )
                {
                    if ( pickGame() )
                    {
                        defense -= 1;
                    }
                    if ( defense == 0 )
                    {
                        battle += 1;
                        WinOrLose = true;
                    }
                }
            }
            if ( house == "wood" )
            {
                defense = 3;
                for ( int i = 0; i < 3; i++ )
                {
                    if ( pickGame() )
                    {
                        defense -= 1;
                    }
                }
                if ( defense == 0 )
                {
                    battle += 1;
                    WinOrLose = true;
                }
            }
            if ( house == "brick" )
            {
                defense = 5;
                for ( int i = 0; i < 5; i++ )
                {
                    if ( pickGame() )
                    {
                        defense -= 1;
                    }
                    if ( defense == 0 )
                    {
                        battle += 1;
                        WinOrLose = true;
                    }
                }
            }


            ingame_status[0] = "6";
            ingame_status[1] = to_string(battle);
            ingame_status.push_back(winorlose(WinOrLose));
            autoSave();
            gameEnd = true;
        }
        else if(gameLevel == 6)
        {
            break;
        }
        else
        {
            cout << "Unexpected gameLevel\n";
            exit(-1);
        }

        // Read ingame_status and assign values
        gameLevel = atoi(ingame_status[0].c_str());

    }

    // Ending
    if ( battle == 0 )
    {
     cout << "You are too weak! You can't even get 1 pig for tonight dinner!\n";
     cout << "Three pigs are allied to catch now!\n";
    }
    else if ( battle == 1 )
    {
     cout << "You got one pig for tonight dinner!\n";
     cout << "Congratulations!\n";
    }
    if ( battle == 2 )
    {
     cout << "Not bad! You got two pigs for tonight dinner!\n";
     cout << "Congratulations!\n";
    }
    if ( battle == 3 )
    {
     cout << "Wow you got all pigs for tonight dinner!\n";
     cout << "You are the King of wolves!\n";
    }
    cout << "End\n";

    return 0;
}
