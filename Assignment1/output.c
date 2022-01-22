#include "header.h"

/****************************************************************************
Function Name: menu
Purpose: To prompt the user with a menu, as well as the current options.
Function in parameters: void
Function out parameter: void
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
void menu(void)
{
    printf("         ROLL THE DICE WITH [ENTER] QUIT TO [q]\n");
    printf("-----------------------------------------------------------\n");
    printf("ROLL NUM    DICE #1    DICE #2    TOTAL ROLL    POINT MATCH\n");
    printf("-----------------------------------------------------------\n");
} /* End of function menu. */


/****************************************************************************
Function Name: rollDice
Purpose: To return a truely random dice roll from 1 - 6
Function in parameters: void
Function out parameter: int - the dice roll result
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int rollDice(void)
{
    int rand_num;
    /* struct of timeval, so we can get more accurate times for our seeding of srand. */
    struct timeval stop, start;

    gettimeofday(&start, NULL); /* Start time milisecounds */
    gettimeofday(&stop, NULL); /* Stop time milisecounds */
    /* Seed random, with stop time milisounds minus start time in secounds, etc, so we can get a truely random milisecound dice roll. */
    srand((stop.tv_usec - start.tv_sec) * 1000000 + (stop.tv_usec - start.tv_sec) / 1000);
    return rand_num = rand() % 6 + 1; /* Return a random number using the prior seeded values from prior. */
} /* End of function rollDice. */


/****************************************************************************
Function Name: gameResult
Purpose: To return to the play game section the current status of the game.
Function in parameters: void
Function out parameter: int - LOST 0, WON 1, MID 2
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int gameResult(void)
{
    /* Player result, this calculates if the player has won/lost/nothing */
    switch (result_player)
    {
        /* Drop down cases on both win and lose, and updates the wallets accordingly. */
    case SEVEN:
    case ELEVEN:
        totalWins++;
        printf("\n\nCongratulations you rolled %d and WON%s!!!\n", result_player, (rollNumber == 1) ? " at your first try" : " ");
        wallet += currentBet;
        return WON;
        break;
    case TWO:
    case THREE:
    case TWELVE:
        totalLoses++;
        printf("\n\nSorry, you rolled %d and you lose!!!\n", result_player);
        wallet -= currentBet;
        return LOST;
        break;
    default:
        /* This is a misc, winning condition, as it is the point match component. This updates the wallet accordingly.*/
        if (rollNumber > 1 && result_player == pm)
        {
            printf("\n\nCongratulations you rolled %d and WON!!!\n", result_player);
            totalWins++;
            wallet += currentBet;
            return WON;
        }
        /* NPC version of win/lose */
        switch (result_npc)
        {
            /* Drop down cases on both win and lose, and updates the wallets accordingly. This is the npc's version of this list. */
            case SEVEN:
            case ELEVEN:
                printf("\n\nComputer rolled %d and you Lose\n", result_npc);
                totalLoses++;
                wallet -= currentBet;
                return LOST;
                break;
            case TWO:
            case THREE:
            case TWELVE:
                printf("\n\nComputer rolled %d and you win!!!\n", result_npc);
                wallet += currentBet;
                totalWins++;
                return WON;
                break;
            default:
                /* NPC rolled point match, thus the npc has won in this case. */
                if (rollNumber > 1 && result_npc == pm)
                {
                    printf("\n\nComputer rolled %d and you lose :( \n", result_npc);
                    totalLoses++;
                    wallet += currentBet;
                    return WON;
                }
                /* Neither the npc nor the player has won, this round. */
                return MID;
        } /* End of inner switch statement */
    } /* End of outter switch statement */
    return 0;
} /* End of function gameResult.*/