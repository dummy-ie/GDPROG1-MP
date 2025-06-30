/*  printMenu() prints the main menu UI.
    @param nGems is the amount of gems to display on the menu. Default 1000
*/
void printMenu(int nGems){
    system("cls"); // clear console to make space for TUI
    printf(
        GRN
        TOP
        "█    ___   _ _____ _____ _    ___  __   _____ _    _      _      █\n"
        "█   | _ ) /_\\_   _|_   _| |  | __| \\ \\ / /_ _| |  | |    /_\\     █\n"
        "█   | _ \\/ _ \\| |   | | | |__| _|   \\ V / | || |__| |__ / _ \\    █\n"
        "█   |___/_/ \\_\\_|   |_| |____|___|   \\_/ |___|____|____/_/ \\_\\   █\n"
        BOT
        RESET
        MID
        "█                          "CYN"GEMS ♦ "WHT"%04d"RESET"                           █\n"
        "█                        "YEL"["WHT"1"YEL"]SYNC PAIRS"RESET"                           █\n"
        "█                        "MAG"["WHT"2"MAG"]BATTLE"RESET"                               █\n"
        "█                        "BLU"["WHT"3"BLU"]SHOP"RESET"                                 █\n"
        "█                        "RED"["WHT"0"RED"]EXIT"RESET"                                 █\n"
        MID
        BOT
        SEP
        GRN
        "               [ENTER A NUMBER]: "
        , nGems
    );
}

/*  printSyncPairs prints the screen for the player's inventory, 
    showing how many sync pairs are owned for each type. 
    @param player p is used to display the amount of sync pairs owned.
*/
// * no need to alter the values of player p so no need for pointer
void printSyncPairs(int nSyncPairHeld[]){
    system("cls"); // clear console to make space for TUI
    printf(
        YEL
        TOP
        "█                           [SYNC PAIRS]                         █\n"
        "█                    Viewing owned sync pairs.                   █\n"
        BOT
        RESET
        "█ "RED"["WHT"0"RED"]BACK"RESET"                                                        █\n"
        MID
        "█            "ORN"╔-= ♠ =-╗"RESET"       "BLU"╔-= ♣ =-╗"RESET"       "GRN"╔-= ♥ =-╗"RESET"           █\n"
        "█            "ORN"|► "WHT"%03d"ORN" ◄|"RESET"       "BLU"|► "WHT"%03d"BLU" ◄|"RESET"       "GRN"|► "WHT"%03d"GRN" ◄|"RESET"           █\n"
        "█            "ORN"╚-=STK=-╝"RESET"       "BLU"╚-=TEC=-╝"RESET"       "GRN"╚-=SUP=-╝"RESET"           █\n"
        "█            "ORN"STRIKE"RESET"          "BLU"TECH"RESET"            "GRN"SUPPORT"RESET"             █\n"
        "█            "ORN"STK"RESET" pairs       "BLU"TEC"RESET" pairs       "GRN"SUP"RESET" pairs           █\n"
        "█            deal "ORN"DMG"RESET".       inflict         heal "GRN"HP"RESET" for         █\n"
        "█                            "BLU"FLINCH"RESET".         all pairs.          █\n"
        "█                            (20%% chance)                        █\n"
        MID
        BOT
        SEP
        GRN "                [ENTER A NUMBER]: "
        , nSyncPairHeld[0], nSyncPairHeld[1], nSyncPairHeld[2]
    );
}

/*  printShop prints the UI for the shop screen. players are prompted to choose which sync pair to buy for 200 gems.
    player cannot buy sync pairs without at least 200 gems.
    @param player p for the player's information (nGems, nHeldStrike, nHeldTech, nHeldSupport)
*/
// * no need to alter the values of player p so no need for pointer
void printShop(int nGems, int nSyncPairHeld[]){
    system("cls");
    printf(
        BLU
        TOP
        "█                              [SHOP]                            █\n"
        "█                 One (1) Sync Pair costs 200 GEMs.              █\n"
        BOT
        RESET
        "█ "RED"["WHT"0"RED"]BACK"RESET"                                                        █\n"
        MID
        "█                          "CYN"GEMS ♦ "WHT"%04d"RESET"                           █\n"
        MID
        "█            "ORN"╔-= ♠ =-╗"RESET"       "BLU"╔-= ♣ =-╗"RESET"       "GRN"╔-= ♥ =-╗"RESET"           █\n"
        "█            "ORN"|► "WHT"%03d"ORN" ◄|"RESET"       "BLU"|► "WHT"%03d"BLU" ◄|"RESET"       "GRN"|► "WHT"%03d"GRN" ◄|"RESET"           █\n"
        "█            "ORN"╚-=STK=-╝"RESET"       "BLU"╚-=TEC=-╝"RESET"       "GRN"╚-=SUP=-╝"RESET"           █\n"
        "█               "ORN"["WHT"1"ORN"]"RESET"             "BLU"["WHT"2"BLU"]"RESET"             "GRN"["WHT"3"GRN"]"RESET"              █\n"
        "█              "ORN"BUY 1"RESET"           "BLU"BUY 1"RESET"           "GRN"BUY 1"RESET"             █\n"
        MID
        BOT
        SEP
        GRN
        "               [ENTER A NUMBER]: "
        , nGems, nSyncPairHeld[0], nSyncPairHeld[1], nSyncPairHeld[2]
    );
}

