#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height?\n");
    }
    while (h > 8 || h <= 0);

    int i;
    int j;


    for (i = 0; i < h; i++)
    {
        for (j = 0; j < h - i - 1; j++)
        {
            printf(" ");
        }

        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        for (j = 0; j < 2; j++)
        {
            printf(" ");
        }

        for (j = 0; j <  i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }

}
