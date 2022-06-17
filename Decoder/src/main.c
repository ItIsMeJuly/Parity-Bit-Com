#include <stdio.h>
#include "decoder.h"
#include <stdlib.h>
#include <unistd.h> 

// initial path to concat the file
char *dir = "";

int main(int argc, char *argv[])
{
    FILE *input = NULL;
    FILE *output = NULL;

    // calculate the size of the dynamic memory
    const size_t path_size1 = strlen(dir) + strlen(argv[1]) + 1;
    const size_t path_size2 = strlen(dir) + strlen(argv[2]) + 1;

    // allocate memory for the path to the file
    char *path1 = malloc(path_size1);
    char *path2 = malloc(path_size2);

    // change directory to the upper one
    chdir("..");

    // if paths are correct
    if (path1 && path2)
    {
        snprintf(path1, path_size1, "%s%s", dir, argv[1]);  // concat the path with the file
        snprintf(path2, path_size2, "%s%s", dir, argv[2]);

        input = fopen(path1, "r");  
        output = fopen(path2, "w"); 

        // check if both are open
        if (input == NULL || output == NULL)
        {
            fprintf(stderr, "file failed to open");
            exit(EXIT_FAILURE);
        }

        uint8_t high, low, byte;

        // get all letters in pairs of high and low
        char inputChar1, inputChar2;
        while ((inputChar1 = fgetc(input)) != EOF)
        {
            inputChar2 = fgetc(input);

            decodeByte(inputChar1, inputChar2, &byte);

            // write the result to the file
            fputc((char)byte, output);
        }

        free(path1);
        free(path2);
        return 0;
    }
}