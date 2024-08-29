#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnumbers = get_long("What are your card details?");
    long originalnumbers = cardnumbers;
    int multipliedcount = 0;
    int sumcount = 0;
    int finalnumber;
    int positioncount = 0;
    int firsttwodigits = 0;

    while (cardnumbers)
    {
        // if numbers are even
        int lastint = cardnumbers % 10;
        if ((positioncount % 2) == 0)
        {
            sumcount += lastint;
        }
        else
        {
            lastint = lastint * 2;
            if (lastint > 9)
            {
                multipliedcount += lastint % 10;
                multipliedcount += 1;
            }
            else
            {
                multipliedcount += lastint;
            }
        }
        positioncount++;
        cardnumbers /= 10;
    }

    // final sum
    finalnumber = multipliedcount + sumcount;

    if (finalnumber % 10 == 0)
    {
        while (originalnumbers >= 100)
        {
            firsttwodigits = originalnumbers /= 10;
        }
        if ((firsttwodigits == 34 || firsttwodigits == 37) && positioncount == 15)
        {
            printf("AMEX\n");
        }
        else if ((firsttwodigits == 51 || firsttwodigits == 51 || firsttwodigits == 53 ||
                  firsttwodigits == 54 || firsttwodigits == 55) &&
                 positioncount == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (firsttwodigits / 10 == 4 && (positioncount == 13 || positioncount == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
