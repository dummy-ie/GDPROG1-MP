/*  playerTurn executes the player's turn during the game loop. Will show the player's options and allow the player to commit an action.
    based on the player's choice, the player may attack the enemy, try to flinch the enemy, heal the team of sync pairs, 
    skip their turn, or forfeit the match entirely. Forfeiting will treat the battle as a loss and reset the player's progress.
    @param player* p The player's information will be altered accordingly during the battle.
    @param enemy* e The enemy's information will be altered accordingly during the battle.
*/
void playerTurn(player* p, enemy* e){
    char cSelect;
    int nHPHealed;
    int nDMGDealt;

    printBattle(*p, *e);
    // printf("%d, %d, %d\n", p->nHeldStrike, p->nHeldTech, p->nHeldSupport); // * for debugging purposes
    printf(    
        GRN
        "               [ENTER A NUMBER]: "
        );

    cSelect = getche();

    printf("\n"RESET); //reset colors
    
    switch (cSelect){ // process user input
        case '1': // * strike
            if(isSyncPairFlinching(0, p->nSyncPairFlinching[0])){
                playerTurn(p, e);
            }
            else{
                nDMGDealt = dealDMG(10, 20, e->strEnemyName);
                e->nEnemyHP -= nDMGDealt;
                incrementSyncMoveCounter(&p->nSyncMoveCounter);
                checkLoss(p, e, 0);
            }
            break;
        case '2': // * tech
            if(p->nSyncPairHealth[1] > 0){ // check if our TEC is alive 
                if(isSyncPairFlinching(1, p->nSyncPairFlinching[1])){
                    playerTurn(p, e);
                }
                else if(e->nEnemyFlinching >= 1){ // can't flinch enemy that is already flinching
                    printf(GRN"               ["RED"%s"GRN" is already "BLU"FLINCH"GRN"ing]! \n"RESET, e->strEnemyName);
                    Sleep(1000);
                    playerTurn(p, e);
                }
                else{
                    e->nEnemyFlinching = tryFlinch(20, e->strEnemyName);
                    incrementSyncMoveCounter(&p->nSyncMoveCounter);
                    enemyTurn(p, e, 1);
                }
            }
            else{
                printf(GRN"               [You are out of "BLU"TEC"GRN" pairs]... \n"RESET);
                Sleep(1000);
                playerTurn(p, e);
            }
            break;
        case '3': // * support
            if(p->nSyncPairHealth[2] > 0){ // check if our SUP is alive
                if(isSyncPairFlinching(2, p->nSyncPairFlinching[2])){
                    playerTurn(p, e);
                }
                else{
                    nHPHealed = healHP();
                    limitPlayerHP(p, nHPHealed);
                    Sleep(1000);
                    incrementSyncMoveCounter(&p->nSyncMoveCounter);
                    enemyTurn(p, e, 2);
                }
            }
            else{
                printf(GRN"               [You are out of "LGR"SUP"GRN" pairs]... \n"RESET);
                Sleep(1000);
                playerTurn(p, e);
            }
            break;
        case '4': // * sync move
            if(p->nSyncMoveCounter >= 9){
                printf(GRN"               [Using "YEL"SYNC MOVE"GRN"]! \n"RESET);
                Sleep(1000);
                nDMGDealt = dealDMG(50, 50, e->strEnemyName);
                e->nEnemyHP -= nDMGDealt;
                p->nSyncMoveCounter = 0;

                checkLoss(p, e, 0);
            }
            else{
                printf(GRN"               [Your "YEL"SYNC MOVE"GRN" isn't charged yet]! \n"RESET);
                Sleep(1000);
                playerTurn(p, e);
            }
            break;
        case '5': // * skip turn
            printf(GRN"               [Skipping turn]... \n"RESET);
            Sleep(1000);
            enemyTurn(p, e, 0);
            break;
        case 'f':
        case 'F': // * either f or F
            printf(GRN"               [Forfeiting match]... \n"RESET);
            Sleep(1000);
            p->nFloor = 1;
            battleEnd(p, false, 0);
            break;
        default: // * wrong inputs
            playerTurn(p, e);
            break;
    }
}

/*  isSyncPairFlinching returns a boolean type depending on if the given sync pair is currently flinching or not.
    0 is STK, 1 is TEC, 2 is SUP.
    @param int nSyncPair is the current sync pair.
    @param int nFlinchRounds is how many rounds the current sync pair is flinching.
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

/*  limitPlayerHP executes upon healing the player's sync pairs and will limit the healing to the player's maximum allowed health.
    @param player* p The player's health to be altered.
    @param int nHPHealed how much to increase the player's health by.
*/
void limitPlayerHP(player* p, int nHPHealed){
    int i;
    for(i = 0; i < 3; i++){
        if(p->nSyncPairHealth[i] + nHPHealed >= 100){
            p->nSyncPairHealth[i] = 100;
        }
        else if(p->nSyncPairHealth[i] > 0){ // * you can only heal alive sync pairs
            p->nSyncPairHealth[i] += nHPHealed;
        }
    }
}