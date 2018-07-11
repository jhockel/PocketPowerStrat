// File: GameData.h
// Game Data will run excel implimentation of gameplay
#ifndef GAMEDATA
#define GAMEDATA

#include "character.h"
#include "space.h"
#include <vector>
using std::vector;

#define BOARD_SIZE 4

class gamedata {
public:

static vector<character> teamA;
static vector<character> teamB;

static space board[BOARD_SIZE][BOARD_SIZE];


// Member functions
// Import character from file
// import spell from file

static bool placeChar(int, int, character*);

static void cleanup();
};

#endif