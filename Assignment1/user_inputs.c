#include "header.h"

/****************************************************************************
Function Name: playGame
Purpose: This function initiates the game. It prompts for betting, prints the menu, rolls the die, and outputs
the final results after a user is done playing.
Function in parameters: void
Function out parameter: EXIT_SUCCESS
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int playGame(){
    wallet = 50;
    

    printf("Welcome To Dice Game\n\n");
    rollNumber = 1;

    while (currentGameStatus != QUIT)
    {
        /* Asking user for bet */
        betPrompt();

        /* reset game */
        if (currentGameStatus == LOST)
        {
            currentGameStatus = MID;
        }

        /* Printing Menu */
        menu();

        ROLLAGAIN:
        /* User Rolling Dice */
        dice_one = rollDice();
        dice_two = rollDice();

        /* Setting Point match if first roll isnt a win/loss */
        pm = (rollNumber == 1) ? (dice_one + dice_two) : pm;

        /* Computer Rolling Dice */
        dice_three = rollDice();
        dice_four = rollDice();

        /* Results of User and PC */
        result_player = dice_one + dice_two;
        result_npc = dice_three + dice_four;

        printf(" %5d  %10d  %10d  %10d  %10d", rollNumber, dice_one, dice_two, result_player, pm);

        currentGameStatus = gameResult();

        switch (getOption())
        {
            /* Enter case: User will hit enter to continue playing */
            case ENTER:
                rollNumber++;
                goto ROLLAGAIN;
                break;
            /* Quit case: When a user is done playing, this case will print the final results*/
            case QUIT: 
                printf("\nYou won %d games and lost %d games!\n", totalWins, totalLoses);
                printf("Exiting...\n");
                currentGameStatus = QUIT;
                break;
        }
    }
    return EXIT_SUCCESS;
}

/****************************************************************************
Function Name: betPrompt
Purpose: This function handles all betting features. Prompts user to bet depending
how much they have in their wallet. All betting is done in increments of 5$. If the
user doesn't want to bet, the user can play for free.
Function in parameters: void
Function out parameter: 0
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int betPrompt(void)
{
    char c;
    int minBet, maxBet, betSize;
    minBet = ((wallet > 5 ? 1 : 0));
    maxBet = wallet / 5;
    currentBet = 0;

    printf("Would you like to bet? [y/n] ");
    do
    {
        scanf(" %1c", &c);
        /* Continue asking unless the user inputs yes or no */
        if (c != STOP && c != CONTINUE) 
        {
            printf("Please enter either y or n \n");
            clearInput();
        }
    } while (c != STOP && c != CONTINUE);

    if (c == CONTINUE)
    {
        betting_s = YES;
        printf("\nYou have $%d, it is $5 a bet, and you can bet %d times\n", wallet, maxBet);
        printf("How many $5 dollar bills would you like to bet [%d-%d] ", minBet, maxBet);

        scanf("%i", &betSize);
        /* While betSize is within minimum and maximum allowed bet */
        while(betSize < minBet || betSize > maxBet){
            clearInput();
            printf("Please only enter a number between %d-%d \n", minBet, maxBet);
            printf("How many $5 dollar bills would you like to bet [%d-%d] ", minBet, maxBet);
            scanf("%i", &betSize);
        }
        currentBet = betSize * 5;
        printf("You bet $%d!\n\n", (currentBet));
    }
    else
    {
        betting_s = NO;
    }
    clearInput();
    return 0;
}

/****************************************************************************
Function Name: getOption
Purpose: This function Asks the user if they want to play another game or not.
Function in parameters: void
Function out parameter: 0
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int getOption(void)
{
    char c;
    /* If user won game, prompt for new game */
    if (currentGameStatus == WON)
    {
        printf("\nAnother game? [y/n] ");
        do
        {
            scanf(" %1c", &c);
            if (c != STOP && c != CONTINUE){
                printf("Please enter either y or n: ");
            }
        } while (c != STOP && c != CONTINUE);
        switch (c)
        {
            case STOP:
                return QUIT;
            case CONTINUE:
                rollNumber = 1;
                return CONTINUE;
        }
    }
    /* During the game, prompt for next roll or give up */
    else if (currentGameStatus == MID)
    {
        while ((c = getchar()) != ENTER && c != GIVEUP)
        {
            printf("\nPlease enter either Enter or q\n");
        }
        switch (c)
        {
            case ENTER:
                return ENTER;
            case GIVEUP:
                totalLoses++;
                printf("\nYou chose to quit and lose\n\n");
                wallet -= currentBet;
                return LOST;
        }
    }
    /* If Game was lost, prompt for new game*/
    else
    {
        printf("\nAnother game? [y/n] ");
        do
        {
            scanf(" %1c", &c);
            if (c != STOP && c != CONTINUE){
                printf("Please enter either y or n: ");
            }
        } while (c != STOP && c != CONTINUE);
        switch (c)
        {
            case CONTINUE:
                rollNumber = 1;
                return CONTINUE;
            case STOP:
                return QUIT;
        }
        clearInput();
    }
    return 0;
}

/****************************************************************************
Function Name: clearInput
Purpose: This function helps clear input stream. 
Function in parameters: void
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
void clearInput(){
    while ((getchar()) != '\n');
}
