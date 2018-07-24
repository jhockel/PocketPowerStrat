// FILE: character.cpp

#include "character.h"

// character::character() {
    // //for(int i = 0; i < BB_SIZE; i++) b.power[i]=0;
// }

int character::getPower(bb stat){
    return b.getPower(stat);
}
int character::getPower(pb stat){
    return b.getPower(stat);
}

double character::getTrue(bb stat){
    return b.getTrue(stat);
}
double character::getTrue(pb stat){
    return b.getTrue(stat);
}
double character::getScale(sb stat){
    return b.scale[stat];
}

int character::getTotalPower(){
    return b.getTotalPower();
}

void character::setPower(bb stat, int p) {
    b.power[stat] = p;
}
void character::setPower(pb stat, int p) {
    b.perc[stat] = p;
}
void character::setScale(sb stat, double s) {
    if( (s < -1) | (s > 1) ) return;
    b.scale[stat] = s;
}
