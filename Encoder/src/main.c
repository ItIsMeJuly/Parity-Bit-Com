#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "encoder.h"
#include <unistd.h> 

// initial path to concat the file
char *dir = "";

int main(int argc, char *argv[])
{
    // change directory to the upper one
    chdir("..");

    FILE* input = NULL;
    FILE* output = NULL;

    // calculate the size of the path
    const size_t path_size1 = strlen(dir) + strlen(argv[1]) + 1;
    const size_t path_size2 = strlen(dir) + strlen(argv[2]) + 1;

    // allocate the necessary memory
    char *path1 = malloc(path_size1);
    char *path2 = malloc(path_size2);

    // if BAD_ALLOC is not present
    if (path1 && path2)
    {
        snprintf(path1, path_size1, "%s%s", dir, argv[1]); // concat the path with the passed file
        snprintf(path2, path_size2, "%s%s", dir, argv[2]);

        input = fopen(path1, "r"); 
        output = fopen(path2, "w"); 

        // if file failed to open
        if(input == NULL || output == NULL){
            fprintf(stderr, "file failed to open");
            exit(EXIT_FAILURE);
        }

        uint8_t high, low;

        char inputChar;

        // get every character in the file  and separate it into 2 halves
		while( (inputChar = fgetc(input)) != EOF) {

            encodeByte(inputChar, &high, &low);

            // write the two halves to the file
            fputc((char)high, output);
            fputc((char)low, output);

		}

        free(path1);
        free(path2);
    }

    fclose(input);
    fclose(output);

    return 0;
}