// File: spell.cpp

#include "spell.h"
#include <iostream>
using namespace std;

spell::spell(){
    for(int i=0; i<POWER_OPT; i++)
        power_opt[i] = 0;
    target = NULL;
    target_type = character;
    target_aim = enemy;
    t.target_stat = health;
    
    rand_affinity = 0;
}

int spell::getManaCost() {
    int r;
    for(int i=0; i<POWER_OPT; i++)
        r += power_opt[i];
    return r;
}