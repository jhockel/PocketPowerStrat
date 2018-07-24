// FILE: main.cpp
// This file serves as 'void main()' for the EXCEL implimentation of gameplay

#include <stdio.h>
#include <iostream>
using namespace std;

#include "character.h"
#include "gamedata.h"
#include "excelio.h"


int main()
{
    character matt;
    
    matt.setPower(health,200);
    matt.setPower(health_regen,200);
    matt.setPower(mana,200);
    matt.setPower(mana_regen,200);
    matt.setPower(attk,500);
    matt.setPower(movement,200);
    
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
    

    // if(!libxlio::drawinputsheets()) {printf("Error with input sheet file -- exiting\n\n"); return 0;}
    

    // libxlio::readinchar();
    
    // if(!libxlio::openGameBook()) {printf("Error opeing game.xlsx file -- exiting\n\n"); return 0;}
    // printf("Game Book was opened successfully\n");
    
    // libxlio::drawboard();
    // libxlio::drawspace(matt,2,2);
    
    // libxlio::closeGameBook(true);
    
    bool go = true;
    int inp;
    printf("\n\n******************* State of Powaaa *********************\n\n");
    printf("Alpha test version of gameplay implimented by John Hockel\n");
    printf("Gameplay required Microsoft Excel for interaction\n\n");
    printf("NOTE: Excel files MUST BE CLOSED when sop.exe functions run\n");
    
    
    while(go) {
            printf("\n Select Input Index:\n");
            printf("[1]: Draw Game Sheets (WILL OVERWRITE EXISTING FiLES)\n");
            printf("[2]: Run Input Sheet Analytics\n");
            printf("[3]: Play Game with Current Sheets (PvP)\n");
            printf("[4]: Exit\n");
            printf("[=]: ");
            cin >> inp;
            printf("\n");
            switch(inp){
                case 1:
                    if(!libxlio::drawinputsheets()) {
                        printf("Error with input sheet file -- exiting\n\n"); 
                        go = false;
                    }
                    printf("***Game Sheet Templates Re-Drawn***\n");
                break;
                case 2:
                    printf("TODO\n");
                break;
                case 3:
                    libxlio::readinchar();
                break;
                case 4:
                    go = false;
                break;
                default:
                    printf("Invalid Input kiddo\n\n");
                    cin.clear();
                    cin.ignore(1000,'\n');
                break;
            }
    }
    
    printf("Reiterate, reapproach\n\n");

	return 1;
}

