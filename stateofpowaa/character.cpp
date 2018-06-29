// FILE: character.cpp

#include "character.h"

character::character() {
    //for(int i = 0; i < BB_SIZE; i++) b.power[i]=0;
}

int character::getPower(bb stat){
    return b.getPower(stat);
}
int character::getPower(pb stat){
    return b.getPower(stat);
}

int character::getTrue(bb stat){
    return b.getTrue(stat);
}

int character::getTotalPower(){
    return b.getTotalPower();
}

void character::setPower(bb stat, int p) {
    b.power[stat] = p;
}
