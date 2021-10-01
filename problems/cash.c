#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float dollars;

    do
    {
        dollars = get_float("How much change?\n");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);

    int z = cents / 25;

    if (cents - 25 * z == 0)
    {
        printf ("%i\n", z);
    }
    else
    {
       int y = (cents - 25 * z) / 10;

       if (cents - 25 * z - 10 * y == 0)
       {
           printf("%i\n", y + z);
       }
       else
       {
            int x = (cents - 25 * z - 10 * y) / 5;

            if (cents - 25 * z - 10 * y - 5 * x == 0)
            {
                printf("%i\n", x + y + z);
            }
            else
            {
                int m = cents - 25 * z - 10 * y - 5 * x;
                printf("%i\n", z + y + x + m);
            }
        }
     }
}


