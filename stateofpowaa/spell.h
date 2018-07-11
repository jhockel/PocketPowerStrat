// File: spell.h
#ifndef SPELL
#define SPELL

#include "backbone.h"

#define POWER_OPT 5
enum sp{
    targettype,
    targetaim,
    duration,
    random,
    reroll
};
enum tt {
    character,
    space
};
enum ta {
    neutral,
    enemy,
    friendly
};

class spell {
public:

    int power_opt[POWER_OPT];
    
    void* target;
    tt target_type;
    ta target_aim;
    
    union targ_spec {
        bb target_stat;
        pb target_perc;
    } t;
    
    int rand_affinity;
    
// Member Functions:
    spell();
    int getManaCost();
  
};

#endif