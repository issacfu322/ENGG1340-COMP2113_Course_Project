# ENGG1340-COMP2113_Course_Project
## Group 130
Group members+UID: Cheng Ho Kin (3035779612), Fu Kin Hang (3035801403)

## Description
Our group designed a text-based adventure game which is based on the story of three little pigs. The player will role-play as the wolf that tries to eat the pigs. The game will be divided into three parts with respect to the three pigs. Player will try to destroy house of pigs and decide whether the wolf should eat them. Choices of the player will lead to different endings.

Each part will start with deciding which house the wolf would break in. Then there will mini games that decide how much damage can the wolf do to the house. The house will collapse if damage is high enough. Mini games will include rolling dice, guessing number, Blackjack, Battleship, common knowledge questions and rock-paper-scissors.

## Features
1. Generation of random game sets or events
   - The mini games are chosen in random manner, events in each game are randomized.

2. Data structures for storing game status
   - Player's status and choices are stored in arrays (e.g. string arrays).

3. Dynamic memory management
   - There are memory allocations based on the game progress and player's inputs using linked list and vector.

4. File input/output
   - The game status can be load and save in file.

5. Program codes in multiple files
   - The mini games are implemented in separate files, and used in the main game file.

## Compliation and execution instructions
1. Download the gamefile
2. cd gamefile
3. make main
4. ./main

## Sample input/output file
As the game contains lots of random events, the file only showcases the full game play in text.

