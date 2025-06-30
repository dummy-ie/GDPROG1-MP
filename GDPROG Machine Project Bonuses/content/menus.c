/*  openMenu holds the text-based UI (TUI) for the main menu. 
    Can navigate to Sync Pairs, Battle Villa, and Shop Screen. Exit by entering 0.
    @param player* p holds all necessary information to be passed around to other menus. 
    In the menu, nGems is used.

    how the UI is supposed to look:
    █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█GRN
    █   ___   _ _____ _____ _    ___  __   _____ _    _      _     █GRN
    █  | _ ) /_\_   _|_   _| |  | __| \ \ / /_ _| |  | |    /_\    █GRN
    █  | _ \/ _ \| |   | | | |__| _|   \ V / | || |__| |__ / _ \   █GRN
    █  |___/_/ \_\_|   |_| |____|___|   \_/ |___|____|____/_/ \_\  █GRN
    █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█GRN 
    █                                                              █one row is 64 long
    █                          GEMS ♦ 0000                         █TEXT CYN
    █                       [1]SYNC PAIRS                          █TEXT YEL
    █                       [2]BATTLE                              █TEXT MAG
    █                       [3]SHOP                                █TEXT BLU
    █                       [0]EXIT                                █TEXT RED
    █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█
                    -----=====≡≡≡≡≡◄☼☼►≡≡≡≡≡=====-----
                    [ENTER A NUMBER]:                               TEXT GRN (including input text)
*/
void openMenu(player* p){
    char cSelect;

    printMenu(p->nGems);

    cSelect = getche(); // receive through getche() so you don't need to press the ENTER key
    printf("\n"RESET); // reset the color so that the rest of the console isn't green
        
    switch (cSelect){ //process using switch case. if invalid input, then reload the menu.
        case '0':
            break;
        case '1':
            openSyncPairs(p);
            break;
        case '2':
            openBattleVilla(p);
            break;
        case '3':
            openShop(p);
            break;
        default:
            openMenu(p);
            break;
    }
}

/*  openSyncPairs opens the text-based UI for the sync pairs screen. 
    Shows the user how many sync pairs they have. Also includes basic info on what each sync pair does.
    @param player* p holds all necessary information to be passed around to other menus. 
    In the sync pair menu, nHeldStrike, nHeldTech, and nHeldSupport is used.

    how the UI is supposed to look:
    █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█YEL
    █                          [SYNC PAIRS]                        █YEL
    █                   Viewing owned sync pairs.                  █YEL
    █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█YEL
    █[0]BACK                                                       █TEXT RED
    █                                                              █
    █           ╔-= ♠ =-╗       ╔-= ♣ =-╗       ╔-= ♥ =-╗          █RED/BLU/GRN
    █           |► 000 ◄|       |► 000 ◄|       |► 000 ◄|          █RED/BLU/GRN
    █           ╚-=STK=-╝       ╚-=TEC=-╝       ╚-=SUP=-╝          █RED/BLU/GRN
    █           STRIKE          TECH            SUPPORT            █TEXT RED/BLU/GRN
    █           STK pairs       TEC pairs       SUP pairs          █TEXT RED/BLU/GRN
    █           deal DMG.       inflict         heal HP for        █TEXT RED/BLU/GRN
    █                           FLINCH.         all pairs.         █TEXT BLU/GRN
    █                           (20% chance)                       █TEXT BLU
    █                                                              █
    █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█
                    -----=====≡≡≡≡≡◄☼☼►≡≡≡≡≡=====-----
                    [ENTER A NUMBER]:                               TEXT GRN (including input text)
    */
void openSyncPairs(player* p){
    char cSelect;

    printSyncPairs(p->nSyncPairHeld);
    
    cSelect = getche();
    printf("\n"RESET); //reset colors
    
    switch (cSelect){ // process user input
        case '0':
            openMenu(p);
            break;
        default:
            openSyncPairs(p);
            break;
    }
}

