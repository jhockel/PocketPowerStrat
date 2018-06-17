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
10,    // health,         // 0
2,     // health_regen,   // 1
    
10,    // mana,           // 2
4,     // mana_regen,     // 3
1,     // mana_color,     // 4
1,     // mana_weight,    // 5
    
5,     // attk,           // 6
1,     // attk_splash,    // 7
1,     // attk_splash_type,//8
    
1,     // move,           // 9
    
2,     // phys_arm,       // 10
2,     // mag_arm,        // 11
1,     // arm_arm,        // 12
    
2,     // phys_blk,       // 13
2,     // mag_blk,        // 14
1,     // blk_blk,        // 15
    
2,     // phys_evas,      // 16
2,     // mag_evas,       // 17
1,     // evas_evas,      // 18
    
1     // random          // 19
};

class backbone {
public:

    int power[BB_SIZE];
    
    
    int getTrue(bb stat) {return (power[stat]*conversion[stat]); };
    int getPower(bb stat) {return power[stat]; };
    int getTotalPower() {int r; for(int i = 0; i < BB_SIZE; i++) r += power[i]; return r; };

};