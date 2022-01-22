#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

/* Different results that may win or lose */
enum game_result
{
    TWO = 2,
    THREE = 3,
    SEVEN = 7,
    ELEVEN = 11,
    TWELVE = 12
};

/* Macros */
#define LOST 0
#define WON 1
#define MID 2
#define NO 0
#define YES 1
#define ENTER '\n'
#define QUIT 'n'
#define CONTINUE 'y'
#define STOP 'n'
#define GIVEUP 'q'

/* methods */
void menu(void);
void clearInput();
int rollDice(void);
int gameResult(void);
int getOption(void);
int betPrompt(void);
int playGame();

/* declaration / variables */
int dice_one, dice_two, dice_three, dice_four, option, sum;
int pm, result_npc, rollNumber, currentGameStatus, currentBet, betting_s, result_player,  wallet, totalWins, totalLoses;