#include <stdio.h>
/*
 Student Name: Donald Sincennes 
 Student Number: 041011305 
 Section Number: 014 
 Course: CST8234 - C Language
 Professor: Surbhi Bahri
 Author Donald Sincennes
 Due Date: 09-26-21 1159pm
*/
/* Prints numbers 1-100 and says if it is a multiple of 3, 5, or both!*/
int main()
{
    int i;
    /* for loop prints 100 numbers */
    for (i = 1; i < 101; i++) 
    { 
        /* if number printed is multiple of 3 & 5 */
        if (i % 15 == 0) 
        { 
            printf("%d I'm multiple of 3 && 5!!!\n", i);
        }
        /* if number printed is multiple of 3 */
        else if (i % 3 == 0) 
        { 
            printf("%d I'm multiple of 3!!!\n", i);
        }
        /* if number printed is multiple of 5 */
        else if (i % 5 == 0) 
        { 
            printf("%d I'm multiple of 5!!!\n", i);
        }
        else
        {
            printf("%d \n", i); /* to print #'s 1-100 */
        }
    }
    return 0;
}