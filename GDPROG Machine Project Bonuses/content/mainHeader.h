#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h> // system(cls)
#include <string.h> // strcmp(), strlen()
#include <time.h> // srand(time())
#include <Windows.h> // Sleep(microseconds)
#include <conio.h> // getche() (no need to press ENTER while playing.)
#include <stdbool.h> // boolean data type

// defining constants for changing the color of text mid-print and displaying ASCII in a consistent way.
#define RED "\x1B[31m"
#define DRD "\x1B[38;5;88m" // dark red
#define ORN "\x1B[38;5;202m" // orange
#define DOR "\x1B[38;5;130m" // dark orange
#define LGR "\x1B[38;5;46m" // light green
#define GRN "\x1B[32m"
#define DGR "\x1B[38;5;22m" // dark green
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define DBL "\x1B[38;5;18m" // dark blue
#define MAG "\x1B[35m" // magenta
#define CYN "\x1B[36m" // cyan
#define DCY "\x1B[38;5;31m" // dark cyan
#define WHT "\x1B[37m" // white
#define GRY "\x1B[38;5;8m" // gray
#define RESET "\x1B[0m"
#define TOP "█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n"
#define MID "█                                                                █\n"
#define BOT "█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n"
#define SEP "               -----=====≡≡≡≡≡◄☼☼►≡≡≡≡≡=====-----\n"


/*  defining struct type Player:
    struct Player holds all information on the player, 
    including the gem count and sync pair count, etc.
    typedef for convenience when initializing the struct
    @ int nGems is the player's gem counter.
    @ int nFloor is what floor the player is on.
    @ int nSyncPairHeld[3] is an array of integers that indicate how many sync pairs the player currently owns. 0 is for STK, 1 for TEC, and 2 for SUP
    @ int nSyncPairHealth[3] is an array of numbers that contain the health values for the player's sync pairs. 0 is for STK, 1 for TEC, and 2 for SUP
    @ int nSyncPairFlinching[3] is an array of numbers that determine how many rounds the player's sync pairs are flinching. 0 is for STK, 1 for TEC, and 2 for SUP.
*/
typedef struct Player{
    int nGems;
    int nFloor;
    int nSyncMoveCounter;
    int nSyncPairHeld[3];
    int nSyncPairHealth[3];
    int nSyncPairFlinching[3];
} player;

/*  defining struct type Enemy:
    struct Enemy holds information on each enemy in the battle villa, including the enemy's sync pair health, type, and name.
    @ int nEnemyType is what type of enemy is. 0 for basic, 1 for type 1 elite, 2 for type 2 elite, and 3 for type 3 elite.
    @ int nEnemyHP is the enemy's current health.
    @ int nEnemyMaxHP is the enemy's maximum health.
    @ int nEnemyFlinchChance is the enemy's chance of successfully flinching the player.
    @ int nEnemyMinDMG is the enemy's minimum damage to the player.
    @ int nEnemyMaxDMG is the enemy's maximum damage to the player.
    @ int nEnemyFlinching is how many rounds the enemy will be flinching.
    @ char* strEnemyName is the name of the enemy.
*/
typedef struct Enemy{
    int nEnemyRandomImage;
    int nEnemyType;
    int nEnemySyncMoveCounter;
    int nEnemyHP;
    int nEnemyMaxHP;
    int nEnemyFlinchChance;
    int nEnemyMinDMG;
    int nEnemyMaxDMG;
    int nEnemyFlinching;
    char* strEnemyName;
} enemy;

// --------------------------------------------------------------------
//    prototype all the functions so i don't get warnings on compile
// --------------------------------------------------------------------

// display.c
void printMenu(int nGems);
void printSyncPairs(int nSyncPairHeld[]);
void printShop(int nGems, int nSyncPairHeld[]);
void printBattleVilla(int nFloor);
void printEnemy(int nRandomImage, int nEnemyFlinching);
void printStrike(int nSyncPairFlinching);
void printTech(int nSyncPairHealth, int nSyncPairFlinching);
void printSupport(int nSyncPairHealth, int nSyncPairFlinching);
void printBattle(player p, enemy e);
void syncMoveCounter(int nCounter);
void HPToColor(int nSyncPairHealth, int nSyncPairMaxHP);
void healthBar(int nSyncPairHealth, int nSyncPairMaxHP);
void printBattleEnd(int nFloor, bool bPlayerWon, int nGemsWon);
void printChooseEliteReward();
void printChooseElite(char* strEnemyChoice1, char* strEnemyChoice2);
// void printPlayer(player p, int nSyncPair); // ! deprecated !
// void centerText(char* strText, int nFieldWidth); // ! deprecated !

// menus.c // TODO: be able to save and load the game through a settings menu (openSettings)
void openMenu(player* p);
void openSyncPairs(player* p);
void openShop(player* p);
void openBattleVilla(player* p);

// beforeBattle.c
int randRange(int nMin, int nMax);
void startBattle(player* p);
void generateEnemy(enemy* e);
void chooseElite(enemy* e, int nFloor);
void generateElite(enemy* e, char* strEliteName);

// battle.c // TODO: implement Sync Move option for both the enemy and the player.
char* convertPairIntToColor(int nLastPairUsed);
char* convertPairIntToStr(int nLastPairUsed);
void updateFlinchCounter(player* p, enemy* e, bool isCheckingPlayer);
int dealDMG(int nMinDMG, int nMaxDMG, char* strName);
int tryFlinch(int nFlinchChance, char* strName);
int healHP();
void incrementSyncMoveCounter(int* nSyncMoveCounter);
void checkLoss(player* p, enemy* e, bool bPlayerWon);

// afterBattle.c
void replenishSyncPairs(player* p);
void battleEnd(player* p, bool bPlayerWon, int nGemsWon);
void chooseEliteReward(player* p);
int getReward(int nFloor);

// player.c
void playerTurn(player* p, enemy* e);
bool isSyncPairFlinching(int nSyncPair, int nFlinchRounds);
void limitPlayerHP(player* p, int nHPHealed);

// enemy.c 
void enemyTurn(player* p, enemy* e, int nLastPairUsed);
int enemyChooseMove(enemy* e, int nLastPairUsed, int nSTKFlinch);
void updateSyncPairs(player* p);

#endif