// FILE: backbone.h
#ifndef BACKBONE
#define BACKBONE

#define BB_SIZE 13
#define PB_SIZE 6
#define SB_SIZE 3

enum bb {
    health,         // 0
    health_regen,   // 1

    mana,           // 2
    mana_regen,     // 3

    attk,           // 4

    move,           // 5

    phys_blk,       // 6
    mag_blk,        // 7
    true_blk,       // 8
    
    phys_evas,      // 9
    mag_evas,       // 10
    true_evas,      // 11

    rand_roll       // 12
};
enum pb {
    phys_arm,       // 0 %% PERCENT
    mag_arm,        // 1 %% PERCENT
    true_arm,       // 2 %% PERCENT
    
    attk_splash,    // 3 %% PERCENT
    attk_range,     // 4 %% PERCENT
    
    speed           // 5 %% PERCENT
};
enum sb {
    physique,       // 0 ## SCALAR: STRENGTH vs ACCURACY: attack SPLASH vs RANGE
    mana_color,     // 1 ## SCALAR: LIGHT vs DARK: 
    mana_weight,    // 2 ## SCALAR: HEAVY vs LIGHT:
    attk_splash_type// 3 ## SCALAR: defines SPLASH, CLUSTER, or SPLIT
    
};

class backbone {
public:
// Members:
    int power[BB_SIZE];     // Power Array for Base Stats
    int perc[PB_SIZE];      // Power Array for Percentage Based stats
    double scale[SB_SIZE];  // Array of cost scalars
    
// Member Functions:
    backbone();
    double getTrue(bb stat);
    double getTrue(pb stat);
    double getScale(sb stat);
    int getPower(bb stat);
    int getPower(pb stat);
    int getBasePower();
    int getTotalPower();

};


#endif