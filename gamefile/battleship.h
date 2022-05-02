#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

void setship(int b[10][10]);
void printBoard(int b[10][10]);
void boardcheck(int b[10][10], int x, int y);
bool noremain(int b[10][10]);
bool battleship();

#endif

