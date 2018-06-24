// File: GameData.h
#ifndef GAMEDATA
#define GAMEDATA

#include "character.h"
#include "space.h"
#include <vector>
using std::vector;

#define BOARD_SIZE 4

class gamedata {
public:

vector<character> teamA;
vector<character> teamB;

space board[BOARD_SIZE][BOARD_SIZE];


};

#endif