#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string book = get_string("Text: ") ;
    int letter_num = 0;
    int word_num = 1;
    int sentence_num = 0;
    for (int i = 0; i < strlen(book); i++)
    {
        // set letter_num
        if (('a' <= book[i] && book[i] <= 'z') || ('A' <= book[i] && book[i] <= 'Z'))
        {
            letter_num += 1;
        }
        // set book_num
        if (book[i] == ' ')
        {
            word_num += 1;
        }
        //set sentence_num
        if (book[i] == '.' || book[i] == '!' || book[i] == '?')
        {
            sentence_num += 1;
        }
    }
    //calculate index 
    float L = (float)letter_num / (float)word_num * 100;
    float S = (float)sentence_num / (float)word_num * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // round index 
    int grade = (int) round(index);
    if (1 <= grade && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
    //printf("%f letter(s)\n", L);
    //printf("%f word(s)\n", S);
    //printf("%i sentence(s)\n", sentence_num);
    
}