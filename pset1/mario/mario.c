#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //creat a int n
    int n;
    do
    {
        n = get_int("Height: ");
        
    }
    while (n > 8 || n < 1);
    //for i in the range(1.8)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        //comments
        for (int j = n + 1 - i; j <= n; j++)
        {
            printf("#");
        }
        //comments
        printf("\n");
    }
    
    

}