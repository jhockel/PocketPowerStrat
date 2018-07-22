// File: spell.h
#ifndef SPELL
#define SPELL

#include "backbone.h"

#define SP_SIZE 2
#define SPP_SIZE 3
#define SS_SIZE 1
enum sp{
    power,
    reroll
};
enum spp {
    targettype,
    targetaim,
    duration
};
enum ss {
    spell_rand
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

    int spell_power[SP_SIZE];
    int spell_perc[SPP_SIZE];
    double spell_scale[SS_SIZE];
    
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