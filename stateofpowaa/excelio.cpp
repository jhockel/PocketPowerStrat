// File: excelio.cpp
// Imp file for excelio functions

#include "character.h"
#include <iostream>
#include <string>
using std::string;
#include "libxl.h"
using namespace libxl;
#include "excelio.h"

// KEY METRICS:

// SPACE SIZE:          4x8 cells
// DEFAULT BOARD SIZE:  4x4 spaces

// For Draw Space X,Y:
// Xe = Y%2? X0 + 4*X : X0 + 2 + 4*X%2
// Ye = Y0 + Y*8

// To Move from X,Y:
// dX: +/-1
// dY: Y%2? X=X|X-1 : X|X+1
    
// // LibXL Constants:
const string GameBoard("Gameplay/game.xlsx");
Book* gameBook = NULL;
Sheet* gamePage = NULL;

// Excel Interaction Implimentations

int libxlio::openGameBook() {
    gameBook = xlCreateXMLBook();
    if(!gameBook->load(GameBoard.c_str())) return 0;
    gamePage = gameBook->getSheet(0);
    if(!gamePage) return 0;
    return 1;
}
void libxlio::closeGameBook(bool save) {
    if(save) gameBook->save(GameBoard.c_str());
    gameBook->release();
}

int libxlio::readinchar() {
    
    return 0;
}
int libxlio::readinspell() {
    
    return 0;
}
    
int libxlio::drawspace(character& c, int x, int y) {
    
    return 0;
}
int libxlio::clearspace(int x, int y) {
    
    return 0;
}

void libxlio::drawboard() {
    Format* topB = gameBook->addFormat();
    topB->setBorderTop(BORDERSTYLE_THICK);
    Format* leftB = gameBook->addFormat();
    topB->setBorderLeft(BORDERSTYLE_THICK);
    
    gamePage->writeBlank(3,3,topB);
    gamePage->writeBlank(3,4,leftB);
    
    
}