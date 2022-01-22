#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <ctype.h>

#define CREATE_DECK 1
#define SHUFFLE_DECK 2
#define DISPLAY 3
#define PLAY_GAME 4
#define QUIT 5
#define ENTER '\n'
#define STOP 'q'

enum rank
{
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

enum suit
{
    CLUB,
    DIAMOND,
    HEART,
    SPADE
};

typedef struct card
{
    char rank[6];
    char suit[8];
} card;

int menu();
int getRand(void);
card *createDeck(void);
void shuffle(card *deck);
int getSuit(card currentCard);
int getRank(card currentCard);
int compareCards(card playerCard, card npcCard);
void display(card *deck);
card *drawCard(int cardNum, card *deck);
void clearInput();
void playGame();

int currentDeckCursor, playerWins, npcWins;
card *playerHand, *npcHand, *deck;