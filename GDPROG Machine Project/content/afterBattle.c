/*  replenishSyncPairs executes upon losing the battle with 0 of a given sync pair. 
    Will return 1 sync pair to the player and replenish its health if it has fainted and the player has lost.  
    Pre-condition: player has 0 of any sync pairs after a battle. (any sync pair held = 0)
*/
void replenishSyncPairs(){
    int* nPtrSTKHeld = playerVars("STKHeld");
    int* nPtrTECHeld = playerVars("TECHeld");
    int* nPtrSUPHeld = playerVars("SUPHeld");
    int* nPtrSTKHealth = playerVars("STKHealth");
    int* nPtrTECHealth = playerVars("TECHealth");
    int* nPtrSUPHealth = playerVars("SUPHealth");

    if(*nPtrSTKHeld == 0){ // * there should be no cases where nSyncPairHeld[i] is negative
        if(*nPtrSTKHealth <= 0){
            printf(GRN"\n               [Returning 1 %s%s"GRN" Sync Pair to you]... \n"RESET, convertPairIntToColor(0), convertPairIntToStr(0));
            Sleep(1000);
            *nPtrSTKHealth = 100;
        }
        *nPtrSTKHeld += 1;
    }
    if(*nPtrTECHeld == 0){ // * there should be no cases where nSyncPairHeld[i] is negative
        if(*nPtrTECHealth <= 0){
            printf(GRN"\n               [Returning 1 %s%s"GRN" Sync Pair to you]... \n"RESET, convertPairIntToColor(1), convertPairIntToStr(1));
            Sleep(1000);
            *nPtrTECHealth = 100;
        }
        *nPtrTECHeld += 1;
    }
    if(*nPtrSUPHeld == 0){ // * there should be no cases where nSyncPairHeld[i] is negative
        if(*nPtrSUPHealth <= 0){
            printf(GRN"\n               [Returning 1 %s%s"GRN" Sync Pair to you]... \n"RESET, convertPairIntToColor(2), convertPairIntToStr(2));
            Sleep(1000);
            *nPtrSUPHealth = 100;
        }
        *nPtrSUPHeld += 1;
    }
}

/*  battleEnd runs after the battle between the player and enemy. Resets the flinch counters for the player's sync pairs,
    and will prompt the player to choose between some options depending on if the player won or lost.
    @param bool bPlayerWon determines if the player won or lost. (1 if the player won, 0 if the player lost.)
    @param int nGemsWon is how many GEMS the player has won. (0 if the player lost.)
*/
void battleEnd(bool bPlayerWon, int nGemsWon){
    char cSelect;
    int* nPtrFloor = playerVars("Floor");
    int* nPtrSTKFlinch = playerVars("STKFlinch");
    int* nPtrTECFlinch = playerVars("TECFlinch");
    int* nPtrSUPFlinch = playerVars("SUPFlinch");
    
    printBattleEnd(*nPtrFloor, bPlayerWon, nGemsWon);


    *nPtrSTKFlinch = 0;
    *nPtrTECFlinch = 0;
    *nPtrSUPFlinch = 0;
    
    cSelect = getche();
    printf(RESET); //reset colors
    
    replenishSyncPairs();

    switch(cSelect){
        case '0':
            if(*nPtrFloor == 21){
                *nPtrFloor = 1;
            }
            openBattleVilla();
            break;
        case '1':
            if(bPlayerWon && *nPtrFloor != 21){
                startBattle();
            }
            else{
                battleEnd(bPlayerWon, nGemsWon);
            }
            break;
        default:
            battleEnd(bPlayerWon, nGemsWon);
            break;
    }
}

/*  chooseEliteReward runs after a player beats an elite enemy. 
    Will prompt the player to choose between 3 rewards.
*/
void chooseEliteReward(){
    char cSelect;
    int nGemsGenerated;
    int* nPtrGems = playerVars("Gems");
    int* nPtrSTKHealth = playerVars("STKHealth");
    int* nPtrTECHealth = playerVars("TECHealth");
    int* nPtrSUPHealth = playerVars("SUPHealth");

    printChooseEliteReward();

    cSelect = getche();
    printf("\n"RESET); //reset colors

    switch(cSelect){
        case '1':
            *nPtrSTKHealth = 100;
            *nPtrTECHealth = 100;
            *nPtrSUPHealth = 100;
            printf(GRN"               [Healed all Sync Pairs to "LGR"full HP"GRN"]! \n"RESET);
            Sleep(2000);
            break;
        case '2':
            *nPtrGems += 500;
            printf(GRN"               [Obtained "CYN"500 GEMS"GRN"]! \n"RESET);
            Sleep(2000);
            break;
        case '3':
            nGemsGenerated = randRange(100, 1000);
            *nPtrGems += nGemsGenerated;
            printf(GRN"               [Obtained "CYN"%d GEMS"GRN"]! \n"RESET, nGemsGenerated);
            Sleep(2000);
            break;
        default:
            chooseEliteReward();
            break;
    }
}

/*  getReward returns the reward for the given floor.
    @param int nFloor is used to determine the reward for the given floor.
    @return reward given depending on the floor.
    Pre-condition: nFloor is > 1 else will return 500.
*/
int getReward(int nFloor){
    nFloor -= 1; // evaluating the previous floor, not the current 
                 // (nFloor is incremented right after the battle ends)
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