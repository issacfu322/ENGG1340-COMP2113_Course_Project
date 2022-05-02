#ifndef GUESS_NUM_H
#define GUESS_NUM_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <cctype>

using namespace std;

void grow_array(char * & array, int & size);
void get_input(char * & user_in, int & inSize);
bool guess_num();

#endif

