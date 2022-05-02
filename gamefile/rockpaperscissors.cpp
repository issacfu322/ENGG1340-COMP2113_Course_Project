// description: play rock paper scissors game

#include "rockpaperscissors.h"

int numberofpshape;
int numberofcshape;
string playershape;
string computershape;
string shapes[3] = {"paper", "rock", "scissors"};
bool gamefinish = false;
bool winlose = false;

bool rockpaperscissors()
{
  srand(time(0));
  cout << "Time to play rock paper scissors!\n\n";
  cout << "Press [enter] to start..." << endl;
  while(cin.get() != '\n'); // Pause for player response
while ( !gamefinish )
{
  numberofcshape = rand() % 3; // get shapes from computer
  cout << "Paper, Rock or Scissors? (0 or 1 or 2)" << endl;
  cin >> numberofpshape; // get shapes from players
  playershape = shapes[numberofpshape];
  computershape = shapes[numberofcshape];

  if ( numberofpshape == 0 && numberofcshape == 0 )
  {
    cout << "Your shape: " << playershape;
    cout << endl;
    cout << "Computer shape: " << computershape;
    cout << endl;
    cout << "Tied! Play again!\n";
  }
  else if ( numberofpshape == 0 && numberofcshape == 1 )
  {
    cout << "Your shape: " << playershape;
    cout << endl;
    cout << "Computer shape: " << computershape;
    cout << endl;
    cout << "You win!\n";
    cout << "You did a lot of damage!\n\n";
    gamefinish = true;
    winlose = true;
  }
  else if ( numberofpshape == 0 && numberofcshape == 2 )
  {
    cout << "Your shape: " << playershape;
    cout << endl;
    cout << "Computer shape: " << computershape;
    cout << endl;
    cout << "You lose!\n";
    cout << "The attack seems to be ineffective...\n\n";
    gamefinish = true;
  }
  else if ( numberofpshape == 1 && numberofcshape == 0 )
  {
    cout << "Your shape: " << playershape;
    cout << endl;
    cout << "Computer shape: " << computershape;
    cout << endl;
    cout << "You lose!\n";
    cout << "The attack seems to be ineffective...\n\n";
    gamefinish = true;
  }
  else if ( numberofpshape == 1 && numberofcshape == 1 )
  {
    cout << "Your shape: " << playershape;
    cout << endl;
    cout << "Computer shape: " << computershape;
    cout << endl;
    cout << "Tied! Play again!\n";
  }
  else if ( numberofpshape == 1 && numberofcshape == 2 )
  {
    cout << "Your shape: " << playershape;
    cout << endl;
    cout << "Computer shape: " << computershape;
    cout << endl;
    cout << "You win!\n";
    cout << "You did a lot of damage!\n\n";
    gamefinish = true;
    winlose = true;
  }
  else if ( numberofpshape == 2 && numberofcshape == 0 )
  {
    cout << "Your shape: " << playershape;
    cout << endl;
    cout << "Computer shape: " << computershape;
    cout << endl;
    cout << "You win!\n";
    cout << "You did a lot of damage!\n\n";
    gamefinish = true;
    winlose = true;
  }
  else if ( numberofpshape == 2 && numberofcshape == 1 )
  {
    cout << "Your shape: " << playershape;
    cout << endl;
    cout << "Computer shape: " << computershape;
    cout << endl;
    cout << "You lose!\n";
    cout << "The attack seems to be ineffective...\n\n";
    gamefinish = true;
  }
  else if ( numberofpshape == 2 && numberofcshape == 2 )
  {
    cout << "Your shape: " << playershape;
    cout << endl;
    cout << "Computer shape: " << computershape;
    cout << endl;
    cout << "Tied! Play again!\n";
  }
}
  if ( winlose == true )
  {
    cin.get();  // ignore extra enter key
    gamefinish = false;
    return true;
  }

cin.get();  // ignore extra enter key
gamefinish = false;
return false;



}
