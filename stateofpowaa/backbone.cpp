// File: backbone.cpp
// Implimentation file for backbone class
// Handles important 'getter' functions for critical numbers

#include "backbone.h"

static int conversion[BB_SIZE] = {
5,     // health,         
2,     // health_regen,
    
2,     // mana,
1,     // mana_regen,
    
3,     // attk,
    
1,     // move,
    
2,     // phys_blk,
2,     // mag_blk,
1,     // blk_blk,
    
2,     // phys_evas,
2,     // mag_evas,
1,     // evas_evas,

1      // rand_roll
};

backbone::backbone() {
    for(int i = 0; i < BB_SIZE; i++) 
        power[i]=0; 
    for(int i = 0; i < PB_SIZE; i++) 
        perc[i]=0; 
    for(int i = 0; i < SB_SIZE; i++) 
        scale[i]=0.5; 
}
int backbone::getTrue(bb stat) {
    
    return (power[stat]*conversion[stat]); 
}
int backbone::getPower(bb stat) {
    
    return power[stat]; 
}
int backbone::getPower(pb stat) {
    
    return perc[stat]; 
}
double backbone::getScale(sb stat) {
    
    return scale[stat]; 
}
int backbone::getTotalPower() {
    
    int r = 0; for(int i = 0; i < BB_SIZE; i++) 
        r += power[i]; 
    return r; 
}