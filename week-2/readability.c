#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float calculate_index(float letter, float word, float sentence);

int main(void)
{
    string text = get_string("text: ");
    float lettercount = 0;
    float wordcount = 1;
    float sentencecount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            lettercount = lettercount + 1;
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentencecount++;
        }
        else if (isblank(text[i]))
        {
            wordcount++;
        }
    }
    float result_before_round = calculate_index(lettercount, wordcount, sentencecount);
    int result = round(result_before_round);

    if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
}

float calculate_index(float letter, float word, float sentence)
{
    float l = (letter / word) * 100;
    float s = (sentence / word) * 100;
    return 0.0588 * l - 0.296 * s - 15.8;
}
