// File: spell.cpp

#include "spell.h"
#include <iostream>
using namespace std;

spell::spell(){
    for(int i=0; i<SP_SIZE; i++)
        spell_power[i] = 0;
    for(int i=0; i<SPP_SIZE; i++)
        spell_perc[i] = 0;
    for(int i=0; i<SS_SIZE; i++)
        spell_scale[i] = 0;
    target = NULL;
    target_type = targ_character;
    target_aim = enemy;
    t.target_stat = health;
    
    rand_affinity = 0;
}

int spell::getManaCost() {
    int r;
    for(int i=0; i<SP_SIZE; i++)
        r += spell_power[i];
    return r;
}