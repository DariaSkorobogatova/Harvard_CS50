#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters = 0, words = 0, sentences = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters += 1;
        }
        else if (text[i] == ' ')
        {
            words += 1;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }
    words = words + 1;
    float L = 100 * letters / (float) words;
    float S = 100 * sentences / (float) words;

    float G = 0.0588 * L - 0.296 * S - 15.8;
    if (G < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int G1 = round(0.0588 * L - 0.296 * S - 15.8);
        if (G1 > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", G1);
        }
    }
}
