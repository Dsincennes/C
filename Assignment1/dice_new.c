#include "header.h"
/*
* Title: Assignment 1 - Dice Game
* Course: CST8234 C Language
* @Author: <<< Robert Jackson (040627795) Donald Sincennes (041011305) >>>
* Lab Section: 011 (Robert) & 014 (Donald)
* Professor: Surbhi Bahri
* Due date: 11/09/21
* Submission date: 11/09/21
*/

/*
* Status:
* Requirement #1: complete ** Define WON and LOST as macros in your program. Use the values of 1 for WON and 0 for LOOSE
* Requirement #2: complete ** Implement a function, with function prototype int rollDice( void ):
* Requirement #3: complete ** Implement a function, with function prototype int playGame( void );
* Requirement #4: complete ** Your main( ) should call your function playGame() etc...
* Requirement #5: complete ** Your program should use at least once the conditional operator.
* Requirement #6: complete ** Write a program must implement ALL the requirements, explicit and implicit, listed above.
* Requirement #7: complete ** You must distribute your functions in a meaningful manner across multiple .c files. The .c files 
should contain functions that represent sensible groupings of functionality
* Requirement #8: complete ** You must define .h files as appropriate.
* Requirement #9: complete ** Each function must have a header comments that explain what it does, and 
describe/explain its inputs (if any) and return value (if any)
* Requirement #10: complete ** You must submit makefile along with terminal screenshots and text files of your properly commented code.
* Requirement #11: complete ** Your program should present information to the user in clear way.
* Requirement #12: complete ** Input validation is the primary task in all the inputs user is supplying to the heap. Failing to do 
so will result in loosing marks.
* Requirement #13: complete **  Your program should compile with the flags -Wall -ansi –pedantic
*/


/****************************************************************************
Function Name: main
Purpose: Drives the program, calls playGame
Function in parameters: void
Function out parameter: EXIT_SUCCESS
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int main(void)
{
    playGame();

    return 0;
}