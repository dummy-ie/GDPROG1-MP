/*  replenishSyncPairs executes upon losing the battle with 0 of a given sync pair. 
    Will return 1 sync pair to the player and replenish its health if it has fainted and the player has lost.  
    @param player* p is the player's sync pairs to be replenished (specifically nSyncPairHeld[] and nSyncPairHealth[])
    Pre-condition: player has 0 of any sync pairs after a battle. (any member of nSyncPairHeld[] = 0)
*/
void replenishSyncPairs(player* p){
    int i;

    for(i = 0; i < 3; i++){
        if(p->nSyncPairHeld[i] == 0){ // * there should be no cases where nSyncPairHeld[i] is negative
            if(p->nSyncPairHealth[i] <= 0){
                printf(GRN"\n               [Returning 1 %s%s"GRN" Sync Pair to you]... \n"RESET, convertPairIntToColor(i), convertPairIntToStr(i));
                Sleep(1000);
                p->nSyncPairHealth[i] = 100;
            }
            p->nSyncPairHeld[i] += 1;
        }
    }
}

/*  battleEnd runs after the battle between the player and enemy.
    @param player* p is the player's information.
    @param bool bPlayerWon determines if the player won or lost. (1 if the player won, 0 if the player lost.)
    @param int nGemsWon is how many GEMS the player has won. (0 if the player lost.)
*/
void battleEnd(player* p, bool bPlayerWon, int nGemsWon){
    char cSelect;
    int i;
    
    printBattleEnd(p->nFloor, bPlayerWon, nGemsWon);


    for(i = 0; i < 3; i++){ // reset flinch counters after a match.
        p->nSyncPairFlinching[i] = 0;
    }
    
    cSelect = getche();
    printf(RESET); //reset colors
    
    replenishSyncPairs(p);

    switch(cSelect){
        case '0':
            if(p->nFloor == 21){
                p->nFloor = 1;
            }
            openBattleVilla(p);
            break;
        case '1':
            if(bPlayerWon && p->nFloor != 21){
                startBattle(p);
            }
            else{
                battleEnd(p, bPlayerWon, nGemsWon);
            }
            break;
        default:
            battleEnd(p, bPlayerWon, nGemsWon);
            break;
    }
}

/*  chooseEliteReward runs after a player beats an elite enemy. Will prompt the player to choose between 3 rewards.
    @param player* p is the player's information to be altered. (nSyncPairHealth[] and nGems)
*/
void chooseEliteReward(player* p){
    char cSelect;
    int nGemsGenerated;
    int i;

    printChooseEliteReward();

    cSelect = getche();
    printf("\n"RESET); //reset colors

    switch(cSelect){
        case '1':
            for(i = 0; i < 3; i++){
                p->nSyncPairHealth[i] = 100;
            }
            // ? is a for loop better than this?? idk
            // p->nSyncPairHealth[0] = 100;
            // p->nSyncPairHealth[1] = 100;
            // p->nSyncPairHealth[2] = 100;
            printf(GRN"               [Healed all Sync Pairs to "LGR"full HP"GRN"]! \n"RESET);
            Sleep(2000);
            break;
        case '2':
            p->nGems += 500;
            printf(GRN"               [Obtained "CYN"500 GEMS"GRN"]! \n"RESET);
            Sleep(2000);
            break;
        case '3':
            nGemsGenerated = randRange(100, 1000);
            p->nGems += nGemsGenerated;
            printf(GRN"               [Obtained "CYN"%d GEMS"GRN"]! \n"RESET, nGemsGenerated);
            Sleep(2000);
            break;
        default:
            chooseEliteReward(p);
            break;
    }
}

/*  getReward returns the reward for the given floor.
    @param int nFloor is used to determine the reward for the given floor.
    @return reward given depending on the floor.
    Pre-condition: nFloor is > 0 else will return 500.
*/
int getReward(int nFloor){
    if(nFloor >= 1 && nFloor <= 10){
        return 50;
    }
    else if(nFloor >= 11 && nFloor <= 15){
        return 80;
    }
    else if(nFloor >= 16 && nFloor <= 19){
        return 100;
    }
    else{
        return 500;
    }
}