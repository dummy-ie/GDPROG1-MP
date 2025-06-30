/*  randRange returns a random number between a given range nMin to nMax.
    @param int nMin - the minimum number
    @param int nMax - the maximum number
    @return a random number between nMin and nMax
    Pre-condition: nMin <= nMax
*/
int randRange(int nMin, int nMax){
    return nMin + (rand() / (RAND_MAX / (nMax - nMin + 1) + 1));
}

/*  enemyVars holds static int variables related to the enemy. Will return a pointer to the proper variable.
    @param char strVariable[] is a string that determines which pointer to return.  
    @returns a pointer to a static int variable.
*/
int* enemyVars(char strVariable[]){
    static int nEnemyRandomImage;
    static int nEnemyType;
    static int nEnemyHealth;
    static int nEnemyMaxHP;
    static int nEnemyFlinchChance;
    static int nEnemyMinDMG;
    static int nEnemyMaxDMG;
    static int nEnemyFlinch;
    // static bool bRunOnce = false;

    if(!strcmp(strVariable, "EnemyRandomImage")){
        return &nEnemyRandomImage;
    }
    else if(!strcmp(strVariable, "EnemyType")){
        return &nEnemyType;
    }
    else if(!strcmp(strVariable, "EnemyHealth")){
        return &nEnemyHealth;
    }
    else if(!strcmp(strVariable, "EnemyMaxHP")){
        return &nEnemyMaxHP;
    }
    else if(!strcmp(strVariable, "EnemyFlinchChance")){
        return &nEnemyFlinchChance;
    }
    else if(!strcmp(strVariable, "EnemyMinDMG")){
        return &nEnemyMinDMG;
    }
    else if(!strcmp(strVariable, "EnemyMaxDMG")){
        return &nEnemyMaxDMG;
    }
    else if(!strcmp(strVariable, "EnemyFlinch")){
        return &nEnemyFlinch;
    }
    else{
        return NULL;
    }
}

char** enemyName(){
    static char* strName;
    return &strName;
}

/*  startBattle initializes an enemy to fight then proceeds to playerTurn.
    if the current floor is an elite floor, will prompt the player to choose which enemy to fight.
    else, will generate a generic enemy.
*/
void startBattle(){
    int* nPtrSTKHeld = playerVars("STKHeld");
    int* nPtrTECHeld = playerVars("TECHeld");
    int* nPtrSUPHeld = playerVars("SUPHeld");
    int* nPtrFloor = playerVars("Floor"); 

    if(*nPtrFloor % 5 == 0){ // let player choose an elite enemy to fight 
        chooseElite(*nPtrFloor);
    }
    else{
        generateEnemy(); // instantiate a basic enemy to fight
    }

    *nPtrSTKHeld -= 1;
    if(*nPtrTECHeld > 0){
        *nPtrTECHeld -= 1;
    }
    if(*nPtrSUPHeld > 0){
        *nPtrSUPHeld -= 1;
    }
    
    playerTurn();
}

/*  generateEnemy adjusts the stats of the enemy to be the stats of a basic enemy on floor numbers not divisible by 5.
    will also give the enemy a randomized name. 
    Pre-condition: the player is on a floor number NOT divisible by 5.
*/
void generateEnemy(){
    char** strPtrEnemyName = enemyName();
    int* nPtrEnemyRandomImage = enemyVars("EnemyRandomImage");
    int* nPtrEnemyHealth = enemyVars("EnemyHealth");
    int* nPtrEnemyType = enemyVars("EnemyType");
    int* nPtrEnemyFlinch = enemyVars("EnemyFlinch");
    int* nPtrEnemyMaxHP = enemyVars("EnemyMaxHP");
    int* nPtrEnemyMinDMG = enemyVars("EnemyMinDMG");
    int* nPtrEnemyMaxDMG = enemyVars("EnemyMaxDMG");
    int* nPtrEnemyFlinchChance = enemyVars("EnemyFlinchChance");
    // // Array of strings (list of the possible enemy names)
    // int nRandomName = randRange(0, 45); // generate a random number to choose a random element from the array strEnemyNames
    // char* strEnemyNames[46] = { // ! deprecated, is an array so prohibited in normal version
    //     "Lord Oni",
    //     "Hog Rider",
    //     "Sorc Tails",
    //     "Prof Azmyne",
    //     "Gamer Exile",
    //     "Trainer Rai",
    //     "Lechonk",
    //     "Crewmate",
    //     "Impostor",
    //     "Michael",
    //     "Trainer DIO",
    //     "Trainer JoJo",
    //     "Tarnished",
    //     "Trainer Fia",
    //     "Gideon Ofnir",
    //     "Sorc Rogier",
    //     "Goldmask",
    //     "Roderika",
    //     "Witch Ranni",
    //     "Wolf Blaidd",
    //     "Patches",
    //     "Dung Eater",
    //     "Astolfo",
    //     "Isshin",
    //     "Gyoubu Oniwa",
    //     "Rimuru",
    //     "Benimaru",
    //     "Guy Crimson",
    //     "Rain",
    //     "Misery",
    //     "Diablo",
    //     "Testarossa",
    //     "Ultima",
    //     "Carrera",
    //     "Leon",
    //     "Ramiris",
    //     "Dino",
    //     "Dagruel",
    //     "Valentine",
    //     "Milim Nava",
    //     "Veldora",
    //     "Velzard",
    //     "Velgrynd",
    //     "Guts",
    //     "Griffith",
    //     "Caska",
    // };

    *nPtrEnemyRandomImage = randRange(0, 4);
    *nPtrEnemyHealth = 100;
    *nPtrEnemyType = 0;
    *nPtrEnemyFlinch = 0;
    *nPtrEnemyMaxHP = 100;
    *nPtrEnemyMinDMG = 10;
    *nPtrEnemyMaxDMG = 20;
    *nPtrEnemyFlinchChance = 20;
    *strPtrEnemyName = "Enemy";
}

