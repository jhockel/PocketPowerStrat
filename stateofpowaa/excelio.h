// File: Excel Wrapper for Game
// Purpose: Handle all Excel interaction for simulated gameplay
#ifndef EXCELIO
#define EXCELIO


#include "libxl.h"
using namespace libxl;

#include "character.h"

namespace libxlio {
    
    int readinchar();
    int readinspell();
    
    int drawspace(character&, int, int);
    int clearspace(int, int);
    
    void drawboard();
    
}

#endif