/*  prints the UI for the entrance to the battle villa. players enter a battle through here.
    @param int nFloor is the number of the floor the player is currently on.
*/
void printBattleVilla(int nFloor){
    system("cls"); // clear console to make space for TUI
    printf(
        MAG
        TOP
        "█                          [BATTLE VILLA]                        █\n"
        "█      Fight through the Battle Villa for precious rewards!      █\n"
        BOT
        RESET
        "█ "RED"["WHT"0"RED"]BACK"RESET"                                                        █\n"
        MID
        "█                           "MAG"FLOOR"RESET" %02d                             █\n"
    , nFloor);

    if(nFloor % 5 == 0){ // this is to notify the player that they are on an elite floor.
    printf(
        "█                           "YEL"[ELITE!]"RESET"                             █\n"
    );
    }

    printf(
        MID
        "█                      "MAG"["WHT"1"MAG"]START BATTLE"RESET"                           █\n"
        "█                      "RED"["WHT"R"RED"]RESET FLOOR PROGRESS"RESET"                   █\n"
        MID
        BOT
        SEP
        GRN
        "               [ENTER A NUMBER]: "
    );
} 

/*  printEnemy prints the image for an enemy based on nRandomImage, determined on initial generation of an enemy. (generateEnemy or generateElite)
    Displays a flinch overlay on the sprite if the enemy is currently flinching.
    @param int nRandomImage determines which image to print.
    @param int nEnemyFlinching is if the enemy is flinching.
*/
void printEnemy(int nRandomImage, int nEnemyFlinching){
    // nRandomImage = 4; // * for testing
    if(nEnemyFlinching >= 1){
        switch(nRandomImage){
            case 0:
                printf(
                    "█                    "RED" ╔------=========------╗ "RESET"                   █\n"
                    "█                    "RED" |        ▄▄▄▄▄        | "RESET"                   █\n"
                    "█                    "RED" |       ███████       | "RESET"                   █\n"
                    "█                    "BLU" ╔=====================╗ "RESET"                   █\n"
                    "█                    "BLU" [      "WHT"FLINCHING!"BLU"     ] "RESET"                   █\n"
                    "█                    "BLU" ╚=====================╝ "RESET"                   █\n"
                    "█                    "RED" |     "DRD"▀█"RED"███████       | "RESET"                   █\n"
                    "█                    "RED" |       ██  ██        | "RESET"                   █\n"
                    "█                    "RED" |       ▀▀  ▀▀        | "RESET"                   █\n"
                    "█                    "RED" ╚------=========------╝ "RESET"                   █\n"
                );
                break;
            case 1:
                printf(
                    "█                     "RED"╔------=========------╗ "RESET"                   █\n"
                    "█                     "RED"|        "WHT"▄.  ,▄"RED"       | "RESET"                   █\n"
                    "█                     "RED"|        ██  ██       | "RESET"                   █\n"
                    "█                     "BLU"╔=====================╗ "RESET"                   █\n"
                    "█                     "BLU"[      "WHT"FLINCHING!"BLU"     ] "RESET"                   █\n"
                    "█                     "BLU"╚=====================╝ "RESET"                   █\n"
                    "█                     "RED"|     ████████████    | "RESET"                   █\n"
                    "█                     "RED"|     ████████████    | "RESET"                   █\n"
                    "█                     "RED"|     ▀██m████m██▀    | "RESET"                   █\n"
                    "█                     "RED"╚------=========------╝ "RESET"                   █\n"
                );
                break;
            case 2:
                printf(
                    "█                     "RED"╔------=========------╗                    "RESET"█\n"
                    "█                     "RED"|      ▄▄▄▄▄▄▄▄▄▄     |                    "RESET"█\n"
                    "█                     "RED"|     ████████████    |                    "RESET"█\n"
                    "█                     "BLU"╔=====================╗ "RESET"                   █\n"
                    "█                     "BLU"[      "WHT"FLINCHING!"BLU"     ] "RESET"                   █\n"
                    "█                     "BLU"╚=====================╝ "RESET"                   █\n"
                    "█                     "RED"|   "DRD"██"RED"████"DCY"██"CYN"████████"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DRD"██"RED"████"DCY"▀████"CYN"████▀"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DRD"██"RED"████████████    |                    "RESET"█\n"
                    "█                     "RED"╚------=========------╝                    "RESET"█\n"
                );
                break;
            case 3:
                printf(
                    "█                     "RED"╔------=========------╗                    "RESET"█\n"
                    "█                     "RED"|     "YEL" ▄▄▄▄▄▄▄▄▄▄"RED"     |                    "RESET"█\n"
                    "█                     "RED"|     "YEL"████████████"RED"    |                    "RESET"█\n"
                    "█                     "BLU"╔=====================╗ "RESET"                   █\n"
                    "█                     "BLU"[      "WHT"FLINCHING!"BLU"     ] "RESET"                   █\n"
                    "█                     "BLU"╚=====================╝ "RESET"                   █\n"
                    "█                     "RED"|   "DOR"██"YEL"████"DCY"██"CYN"████████"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"YEL"████"DCY"▀████"CYN"████▀"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"YEL"████████████"RED"    |                    "RESET"█\n"
                    "█                     "RED"╚------=========------╝                    "RESET"█\n"
                );
                break;
            case 4:
                printf(
                    "█                     "RED"╔------=========------╗                    "RESET"█\n"
                    "█                     "RED"|     "MAG" ▄▄▄▄▄▄▄▄▄▄"RED"     |                    "RESET"█\n"
                    "█                     "RED"|     "MAG"████████████"RED"    |                    "RESET"█\n"
                    "█                     "BLU"╔=====================╗ "RESET"                   █\n"
                    "█                     "BLU"[      "WHT"FLINCHING!"BLU"     ] "RESET"                   █\n"
                    "█                     "BLU"╚=====================╝ "RESET"                   █\n"
                    "█                     "RED"|   "DOR"██"MAG"████"DCY"██"CYN"████████"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"MAG"████"DCY"▀████"CYN"████▀"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"MAG"████████████"RED"    |                    "RESET"█\n"
                    "█                     "RED"╚------=========------╝                    "RESET"█\n"
                );
                break;
        }
    }
    else{
        switch(nRandomImage){
            case 0:
                printf(
                    "█                    "RED" ╔------=========------╗ "RESET"                   █\n"
                    "█                    "RED" |        ▄▄▄▄▄        | "RESET"                   █\n"
                    "█                    "RED" |       ███████       | "RESET"                   █\n"
                    "█                    "RED" |     "DRD"▄█"RED"████"CYN"▄██"WHT"█▄"RED"     | "RESET"                   █\n"
                    "█                    "RED" |     "DRD"██"RED"████"DCY"▀█"CYN"██▀"RED"     | "RESET"                   █\n"
                    "█                    "RED" |     "DRD"██"RED"███████       | "RESET"                   █\n"
                    "█                    "RED" |     "DRD"▀█"RED"███████       | "RESET"                   █\n"
                    "█                    "RED" |       ██  ██        | "RESET"                   █\n"
                    "█                    "RED" |       ▀▀  ▀▀        | "RESET"                   █\n"
                    "█                    "RED" ╚------=========------╝ "RESET"                   █\n"
                );
                break;
            case 1:
                printf(
                    "█                     "RED"╔------=========------╗ "RESET"                   █\n"
                    "█                     "RED"|        "WHT"▄.  ,▄"RED"       | "RESET"                   █\n"
                    "█                     "RED"|        ██  ██       | "RESET"                   █\n"
                    "█                     "RED"|       ▄██▄▄██▄      | "RESET"                   █\n"
                    "█                     "RED"|      ███"YEL"▄"RED"██"YEL"▄"RED"███     | "RESET"                   █\n"
                    "█                     "RED"|     ▄████"WHT"\x1B[48;5;167mVV\x1B[48;5;0m"RED"████▄    | "RESET"                   █\n"
                    "█                     "RED"|     ████████████    | "RESET"                   █\n"
                    "█                     "RED"|     ████████████    | "RESET"                   █\n"
                    "█                     "RED"|     ▀██m████m██▀    | "RESET"                   █\n"
                    "█                     "RED"╚------=========------╝ "RESET"                   █\n"
                );
                break;
            case 2:
                printf(
                    "█                     "RED"╔------=========------╗                    "RESET"█\n"
                    "█                     "RED"|      ▄▄▄▄▄▄▄▄▄▄     |                    "RESET"█\n"
                    "█                     "RED"|     ████████████    |                    "RESET"█\n"
                    "█                     "RED"|     ████"CYN"▄█████"WHT"███▄"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DRD" █"RED"████"CYN"█████████"WHT"█"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DRD"██"RED"████"CYN"██████████"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DRD"██"RED"████"DCY"██"CYN"████████"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DRD"██"RED"████"DCY"▀████"CYN"████▀"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DRD"██"RED"████████████    |                    "RESET"█\n"
                    "█                     "RED"╚------=========------╝                    "RESET"█\n"
                );
                break;
            case 3:
                printf(
                    "█                     "RED"╔------=========------╗                    "RESET"█\n"
                    "█                     "RED"|     "YEL" ▄▄▄▄▄▄▄▄▄▄"RED"     |                    "RESET"█\n"
                    "█                     "RED"|     "YEL"████████████"RED"    |                    "RESET"█\n"
                    "█                     "RED"|     "YEL"████"CYN"▄█████"WHT"███▄"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR" █"YEL"████"CYN"█████████"WHT"█"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"YEL"████"CYN"██████████"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"YEL"████"DCY"██"CYN"████████"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"YEL"████"DCY"▀████"CYN"████▀"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"YEL"████████████"RED"    |                    "RESET"█\n"
                    "█                     "RED"╚------=========------╝                    "RESET"█\n"
                );
                break;
            case 4:
                printf(
                    "█                     "RED"╔------=========------╗                    "RESET"█\n"
                    "█                     "RED"|     "MAG" ▄▄▄▄▄▄▄▄▄▄"RED"     |                    "RESET"█\n"
                    "█                     "RED"|     "MAG"████████████"RED"    |                    "RESET"█\n"
                    "█                     "RED"|     "MAG"████"CYN"▄█████"WHT"███▄"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR" █"MAG"████"CYN"█████████"WHT"█"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"MAG"████"CYN"██████████"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"MAG"████"DCY"██"CYN"████████"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"MAG"████"DCY"▀████"CYN"████▀"RED"  |                    "RESET"█\n"
                    "█                     "RED"|   "DOR"██"MAG"████████████"RED"    |                    "RESET"█\n"
                    "█                     "RED"╚------=========------╝                    "RESET"█\n"
                );
                break;
        }
    }
}

