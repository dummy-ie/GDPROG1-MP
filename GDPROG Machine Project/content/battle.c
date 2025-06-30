/*  convertPairIntToColor returns the color of the sync pair int value passed to it.
    @param nSyncPair determines which pair is converted to a string.
    @retun a string literal that holds a color.
    Pre-condition: nSyncPair >= 0 and nSyncPair <= 2
*/
char* convertPairIntToColor(int nSyncPair){
    switch(nSyncPair){
        case 0: 
            return ORN;
        case 1:
            return BLU;
        case 2: 
            return LGR;
        default:
            return "NULL";
    }
}

/*  convertPairIntToStr converts the sync pair's int to a string and returns it.
    @param nSyncPair determines which pair is converted to a string.
    @return a string containing the name of a sync pair.
    Pre-condition: nSyncPair >= 0 and nSyncPair <= 2
*/
char* convertPairIntToStr(int nSyncPair){
    switch(nSyncPair){
        case 0: 
            return "STK";
        case 1: 
            return "TEC";
        case 2: 
            return "SUP";
        default:
            return "NULL";
    }
}

/*  updateFlinchCounter runs on each turn. 
    Checks if player is flinching and will update the counter accordingly.
    If called for enemy, will update the counter without checking.
    @param bool bIsCheckingPlayer is true if the function is checking the player. Otherwise false.
    Pre-condition: if this function is called and bIsCheckingPlayer = false, the enemy is flinching.
*/
void updateFlinchCounter(bool bIsCheckingPlayer){
    char** strPtrEnemyName = enemyName();
    int* nPtrSTKFlinch = playerVars("STKFlinch");
    int* nPtrTECFlinch = playerVars("TECFlinch");
    int* nPtrSUPFlinch = playerVars("SUPFlinch");
    int* nPtrEnemyFlinch = enemyVars("EnemyFlinch");

    if(bIsCheckingPlayer){
        if(*nPtrSTKFlinch > 0){
            *nPtrSTKFlinch -= 1;
        }
        else if(*nPtrTECFlinch > 0){
            *nPtrTECFlinch -= 1;
        }
        else if(*nPtrSUPFlinch > 0){
            *nPtrSUPFlinch -= 1;
        }
    }
    else{
        printf(GRN"               ["RED"%s"GRN" is "BLU"FLINCH"GRN"ing]! \n"RESET, *strPtrEnemyName);
        Sleep(1000);
        *nPtrEnemyFlinch -= 1;
    }
}

/*  dealDMG calculates and returns the damage given to a sync pair.
    @param nMinDMG is the minimum range of damage given to a sync pair.
    @param nMaxDMG is the maximum range of damage given to a sync pair.
    @param int nLastPairUsed is for which sync pair the player last used.
    @return the damage done to a sync pair.
    Pre-condition: Minimum damage and maximum damage are both positive.
*/
int dealDMG(int nMinDMG, int nMaxDMG, char* strName){
    int nDMGDealt = randRange(nMinDMG, nMaxDMG);
    printf(GRN"               [Dealt "ORN"%d DMG"GRN" to "RED"%s"GRN"]! \n"RESET, nDMGDealt, strName);
    Sleep(1000);
    return nDMGDealt;
}

/*  tryFlinch calculates a flinch chance based on the enemy's type 
    and returns how many rounds the targeted sync pair will flinch for.
    @param int nFlinchChance determines the chance of a successful flinch move.
    @param int nLastPairUsed determines which sync pair the player last used. (0 means STK, 1 means TEC, 2 means SUP)
    @param char* strEnemyName is the name of the enemy if the player is using tryFlinch. Otherwise it is blank.
    @return how many rounds a sync pair will flinch.
*/
int tryFlinch(int nFlinchChance, char* strName){
    int nFlinch = randRange(1, 100);
    int nFlinchRounds = 0;
    // int nFlinch = 1; // * for testing

    printf(GRN"               [Trying to "BLU"FLINCH "RED"%s"GRN"]! \n"RESET, strName);
    Sleep(1000);
    if(nFlinch < nFlinchChance){
        printf(GRN"               ["RED"%s"GRN" is now "BLU"FLINCH"GRN"ing]! \n"RESET, strName);
        nFlinchRounds = 2;
    }
    else{
        printf(GRN"               ["RED"%s"GRN" didn't "BLU"FLINCH"GRN"]... \n"RESET, strName);
    }
    Sleep(1000);
    return nFlinchRounds;
}

