#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <array>

using namespace std;

int sumHand( int hands[5] );
void addCard(int * hand[5], int * handSize);
void printHand();
bool blackjack();

#endif