/*  printStrike displays the image for the STRIKE sync pair.    
    Displays a flinch overlay on the sprite if STK is currently flinching.
    No display for STK fainted, because when STK faints, either it is replenished or you lose.
    @param nSyncPairFlinching is how many rounds STK is flinching. 
*/
void printStrike(int nSyncPairFlinching){
    if(nSyncPairFlinching >= 1){ // battle ends when STK is fainted, so no fainted sprite
        printf(
            RESET"█ "ORN"╔►  ♠  ◄======-----╗\n"
            RESET"█ "ORN"|    ▄▄▄▄▄▄▄▄▄▄    |\n"
            RESET"█ "ORN"|   ████████████   |\n"
            RESET"█ "BLU"╔==================╗\n"
            RESET"█ "BLU"[    "WHT"FLINCHING!"BLU"    ]\n"
            RESET"█ "BLU"╚==================╝\n"
            RESET"█ "ORN"| "DOR"██"ORN"████"DCY"██"CYN"████████"ORN" |\n"
            RESET"█ "ORN"| "DOR"██"ORN"████"DCY"▀████"CYN"████▀"ORN" |\n"
            RESET"█ "ORN"| "DOR"██"ORN"████████████   |\n"
            RESET"█ "ORN"╚-----======► STK ◄╝\n"
        );
    }
    else{
        printf(
                RESET"█ "ORN"╔►  ♠  ◄======-----╗ \n"
                RESET"█ "ORN"|    ▄▄▄▄▄▄▄▄▄▄    | \n"
                RESET"█ "ORN"|   ████████████   | \n"
                RESET"█ "ORN"|   ████"CYN"▄█████"WHT"███▄"ORN" | \n"
                RESET"█ "ORN"| "DOR" █"ORN"████"CYN"█████████"WHT"█"ORN" | \n"
                RESET"█ "ORN"| "DOR"██"ORN"████"CYN"██████████"ORN" | \n"
                RESET"█ "ORN"| "DOR"██"ORN"████"DCY"██"CYN"████████"ORN" | \n"
                RESET"█ "ORN"| "DOR"██"ORN"████"DCY"▀████"CYN"████▀"ORN" | \n"
                RESET"█ "ORN"| "DOR"██"ORN"████████████   | \n"
                RESET"█ "ORN"╚-----======► STK ◄╝\n"
            );
    }
}

