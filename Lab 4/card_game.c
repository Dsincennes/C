#include "header.h"
/*
* Title: Lab 4/5 - Card Game
* Course: CST8234 C Language
* @Author: <<< Robert Jackson (040627795) Donald Sincennes (041011305) >>>
* Lab Section: 011 (Robert) & 014 (Donald)
* Professor: Surbhi Bahri
* Due date: 11/28/21
* Submission date: 11/20/21
*/

/*
* Status:
* Requirement #1: complete ** Define 2D array demonstrating the card array deck and display it using display().
* Requirement #2: complete ** Before randomizing, make sure that you have initialized suit array, face array, deck array.
* Requirement #3: complete ** You must use %s conversion specifier to print the string of characters
* Requirement #4: complete ** Sample Shuffle execution: 
* Requirement #5: complete ** A Boolean function that compares two cards and returns true if the first card "beats" the second 
* Requirement #6: complete ** Another function to deal two hands from a deck of cards. The function takes as input the deck 
of cards and the number of cards to be dealt to each player.
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
Purpose: This is the main method of the project
Function in parameters: int, returns exit status
Version: 1
Author: Robert Jackson, Donald Sincennes
******************************************************************************/
int main(void)
{
    menu();
    return 0;
}