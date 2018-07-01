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
    
    matt.setPower(health,200);
    matt.setPower(health_regen,200);
    matt.setPower(mana,200);
    matt.setPower(mana_regen,200);
    matt.setPower(attk,500);
    matt.setPower(move,200);
    
    matt.setPower(true_arm,400);
    
    matt.name = "COOL NAME";
    matt.health = 600;
    matt.mana = 350;
    
    printf("SABA \n");
    printf("Total: %d\n", matt.b.getTotalPower());
    printf("health:       %d, %f\n",    matt.getPower(health), matt.getTrue(health));
    printf("health_regen: %d, %f\n",    matt.getPower(health_regen), matt.getTrue(health_regen));
    printf("mana:         %d, %f\n",    matt.getPower(mana), matt.getTrue(mana));
    printf("mana_regen:   %d, %f\n",    matt.getPower(mana_regen), matt.getTrue(mana_regen));
    
    printf("\nPerc Check:\n");
    printf("true_arm:     %d, %f\n",    matt.getPower(true_arm), matt.getTrue(true_arm));
    
    // if(!libxlio::openGameBook()) {printf("Error opeing game.xlsx file -- exiting\n\n"); return 0;}
    // printf("Game Book was opened successfully\n");
    
    // libxlio::drawboard();
    // libxlio::drawspace(matt,2,2);
    
    // libxlio::closeGameBook(true);
	return 1;
}

