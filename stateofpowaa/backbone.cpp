// File: backbone.cpp
// Implimentation file for backbone class
// Handles important 'getter' functions for critical numbers

#include "backbone.h"
#include <vector>
using std::vector;
#include <cmath>
using namespace std;

#include <stdio.h>
#define CWB 1

bb_value backbone::bb_conversion[BB_SIZE] = {
    {5.0, vector<bb_scalar>(), true},     // health,         
    {2.0, vector<bb_scalar>(), true},     // health_regen,
    
    {2.0, vector<bb_scalar>(), true},     // mana,
    {1.0, vector<bb_scalar>(), true},     // mana_regen,
    
    {3.0, vector<bb_scalar>(), true},     // attk,
    
    {0.01, vector<bb_scalar>(), true},     // move,
    
    {2.0, vector<bb_scalar>(), false},     // phys_blk,
    {2.0, vector<bb_scalar>(), false},     // mag_blk,
    {1.0, vector<bb_scalar>(), false},     // blk_blk,
    
    {2.0, vector<bb_scalar>(), false},     // phys_evas,
    {2.0, vector<bb_scalar>(), false},     // mag_evas,
    {1.0, vector<bb_scalar>(), false},     // evas_evas,

    {1.0, vector<bb_scalar>(), false}      // rand_roll
};
// Value for Percent Based Stats work as Recipricol of percent invest... EHHHH
pb_value backbone::pb_conversion[PB_SIZE] = {
    {4.0, vector<pb_scalar>(), false},     // phys_arm
    {4.0, vector<pb_scalar>(), false},     // mag_arm
    {2.0, vector<pb_scalar>(), false},     // true_arm
    
    {10.0, vector<pb_scalar>{               // attk_splash
        (pb_scalar){physique, -0.8} },
        true},
    {10.0, vector<pb_scalar>{               // attk_range
        (pb_scalar){physique, 0.8} },
        true},
    
    {1.0, vector<pb_scalar>(), false}     // speed
};

backbone::backbone() {
    for(int i = 0; i < BB_SIZE; i++) 
        power[i]=0; 
    for(int i = 0; i < PB_SIZE; i++) 
        perc[i]=0; 
    for(int i = 0; i < SB_SIZE; i++) 
        scale[i]=0.0; 
}
double backbone::getTrue(bb stat) {
    double r = power[stat] * getScaledValue(stat);

    if(bb_conversion[stat].integer_lock == true) {
        double f =  floor(r);
        if((r!=0) & ((r-f) > (r/power[stat]))) if(CWB) {
            printf("Warning - Power Waste at index %d: %f vs %f\n", stat, r, f);
            printf("Can lower by %d\n", (int)((r-f)*power[stat]/r));
        }
        return f;
    }
    else return r; 
}
double backbone::getScaledValue(bb stat) {
    double r = bb_conversion[stat].value;
    
    for(vector<bb_scalar>::iterator i = bb_conversion[stat].scalers.begin();
                                    i != bb_conversion[stat].scalers.end(); ++i)
        r = r * ( 1 + (i->swing * scale[i->scaler]));
        
    return r;
}
double backbone::getTrue(pb stat) {
    
    double base_percent = (double)perc[stat]/(double)getBasePower();
    double r = base_percent * getScaledValue(stat);

    if(pb_conversion[stat].integer_lock == true) {
        double f =  floor(r);
        if((r!=0) & ((r-f) > (r/perc[stat]))) if(CWB) {
            printf("Warning - Power Waste at index %d: %f vs %f\n", stat, r, f);
            printf("Can lower by %d\n", (int)((r-f)*perc[stat]/r));
        }
        return f;
    }
    else return r; 
}
double backbone::getScaledValue(pb stat) {
    double r = pb_conversion[stat].value;

    for(vector<pb_scalar>::iterator i = pb_conversion[stat].scalers.begin();
                                    i != pb_conversion[stat].scalers.end(); ++i)
        r = r * ( 1 + (i->swing * scale[i->scaler]));
        
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