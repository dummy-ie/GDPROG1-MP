/*  enemyTurn randomly selects a move for the enemy to make by generating a random number between 1 and 3 to deal damage, try flinch, or heal.
    @param int nLastPairUsed determines which sync pair the player last used. (0 means STK, 1 means TEC, 2 means SUP - for convenience with arrays.)
*/
void enemyTurn(int nLastPairUsed){
    char** strPtrEnemyName = enemyName();
    int* nPtrSTKFlinch = playerVars("STKFlinch");
    int* nPtrEnemyType = enemyVars("EnemyType");
    int* nPtrEnemyFlinch = enemyVars("EnemyFlinch");
    int nEnemyChoice;
    int nRandom;
    // int nEnemyChoice = 69; // * for testing

    if(*nPtrSTKFlinch > 0 && nLastPairUsed == 0){ // don't choose flinch on STK if STK is already flinching
        nRandom = randRange(1, 100);
        if(nRandom <= 70){
            nEnemyChoice = 1;
        }
        else{
            nEnemyChoice = 3;
        }
    }
    else{
        nEnemyChoice = enemyChooseMove(*nPtrEnemyType);
    }

    updateFlinchCounter(true); // player's turn is done, so updateFlinchCounter for player.

    printBattle();
    if(*nPtrEnemyFlinch == 0){
        printf(GRN"               ["RED"%s"GRN" is making a move]! \n"RESET, *strPtrEnemyName);
        Sleep(2000);

        switch(nEnemyChoice){
            case 1:
                enemyStrikeMove(nLastPairUsed);
                break;
            case 2:
                enemyTechMove(nLastPairUsed);
                break;
            case 3:
                enemySupportMove();
                break;
        }
    }
    else{
        updateFlinchCounter(false);
    }

    checkLoss(true);
}

/*  enemyStrikeMove executes if the enemy chooses to attack the player.
    calculates and applies the damage dealt towards the player's sync pair.
    uses dealDMG(int nMinDMG, int nMaxDMG, char* strName) to calculate the damage done to the player.
    Pre-condition: nLastPairUsed is 0 - 2.
*/
void enemyStrikeMove(int nLastPairUsed){
    int* nPtrSTKHealth = playerVars("STKHealth");
    int* nPtrTECHealth = playerVars("TECHealth");
    int* nPtrSUPHealth = playerVars("SUPHealth");
    int* nPtrEnemyMinDMG = enemyVars("EnemyMinDMG");
    int* nPtrEnemyMaxDMG = enemyVars("EnemyMaxDMG");

    if(!strcmp(convertPairIntToStr(nLastPairUsed), "STK")){
        *nPtrSTKHealth -= dealDMG(*nPtrEnemyMinDMG, *nPtrEnemyMaxDMG, convertPairIntToStr(nLastPairUsed));
    }
    else if(!strcmp(convertPairIntToStr(nLastPairUsed), "TEC")){
        *nPtrTECHealth -= dealDMG(*nPtrEnemyMinDMG, *nPtrEnemyMaxDMG, convertPairIntToStr(nLastPairUsed));
    }
    else if(!strcmp(convertPairIntToStr(nLastPairUsed), "SUP")){
        *nPtrSUPHealth -= dealDMG(*nPtrEnemyMinDMG, *nPtrEnemyMaxDMG, convertPairIntToStr(nLastPairUsed));
    }

    updateSyncPairs();
}

/*  enemyTechMove executes if the enemy chooses to try and flinch the player.
    rolls for a chance to flinch the player's sync pair successfully depending on the enemy's flinch chances.
    uses tryFlinch(int nFlinchChance, char* strName) to try to flinch the player's sync pair.
    Pre-condition: nLastPairUsed is 0 - 2.
*/
void enemyTechMove(int nLastPairUsed){
    int* nPtrSTKFlinch = playerVars("STKFlinch");
    int* nPtrTECFlinch = playerVars("TECFlinch");
    int* nPtrSUPFlinch = playerVars("SUPFlinch");
    int* nPtrEnemyFlinchChance = enemyVars("EnemyFlinchChance");

    if(!strcmp(convertPairIntToStr(nLastPairUsed), "STK")){
        *nPtrSTKFlinch = tryFlinch(*nPtrEnemyFlinchChance, convertPairIntToStr(nLastPairUsed));
    }
    else if(!strcmp(convertPairIntToStr(nLastPairUsed), "TEC")){
        *nPtrTECFlinch = tryFlinch(*nPtrEnemyFlinchChance, convertPairIntToStr(nLastPairUsed));
    }
    else if(!strcmp(convertPairIntToStr(nLastPairUsed), "SUP")){
        *nPtrSUPFlinch = tryFlinch(*nPtrEnemyFlinchChance, convertPairIntToStr(nLastPairUsed));
    }
}