// 22 spaces away from the beginning, \t is 8 spaces, \033[C moves cursor to the right, \033[F moves cursor up
/*  printTech displays the image for the TECH sync pair.
    Displays a flinch overlay on the sprite if TEC is currently flinching.
    Displays a fainted overlay on the sprite if TEC is currently fainted.
    @param nSyncPairHealth is TEC's current health.
    @param nSyncPairFlinching is how many rounds TEC is flinching.
*/
void printTech(int nSyncPairHealth, int nSyncPairFlinching){
    char* strTECSpaces = "\t\t\033[C\033[C\033[C\033[C\033[C\033[C";

    if(nSyncPairHealth <= 0){
        printf(
            "%s "GRY"╔►  ♣  ◄======-----╗\n"
            "%s "GRY"|    ▄▄▄▄▄▄▄▄▄▄    |\n"
            "%s "GRY"|   ████████████   |\n"
            "%s "RED"╔==================╗\n"
            "%s "RED"[      "WHT"FAINTED"RED"     ]\n"
            "%s "RED"╚==================╝\n"
            "%s "GRY"| ██████"DCY"██"CYN"████████"GRY" |\n"
            "%s "GRY"| ██████"DCY"▀████"CYN"████▀"GRY" |\n"
            "%s "GRY"| ██████████████   |\n"
            "%s "GRY"╚-----======► TEC ◄╝\n"
            , strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces
        );
    }
    else if(nSyncPairFlinching >= 1){
        printf(
            "%s "BLU"╔►  ♣  ◄======-----╗\n"
            "%s "BLU"|    ▄▄▄▄▄▄▄▄▄▄    |\n"
            "%s "BLU"|   ████████████   |\n"
            "%s "BLU"╔==================╗\n"
            "%s "BLU"[    "WHT"FLINCHING!"BLU"    ]\n"
            "%s "BLU"╚==================╝\n"
            "%s "BLU"| "DBL"██"BLU"████"DCY"██"CYN"████████"BLU" |\n"
            "%s "BLU"| "DBL"██"BLU"████"DCY"▀████"CYN"████▀"BLU" |\n"
            "%s "BLU"| "DBL"██"BLU"████████████   |\n"
            "%s "BLU"╚-----======► TEC ◄╝\n"
            // ? how do you use one argument multiple times????
            , strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces
        );
    }
    else{
        printf(
            "%s "BLU"╔►  ♣  ◄======-----╗\n"
            "%s "BLU"|    ▄▄▄▄▄▄▄▄▄▄    |\n"
            "%s "BLU"|   ████████████   |\n"
            "%s "BLU"|   ████"CYN"▄█████"WHT"███▄"BLU" |\n"
            "%s "BLU"|  "DBL"█"BLU"████"CYN"█████████"WHT"█"BLU" |\n"
            "%s "BLU"| "DBL"██"BLU"████"CYN"██████████"BLU" |\n"
            "%s "BLU"| "DBL"██"BLU"████"DCY"██"CYN"████████"BLU" |\n"
            "%s "BLU"| "DBL"██"BLU"████"DCY"▀████"CYN"████▀"BLU" |\n"
            "%s "BLU"| "DBL"██"BLU"████████████   |\n"
            "%s "BLU"╚-----======► TEC ◄╝\n"
            , strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces, strTECSpaces
        );
    }
}

