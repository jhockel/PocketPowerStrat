// FILE: main.cpp
// This file serves as 'void main()' for the EXCEL implimentation of gameplay

#include <stdio.h>
//using std::printf;

#include "character.h"
#include "excelio.h"

int main()
{
	
    character matt;
    
    matt.b.power[0] = 100;
    
    printf("SABA \n");
    printf("sa %d\n", matt.getPower(health));
    printf("sa %d\n", matt.getPower(health_regen));
    printf("sa %d\n", matt.getPower(attk_splash));
    printf("sa %d\n", matt.getPower(phys_blk));
    printf("sa %d\n", matt.getPower(mag_blk));
    printf("sa %d\n", matt.getPower(true_blk));
    printf("Total: %d\n", matt.b.getTotalPower());
    
    if(!libxlio::openGameBook()) {printf("Error opeing game.xlsx file -- exiting\n\n"); return 0;}
    printf("Game Book was opened successfully\n");
    
    libxlio::drawboard();
    
    
    libxlio::closeGameBook(true);
	return 1;
}

