/*  convertPairIntToColor returns the color of the sync pair int value passed to it.
    @param nLastPairUsed determines which pair is converted to a string.
    Pre-condition: nLastPairUsed >= 0 and nLastPairUsed <= 2
*/
char* convertPairIntToColor(int nLastPairUsed){
    switch(nLastPairUsed){
        case 0: 
            return ORN;
        case 1:
            return BLU;
        case 2: 
            return LGR;
        default:
            return RED;
    }
}

/*  convertPairIntToStr converts the sync pair's int to a string and returns it.
    @param nLastPairUsed determines which pair is converted to a string.
    Pre-condition: nLastPairUsed >= 0 and nLastPairUsed <= 2
*/
char* convertPairIntToStr(int nLastPairUsed){
    switch(nLastPairUsed){
        case 0: 
            return "STK";
        case 1: 
            return "TEC";
        case 2: 
            return "SUP";
        default:
            return RED;
    }
}

/*  updateFlinchCounter runs on each turn. Checks if player or enemy is flinching and will update the counter accordingly.
    @param player* p is the player's information.
    @param enemy* e is the enemy's information.
    @param bool bIsCheckingPlayer is true if the function is checking the player. Otherwise false.
*/
void updateFlinchCounter(player* p, enemy* e, bool bIsCheckingPlayer){
    int i;

    if(bIsCheckingPlayer){
        for(i = 0; i < 3; i++){
            if(p->nSyncPairFlinching[i] > 0){
                p->nSyncPairFlinching[i] -= 1;
            }
        }
    }
    else{
        printf(GRN"               ["RED"%s"GRN" is "BLU"FLINCH"GRN"ing]! \n"RESET, e->strEnemyName);
        Sleep(1000);
        e->nEnemyFlinching -= 1;
    }
}

/*  dealDMG calculates and returns the damage given to a sync pair.
    @param nMinDMG is the minimum range of damage given to a sync pair.
    @param nMaxDMG is the maximum range of damage given to a sync pair.
    @param int nLastPairUsed is for which sync pair the player last used.
    @return the damage done to a sync pair.
*/
int dealDMG(int nMinDMG, int nMaxDMG, char* strName){
    int nDMGDealt = randRange(nMinDMG, nMaxDMG);
    printf(GRN"               [Dealt "ORN"%d DMG"GRN" to "RED"%s"GRN"]! \n"RESET, nDMGDealt, strName);
    Sleep(1000);
    return nDMGDealt;
}

/*  tryFlinch calculates a flinch chance based on the enemy's type and returns how many rounds the targeted sync pair will flinch for.
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

void incrementSyncMoveCounter(int* nSyncMoveCounter){
    if(*nSyncMoveCounter >= 9){
        *nSyncMoveCounter = 9;
    }
    else{
        *nSyncMoveCounter += 1;
    }
}

/*  checkLoss runs after each enemy turn or if the player used STK, and checks if the player has won or lost.
    @param player* p is the player's information.
    @param enemy* e is the enemy's information.
    @param bool bIsCheckingPlayer determines if the function is checking the player or enemy. (1 if checking player, 0 otherwise)
*/
void checkLoss(player* p, enemy* e, bool bIsCheckingPlayer){
    int nGemsWon;

    if(bIsCheckingPlayer){
        if(p->nSyncPairHealth[0] <= 0 && p->nSyncPairHeld[0] == 0){
            printf(GRN"               [You lost the match]! \n"RESET);
            Sleep(2000);
            p->nFloor = 1;
            battleEnd(p, false, 0);
        }
        else{
            playerTurn(p, e);
        }
    }
    else if(e->nEnemyHP <= 0){
        printf(GRN"               ["RED"%s"GRN"'s Sync Pair has fainted]! \n"RESET, e->strEnemyName);
        Sleep(2000);
        if(p->nFloor % 5 == 0){
            chooseEliteReward(p);
        }
        if(p->nFloor != 21){
            p->nFloor++;
        }

        nGemsWon = getReward(p->nFloor);
        p->nGems += nGemsWon;
        battleEnd(p, true, nGemsWon);
    }
    else{
        enemyTurn(p, e, 0);
    }
}