/*  printSupport displays the image for the SUPPORT sync pair.
    Displays a flinch overlay on the sprite if SUP is currently flinching.
    Displays a fainted overlay on the sprite if SUP is currently fainted.
    @param nSyncPairHealth is SUP's current health.
    @param nSyncPairFlinching is how many rounds SUP is flinching.
*/
void printSupport(int nSyncPairHealth, int nSyncPairFlinching){
    char* strSUPSpaces = "\t\t\t\t\t\033[C\033[C\033[C";

    if(nSyncPairHealth <= 0){
        printf(// 43 spaces away from the beginning
            "%s "GRY"╔►  ♥  ◄======-----╗ "RESET"█\n"
            "%s "GRY"|    ▄▄▄▄▄▄▄▄▄▄    | "RESET"█\n"
            "%s "GRY"|   ████████████   | "RESET"█\n"
            "%s "RED"╔==================╗ "RESET"█\n"
            "%s "RED"[      "WHT"FAINTED"RED"     ] "RESET"█\n"
            "%s "RED"╚==================╝ "RESET"█\n"
            "%s "GRY"| ██████"DCY"██"CYN"████████ "GRY"| "RESET"█\n"
            "%s "GRY"| ██████"DCY"▀████"CYN"████▀ "GRY"| "RESET"█\n"
            "%s "GRY"| ██████████████   | "RESET"█\n"
            "%s "GRY"╚-----======► SUP ◄╝ "RESET"█\n"
            , strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces
        );
    }
    else if(nSyncPairFlinching >= 1){
        printf(// 43 spaces away from the beginning
            "%s "GRN"╔►  ♥  ◄======-----╗ "RESET"█\n"
            "%s "GRN"|    ▄▄▄▄▄▄▄▄▄▄    | "RESET"█\n"
            "%s "GRN"|   ████████████   | "RESET"█\n"
            "%s "BLU"╔==================╗ "RESET"█\n"
            "%s "BLU"[    "WHT"FLINCHING!"BLU"    ] "RESET"█\n"
            "%s "BLU"╚==================╝ "RESET"█\n"
            "%s "GRN"| "DGR"██"GRN"████"DCY"██"CYN"████████ "GRN"| "RESET"█\n"
            "%s "GRN"| "DGR"██"GRN"████"DCY"▀████"CYN"████▀ "GRN"| "RESET"█\n"
            "%s "GRN"| "DGR"██"GRN"████████████   | "RESET"█\n"
            "%s "GRN"╚-----======► SUP ◄╝ "RESET"█\n"
            , strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces
        );
    }
    else{
        printf(// 43 spaces away from the beginning
            "%s "GRN"╔►  ♥  ◄======-----╗ "RESET"█\n"
            "%s "GRN"|    ▄▄▄▄▄▄▄▄▄▄    | "RESET"█\n"
            "%s "GRN"|   ████████████   | "RESET"█\n"
            "%s "GRN"|   ████"CYN"▄█████"WHT"███▄ "GRN"| "RESET"█\n"
            "%s "GRN"|  "DGR"█"GRN"████"CYN"█████████"WHT"█ "GRN"| "RESET"█\n"
            "%s "GRN"| "DGR"██"GRN"████"CYN"██████████ "GRN"| "RESET"█\n"
            "%s "GRN"| "DGR"██"GRN"████"DCY"██"CYN"████████ "GRN"| "RESET"█\n"
            "%s "GRN"| "DGR"██"GRN"████"DCY"▀████"CYN"████▀ "GRN"| "RESET"█\n"
            "%s "GRN"| "DGR"██"GRN"████████████   | "RESET"█\n"
            "%s "GRN"╚-----======► SUP ◄╝ "RESET"█\n"
            , strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces, strSUPSpaces
        );
    }
}

