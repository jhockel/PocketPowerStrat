// FILE: main.cpp
// This file serves as 'void main()' for the EXCEL implimentation of gameplay

#include <stdio.h>
//using std::printf;

#include "gamedata.h"
#include "character.h"
#include "excelio.h"


int main()
{
	
    character matt;
    
    matt.setPower(health,400);
    matt.setPower(mana,200);
    matt.setPower(attk,500);
    matt.setPower(move,200);
    
    matt.name = "COOL NAME";
    matt.health = 600;
    matt.mana = 350;
    
    printf("SABA \n");
    printf("sa %d\n", matt.getPower(health));
    printf("sa %d\n", matt.getTrue(health));
    printf("sa %d\n", matt.getPower(health_regen));
    printf("sa %d\n", matt.getPower(attk_splash));
    printf("sa %d\n", matt.getPower(phys_blk));
    printf("sa %d\n", matt.getPower(mag_blk));
    printf("sa %d\n", matt.getPower(true_blk));
    printf("Total: %d\n", matt.b.getTotalPower());
    
    if(!libxlio::openGameBook()) {printf("Error opeing game.xlsx file -- exiting\n\n"); return 0;}
    printf("Game Book was opened successfully\n");
    
    libxlio::drawboard();
    libxlio::drawspace(matt,2,2);
    
    libxlio::closeGameBook(true);
	return 1;
}

