/*  playerTurn executes the player's turn during the game loop. Will show the player's options and allow the player to commit an action.
    based on the player's choice, the player may attack the enemy, try to flinch the enemy, heal the team of sync pairs, 
    skip their turn, or forfeit the match entirely. Forfeiting will treat the battle as a loss and reset the player's progress.
*/
void playerTurn(){
    char cSelect;
    int* nPtrFloor = playerVars("Floor");
    int* nPtrSTKHeld = playerVars("STKHeld");
    int* nPtrTECHeld = playerVars("TECHeld");
    int* nPtrSUPHeld = playerVars("SUPHeld");
    
    printBattle();
    // printf("%d, %d, %d\n", *nHeldStrike, *nHeldTech, *nHeldSupport); // * for debugging purposes
    printf(    
        GRN
        "               [ENTER A NUMBER]: "
        );

    cSelect = getche();

    printf("\n"RESET); //reset colors
    
    switch (cSelect){ // process user input
        case '1': // * strike
            playerStrikeMove();
            break;
        case '2': // * tech
            playerTechMove();
            break;
        case '3': // * support
            playerSupportMove();
            break;
        case '4': // * skip turn
            printf(GRN"               [Skipping turn]... \n"RESET);
            Sleep(1000);
            enemyTurn(0);
            break;
        case 'f':
        case 'F': // * either f or F
            printf(GRN"               [Forfeiting match]... \n"RESET);
            Sleep(1000);
            *nPtrSTKHeld += 1;
            *nPtrTECHeld += 1;
            *nPtrSUPHeld += 1;
            *nPtrFloor = 1;
            battleEnd(false, 0);
            break;
        default: // * wrong inputs
            playerTurn();
            break;
    }
}

/*  playerStrikeMove executes when the player chooses to use their STRIKE pair.
    calculates and applies the damage done to the enemy's sync pair if the player's STRIKE pair is not flinching.
    uses dealDMG(int nMinDMG, int nMaxDMG, char* strName) to calculate the damage done to the enemy's sync pair.
*/
void playerStrikeMove(){
    int nDMGDealt;
    char** strPtrEnemyName = enemyName();
    int* nPtrSTKFlinch = playerVars("STKFlinch");
    int* nPtrEnemyHealth = enemyVars("EnemyHealth");

    if(isSyncPairFlinching(0, *nPtrSTKFlinch)){
        playerTurn();
    }
    else{
        nDMGDealt = dealDMG(10, 20, *strPtrEnemyName);
        *nPtrEnemyHealth -= nDMGDealt;
        checkLoss(0);
    }
}

/*  playerTechMove executes when the player chooses to use their TECH pair.
    tries for a 20% chance to flinch the enemy if the player's TECH pair is not flinching nor fainted.
    uses tryFlinch(int nFlinchChance, char* strName) function to calculate the chances for a successful flinch.
*/
void playerTechMove(){
    char** strPtrEnemyName = enemyName();
    int* nPtrTECHealth = playerVars("TECHealth");
    int* nPtrTECFlinch = playerVars("TECFlinch");
    int* nPtrEnemyFlinch = enemyVars("EnemyFlinch");

    if(*nPtrTECHealth > 0){ // check if our TEC is alive 
        if(isSyncPairFlinching(1, *nPtrTECFlinch)){
            playerTurn();
        }
        else if(*nPtrEnemyFlinch >= 1){
            printf(GRN"               ["RED"%s"GRN" is already "BLU"FLINCH"GRN"ing]! \n"RESET, *strPtrEnemyName);
            Sleep(1000);
            playerTurn();
        }
        else{
            *nPtrEnemyFlinch = tryFlinch(20, *strPtrEnemyName);
            enemyTurn(1);
        }
    }
    else{
        printf(GRN"               [You are out of "BLU"TEC"GRN" pairs]... \n"RESET);
        Sleep(1000);
        playerTurn();
    }
}

/*  playerSupportMove executes when the player chooses to use their SUPPORT pair.
    calculates and applies the health healed to all of the player's sync pairs if the player's SUPPORT pair is not flinching or fainted.
    uses healHP() and limitPlayerHP(int nHPHealed) function to calculate the health healed.
*/
void playerSupportMove(){
    int nHPHealed;
    int* nPtrSUPHealth = playerVars("SUPHealth");
    int* nPtrSUPFlinch = playerVars("SUPFlinch");

    if(*nPtrSUPHealth > 0){ // check if our SUP is alive
        if(isSyncPairFlinching(2, *nPtrSUPFlinch)){
            playerTurn();
        }
        else{
            nHPHealed = healHP();
            limitPlayerHP(nHPHealed);
            Sleep(1000);
            enemyTurn(2);
        }
    }
    else{
        printf(GRN"               [You are out of "LGR"SUP"GRN" pairs]... \n"RESET);
        Sleep(1000);
        playerTurn();
    }
}

/*  isSyncPairFlinching returns a boolean type depending on if the given sync pair is currently flinching or not.
    0 is STK, 1 is TEC, 2 is SUP.
    @param int nSyncPair is the current sync pair.
    @param int nFlinchRounds is how many rounds the current sync pair is flinching.
    Pre-condition: nSyncPair is 0 - 2
*/
bool isSyncPairFlinching(int nSyncPair, int nFlinchRounds){
    if(nFlinchRounds > 0){
        printf(GRN"               [%s%s"GRN" is "BLU"FLINCH"GRN"ing]! \n"RESET, convertPairIntToColor(nSyncPair), convertPairIntToStr(nSyncPair));
        Sleep(1000);
        return true;

        // ! deprecated !
        // switch(nSyncPair){
        //     case 0:
        //         printf(GRN"               ["ORN"STK"GRN" is "BLU"FLINCH"GRN"ing]! \n"RESET);
        //         Sleep(1000);
        //         return true;
        //     case 1:
        //         printf(GRN"               ["BLU"TEC"GRN" is "BLU"FLINCH"GRN"ing]! \n"RESET);
        //         Sleep(1000);
        //         return true;
        //     case 2:
        //         printf(GRN"               ["LGR"SUP"GRN" is "BLU"FLINCH"GRN"ing]! \n"RESET);
        //         Sleep(1000);
        //         return true;
        // }
        // ! deprecated !
    }
    else{
        return false;
    }
}

/*  limitPlayerHP executes upon healing the player's sync pairs 
    and will limit the healing to the player's maximum allowed health.
    @param int nHPHealed how much to increase the player's health by.
*/
void limitPlayerHP(int nHPHealed){
    int* nPtrSTKHealth = playerVars("STKHealth");
    int* nPtrTECHealth = playerVars("TECHealth");
    int* nPtrSUPHealth = playerVars("SUPHealth");

    if(*nPtrSTKHealth + nHPHealed >= 100){
        *nPtrSTKHealth = 100;
    }
    else if(*nPtrSTKHealth > 0){ // * you can only heal alive sync pairs
        *nPtrSTKHealth += nHPHealed;
    }
    if(*nPtrTECHealth + nHPHealed >= 100){
        *nPtrTECHealth = 100;
    }
    else if(*nPtrTECHealth > 0){ // * you can only heal alive sync pairs
        *nPtrTECHealth += nHPHealed;
    }
    if(*nPtrSUPHealth + nHPHealed >= 100){
        *nPtrSUPHealth = 100;
    }
    else if(*nPtrSUPHealth > 0){ // * you can only heal alive sync pairs
        *nPtrSUPHealth += nHPHealed;
    }

}