// prints the UI for the battle screen.
/*symbols + code + code in octal:
    1 ☺      
    2 ☻      
    3 ♥      
    4 ♦      
    5 ♣      
    6 ♠
    16 ► 20
    17 ◄ 21
    187 ╗ 273
    188 ╝ 274
    200 ╚ 310
    201 ╔ 311

    STK/TEC/SUP counters:
    ╔-  ♠  -╗ ╔-  ♣  -╗ ╔-= ♥ =-╗ ╔-= ♠ =-╗
    |► 000 ◄| |► 000 ◄| |► 000 ◄| |► %03d ◄|
    ╚-=STK=-╝ ╚-=TEC=-╝ ╚-=SUP=-╝ ╚-=STK=-╝

        "█                     "YEL" ╔------========------╗ "RESET"                 █\n"
        "█                     "YEL" |       ,.  ,.       |       "RESET"           █\n"
        "█                     "YEL" |       ||  ||       |       "RESET"           █\n"
        "█                     "YEL" |      ,''--''.      |       "RESET"           █\n"
        "█                     "YEL" |     : (o)(o) :     |       "RESET"           █\n"
        "█                     "YEL" |    ,'   VV   `.    |       "RESET"           █\n"
        "█                     "YEL" |    :          :    |       "RESET"           █\n"
        "█                     "YEL" |    :          :    |       "RESET"           █\n"
        "█                     "YEL" |    `._m____m_,'    |       "RESET"           █\n"
        "█                     "YEL" ╚------========------╝ "RESET"                 █\n"
        
        "█        "ORN" ╔-=[1]=-╗ "RESET"      "BLU"  ╔-=[2]=-╗ "RESET"     "GRN"   ╔-=[3]=-╗ "RESET"       █\n"
        "█        "ORN" |►  ♠  ◄|  "RESET"      "BLU" |►  ♣  ◄|   "RESET"     "GRN" |►  ♥  ◄|    "RESET"    █\n"
        "█        "ORN" ╚-=STK=-╝ "RESET"      "BLU"  ╚-=TEC=-╝ "RESET"     "GRN"   ╚-=SUP=-╝ "RESET" 

    Player frames:
    ╔-----=  STK =-----╗ ╔-----=  TEC =-----╗ ╔-----=  SUP =-----╗ 
    |    ▄▄▄▄▄▄▄▄▄▄    | |    ▄▄▄▄▄▄▄▄▄▄    | |    ▄▄▄▄▄▄▄▄▄▄    | 
    |   ████████████   | |   ████████████   | |   ████████████   | 
    |   ████▄████████▄ | |   ████▄████████▄ | |   ████▄████████▄ | 
    |  ███████████████ | |  ███████████████ | |  ███████████████ | 
    | ████████████████ | | ████████████████ | | ████████████████ | 
    | ████████████████ | | ████████████████ | | ████████████████ | 
    | ██████▀████████▀ | | ██████▀████████▀ | | ██████▀████████▀ | 
    | ██████████████   | | ██████████████   | | ██████████████   |   
    ╚-----========-----╝ ╚-----========-----╝ ╚-----========-----╝ 
    printf(
        "█"ORN"╔----=►  ♠  ◄=-----╗ "BLU"╔----=►  ♣  ◄=-----╗ "GRN"╔----=►  ♥  ◄=-----╗"RESET"█\n"
        "█"ORN"|    ▄▄▄▄▄▄▄▄▄▄    | "BLU"|    ▄▄▄▄▄▄▄▄▄▄    | "GRN"|    ▄▄▄▄▄▄▄▄▄▄    |"RESET"█\n"
        "█"ORN"|   ████████████   | "BLU"|   ████████████   | "GRN"|   ████████████   |"RESET"█\n"
        "█"ORN"|   ████"CYN"▄█████"WHT"███▄"ORN" | "BLU"|   ████"CYN"▄█████"WHT"███▄"BLU" | "GRN"|   ████"CYN"▄█████"WHT"███▄ "GRN"|"RESET"█\n"
        "█"ORN"| "DOR" █"ORN"████"CYN"█████████"WHT"█"ORN" | "BLU"|  "DBL"█"BLU"████"CYN"█████████"WHT"█"BLU" | "GRN"|  "DGR"█"GRN"████"CYN"█████████"WHT"█ "GRN"|"RESET"█\n"
        "█"ORN"| "DOR"██"ORN"████"CYN"██████████"ORN" | "BLU"| "DBL"██"BLU"████"CYN"██████████"BLU" | "GRN"| "DGR"██"GRN"████"CYN"██████████ "GRN"|"RESET"█\n"
        "█"ORN"| "DOR"██"ORN"████"DCY"██"CYN"████████"ORN" | "BLU"| "DBL"██"BLU"████"DCY"██"CYN"████████"BLU" | "GRN"| "DGR"██"GRN"████"DCY"██"CYN"████████ "GRN"|"RESET"█\n"
        "█"ORN"| "DOR"██"ORN"████"DCY"▀████"CYN"████▀"ORN" | "BLU"| "DBL"██"BLU"████"DCY"▀████"CYN"████▀"BLU" | "GRN"| "DGR"██"GRN"████"DCY"▀████"CYN"████▀ "GRN"|"RESET"█\n"
        "█"ORN"| "DOR"██"ORN"████████████   | "BLU"| "DBL"██"BLU"████████████   | "GRN"| "DGR"██"GRN"████████████   |"RESET"█\n"
        "█"ORN"╚----=► STK ◄=-----╝ "BLU"╚----=► TEC ◄=-----╝ "GRN"╚----=► SUP ◄=-----╝"RESET"█\n"
    );
             
    Enemy frame:
    ╔------========------╗ ╔------========------╗
    |        ▄▄▄▄        | |        ▄▄▄▄        |
    |       ██████       | |       ██████       |
    |     ▄████▄███▄     | |     ▄████▄███▄     |
    |     █████▀███▀     | |     █████▀███▀     |
    |     ████████       | |     ████████       |
    |     ▀███████       | |     ▀███████       |
    |       ██  ██       | |       ██  ██       |
    |       ▀▀  ▀▀       | |       ▀▀  ▀▀       |  
    ╚------========------╝ ╚------========------╝
            ENEMY 

    UI concept:
    █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
    █[F]FORFEIT                                                    █TEXT RED
    █                            FLOOR 00                          █TEXT RED
    █                     ╔------========------╗                   █
    █                     |       ,.  ,.       |                   █
    █                     |       ||  ||       |                   █
    █                     |      ,''--''.      |                   █
    █                     |     : (o)(o) :     |                   █
    █                     |    ,'   VV   `.    |                   █
    █                     |    :          :    |                   █
    █                     |    :          :    |                   █
    █                     |    `._m____m_,'    |                   █
    █                     ╚------========------╝                   █
    █                        ENEMY SYNC PAIR                       █TEXT RED
    █                         ◄ ██████████ ►                       █RED
    █                               HP                             █RED
    █                                                              █
    █         ╔-=[1]=-╗         ╔-=[2]=-╗         ╔-=[3]=-╗        █RED/BLU/GRN
    █         |►  ♠  ◄|         |►  ♣  ◄|         |►  ♥  ◄|        █RED/BLU/GRN
    █         ╚-=STK=-╝         ╚-=TEC=-╝         ╚-=SUP=-╝        █RED/BLU/GRN
    █      |+|██████████     |+|██████████     |+|██████████       █RED
    █                                                              █
    █                          [4]END TURN                         █TEXT MAG
    █                                                              █
    █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█
                    -----=====≡≡≡≡≡◄☼☼►≡≡≡≡≡=====-----
                    [ENTER A NUMBER]:                               TEXT GRN (including input text)
*/
/*  printBattle prints the display for the ongoing battle between the player and an enemy.
    reads from player p and enemy e and displays the proper information based on the variable states.
    @param player p holds all the information on the player's sync pairs.
    @param enemy e holds all the information on the enemy's sync pair.
*/
void printBattle(player p, enemy e){
    system("cls"); // clear console to make space for TUI
    printf(
        TOP
        "█ "RED"[F]FORFEIT"RESET"                                                     █\n"
        "█                           "MAG"[FLOOR]"RESET" %02d                           █\n"
        "█                              "RED"ENEMY"RESET"                             █\n"
        , p.nFloor
    );
    printEnemy(e.nEnemyRandomImage, e.nEnemyFlinching);
    printf(
        "█                     "WHT"%-13s"RESET
        , e.strEnemyName
    );
    healthBar(e.nEnemyHP, e.nEnemyMaxHP);
    printf(
        RESET"                    █\n"
        "█                                         ");
    HPToColor(e.nEnemyHP, e.nEnemyMaxHP);
    printf("%03d", e.nEnemyHP);
    printf( 
        "                    "RESET"█\n"
        MID
    );

    // Sync pair images ----------------------------------------
    printStrike(p.nSyncPairFlinching[0]);
    for(int i = 0; i < 10; i++){
        printf("\033[F"); // return to the top.
    }
    printTech(p.nSyncPairHealth[1], p.nSyncPairFlinching[1]);
    for(int i = 0; i < 10; i++){
        printf("\033[F"); // return to the top.
    }
    printSupport(p.nSyncPairHealth[2], p.nSyncPairFlinching[2]);

    // Sync pair health bars -----------------------------------
    printf("█ "ORN"["WHT"1"ORN"]"RESET"       ");
    healthBar(p.nSyncPairHealth[0], 100);
    printf(RESET" "BLU"["WHT"2"BLU"]"RESET"       ");
    healthBar(p.nSyncPairHealth[1], 100);
    printf(RESET" "LGR"["WHT"3"LGR"]"RESET"       ");
    healthBar(p.nSyncPairHealth[2], 100);
    printf(RESET" █\n");

    // Sync pair health values ---------------------------------
    printf("█");
    HPToColor(p.nSyncPairHealth[0], 100);
    printf("                  %03d", p.nSyncPairHealth[0]);
    HPToColor(p.nSyncPairHealth[1], 100);
    printf("                  %03d", p.nSyncPairHealth[1]);
    HPToColor(p.nSyncPairHealth[2], 100);
    printf("                  %03d", p.nSyncPairHealth[2]);

    // ! deprecated !
    // printf("█   "RED"|%03d|", p.nSyncPairHealth[0]);
    // printf("     |%03d|", p.nSyncPairHealth[1]);
    // printf("   |%03d|", p.nSyncPairHealth[2]);
    // ! deprecated !
    printf( 
        RESET                 
        " █\n"
        MID
        "█                       "YEL"╔► ± ◄======-------╗"RESET"                     █\n"
        "█                       "
    );
    syncMoveCounter(p.nSyncMoveCounter);
    printf(
        RESET
        "¤                    █\n"
        "█                       "YEL"╚ SYNC MOVE CHARGE ╝"RESET"                     █\n"
        MID
        "█              "YEL"["WHT"4"YEL"]SYNC MOVE"RESET"               "MAG"["WHT"5"MAG"]END TURN"RESET"            █\n"
        MID
        "█-----------------========►  "YEL"INVENTORY"RESET"  ◄========----------------█\n"
        "█       "ORN"╔-= ♠ =-╗"RESET"            "BLU"╔-= ♣ =-╗"RESET"           "GRN"╔-= ♥ =-╗"RESET"       █\n"
        "█       "ORN"|► "WHT"%03d"ORN" ◄|"RESET"            "BLU"|► "WHT"%03d"BLU" ◄|"RESET"           "GRN"|► "WHT"%03d"GRN" ◄|"RESET"       █\n"
        "█       "ORN"╚-=STK=-╝"RESET"            "BLU"╚-=TEC=-╝"RESET"           "GRN"╚-=SUP=-╝"RESET"       █\n"
        BOT
        SEP
        , p.nSyncPairHeld[0], p.nSyncPairHeld[1], p.nSyncPairHeld[2]
        // "%d, %d, %d, %d, %d\n" // * for testing purposes
        // ,e.nEnemyHP, e.nEnemyMaxHP, e.nEnemyMinDMG, e.nEnemyMaxDMG, e.nEnemyFlinchChance
    );
}

