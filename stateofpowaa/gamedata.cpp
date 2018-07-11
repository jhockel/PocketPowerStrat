// File: gamedata.cpp

#include "gamedata.h"

vector<character> gamedata::teamA;
vector<character> gamedata::teamB;

space gamedata::board[BOARD_SIZE][BOARD_SIZE];

bool gamedata::placeChar(int x, int y, character *c){
    if(board[x][y].occupant != NULL) return false;
    board[x][y].occupant = c;
    return true;
}
// Eventually this function should save log data
void gamedata::cleanup(){
    while(!teamA.empty()){
        teamA.pop_back();
    }
   while(!teamB.empty()){
        teamB.pop_back();
    }
}