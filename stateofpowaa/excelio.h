// File: Excel Wrapper for Game
// Purpose: Handle all Excel interaction for simulated gameplay
#ifndef EXCELIO
#define EXCELIO

#include "libxl.h"
using namespace libxl;
#include "character.h"
#include <string>
using std::string;

class libxlio {

public:    
    // Excel Interaction Functions:
    static int openGameBook();
    static void closeGameBook(bool);
    
    static int readinchar();
    static int readinspell();
    
    static int drawspace(character&, int, int);
    static int clearspace(int, int);
    
    static void drawboard();
    
};

#endif