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
/* Gets user input, and reformats it i  nto a phone number of the format ###-#### */
int main()
{

    int min = 1000000; /* minimum number allowed for input */
    int max = 9999999; /* maximum number allowed for input */

    while (1)
    {
        int num = 6;
        char output[7];
        int number = 0;
        int i;
        printf("Enter a phone number: "); /* asks user to enter a phone number */
        scanf("%d", &number);             /* user input */
        if (number == 0)
        { /* to exit loop */
            return 0;
        }
        /* phone number input is too small to format */
        else if (number < min) 
        {
            printf("Invalid phone number: too few digits\n");
        }
        /* phone number is to big to format */
        else if (number > max) 
        {
            printf("Invalid phone number: too many digits\n");
        }
        /* phone number begins with a 1 */
        else if (number / 1000000 == 1) 
        {
            printf("invalid central office code: 1\n");
        }
        else
        {
            do
            {
                output[num] = (number % 10) + 48; /* number mod 10 gets last number, then + 48 for ascii value  ( 3 + 48 = 51 which is 3) */
                number /= 10;
                num--;
            /* loops until number is 0 */
            } while ((number > 0) && (num >= 0)); 
            /* prints first 3 numbers( index 0 - 2) */
            for (i = 0; i < 3; i++) 
            {
                printf("%c", output[i]);
            }
            printf("-");
            /* prints last 4 numbers( index 3 - 6 ) */
            for (i = 3; i < 7; i++) 
            {
                printf("%c", output[i]);
            }
            printf("\n");
        }
    }
    return 0;
}