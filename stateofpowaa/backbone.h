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


class backbone {
public:

    int pow[BB_SIZE];
    
    
    
    int getTotal() {int r; for(int i = 0; i < BB_SIZE; i++) r += pow[i]; return r;};

};