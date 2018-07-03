// File: spell.cpp

#include "spell.h"

spell::spell(){
    for(int i=0; i<POWER_OPT; i++)
        power_opt[i] = 0;
    target = NULL;
    target_type = character;
    target_aim = enemy;
    t.target_stat = health;
    
}

int spell::getManaCost() {
    int r;
    for(int i=0; i<POWER_OPT; i++)
        r += power_opt[i];
    return r;
}