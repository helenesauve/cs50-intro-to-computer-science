#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    string key = argv[1];

    if (argc == 2 && strlen(key) == 26)
    {
        for (int i = 0; i < strlen(key); i++)
        {
            if (isalpha(key[i]))
            {
                for (int j = i + 1; j < strlen(key); j++)
                {
                    if (key[i] == key[j])
                        return 1;
                }
            }
            else
            {
                return 1;
            }
        }
    }
    else
    {
        return 1;
    }

    string text = get_string("Plaintext: ");
    printf("ciphertext: ");
    for (int h = 0; h < strlen(text); h++)
    {
        if (isupper(text[h]))
        {
            int position = text[h] - 65;
            printf("%c", toupper(key[position]));
        }
        else if (islower(text[h]))
        {
            int position = text[h] - 97;
            printf("%c", tolower(key[position]));
        }
        else if (!(isalpha(text[h])))
        {
            printf("%c", text[h]);
        }
    }
    printf("\n");
    return 0;
}
