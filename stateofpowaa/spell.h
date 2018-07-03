// File: spell.h
#ifndef SPELL
#define SPELL

#include "backbone.h"

#define POWER_OPT 5
enum sp{
    targettype,
    targetaim,
    duration,
    rand,
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
    
    union t {
        bb target_stat;
        pb target_perc;
    };
    
    int duration;
    
    double rand;
    int reroll;
    int rand_affinity;
    
// Member Functions:
    int getManaCost();
  
};

#endif