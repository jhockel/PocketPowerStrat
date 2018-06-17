// FILE: backbone.h

#define BB_SIZE 20

enum bb {
    health,         // 0
    health_regen,   // 1
    
    mana,           // 2
    mana_regen,     // 3
    mana_color,     // 4
    mana_weight,    // 5
    
    attk,           // 6
    attk_splash,    // 7
    attk_splash_type,//8
    
    move,           // 9
    
    phys_arm,       // 10
    mag_arm,        // 11
    arm_arm,        // 12
    
    phys_blk,       // 13
    mag_blk,        // 14
    blk_blk,        // 15
    
    phys_evas,      // 16
    mag_evas,       // 17
    evas_evas,      // 18
    
    random          // 19
};
static int conversion[BB_SIZE] = {
10,    // health,         
2,     // health_regen,
    
10,    // mana,
4,     // mana_regen,
1,     // mana_color,
1,     // mana_weight,
    
5,     // attk,
1,     // attk_splash,
1,     // attk_splash_type,
    
1,     // move,
    
2,     // phys_arm,
2,     // mag_arm,
1,     // arm_arm,
    
2,     // phys_blk,
2,     // mag_blk,
1,     // blk_blk,
    
2,     // phys_evas,
2,     // mag_evas,
1,     // evas_evas,
    
1      // random
};

class backbone {
public:

    int power[BB_SIZE];
    
    
    int getTrue(bb stat) {return (power[stat]*conversion[stat]); };
    int getPower(bb stat) {return power[stat]; };
    int getTotalPower() {int r; for(int i = 0; i < BB_SIZE; i++) r += power[i]; return r; };

};