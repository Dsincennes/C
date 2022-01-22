#include "header.h"

/****************************************************************************
Function Name: playGame()
Purpose: This function handles the playing of the game, deals out cards to player,
calls all functions to compare cards and determines winner/loser.
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
void playGame()
{
    int numCards;
    char c = 0;
    int cardPointer = 0;
    int availableCards = (52 - currentDeckCursor) / 2;

        printf("\nDeck Size: %d\n", (52 - currentDeckCursor));
        printf("How many cards do you want to deal (1 - %d)\n> ", availableCards);
        scanf(" %2i", &numCards);
        while (numCards < 1 || numCards > availableCards)
        {
            clearInput();
            printf("Please only enter a number between (1 - %d)\n> ", availableCards);
            scanf(" %2i", &numCards);
        }
        clearInput();
        playerHand = drawCard(numCards, deck);
        npcHand = drawCard(numCards, deck);
    do
    {
        if (numCards == cardPointer)
        {
            printf("\n-------------------------------------------------------------------------------");
            printf("\n-----Your hand is empty, Deal more card's if you would like to play again.-----\n");
            printf("-------------------------------------------------------------------------------\n");
            break;
        }
        printf("\nPress enter to play a card or q to quit > ");
        /* Continue asking unless the user inputs yes or no */

        c = tolower(getchar());
        if (c != STOP && c != ENTER)
        {
            printf("\nPlease press enter or q");
            clearInput();
        }
        if (c == ENTER)
        {
            printf("\n*** %s of %s vs %s of %s ***\n", playerHand[cardPointer].rank, playerHand[cardPointer].suit, npcHand[cardPointer].rank, npcHand[cardPointer].suit);
            compareCards(playerHand[cardPointer], npcHand[cardPointer]);
            cardPointer++;
        }

    } while (c != STOP);
}

/****************************************************************************
Function Name: menu
Purpose: The holds the menu to call specific functions of the game.
Function in parameters: int, returns exit status
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int menu()
{
    int toggle = 0;
    int option;
    while (toggle != QUIT)
    {
        printf("\nPlease choose one of the following actions:\n");
        printf("1- Create a Deck\n2- Shuffle The Deck\n3- Display Deck\n4- Deal Cards\n5- Quit\n> ");
        scanf("%1d", &option);
        switch (option)
        {
        case CREATE_DECK:
            deck = createDeck();
            break;
        case SHUFFLE_DECK:
            if (deck != NULL)
                shuffle(deck);
            else
                printf("Please create the deck before attempting to shuffle.\n");
            break;
        case DISPLAY:
            if (deck != NULL)
                display(deck);
            else
                printf("Please create the deck before attempting to display.\n");
            break;
        case PLAY_GAME:
            if (52 - currentDeckCursor <= 1)
            {
                printf("Please re-shuffle deck before continuing to play\n");
                break;
            }
            if (deck != NULL)
                playGame();
            else
                printf("Please create the deck before attempting to Deal Cards.\n");
            break;
        case QUIT:
            printf("\nPlayer One Wins: %d\nPlayer Two Wins: %d\n", playerWins, npcWins);
            printf("\nExiting...\n");
            free(playerHand);
            free(npcHand);
            free(deck);
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("You've selected an invalid menu choice.");
            clearInput();
        }
    }
    return 0;
}