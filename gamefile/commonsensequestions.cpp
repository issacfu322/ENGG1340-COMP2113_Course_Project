// dsecription : answer some easy questions

#include "commonsensequestions.h"

int questionNumber;
bool winloses = false;
char answer;

bool commonsensequestions()
{
  srand(time(0));
  questionNumber = rand() % 5; // get question number
  cout << "You are going to answer a interesting question!\n";
  cout << "Press [enter] to start..." << endl;
  while(cin.get() != '\n'); // Pause for player response
  if (questionNumber == 0)
  {
    cout << "Is Marrakesh the capital of Morocco ? ( T or F )\n";
    cin >> answer;
    if ( answer == 'F')
    {
      cout << "You are correct!\n";
      cout << "You did a lot of damage!\n\n";
      winloses = true;
    }
    else
    {
      cout << "Wrong! It's Rabat!\n";
      cout << "You lose!\n";
      cout << "The attack seems to be ineffective...\n\n";
    }
  }
  if (questionNumber == 1)
  {
    cout << "Is the Great Wall of China is longer than ";
    cout << "the distance between London and Beijing ? ( T or F )\n";
    cin >> answer;
    if ( answer == 'T')
    {
      cout << "You are correct!\n";
      cout << "You did a lot of damage!\n\n";
      winloses = true;
    }
    else
    {
      cout << "Wrong! London to Beijing is only 8,136 km!\n";
      cout << "But the Great Wall of China is 21,196 km!";
      cout << "You lose!\n";
      cout << "The attack seems to be ineffective...\n\n";
    }
  }
  if (questionNumber == 2)
  {
    cout << "Is 'A' the most common letter used in the English language ? ( T or F )\n";
    cin >> answer;
    if ( answer == 'F')
    {
      cout << "You are correct!\n";
      cout << "You did a lot of damage!\n\n";
      winloses = true;
    }
    else
    {
      cout << "Wrong! 'E' is the most common letter!\n";
      cout << "according to Oxford Dictionaries, it appears in 11 percent of all english words\n";
      cout << "You lose!\n";
      cout << "The attack seems to be ineffective...\n\n";
    }
  }
  if (questionNumber == 3)
  {
    cout << "Is Alexander Fleming the one who discovered penicillin ? ( T or F )\n";
    cin >> answer;
    if ( answer == 'T')
    {
      cout << "You are correct!\n";
      cout << "You did a lot of damage!\n\n";
      winloses = true;
    }
    else
    {
      cout << "Go wiki this guy!\n";
      cout << "You lose!\n";
      cout << "The attack seems to be ineffective...\n\n";
    }
  }
  if (questionNumber == 4)
  {
    cout << "Is Venus the hottest planet in the solar system ? ( T or F )\n";
    cin >> answer;
    if ( answer == 'T')
    {
      cout << "You are correct!\n";
      cout << "You did a lot of damage!\n\n";
      winloses = true;
    }
    else
    {
      cout << "Wrong! Venus has an average surface temperature of around 450° C.\n";
      cout << "You lose!\n";
      cout << "The attack seems to be ineffective...\n\n";
    }
  }
  if (winloses == true)
  {
    cin.get();  // ignore extra enter key
    return true;
  }
  cin.get();  // ignore extra enter key
  return false;
}
