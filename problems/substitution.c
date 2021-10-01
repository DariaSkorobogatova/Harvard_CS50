#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 1 || argc >= 3) // проверка на количество агрументов
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int n = strlen(argv[1]); // проверка, что количество символов в аргументе = 26
    if (n != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    int a = 0; //проверка, что все символы в аргументе - это буквы
    for (int i = 0; i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            a += 1;
        }
    }
    if (a != 26)
    {
        printf("Key must contain only characters\n");
        return 1;
    }
    int b = 0; // проверка, что буквы не повторяются, включая 'А' и 'а'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (argv[1][i] == argv[1][j] || argv[1][i] == argv[1][j] + 32 || argv[1][i] == argv[1][j] - 32)
            {
                b +=  1;
            }
        }
    }
    if (b > 26)
    {
         printf("Key must contain only unique characters\n");
         return 1;
    }
    string plaintext = get_string("plaintext: ");
    int m = strlen(plaintext);
    printf("ciphertext: ");
    for (int i = 0; i < m; i++)
    {
        if (isupper(plaintext[i])) // находим в ключе букву, порядковый номер которой соответствует букве в plaintext
        // (если регистр буквы в ключе не соответствует регистру буквы в plaintext - переводим ее в нужный регистр)
        {
            int k = plaintext[i] - 65;
            if (islower(argv[1][k]))
            {
                printf("%c", toupper(argv[1][k]));
            }
            else
            {
                printf("%c", argv[1][k]);
            }
        }
        else if (islower(plaintext[i]))
        {
            int k = plaintext[i] - 97;
            if (isupper(argv[1][k]))
            {
                printf("%c", tolower(argv[1][k]));
            }
            else
            {
                printf("%c", argv[1][k]);
            }
        }
        else // если символ в plaintext - не буква, то печатаем, как есть
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

