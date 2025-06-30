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

// --------------------------------------------------------------------
//    prototype all the functions so i don't get warnings on compile
// --------------------------------------------------------------------

// driver.c
int* playerVars(char strVariable[]);
void initializePlayerVars();

// display.c
void printMenu();
void printSyncPairs();
void printShop();
void printBattleVilla();
void printEnemy(int nRandomImage, int nEnemyFlinching);
void printStrike(int nSyncPairFlinching);
void printTech(int nSyncPairHealth, int nSyncPairFlinching);
void printSupport(int nSyncPairHealth, int nSyncPairFlinching);
void printBattle();
void HPToColor(int nSyncPairHealth, int nSyncPairMaxHP);
void healthBar(int nSyncPairHealth, int nSyncPairMaxHP);
void printBattleEnd(int nFloor, bool bPlayerWon, int nGemsWon);
void printChooseEliteReward();
void printChooseElite(char* strEnemyChoice1, char* strEnemyChoice2);
// void printPlayer(player p, int nSyncPair); // ! deprecated !
// void centerText(char* strText, int nFieldWidth); // ! deprecated !

// menus.c // TODO: be able to save and load the game through a settings menu (openSettings)
void openMenu();
void openSyncPairs();
void openShop();
void openBattleVilla();

// beforeBattle.c
int randRange(int nMin, int nMax);
char** enemyName();
int* enemyVars(char nVariable[]);
void startBattle();
void generateEnemy();
void chooseElite(int nFloor);
void generateElite(char* strEliteName);

// battle.c // TODO: implement Sync Move option for both the enemy and the player.
char* convertPairIntToColor(int nLastPairUsed);
char* convertPairIntToStr(int nLastPairUsed);
void updateFlinchCounter(bool isCheckingPlayer);
int dealDMG(int nMinDMG, int nMaxDMG, char* strName);
int tryFlinch(int nFlinchChance, char* strName);
int healHP();
void checkLoss(bool bPlayerWon);
void playerWon();
void playerLost();

// afterBattle.c
void replenishSyncPairs();
void battleEnd(bool bPlayerWon, int nGemsWon);
void chooseEliteReward();
int getReward(int nFloor);

// player.c
void playerTurn();
void playerStrikeMove();
void playerTechMove();
void playerSupportMove();
bool isSyncPairFlinching(int nSyncPair, int nFlinchRounds);
void limitPlayerHP(int nHPHealed);

// enemy.c 
void enemyTurn(int nLastPairUsed);
void enemyStrikeMove(int nLastPairUsed);
void enemyTechMove(int nLastPairUsed);
void enemySupportMove();
int enemyChooseMove(int nEnemyType);
void updateSyncPairs();

#endif