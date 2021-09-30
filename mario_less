#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h=get_int("Height?\n");
    }
    while(h>8||h<=0);

    int i;
    int j;
    int k;

    for (i=0;i<h;i++)
    {
        for (k=0;k<h-i-1;k++)
        {
        printf(".");
        }

        for (j=0;j<i+1;j++)
        {
        printf("#");
        }

    printf("\n");
    }
}
