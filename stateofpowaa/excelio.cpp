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
const string GameSheet("GameBoard");
Book* gameBook = NULL;
Sheet* gamePage = NULL;

#define TLcR(RY,RX) (6+RY*8)
#define TLcC(RY,RX) (RY%2 ? 8+RX*4 : 6+RX*4)

// Excel Interaction Implimentations

int libxlio::openGameBook() {
    gameBook = xlCreateXMLBook();
    if(!gameBook) return 0;
    gamePage = gameBook->insertSheet(0,GameSheet.c_str());
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
    leftB->setBorderLeft(BORDERSTYLE_THICK);
    Format* rightB = gameBook->addFormat();
    rightB->setBorderRight(BORDERSTYLE_THICK);
    Format* bottomB = gameBook->addFormat();
    bottomB->setBorderBottom(BORDERSTYLE_THICK);
    
    Format* TLc = gameBook->addFormat();
    TLc->setBorderTop(BORDERSTYLE_THICK);
    TLc->setBorderLeft(BORDERSTYLE_THICK);
    Format* TRc = gameBook->addFormat();
    TRc->setBorderTop(BORDERSTYLE_THICK);
    TRc->setBorderRight(BORDERSTYLE_THICK);
    Format* BLc = gameBook->addFormat();
    BLc->setBorderBottom(BORDERSTYLE_THICK);
    BLc->setBorderLeft(BORDERSTYLE_THICK);
    Format* BRc = gameBook->addFormat();
    BRc->setBorderBottom(BORDERSTYLE_THICK);
    BRc->setBorderRight(BORDERSTYLE_THICK);
    
    gamePage->setCol(0,30,5.5);
    // First, draw outer boarder 
    // Top Left corner: (8,4)
    // 5.5x5 spaces:
    // 22x40 cells
    
    gamePage->writeBlank(2,4,TLc);
    gamePage->writeBlank(2,25,TRc);
    gamePage->writeBlank(41,4,BLc);
    gamePage->writeBlank(41,25,BRc);
    
    for(int i = 5; i<25; i++) {
        gamePage->writeBlank(2,i,topB);
        gamePage->writeBlank(42,i,topB);
    }
    for(int i = 3; i<41; i++) {
        gamePage->writeBlank(i,4,leftB);
        gamePage->writeBlank(i,26,leftB);
    }
    
    for(int x = 0; x<4; x++)
        for(int y = 0; y<4; y++) {
            gamePage->writeBlank(TLcR(x,y),TLcC(x,y),TLc);
            gamePage->writeBlank(TLcR(x,y),TLcC(x,y)+3,TRc);
            gamePage->writeBlank(TLcR(x,y)+7,TLcC(x,y),BLc);
            gamePage->writeBlank(TLcR(x,y)+7,TLcC(x,y)+3,BRc);
            for(int z = 1; z<3; z++){
                gamePage->writeBlank(TLcR(x,y),TLcC(x,y)+z,topB);
                gamePage->writeBlank(TLcR(x,y)+7,TLcC(x,y)+z,bottomB);
            }
            for(int z = 1; z<7; z++){
                gamePage->writeBlank(TLcR(x,y)+z,TLcC(x,y),leftB);
                gamePage->writeBlank(TLcR(x,y)+z,TLcC(x,y)+3,rightB);
            }
        }
    
}