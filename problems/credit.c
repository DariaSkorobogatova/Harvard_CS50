#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long  card_number = get_long("Card number?\n");
    long cn = card_number;
    int v = 0;
    int i = 0;
    int rm;
    do
    {
        rm = cn % 10;
        i = i + 1;
        if (i % 2 == 0)
        {
            int m = 2 * rm;
            rm = 0;
            do
            {
                int r = m % 10;
                rm = rm + r;
                m = m / 10;
            }
            while (m > 0);

        }
        v = v + rm;
        cn = cn / 10;

    }
    while (cn > 0);

    int x = card_number / pow(10, (i - 1));
    int y = card_number / pow(10, (i - 2));


    if (v % 10 == 0 && i == 15 && (y ==  37 || y == 34))
    {
       printf("AMEX\n");
    }
    else if (v % 10 == 0 && i == 16 && (y == 51 || y == 52 || y == 53 || y == 54 || y == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (v % 10 == 0 && x == 4 && (i == 16 || i == 13))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}