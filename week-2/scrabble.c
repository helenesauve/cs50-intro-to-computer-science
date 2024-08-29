#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculateSum(string name);
int numbers[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player1turn = get_string("Player 1: ");
    string player2turn = get_string("Player 2: ");

    int player1total = calculateSum(player1turn);
    int player2total = calculateSum(player2turn);

    if (player1total > player2total)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2total > player1total)
    {
        printf("Player 2 wins!\n");
    }
    else
        printf("Tie!\n");
}

int calculateSum(string name)
{
    int lettercount = 0;
    for (int i = 0; i < strlen(name); i++)
    {
        if (isalpha(name[i]))
        {
            int letter = tolower(name[i]) - 97;
            lettercount += numbers[letter];
        }
    }
    return lettercount;
}