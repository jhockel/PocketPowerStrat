// FILE: character.h
#ifndef CHARACTER
#define CHARACTER

#include "backbone.h"

class character {
public:

    // Name
    // Sprite
    
    backbone b;
    int health;
    
    // Vector of mods
    
    
    // Member Functions and Accessors
    character();
    int getPower(bb);
    int getTrue(bb);
    int getTotalPower();
};

#endif