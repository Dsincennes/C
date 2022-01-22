#include "header.h"

/****************************************************************************
Function Name: main
Purpose: This is the main method of the project
Function in parameters: int, returns exit status, void for function parameter
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int getRand(void)
{
    int rand_num;
    /* struct of timeval, so we can get more accurate times for our seeding of srand. */
    struct timeval stop, start;

    gettimeofday(&start, NULL); /* Start time milisecounds */
    gettimeofday(&stop, NULL);  /* Stop time milisecounds */
    /* Seed random, with stop time milisounds minus start time in secounds, etc, so we can get a truely random milisecound dice roll. */
    srand((stop.tv_usec - start.tv_sec) * 1000000 + (stop.tv_usec - start.tv_sec) / 1000);
    return rand_num = rand() % 52; /* Return a random number using the prior seeded values from prior. */
} /* End of function rollDice. */

/****************************************************************************
Function Name: createDeck
Purpose: This function is used to create a deck of 52 cards, using a custom made struct object named card.
This is then filled with cards in new deck order.
Function in parameters: void for return, as well as function parameters.
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
card *createDeck(void)
{
    int count;
    card *deck = malloc(sizeof(card) * 52);

    char rank[13][6] = {
        "Ace",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
        "Ten",
        "Jack",
        "Queen",
        "King",
    };

    char suit[4][8] = {
        "Spade",
        "Heart",
        "Diamond",
        "Clubs",
    };

    for (count = 0; count < 52; count++)
    {
        strcpy(deck[count].rank, (rank[count % 13]));
        strcat(deck[count].suit, (suit[count / 13]));
    }
    printf("\nUnpacking the deck of cards...\n");
    return deck;
}

/****************************************************************************
Function Name: shuffle
Purpose: The purpose of this function is to randomize our deck of cards.
Function in parameters: no return, nor function params
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
void shuffle(card *deck)
{
    int first, second;
    card tempCard;

    for (first = 0; first < 52; first++)
    {
        second = getRand();
        tempCard = deck[first];
        deck[first] = deck[second];
        deck[second] = tempCard;
    }
    currentDeckCursor = 0;
    printf("\nShuffling Deck...\n");
}

/****************************************************************************
Function Name: getSuit
Purpose: This functions purpose is to return the value of the suit of the passed through card.
Function in parameters: integer value of our card's suit, and our function parameters are the card in question.
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int getSuit(card currentCard)
{
    if (strcmp(currentCard.suit, "Spade") == 0)
        return SPADE;
    if (strcmp(currentCard.suit, "Heart") == 0)
        return HEART;
    if (strcmp(currentCard.suit, "Diamond") == 0)
        return DIAMOND;
    if (strcmp(currentCard.suit, "Clubs") == 0)
        return CLUB;
    return 1;
}

/****************************************************************************
Function Name: getRank
Purpose: This functions purpose is to return the value of the rank of the passed through card.
Function in parameters: integer value of the card's suit is returned, and our function parameters are the card in question.
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int getRank(card currentCard)
{
    if (strcmp(currentCard.rank, "Ace") == 0)
        return ACE;
    if (strcmp(currentCard.rank, "Two") == 0)
        return TWO;
    if (strcmp(currentCard.rank, "Three") == 0)
        return THREE;
    if (strcmp(currentCard.rank, "Four") == 0)
        return FOUR;
    if (strcmp(currentCard.rank, "Five") == 0)
        return FIVE;
    if (strcmp(currentCard.rank, "Six") == 0)
        return SIX;
    if (strcmp(currentCard.rank, "Seven") == 0)
        return SEVEN;
    if (strcmp(currentCard.rank, "Eight") == 0)
        return EIGHT;
    if (strcmp(currentCard.rank, "Nine") == 0)
        return NINE;
    if (strcmp(currentCard.rank, "Ten") == 0)
        return TEN;
    if (strcmp(currentCard.rank, "Jack") == 0)
        return JACK;
    if (strcmp(currentCard.rank, "Queen") == 0)
        return QUEEN;
    if ((strcmp(currentCard.rank, "King")) == 0)
        return KING;
    return 1;
}

/****************************************************************************
Function Name: main
Purpose: This method compares two cards, for their values, as to which one is higher.
Function in parameters: integer return status, in a mock rendition of what would be a boolean.
The function parameters would be both of the cards we wish to compare.
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int compareCards(card playerCard, card npcCard)
{
    if (getRank(playerCard) == getRank(npcCard))
    {
        if (getSuit(playerCard) > getSuit(npcCard))
        {
            printf("--- Player One Wins ---\n");
            playerWins++;
            return 1;
        }
        else
        {
            printf("*** Player Two Wins ***\n");
            npcWins++;
            return 0;
        }
    }

    if (getRank(playerCard) > getRank(npcCard))

    {
        printf("--- Player One Wins ---\n");
        playerWins++;
        return 1;
    }
    else
    {
        printf("*** Player Two Wins ***\n");
        npcWins++;
        return 0;
    }
}

/****************************************************************************
Function Name: display()
Purpose: This function displays the entire content of our deck, no matter what it's present order is.
Function in parameters: void for both return as well as function parameters.
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
void display(card *deck)
{
    int i;
    for (i = 0; i < 52; i++)
    {
        printf("%s of %s\n", deck[i].rank, deck[i].suit);
        if (i == 12 || i == 25 || i == 38)
            printf("\n");
    }
}

/****************************************************************************
Function Name: drawCard
Purpose: The function drawCard, will return 
Function in parameters: int, returns exit status
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
card *drawCard(int cardNum, card *deck)
{

    card *hand = malloc(sizeof(card) * cardNum);
    int i;
    for (i = 0; i < cardNum; i++)
        hand[i] = deck[currentDeckCursor++];
    return hand;
}

/****************************************************************************
Function Name: clearInput
Purpose: This function helps clear input stream. 
Function in parameters: void
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
void clearInput()
{
    while ((getchar()) != '\n')
    ;
}