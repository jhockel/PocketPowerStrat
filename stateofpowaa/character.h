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
    int getPower(pb);
    double getTrue(bb);
    double getTrue(pb);
    double getScale(sb);
    int getTotalPower();
    
    void setPower(bb,int);
    void setPower(pb,int);
    void setScale(sb,double);
};

#endif