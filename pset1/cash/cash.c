#include <stdio.h>
#include <cs50.h>
#include <math.h>
//comments 
int main(void)
{
    //set a float dollars
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
        
    }
    while (dollars < 0);
    if (dollars >= 0)
    {
        //comments
        int cents = round(dollars * 100);
        int a = cents / 25;
        cents -= a * 25;
        int b = cents / 10; 
        cents -= b * 10;
        int c = cents / 5;
        cents -= c * 5;
        int d = cents / 1;
        int e = a + b + c + d; 
        //comments 
        printf("%i\n", e);
        
    }
}