#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string book = get_string("Text: ");
    printf("%i\n", (int)book[1]);
    
}