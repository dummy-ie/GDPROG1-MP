// mainHeader.h includes all necessary libraries, defines structs, literals, and prototypes functions. 
#include "content\mainHeader.h"

// menus.c holds all functions for the menus that aren't the battle screen.
#include "content\menus.c"

// beforeBattle.c holds all functions for preparing a battle between the player and enemy.
#include "content\beforeBattle.c"

// battle.c holds the logic for battle or functions that BOTH the player and enemy use for a battle.
#include "content\battle.c"

// afterBattle.c holds all functions that run after a battle.
#include "content\afterBattle.c"

// player.c and enemy.c contain functions used only by the player or enemy respectively.
#include "content\player.c"
#include "content\enemy.c"

// display.c handles functions that print everything to be displayed to the player through a TUI.
#include "content\display.c"

int main() {
    // set to unicode(?) extended ascii or smth idk
    SetConsoleOutputCP(65001);
    // initializing the player struct and the default values for the GEMS and sync pairs. 
    int i;
    player p;
    p.nGems = 1000;
    p.nFloor = 1;
    p.nSyncMoveCounter = 0;

    for(i = 0; i <= 2; i++){
        p.nSyncPairHealth[i] = 100;
        p.nSyncPairFlinching[i] = 0;
        p.nSyncPairHeld[i] = 1;
    }
        // p.nSyncPairHealth[0] = 74; // * testing purposes
        // p.nSyncPairHealth[1] = 12;
        // p.nSyncPairFlinching[1] = 2;
        // p.nSyncPairHeld[2] = 0;
        // p.nSyncPairHealth[2] = 0;

    srand(time(0)); // randomizing the rand() seed

    openMenu(&p);   // goes into the menu. 
                    // you have to exit out from the menu to fully close the program.
    return 0;
}