/*  openShop opens the text-based UI for the shop screen. 
    Shows the shop. Buy 1 sync pair for 200 gems.
    @param player* p holds all necessary information to be passed around to other menus. 
    In the shop menu, nGems is used for transactions. nGems display updates on every purchase. nHeldStrike, nHeldTech, and nHeldSupport is also used.

    how the UI is supposed to look:
    █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█BLU
    █                             [SHOP]                           █BLU
    █                One (1) Sync Pair costs 200 GEMs.             █BLU
    █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█BLU
    █[0]BACK                                                       █TEXT RED
    █                          GEMS ♦ 0000                         █TEXT CYN
    █                                                              █
    █           ╔-= ♠ =-╗       ╔-= ♣ =-╗       ╔-= ♥ =-╗          █SYMBOLS RED/BLU/GRN
    █           |► 000 ◄|       |► 000 ◄|       |► 000 ◄|          █
    █           ╚-=STK=-╝       ╚-=TEC=-╝       ╚-=SUP=-╝          █TEXT RED/BLU/GRN
    █              [1]             [2]             [3]             █
    █            [BUY 1]         [BUY 1]         [BUY 1]           █
    █                                                              █
    █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█
                    -----=====≡≡≡≡≡◄☼☼►≡≡≡≡≡=====-----
                    [ENTER A NUMBER]:                               TEXT GRN (including input text)
*/
void openShop(player* p){
    char cSelect;

    printShop(p->nGems, p->nSyncPairHeld);
    
    cSelect = getche();
    printf(RESET"\n");

    int nSelect = cSelect - '0'; // convert char to int just for this next range
    if(nSelect >= 1 && nSelect <= 3 && p->nGems < 200){
        printf(GRN"               [Not enough "CYN"GEMS"GRN" for purchase.]"RESET);
        Sleep(1000);
        openShop(p);
    }
    else{
        switch (cSelect){
            case '0':
                openMenu(p);
                break;
            case '1':
                p->nGems -= 200;
                p->nSyncPairHeld[0] += 1;
                printf( 
                    GRN"               [Purchased a "ORN"STRIKE"GRN" pair!]"RESET);
                Sleep(1000);
                openShop(p);
                break;
            case '2':
                p->nGems -= 200;
                p->nSyncPairHeld[1] += 1;
                printf(GRN"               [Purchased a "BLU"TECH"GRN" pair!]"RESET);
                Sleep(1000);
                openShop(p);
                break;
            case '3':
                p->nGems -= 200;
                p->nSyncPairHeld[2] += 1;
                printf(GRN"               [Purchased a "LGR"SUPPORT"GRN" pair!]"RESET);
                Sleep(1000);
                openShop(p);
                break;
            default:
                openShop(p);
                break;
        }
    }
}

/*  openBattleVilla opens the text-based UI for the Battle Villa entrance screen. 
    Shows the entrance to the battle villa. 1 starts the first battle, shift+r resets floor progress. 0 takes you back to the menu.
    @param player* p holds all necessary information to be passed around to other menus. 
    In the battle villa entrance, nFloor is used to show the current floor progress, and also if the player is at an elite floor.

    how the UI is supposed to look:
    █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█MAG
    █                         [BATTLE VILLA]                       █MAG
    █     Fight through the Battle Villa for precious rewards!     █MAG
    █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█MAG
    █[0]BACK                                                       █TEXT RED
    █                            FLOOR 00                          █TEXT GRN
    █                            [ELITE!]                          █TEXT GRN and only shows if the floor is a multiple of 5
    █                      [1]START BATTLE                         █TEXT MAG
    █                      [R]RESET FLOOR PROGRESS                 █TEXT RED
    █                                                              █
    █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█
                    -----=====≡≡≡≡≡◄☼☼►≡≡≡≡≡=====-----
                    [ENTER A NUMBER]:                               TEXT GRN (including input text)
*/
void openBattleVilla(player* p){
    char cSelect;

    printBattleVilla(p->nFloor);

    cSelect = getche();
    printf(RESET); //reset colors
    
    switch (cSelect){ // process user input
        case '0':
            openMenu(p);
            break;
        case '1':
            if(p->nSyncPairHeld[0] <= 0){ // * there should be no cases where the player is stuck with 0 STK pairs, but just in case
                printf(    "\n"RED"               [You cannot fight without a "ORN"STK"RED" pair]!"RESET);
                Sleep(1000);
                openBattleVilla(p);
            }
            else{
                startBattle(p);
            }
            break;
        case 'r':
        case 'R': // r or R
            p->nFloor = 1;
            printf(    "\n"RED"               [Resetting progress]..."RESET);
            Sleep(1000);
            openBattleVilla(p);
            break;
        default:
            openBattleVilla(p);
            break;
    }
}
