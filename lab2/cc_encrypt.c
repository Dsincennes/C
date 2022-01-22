#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_MSG 50

/*
 Student Name: Donald Sincennes 
 Student Number: 041011305 
 Section Number: 014 
 Course: CST8234 - C Language
 Professor: Surbhi Bahri
 Author Donald Sincennes
 Due Date: 09-26-21 1159pm
*/

int clean_stdin()
{
    while (getchar() != '\n');
    return 1;
}

int main()
{
    char message[80];
    int key, i;

    /* Asking user to enter message they would like encrypted */
    printf("Enter message to encrypt: ");
    scanf("%[^\n]*c", message);

    /* if message has more than 80 characters, terminates */
    if (strlen(message) > MAX_MSG)
    {
        printf("Invalid number of digits\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        do
        {
            /* Asking User for key to be used for messaging encrypting, within range 1-26 */
            printf("Enter rotation key: ");
            if (!scanf("%d", &key) || key < 0 || key > 26)
            {
                printf("Error - key must be in range 0 and 26. Try again.\n");
                clean_stdin(); /* Clearing Standard input buffer  as alpha will cause inf loop */
            }
            else
            {
                printf("Encrypting message: (key = %i) %s\n", key, message);
                /* looping for the length of the message */
                for (i = 0; i < strlen(message); i++)
                {
                    /* Only performing encryption on letters in a-z range */
                    if (message[i] >= 'a' && message[i] <= 'z')
                    {
                        /* the character at i plus given key minus 'a'(97) modulus 26 plus 'a'(97) to get back in number range */
                        message[i] = ((message[i] + key) - 'a') % 26 + 'a';
                    }
                    /* Only performing encryption on letters in A-Z range */
                    else if (message[i] >= 'A' && message[i] <= 'Z')
                    {
                        /* the character at i plus given key minus 'A'(65) modulus 26 plus 'A'(65) to get back in number range */
                        message[i] = ((message[i] + key) - 'A') % 26 + 'A';
                    }
                }
                printf("%s\n", message);
                exit(EXIT_SUCCESS);
            }
        } while (1);
    }
}
