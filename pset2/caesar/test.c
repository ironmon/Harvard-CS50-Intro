#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //printf("yes\n");
        for (int i = 0; i < strlen(argv[1]); i++) 
        {
            if (! (isdigit(argv[1][i])))
            {
               printf("Usage: ./caesar key\n");
               return 1;
            }

        }
        int j;
        int input = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext;
        for (j = 0; j < strlen(plaintext); j++)
        {
            int a = plaintext[j];
            //printf("%i\n", a);
            int b = (a + input - 97) % 26 + 97;
            //printf("%i\n", b);
            ciphertext[j] = b;
            
            
            
        }
        printf("%s\n", ciphertext);
                
    }
    
    
    
    else
    {       
        printf("Usage: ./caesar key \n");
    }
}