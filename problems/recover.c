#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    BYTE buffer[BUFFER_SIZE];
    int find_jpg = 0;
    FILE *img = NULL;
    int file_count = 0;
    char *name = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(BYTE), BUFFER_SIZE, input) == BUFFER_SIZE) // while (fread(buffer, BUFFER_SIZE, 1, input) == 1) // while (fread(block, sizeof(block), 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (find_jpg == 1)
            {
                fclose(img);
            }
            else
            {
                find_jpg = 1;
            }
            sprintf(name, "%03i.jpg", file_count);
            img = fopen(name, "a");
            file_count++;
        }
        if (find_jpg == 1)
        {
            fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, img);
        }
    }
    free(name);
    fclose(input);
    fclose(img);
}