// File: backbone.cpp
// Implimentation file for backbone class
// Handles important 'getter' functions for critical numbers

#include "backbone.h"
#include <vector>
using std::vector;

struct bb_scalar {
    sb scaler;
    double swing;
};
struct bb_cost {
    double cost;
    vector<bb_scalar> scalers;
};
struct pb_scalar {
    sb scaler;
    double swing;
};
struct pb_cost {
    double cost;
    vector<pb_scalar> scalers;
};

static bb_cost bb_conversion[BB_SIZE] = {
    {5.0, vector<bb_scalar>()},     // health,         
    {2.0, vector<bb_scalar>()},     // health_regen,
    
    {2.0, vector<bb_scalar>()},     // mana,
    {1.0, vector<bb_scalar>()},     // mana_regen,
    
    {3.0, vector<bb_scalar>()},     // attk,
    
    {0.01, vector<bb_scalar>()},     // move,
    
    {2.0, vector<bb_scalar>()},     // phys_blk,
    {2.0, vector<bb_scalar>()},     // mag_blk,
    {1.0, vector<bb_scalar>()},     // blk_blk,
    
    {2.0, vector<bb_scalar>()},     // phys_evas,
    {2.0, vector<bb_scalar>()},     // mag_evas,
    {1.0, vector<bb_scalar>()},     // evas_evas,

    {1.0, vector<bb_scalar>()}      // rand_roll
};
static pb_cost pb_conversion[PB_SIZE] = {
    {2.0, vector<pb_scalar>()},    // phys_arm
    {2.0, vector<pb_scalar>()},    // mag_arm
    {1.0, vector<pb_scalar>()},    // true_arm
    
    {1.0, vector<pb_scalar>{(pb_scalar){physique, 0.5}}},    // attk_splash
    {1.0, vector<pb_scalar>{(pb_scalar){physique, 0.5}}},    // attk_range
    
    {1.0, vector<pb_scalar>()}     // speed
};

backbone::backbone() {
    for(int i = 0; i < BB_SIZE; i++) 
        power[i]=0; 
    for(int i = 0; i < PB_SIZE; i++) 
        perc[i]=0; 
    for(int i = 0; i < SB_SIZE; i++) 
        scale[i]=1.0; 
}
int backbone::getTrue(bb stat) {
    int r = power[stat];
    
    return r; 
}
int backbone::getTrue(pb stat) {
    int r = perc[stat];
    double p = r/getBasePower();
    r = (int)(r * (1 + p * pb_conversion[stat].cost));
    return r; 
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
int backbone::getBasePower() {
    int r = 0;
    for(int i = 0; i < BB_SIZE; i++) 
        r += power[i]; 
    return r; 
}
int backbone::getTotalPower() {
    int r = 0; 
    for(int i = 0; i < BB_SIZE; i++) 
        r += power[i]; 
    for(int i = 0; i < PB_SIZE; i++) 
        r += perc[i]; 
    return r; 
}