void syncMoveCounter(int nCounter){
    int i, j;
    
    printf(YEL);
    printf("╠»");
    for(i = 0; i < nCounter - 1; i++){ // the full bars
        printf("█ ");
        // printf("%c", 219); // * for without utf-8 encoding
    }
    if(nCounter == 9){ // the final bar shouldn't have a space
        printf("█");
    }
    else if(nCounter > 0){
        printf("█ ");
    }

    printf(GRY);
    if(nCounter != 9){
        for(j = i; j < (9 - nCounter + i) - 1; j++){ // the empty bars
            printf("░ ");
        }
        printf("░"); // the final bar shouldn't have a space
    }
    printf(YEL);
    printf("╣");
}

/*  HPToColor receives a sync pair's health value and changes the color of the text
    based on the percentage of the current health left.
    FADED = <0, DRD = 1 - 25, ORN = 26 - 50, YEL = 51 - 75, LGR = >76 (in percentage of the max health)
    @param int nSyncPairHealth is the health value of the sync pair.
*/
void HPToColor(int nSyncPairHealth, int nSyncPairMaxHP){
    float nHealthPercent = ((float)nSyncPairHealth / nSyncPairMaxHP) * 100;
    // printf("%.2f", nHealthPercent); // * for testing purposes
    if(nHealthPercent >= 76){ // >= 76%
        printf(LGR);
    }
    else if(nHealthPercent >= 51){ // 75% - 51%
        printf(YEL);
    }
    else if(nHealthPercent >= 26){ // 50% - 26%
        printf(ORN);
    }
    else if(nHealthPercent >= 1){ // 25% - 1%
        printf("\x1b[38;5;196m"); // bright red
    }
    else{ // fainted
        printf(GRY);
    }
}

