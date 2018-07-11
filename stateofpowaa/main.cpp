// FILE: main.cpp
// This file serves as 'void main()' for the EXCEL implimentation of gameplay

#include <stdio.h>
//using std::printf;

#include "gamedata.h"
#include "character.h"

// COMMENT THIS LINE TO REMOVE EXCEL DEPENDANCIES
#define XLIMP

#ifdef XLIMP
#include "excelio.h"
#endif

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
    matt.setPower(attk_range,84);
    
    matt.setScale(physique, 1.0);
    
    matt.name = "COOL NAME";
    matt.health = 600;
    matt.mana = 350;
    
    printf("SABA \n");
    printf("Total: %d Base: %d\n", matt.b.getTotalPower(), matt.b.getBasePower());
    printf("health:       %4d, %f\n",    matt.getPower(health), matt.getTrue(health));
    printf("health_regen: %4d, %f\n",    matt.getPower(health_regen), matt.getTrue(health_regen));
    printf("mana:         %4d, %f\n",    matt.getPower(mana), matt.getTrue(mana));
    printf("mana_regen:   %4d, %f\n",    matt.getPower(mana_regen), matt.getTrue(mana_regen));
    
    printf("\nPerc Check:\n");
    printf("true_arm:     %4d, %f\n",    matt.getPower(true_arm), matt.getTrue(true_arm));
    printf("attk_range:   %4d, %f\n",    matt.getPower(attk_range), matt.getTrue(attk_range));
    printf("attk_splash:  %4d, %f\n",    matt.getPower(attk_splash), matt.getTrue(attk_splash));
    
#ifdef XLIMP    

    // if(!libxlio::drawinputsheets()) {printf("Error with input sheet file -- exiting\n\n"); return 0;}
    

    libxlio::readinchar();
    
    // if(!libxlio::openGameBook()) {printf("Error opeing game.xlsx file -- exiting\n\n"); return 0;}
    // printf("Game Book was opened successfully\n");
    
    // libxlio::drawboard();
    // libxlio::drawspace(matt,2,2);
    
    // libxlio::closeGameBook(true);
#endif

	return 1;
}

