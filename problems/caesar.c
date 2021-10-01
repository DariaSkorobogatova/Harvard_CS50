#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int amount, string arg[])
{
    if (amount == 1 || amount >= 3)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int n = strlen(arg[1]);
        int a = 0;
        for (int i = 0; i < n; i++)
        {
            if (arg[1][i] < 48 || arg[1][i] > 57)
            {
                a += 1;
            }
        }
        if (a > 0)
        {
          printf("Usage: ./caesar key\n");
          return 1;
        }
        int k = atoi(arg[1]);
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                if (k > 25 && (plaintext[i] + k % 26 > 90))
                {
                  printf("%c", 64 + (k % 26 - (90 - plaintext[i])));
                }
                else if (k > 25)
                {
                  printf("%c", plaintext[i] + k % 26);
                }
                else if (k < 25 && (plaintext[i] + k > 90))
                {
                  printf("%c", 64 + (k - (90 - plaintext[i])));
                }
                else
                {
                  printf("%c", plaintext[i] + k);
                }
            }
            else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                if (k > 25 && (plaintext[i] + k % 26 > 122))
                {
                  printf("%c", 96 + (k % 26 - (122 - plaintext[i])));
                }
                else if (k > 25)
                {
                  printf("%c", plaintext[i] + k % 26);
                }
                else if (k < 25 && (plaintext[i] + k > 122))
                {
                  printf("%c", 96 + (k - (122 - plaintext[i])));
                }
                else
                {
                  printf("%c", plaintext[i] + k);
                }

            }
            else
            {
                 printf("%c", plaintext[i]);
            }
        }
    }
    printf("\n");
    return 0;
}