/*  enemySupportMove executes if the enemy chooses to heal itself.
    calculates and applies the health healed for the enemy.
    uses healHP() function to calculate the health healed.
*/
void enemySupportMove(){
    int nHPHealed;
    int* nPtrEnemyHealth = enemyVars("EnemyHealth");
    int* nPtrEnemyMaxHP = enemyVars("EnemyMaxHP");

    nHPHealed = healHP();
    if((*nPtrEnemyHealth + nHPHealed) >= *nPtrEnemyMaxHP){
        *nPtrEnemyHealth = *nPtrEnemyMaxHP;
    }
    else{
        *nPtrEnemyHealth += nHPHealed;
    }
}

/*  enemyChooseMove reads player's values and determines what the enemy will do depending on its type.
    @param int nEnemyType is used to determine the enemy's choices.
    Pre-condition: nEnemyType is 0 - 3
*/
int enemyChooseMove(int nEnemyType){
    int nRandomPercent = randRange(1, 100);
    switch(nEnemyType){
        case 1:
            if(nRandomPercent < 85){ // 85%
                return 1;
            }
            else if(nRandomPercent < 95){ // 10% 
                return 2;
            }
            else{ // 5%
                return 3;
            }
        case 2:
            if(nRandomPercent < 60){ // 60%
                return 1;
            }
            else{ // 40%
                return 2;
            }
        case 3:
            if(nRandomPercent < 60){ // 60%
                return 1;
            }
            else if(nRandomPercent < 95){ // 35% 
                return 2;
            }
            else{ // 5%
                return 3;
            }
        default: 
            if(nRandomPercent < 50){ // 50%
                return 1;
            }
            else if(nRandomPercent < 90){ // 40% 
                return 2;
            }
            else{ // 10%
                return 3;
            }
    }
}

/*  updateSyncPairs runs after the enemy turn. Updates the sync pairs if they fainted. After this, will run checkLoss.
*/
void updateSyncPairs(){
    int* nPtrSTKHeld = playerVars("STKHeld");
    int* nPtrTECHeld = playerVars("TECHeld");
    int* nPtrSUPHeld = playerVars("SUPHeld");
    int* nPtrSTKHealth = playerVars("STKHealth");
    int* nPtrTECHealth = playerVars("TECHealth");
    int* nPtrSUPHealth = playerVars("SUPHealth");

    if(*nPtrSTKHealth <= 0){ // check if fainted
        if(*nPtrSTKHeld >= 1){ // check if u have spares
            printf(GRN"               [%s%s"GRN" has fainted]! \n"RESET, convertPairIntToColor(0), convertPairIntToStr(0));
            *nPtrSTKHeld -= 1;
            if(*nPtrSTKHeld > 0){
                printf(GRN"               [Replacing %s%s"GRN"]... \n"RESET, convertPairIntToColor(0), convertPairIntToStr(0));
                *nPtrSTKHeld = 100;
            }
            Sleep(1000);
        }
    }
    if(*nPtrTECHealth <= 0){ // check if fainted
        if(*nPtrTECHeld >= 1){ // check if u have spares
            printf(GRN"               [%s%s"GRN" has fainted]! \n"RESET, convertPairIntToColor(1), convertPairIntToStr(1));
            *nPtrTECHeld -= 1;
            if(*nPtrTECHeld > 0){
                printf(GRN"               [Replacing %s%s"GRN"]... \n"RESET, convertPairIntToColor(1), convertPairIntToStr(1));
                *nPtrTECHeld = 100;
            }
            Sleep(1000);
        }
    }
    if(*nPtrSUPHealth <= 0){ // check if fainted
        if(*nPtrSUPHeld >= 1){ // check if u have spares
            printf(GRN"               [%s%s"GRN" has fainted]! \n"RESET, convertPairIntToColor(2), convertPairIntToStr(2));
            *nPtrSUPHeld -= 1;
            if(*nPtrSUPHeld > 0){
                printf(GRN"               [Replacing %s%s"GRN"]... \n"RESET, convertPairIntToColor(2), convertPairIntToStr(2));
                *nPtrSUPHeld = 100;
            }
            Sleep(1000);
        }
    }
}