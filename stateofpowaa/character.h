// FILE: character.h
#ifndef CHARACTER
#define CHARACTER

#include "backbone.h"
#include <string>
using std::string;

class character {
public:

    string name;
    // Sprite
    backbone b;
    int health;
    int mana;
    
    // Vector of mods
    
    
    // Member Functions and Accessors
    character();
    int getPower(bb);
    int getTrue(bb);
    int getTotalPower();
    void setPower(bb,int);
};

#endif