#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int sps, eps;
    do
    {
        sps = get_int("Starting population size? ");
    }
    while (sps < 9);

    do
    {
        eps = get_int("Ending population size? ");
    }
    while (eps < sps);

    int bl, pl;
    int i = 0;
    while (sps < eps)
    {
        bl = sps / 3;
        pl = sps / 4;
        sps = sps + bl - pl;
        i = i + 1;
    }

    printf("Years: %i\n", i);

}


