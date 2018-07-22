// File: excelio.h
// Excel Wrapper for Game
// Purpose: Handle all Excel interaction for simulated gameplay
#ifndef EXCELIO
#define EXCELIO

#include "libxl.h"
using namespace libxl;
#include "character.h"
#include "spell.h"
#include <string>
using std::string;
#include <vector>
using std::vector;

class libxlio {

public:    

    // LibXL String Constants:
    static const string GameBoard;
    static const string GameSheet;
    static const string teamAbook_;
    static const string teamBbook_;
    
    static const string bbenum[];
    static const string pbenum[];
    static const string sbenum[];
    
    static const string spenum[];
    static const string sppenum[];
    static const string ssenum[];
    
    // Game Book Interactions
    static Book* gameBook;
    static Sheet* gamePage;

    // Excel Interaction Functions:
    static int openGameBook();
    static void closeGameBook(bool);
    
    static int readinchar();
    static int readinspell();
    
    static int drawspace(character&, int, int);
    static int clearspace(int, int);
    
    static void drawboard();
    static int drawinputsheets();
    
    // helper function
    static string getCellStr(int,int);
    
};

#endif