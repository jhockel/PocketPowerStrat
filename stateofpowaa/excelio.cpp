// File: excelio.cpp
// Imp file for excelio functions

#include "excelio.h"

#include <iostream>
#include <stdio.h>
#include <string>
using std::string;
#include "libxl.h"
using namespace libxl;

#include "character.h"
#include "backbone.h"

// KEY METRICS:

// SPACE SIZE:          4x8 cells
// DEFAULT BOARD SIZE:  4x4 spaces

// For Draw Space y,x:
// Xe = Y%2? X0 + 4*X : X0 + 2 + 4*X%2
// Ye = Y0 + Y*8

// To Move from y,x:
// dX: +/-1
// dY: Y%2? X=X|X-1 : X|X+1

// Constants for sheets
#define CHAR_SHEET_HEADER 7

// Macros for the metrics: TLcR returns TOP LEFT CORNERS ROW, TLcC returns COL
#define TLcR(RX,RY) (6+RY*8)
#define TLcC(RX,RY) (RY%2 ? 8+RX*4 : 6+RX*4)
    
// Define String Constants:: 
const string libxlio::GameBoard="Gameplay/game.xlsx";
const string libxlio::GameSheet="GameBoard";
const string libxlio::teamAbook_="Gameplay/teamA.xlsx";
const string libxlio::teamBbook_="Gameplay/teamB.xlsx";

// Character String Constants
const string libxlio::bbenum[] = {
    "health",         // 0
    "health_regen",   // 1
    "mana",           // 2
    "mana_regen",     // 3
    "attk",           // 4
    "move",           // 5
    "phys_blk",       // 6
    "mag_blk",        // 7
    "true_blk",       // 8
    "phys_evas",      // 9
    "mag_evas",       // 10
    "true_evas",      // 11
    "rand_roll"       // 12"
    };
const string libxlio::pbenum[] = {
    "phys_arm",       // 0 %% PERCENT
    "mag_arm",        // 1 %% PERCENT
    "true_arm",       // 2 %% PERCENT
    "attk_splash",    // 3 %% PERCENT
    "attk_range",     // 4 %% PERCENT
    "speed"           // 5 %% PERCENT
};
const string libxlio::sbenum[] = {
    "physique",       // 0 ## SCALAR: STRENGTH vs ACCURACY: attack SPLASH vs RANGE
    "mana_color",     // 1 ## SCALAR: LIGHT vs DARK: 
    "mana_weight",    // 2 ## SCALAR: HEAVY vs LIGHT:
    "attk_splash_type"// 3 ## SCALAR: defines SPLASH, CLUSTER, or SPLIT
};

// Spell String Constants
const string libxlio::spenum[] = {
    "power",
    "reroll"
};
const string libxlio::sppenum[] = {
    "targettype",
    "targetaim",
    "duration"
};
const string libxlio::ssenum[] = {
    "spell_rand"
};

Book* libxlio::gameBook = NULL;
Sheet* libxlio::gamePage = NULL;
    
    
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
    Book* teamBook = xlCreateXMLBook();
    int charCount = 0;
    if(teamBook->load(teamAbook_.c_str())) {
        Sheet* charSheet = teamBook->getSheet(0);
        if(charSheet) {
            for(int i_=0; i_<8; i_++){
                int i = 4*i_+5;
                const char* name_ = charSheet->readStr(3,i);
                if(name_ != NULL){
                    charCount++;
                    string name(name_);
                    
                    
                }
            }
        }
    }
    
    printf("got %d of em\n", charCount);
    
    teamBook->release();
    return charCount;
}
int libxlio::readinspell() {
    
    return 0;
}
    
