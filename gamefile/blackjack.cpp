// Description : Run game of blackjack, return a bool

#include "blackjack.h"

int playerhand[5];
int dealerhand[5];
int playerhandSize;
int dealerhandSize;
int playerhandSum;
int dealerhandSum;

void sumHand() // calculate sum of cards value
{
  playerhandSum = 0;
  dealerhandSum = 0;
  for (int i = 0; i < dealerhandSize; i++)
  {
      dealerhandSum += dealerhand[i];
  }

  for (int j = 0; j < playerhandSize; j++)
  {
      playerhandSum += playerhand[j];
  }

  cout << "player hand sum is: " << playerhandSum << endl;
}

void playeraddCard() // give card to player
{
    if (playerhandSize < 5)
    {
        playerhand[playerhandSize] = 1 + (rand() % 11);
        playerhandSize++;
    }
}

void dealeraddCard() // give card to player
{
    if (dealerhandSize < 5)
    {
        dealerhand[dealerhandSize] = 1 + (rand() % 11);
        dealerhandSize++;
    }

}

void printHand()
{
    cout << "Your current hand is ";

    for (int i = 0; i < playerhandSize; i++)
    {
        cout << playerhand[i] << " ";
    }
    cout << endl;

    cout << "Dealer's current hand is ";

    for (int j = 1; j < dealerhandSize; j++)
    {
        cout << dealerhand[j] << " ";
    }
    cout << endl;
}


bool blackjack()
{
  srand(time(0));
  cout << "Time to play blackjack!\n\n";
  cout << "Press [enter] to start..." << endl;
  while(cin.get() != '\n'); // Pause for player response
  playeraddCard(); // round 1
  playeraddCard();
  dealeraddCard();
  dealeraddCard();
  printHand();
  sumHand();

  char YesorNo = ' ';
  while ( playerhandSum < 21 || dealerhandSum < 21 )
    {
        if (playerhandSum < 21)
        {
            cout << "hit? (Y or N)\n";
            cin >> YesorNo;

            if (YesorNo == 'Y')
            {
                playeraddCard();
            }
        }
       dealeraddCard();
       printHand();
       sumHand();
       if ( playerhandSize == 5 || dealerhandSize == 5 )
       {
         break;
       }
    }




  if (playerhandSum > 21)
  {
    cout << "Player's hand exceeded 21. Player loses.\n";
    for ( int i = 0; i < 5; i++ )
    {
    playerhand[i] = 0;
    }
    for ( int i = 0; i < 5; i++ )
    {
    dealerhand[i] = 0;
    }
    playerhandSize = 0;
    dealerhandSize = 0;
    cin.get();  // ignore extra enter key
    return false;
  }
  if ( dealerhandSum > 21 )
  {
    cout << "Player wins\n";
    for ( int i = 0; i < 5; i++ )
    {
      playerhand[i] = 0;
    }
    for ( int i = 0; i < 5; i++ )
    {
      dealerhand[i] = 0;
    }
    playerhandSize = 0;
    dealerhandSize = 0;
    cin.get();  // ignore extra enter key
    return true;
  }
  if (playerhandSum < 21 && dealerhandSum < 21 )
  {
    if ( playerhandSum > dealerhandSum )
    {
      cout << "Player wins\n";
      for ( int i = 0; i < 5; i++ )
      {
      playerhand[i] = 0;
      }
      for ( int i = 0; i < 5; i++ )
      {
      dealerhand[i] = 0;
      }
      playerhandSize = 0;
      dealerhandSize = 0;
      cin.get();  // ignore extra enter key
      return true;
    }
    else
    {
      cout << "Player loses\n";
      for ( int i = 0; i < 5; i++ )
      {
      playerhand[i] = 0;
      }
      for ( int i = 0; i < 5; i++ )
      {
      dealerhand[i] = 0;
      }
      playerhandSize = 0;
      dealerhandSize = 0;
      cin.get();  // ignore extra enter key
      return false;
    }
  }
if (playerhandSum == 21)
{
  cout << "Player wins\n";
for ( int i = 0; i < 5; i++ )
{
  playerhand[i] = 0;
}
  for ( int i = 0; i < 5; i++ )
{
  dealerhand[i] = 0;
}
playerhandSize = 0;
dealerhandSize = 0;
  cin.get();  // ignore extra enter key
  return true;
}
for ( int i = 0; i < 5; i++ )
{
  playerhand[i] = 0;
}
  for ( int i = 0; i < 5; i++ )
{
  dealerhand[i] = 0;
}
playerhandSize = 0;
dealerhandSize = 0;
cin.get();  // ignore extra enter key
return false;
}