/*  chooseElite lets the player choose between 
    two possible elite enemies to fight on floors divisible by 5
    @param int nFloor is used to determine which elite enemy to generate. 
    Pre-condition: the player is on a floor number divisible by 5.
*/
void chooseElite(int nFloor){
    char cSelect;
    int nEliteLevel = (nFloor / 5) - 1;
    char* strEliteEnemyNames[4][2] = {
        {"Will", "Karen"},
        {"Glacia", "Flint"},
        {"Grimsley", "Shauntal"},
        {"Acerola", "Siebold"}
    };

    printChooseElite(strEliteEnemyNames[nEliteLevel][0], strEliteEnemyNames[nEliteLevel][1]);
    cSelect = getche();
    printf(RESET); //reset colors

    switch(cSelect){
        case '1':
            generateElite(strEliteEnemyNames[nEliteLevel][0]);
            break;
        case '2':
            generateElite(strEliteEnemyNames[nEliteLevel][1]);
            break;
        default:
            chooseElite(nFloor);
            break;
    }
}

/*  generateElite initializes an elite enemy to fight, depending on their name and type.
    @param char* strEliteName will be used to identify the enemy type to be generated.
*/
void generateElite(char* strEliteName){
    char** strPtrEnemyName = enemyName();
    int* nPtrEnemyRandomImage = enemyVars("EnemyRandomImage");
    int* nPtrEnemyHealth = enemyVars("EnemyHealth");
    int* nPtrEnemyType = enemyVars("EnemyType");
    int* nPtrEnemyFlinch = enemyVars("EnemyFlinch");
    int* nPtrEnemyMaxHP = enemyVars("EnemyMaxHP");
    int* nPtrEnemyMinDMG = enemyVars("EnemyMinDMG");
    int* nPtrEnemyMaxDMG = enemyVars("EnemyMaxDMG");
    int* nPtrEnemyFlinchChance = enemyVars("EnemyFlinchChance");

    // * cant use switch for string so just chain if else using strcmp()
    // strcmp() returns 0 if the two strings are the same and 1 otherwise.
    if(
        !strcmp("Karen", strEliteName) || 
        !strcmp("Flint", strEliteName) || 
        !strcmp("Siebold", strEliteName)){
        *nPtrEnemyType = 1;
    }
    else if(
        !strcmp("Will", strEliteName) || 
        !strcmp("Grimsley", strEliteName)){
        *nPtrEnemyType = 2;
    }
    else{
        *nPtrEnemyType = 3;
    }

    switch(*nPtrEnemyType){
        case 1:
            *nPtrEnemyHealth = 100;
            *nPtrEnemyMaxHP = 100;
            *nPtrEnemyMinDMG = 15;
            *nPtrEnemyMaxDMG = 30;
            *nPtrEnemyFlinchChance = 15;
            break;
        case 2:
            *nPtrEnemyHealth = 150;
            *nPtrEnemyMaxHP = 150;
            *nPtrEnemyMinDMG = 15;
            *nPtrEnemyMaxDMG = 25;
            *nPtrEnemyFlinchChance = 30;
            break;
        case 3:
            *nPtrEnemyHealth = 200;
            *nPtrEnemyMaxHP = 200;
            *nPtrEnemyMinDMG = 10;
            *nPtrEnemyMaxDMG = 20;
            *nPtrEnemyFlinchChance = 20;
            break;
    }

    *nPtrEnemyRandomImage = randRange(0, 4);
    *nPtrEnemyFlinch = 0;
    *strPtrEnemyName = strEliteName;
}