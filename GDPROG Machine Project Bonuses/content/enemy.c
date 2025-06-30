/*  enemyTurn randomly selects a move for the enemy to make by generating a random number between 1 and 3 to deal damage, try flinch, or heal.
    @param player* p is the player's current state.
    @param enemy* e is used to modify the enemy's state.
    @param int nLastPairUsed determines which sync pair the player last used. (0 means STK, 1 means TEC, 2 means SUP - for convenience with arrays.)
*/
void enemyTurn(player* p, enemy* e, int nLastPairUsed){
    int i;
    int nEnemyChoice;
    // int nEnemyChoice = 69; // * for testing
    // int* nTarget = enemyTarget(p, nLastPairUsed); // ! deprecated: gets address of HP for current target 
    int nHPHealed;

    updateFlinchCounter(p, e, 1); // player's turn is done, so updateFlinchCounter for player.
    
    nEnemyChoice = enemyChooseMove(e, nLastPairUsed, p->nSyncPairFlinching[0]); // enemy choose move 

    printBattle(*p, *e);
    
    if(e->nEnemyFlinching == 0){
        printf(GRN"               ["RED"%s"GRN" is making a move]! \n"RESET, e->strEnemyName);
        Sleep(2000);
        incrementSyncMoveCounter(&e->nEnemySyncMoveCounter);

        switch(nEnemyChoice){
            case 1:
                p->nSyncPairHealth[nLastPairUsed] -= dealDMG(e->nEnemyMinDMG, e->nEnemyMaxDMG, convertPairIntToStr(nLastPairUsed));
                updateSyncPairs(p);
                break;
            case 2:
                p->nSyncPairFlinching[nLastPairUsed] = tryFlinch(e->nEnemyFlinchChance, convertPairIntToStr(nLastPairUsed));
                break;
            case 3:
                nHPHealed = healHP();
                if((e->nEnemyHP + nHPHealed) >= e->nEnemyMaxHP){
                    e->nEnemyHP = e->nEnemyMaxHP;
                }
                else{
                    e->nEnemyHP += nHPHealed;
                }
                break;
            case 4:
                printf(GRN"               [Using "YEL"SYNC MOVE"GRN"]! \n"RESET);
                Sleep(1000);
                for(i = 0; i < 3; i++){ // sync move deals damage to all pairs at once.
                    p->nSyncPairHealth[i] -= dealDMG(50, 50, convertPairIntToStr(i));
                }
                e->nEnemySyncMoveCounter = 0;
                break;
        }
    }
    else{
        updateFlinchCounter(p, e, 0);
    }

    checkLoss(p, e, 1);
}

/*  enemyChooseMove reads player's values and determines what the enemy will do depending on its type.
    @param int nEnemyType is used to determine the enemy's choices.
*/
int enemyChooseMove(enemy* e, int nLastPairUsed, int nSTKFlinch){
    int nRandomPercent = randRange(1, 100);
    if(e->nEnemySyncMoveCounter == 9){
        return 4;
    }
    else if(nSTKFlinch > 0 && nLastPairUsed == 0){ // don't choose flinch on STK if STK is already flinching
        if(nRandomPercent <= 70){ // ? 70% chance to attack i guess ?
            return 1;
        }
        else{
            return 3;
        }
    }
    else{
        switch(e->nEnemyType){
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
}

/*  updateSyncPairs runs after the enemy turn. Updates the sync pairs if they fainted. After this, will run checkLoss.
    @param player* p is the player's sync pair information. (nSyncPairHealth[] and nSyncPairHeld[])
*/
void updateSyncPairs(player* p){
    int i;
    
    for(i = 0; i < 3; i++){
        if(p->nSyncPairHealth[i] <= 0){ // check if fainted
            if(p->nSyncPairHeld[i] >= 1){ // check if u have spares
                printf(GRN"               [%s%s"GRN" has fainted]! \n"RESET, convertPairIntToColor(i), convertPairIntToStr(i));
                p->nSyncPairHeld[i] -= 1;
                if(p->nSyncPairHeld[i] > 0){
                    printf(GRN"               [Replacing "ORN"STK"GRN"]... \n"RESET);
                    p->nSyncPairHealth[i] = 100;
                }
                Sleep(1000);
            }
        }
    }
}