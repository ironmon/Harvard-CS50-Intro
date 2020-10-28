#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    if (argc == 2)
    {
        //printf("yes\n");
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!(isdigit(argv[1][i])))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }

        }
        //comments
        int j;
        int input = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext;
        //comments
        for (j = 0; j < strlen(plaintext); j++)
        {
            if ('a' <= plaintext[j] && plaintext[j] <= 'z')
            {
                int a = plaintext[j];
                //printf("%i\n", a);
                int b = (a + input - 97) % 26 + 97;
                //printf("%i\n", b);
                ciphertext[j] = (plaintext[j] + input - 97) % 26 + 97;
            }
            else if ('A' <= plaintext[j] && plaintext[j] <= 'Z')
            {
                ciphertext[j] = (plaintext[j] + input - 65) % 26 + 65;
            }
            else
            {
                ciphertext[j] = plaintext[j];
            }
            //ciphertext[j] = (int)plaintext[j] + input;
        }
        printf("ciphertext: %s\n", ciphertext);
    }
}