int libxlio::drawspace(character& c, int x, int y) {
    int row = TLcR(y,x);
    int col = TLcC(y,x);
    gamePage->writeStr(row,col,c.name.c_str());
    gamePage->writeNum(row,col+2,c.getTotalPower());
    gamePage->writeStr(row+1,col,"HP");
    gamePage->writeNum(row+1,col+1,(double)c.health/(double)c.getTrue(health));
    gamePage->writeNum(row+1,col+2,c.health);
    gamePage->writeNum(row+1,col+3,c.getTrue(health));
    gamePage->writeStr(row+2,col,"MANA");
    gamePage->writeNum(row+2,col+1,(double)c.mana/(double)c.getTrue(mana));
    gamePage->writeNum(row+2,col+2,c.mana);
    gamePage->writeNum(row+2,col+3,c.getTrue(mana));
    gamePage->writeStr(row+3,col+2,"ATTK");
    gamePage->writeNum(row+3,col+3,c.getTrue(attk));
    gamePage->writeStr(row+4,col+2,"MV");
    gamePage->writeNum(row+4,col+3,c.getTrue(movement));
    return 1;
}
int libxlio::clearspace(int x, int y) {
    
    return 0;
}
int libxlio::drawinputsheets(){
    Book* teamAbook = xlCreateXMLBook();
    if(!teamAbook) return 0;
    
    Format* inpBox = teamAbook->addFormat();
    inpBox->setBorderTop(BORDERSTYLE_THICK);
    inpBox->setBorderLeft(BORDERSTYLE_THICK);
    inpBox->setBorderRight(BORDERSTYLE_THICK);
    inpBox->setBorderBottom(BORDERSTYLE_THICK);
    
    // Draw CHARACTER INPUT SHEET
    
    Sheet* char_inv = teamAbook->insertSheet(0,"Char Inv");

    // COL data (i): 4*i + 4
    // ROW data (j): j + 4              NOTE: replaced const 4 with CHAR_SHEET_HEADER
    //               j + BB_SIZE + 6
    //               j + BB_SIZE + PB_SIZE + 8
    
    // Draw Initial Conversion Stats:
    {   
        int i = 1;
        char_inv->setCol(i,i+1,16);
        char_inv->writeStr(3,i,"Team Total:");
        string tt_formula("SUM(");
        for(int i_ = 0; i_<8; i_++) {
            int i = 4*i_+5;
            tt_formula += getCellStr(2,i);
            if(i_ < 7) tt_formula += ',';
            else tt_formula += ')';
        }
        char_inv->writeFormula(3,i+1,tt_formula.c_str());
        char_inv->writeStr(5,i+1,"Stat Conversion:");
        
        for(int j_ = 0; j_<BB_SIZE;j_++) {
            int j = j_+CHAR_SHEET_HEADER;
            char_inv->writeStr(j,i,bbenum[j_].c_str());
            char_inv->writeNum(j,i+1,backbone::bb_conversion[j_].value);
            
        }
        for(int j_ = 0; j_<PB_SIZE;j_++) {
            int j = j_+BB_SIZE+CHAR_SHEET_HEADER+2;
            char_inv->writeStr(j,i,pbenum[j_].c_str());
            char_inv->writeNum(j,i+1,backbone::pb_conversion[j_].value);
        }
        for(int j_ = 0; j_<SB_SIZE;j_++) {
            int j = j_+BB_SIZE+PB_SIZE+CHAR_SHEET_HEADER+4;
            char_inv->writeStr(j,i,sbenum[j_].c_str());
            string inst((backbone::sb_int_lock[j_]? "Free: nonneg int":"Free: [-1,1]"));
            char_inv->writeStr(j,i+1,inst);
            
        }
    }
    
    // Draw Per Capita Input
    for(int i_ = 0; i_<8; i_++) {
        int i = 4*i_+4;
        char_inv->setCol(i,i,16);
        const string index(1,i_+49);
        string char_i("Character ");
        char_i = char_i+index;
        char_inv->writeStr(2,i,char_i.c_str());
        string ct_formula("SUM(" + getCellStr(CHAR_SHEET_HEADER,i+1) + ':' 
                                    + getCellStr(CHAR_SHEET_HEADER+BB_SIZE-1,i+1) + ","
                                    + getCellStr(CHAR_SHEET_HEADER+BB_SIZE+2,i+1) + ":"
                                    + getCellStr(CHAR_SHEET_HEADER+BB_SIZE+PB_SIZE+1,i+1) + ")");
        char_inv->writeFormula(2,i+1,ct_formula.c_str());
        char_inv->writeStr(3,i,"Name");
        char_inv->writeStr(4,i,"Starting Pos:");
        char_inv->writeBlank(3,i+1,inpBox);
        char_inv->writeBlank(4,i+1,inpBox);
        
        for(int j_ = 0; j_<BB_SIZE;j_++) {
            int j = j_+CHAR_SHEET_HEADER;
            char_inv->writeStr(j,i,bbenum[j_].c_str());
            char_inv->writeBlank(j,i+1,inpBox);
            string formula(getCellStr(j,i+1)+"*"+getCellStr(j,2));
            char_inv->writeFormula(j,i+2,formula.c_str());
        }
        for(int j_ = 0; j_<PB_SIZE;j_++) {
            int j = j_+BB_SIZE+CHAR_SHEET_HEADER+2;
            char_inv->writeStr(j,i,pbenum[j_].c_str());
            char_inv->writeBlank(j,i+1,inpBox);
            char_inv->writeStr(j,i+2,"eventually formula");
        }
        for(int j_ = 0; j_<SB_SIZE;j_++) {
            int j = j_+BB_SIZE+PB_SIZE+CHAR_SHEET_HEADER+4;
            char_inv->writeStr(j,i,sbenum[j_].c_str());
            char_inv->writeNum(j,i+1,0,inpBox);
            char_inv->writeStr(j,i+2,"eventually formula");
        }
    }
        
    // Close book
    teamAbook->save(teamAbook_.c_str());
    teamAbook->release();
    return 1;
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
            int row = TLcR(y,x);
            int col = TLcC(y,x);
            gamePage->writeBlank(row,col,TLc);
            gamePage->writeBlank(row,col+3,TRc);
            gamePage->writeBlank(row+7,col,BLc);
            gamePage->writeBlank(row+7,col+3,BRc);
            for(int z = 1; z<3; z++){
                gamePage->writeBlank(row,col+z,topB);
                gamePage->writeBlank(row+7,col+z,bottomB);
            }
            for(int z = 1; z<7; z++){
                gamePage->writeBlank(row+z,col,leftB);
                gamePage->writeBlank(row+z,col+3,rightB);
            }
            const string xx(1,(65+x));
            const string yy(1,(49+y));
            string s;
            s = xx + yy;
            gamePage->writeStr(row+7,col,s.c_str());
        }
    

}

string libxlio::getCellStr(int y,int x){
    int temp = x+1;
    string col("");
    while(temp > 0){
        if(temp == 26) {
            col = 'Z' + col;
            temp--;
        } else
            col = (char)(temp%26+64) + col;
        temp = temp/26;
    }
    string row("");
    temp = y+1;
    while(temp > 0) {
        row = (char)(temp%10+48) + row;
        temp = temp/10;
    }
    return (col+row);
}