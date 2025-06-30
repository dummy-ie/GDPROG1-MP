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

/*  playerVars holds static int variables that hold information about the player. When called, returns the pointer to the proper variable.
    @param char strVariable[] is a string that determines which pointer to return.  
    @return a pointer to a static int variable.
*/
int* playerVars(char strVariable[]){
    static int nGems;
    static int nFloor;
    static int nSTKHeld;
    static int nTECHeld;
    static int nSUPHeld;
    static int nSTKHealth;
    static int nTECHealth;
    static int nSUPHealth;
    static int nSTKFlinch;
    static int nTECFlinch; 
    static int nSUPFlinch;

    if(!strcmp(strVariable, "Gems")){
        return &nGems;
    }
    else if(!strcmp(strVariable, "Floor")){
        return &nFloor;
    }
    else if(!strcmp(strVariable, "STKHeld")){
        return &nSTKHeld;
    }
    else if(!strcmp(strVariable, "TECHeld")){
        return &nTECHeld;
    }
    else if(!strcmp(strVariable, "SUPHeld")){
        return &nSUPHeld;
    }
    else if(!strcmp(strVariable, "STKHealth")){
        return &nSTKHealth;
    }
    else if(!strcmp(strVariable, "TECHealth")){
        return &nTECHealth;
    }
    else if(!strcmp(strVariable, "SUPHealth")){
        return &nSUPHealth;
    }
    else if(!strcmp(strVariable, "STKFlinch")){
        return &nSTKFlinch;
    }
    else if(!strcmp(strVariable, "TECFlinch")){
        return &nTECFlinch;
    }
    else if(!strcmp(strVariable, "SUPFlinch")){
        return &nSUPFlinch;
    }
    else{
        return NULL;
    }
}

/*  initializePlayerVars is called only once at the start of the program 
    and initializes the default values for the player.
*/
void initializePlayerVars(){
    int* nPtrGems = playerVars("Gems");
    int* nPtrFloor = playerVars("Floor");
    int* nPtrSTKHeld = playerVars("STKHeld");
    int* nPtrTECHeld = playerVars("TECHeld");
    int* nPtrSUPHeld = playerVars("SUPHeld");
    int* nPtrSTKHealth = playerVars("STKHealth");
    int* nPtrTECHealth = playerVars("TECHealth");
    int* nPtrSUPHealth = playerVars("SUPHealth");
    int* nPtrSTKFlinch = playerVars("STKFlinch");
    int* nPtrTECFlinch = playerVars("TECFlinch"); 
    int* nPtrSUPFlinch = playerVars("SUPFlinch");

    *nPtrSTKHeld = 1;
    *nPtrTECHeld = 1;
    *nPtrSUPHeld = 1;
    *nPtrSTKHealth = 100;
    *nPtrTECHealth = 100;
    *nPtrSUPHealth = 100;
    *nPtrSTKFlinch = 0;
    *nPtrTECFlinch = 0; 
    *nPtrSUPFlinch = 0;
    *nPtrGems = 1000;
    *nPtrFloor = 20;
}

int main() {

    initializePlayerVars();
    srand(time(0)); // randomizing the rand() seed

    openMenu();   // goes into the menu. 
                                    // you have to exit out from the menu to fully close the program.
    return 0;
}