/*  healHP calculates and returns the health healed for a sync pair.
    @return amount of health healed
*/
int healHP(){
    int nHPHealed = randRange(8, 15);

    printf(GRN"               [Healed "LGR"%d HP"GRN"]! \n"RESET, nHPHealed);
    Sleep(1000);
    return nHPHealed;
}

/*  checkLoss runs after each enemy turn or if the player used STK, and checks if the player has won or lost.
    @param bool bIsCheckingPlayer determines if the function is checking the player or enemy. (1 if checking player, 0 otherwise)
*/
void checkLoss(bool bIsCheckingPlayer){
    int* nPtrSTKHeld = playerVars("STKHeld");
    int* nPtrSTKHealth = playerVars("STKHealth");
    int* nPtrEnemyHealth = enemyVars("EnemyHealth");

    if(bIsCheckingPlayer){
        if(*nPtrSTKHealth <= 0 && *nPtrSTKHeld == 0){
            playerLost();
        }
        else{
            playerTurn();
        }
    }
    else if(*nPtrEnemyHealth <= 0){
        playerWon();
    }
    else{
        enemyTurn(0);
    }
}

/*  playerWon runs if the player has won the match. 
    Notifies the player that the enemy's sync pair has fainted, and then proceeds to the screen for the end of a battle.
*/
void playerWon(){
    int nGemsWon;
    char** strPtrEnemyName = enemyName();
    int* nPtrGems = playerVars("Gems");
    int* nPtrSTKHeld = playerVars("STKHeld");
    int* nPtrTECHeld = playerVars("TECHeld");
    int* nPtrSUPHeld = playerVars("SUPHeld");
    int* nPtrFloor = playerVars("Floor");

    printf(GRN"               ["RED"%s"GRN"'s Sync Pair has fainted]! \n"RESET, *strPtrEnemyName);
    Sleep(2000);
    if(*nPtrFloor % 5 == 0){
        chooseEliteReward();
    }
    if(*nPtrFloor != 21){
        *nPtrFloor += 1;
    }

    if(*nPtrSTKHeld > 0){
        *nPtrSTKHeld += 1;
    }
    if(*nPtrTECHeld > 0){
        *nPtrTECHeld += 1;
    }
    if(*nPtrSUPHeld > 0){
        *nPtrSUPHeld += 1;
    }

    nGemsWon = getReward(*nPtrFloor);
    *nPtrGems += nGemsWon;
    battleEnd(true, nGemsWon);
}

/*  playerLost runs if the player has lost the match. 
    Notifies the player that they have lost the match, and then proceeds to the screen for the end of a battle.
*/
void playerLost(){
    int* nPtrSTKHeld = playerVars("STKHeld");
    int* nPtrTECHeld = playerVars("TECHeld");
    int* nPtrSUPHeld = playerVars("SUPHeld");
    int* nPtrFloor = playerVars("Floor");

    printf(GRN"               [You lost the match]! \n"RESET);
    Sleep(2000);
    *nPtrFloor = 1;

    if(*nPtrSTKHeld > 0){
        *nPtrSTKHeld += 1;
    }
    if(*nPtrTECHeld > 0){
        *nPtrTECHeld += 1;
    }
    if(*nPtrSUPHeld > 0){
        *nPtrSUPHeld += 1;
    }

    battleEnd(false, 0);
}