// ! deprecated !
/*  centerText prints a string within a specified length and pads it such that the string will be centered.
    @param char* strText is the string to center.
    @param int nFieldWidth is the length of the whole string.
*/
// void centerText(char* strText, int nFieldWidth){
//     int nPadLen = (nFieldWidth - strlen(strText)) / 2;
//     printf("%*s%s%*s", nPadLen, "", strText, nPadLen, "");
// }
// ! deprecated !

/*  healthBar prints out an HP bar according to how much HP is processed. for example, if the element has 80HP, will print out 8 full bars and 2 empty bars. 
    Used to convert HP numbers into an actual bar to show to the player.
    @param int nSyncPairHealth is the HP to be processed into a health bar.
*/
void healthBar(int nSyncPairHealth, int nSyncPairMaxHP){
    int i, j;

    HPToColor(nSyncPairHealth, nSyncPairMaxHP);

    if(nSyncPairHealth > nSyncPairMaxHP){ // limits the HP to nSyncPairMaxHP
        nSyncPairHealth = nSyncPairMaxHP;
    }
    if(nSyncPairHealth < 0){ // limits the bar HP to 0
        nSyncPairHealth = 0;
    }

    for(i = 0; i < nSyncPairHealth / (nSyncPairMaxHP / 10); i++){ // the full bars
        printf("█");
        // printf("%c", 219); // * for without utf-8 encoding
    }

    if(nSyncPairHealth != nSyncPairMaxHP){
        printf(DOR);
        printf("▒");
        printf(RED);
        for(j = i; j < (nSyncPairMaxHP / (nSyncPairMaxHP / 10)) - 1; j++){ // the empty bars
            printf("░");
            // printf("%c", 176); // * for without utf-8 encoding
        }
    }
}

/*  printBattleEnd prints prompt at the end of the battle depending on if the player won or lost.
    @param int nFloor is which floor the player is currently on.
    @param bool bPlayerWon determines if the player just lost or won.
    @param int nGemsWon is how many gems the player has received after the battle. 0 if lost.
*/
void printBattleEnd(int nFloor, bool bPlayerWon, int nGemsWon){
    system("cls"); // clear console to make space for TUI (around 12 lines long)
    printf(
        MAG
        TOP
            "█                           [BATTLE END]                         █\n"
        BOT
        RESET
        MID
    );
    if(bPlayerWon && nFloor == 20){
        printf(
            MID
            "█                           Congratulations                      █\n"
            "█               You Have Completed the Battle Villa!             █\n"
            MID
            "█                              "RED"["WHT"0"RED"]EXIT"RESET"                           █\n"
            MID
        );
    }
    else if(bPlayerWon && nFloor != 20){
        printf(
            MID
            "█                            Battle Won!                         █\n"
            "█                        Earned %03d "CYN"GEMS ♦"RESET"!                      █\n"
            MID
            "█                    "MAG"["WHT"1"MAG"]CONTINUE     "RED"["WHT"0"RED"]TAKE A BREAK"RESET"             █\n"
            MID
        , nGemsWon
        );
    }
    else{
        printf(
            MID
            "█                           Battle Lost!                         █\n"
            MID
            "█                            "RED"["WHT"0"RED"]LEAVE"RESET"                            █\n"
            MID
        );
    }
    printf(
        BOT
        SEP
        GRN
        "               [ENTER A NUMBER]: "
    );
}

/*  printChooseEliteReward prints the display for choosing which reward to take after completing
    a floor that has an elite enemy on it. 
*/
void printChooseEliteReward(){
    system("cls"); // clear console to make space for TUI
    printf(
        MAG
        TOP
        "█                            [BATTLE END]                        █\n"
        BOT
        RESET
        MID
        "█                        Beat an Elite enemy!                    █\n"
        "█                          Choose a reward!                      █\n"
        MID
        "█                           "LGR"["WHT"1"LGR"]FULL HEAL"RESET"                         █\n"
        "█                           "YEL"["WHT"2"YEL"]500 "CYN"GEMS ♦"RESET"                        █\n"
        "█                           "MAG"["WHT"3"MAG"]RANDOM "CYN"GEMS ♦"RESET"                     █\n"
        MID
        BOT
        SEP
        GRN
        "               [ENTER A NUMBER]: "
    );
}

/*  printChooseElite prints the display for the player to select which elite enemy to fight on certain floors.
    @param char* strEliteChoice1 is the name of the first elite enemy.
    @param char* strEliteChoice2 is the name of the second elite enemy.
*/
void printChooseElite(char* strEliteChoice1, char* strEliteChoice2){
    system("cls"); // clear console to make space for TUI
    printf(
        MAG
        TOP
        "█                          [STARTING BATTLE]                     █\n"
        BOT
        RESET
        MID
        "█                            Choose Enemy!                       █\n"
        MID
    );
    printf(
        "█                      "RED"["WHT"1"RED"]%-8s     "BLU"["WHT"2"BLU"]%-8s"RESET"               █\n"
        ,strEliteChoice1, strEliteChoice2
    );
    printf(
        MID
        BOT
        SEP
        GRN
        "               [ENTER A NUMBER]: "
    );
}