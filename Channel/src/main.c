#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "channel.h"
#include <unistd.h> 

// initial path to concat the file
char *dir = "";

int main(int argc, char *argv[])
{
    // time variable for fully random numbers
    time_t t;
    srand((unsigned) time(&t));

    FILE* input = NULL;
    FILE* output = NULL;

    // change directory to the upper one
    chdir("..");

    // the size in bytes for each path
    const size_t path_size1 = strlen(dir) + strlen(argv[1]) + 1;
    const size_t path_size2 = strlen(dir) + strlen(argv[2]) + 1;

    // allocate the memory for the paths to the file
    char *path1 = malloc(path_size1);
    char *path2 = malloc(path_size2);

    // check if the memory is allocated
    if (path1 && path2)
    {
        snprintf(path1, path_size1, "%s%s", dir, argv[1]);
        snprintf(path2, path_size2, "%s%s", dir, argv[2]);

        input = fopen(path1, "r"); 
        output = fopen(path2, "w"); 

        // check if the files are open
        if(input == NULL || output == NULL){
            fprintf(stderr, "file failed to open");
            exit(EXIT_FAILURE);
        }

        char inputChar;
        uint8_t transmitedByte = 0;
		while( (inputChar = fgetc(input)) != EOF) {
            // toggle randm bit and write to file
            transmitByte(inputChar, &transmitedByte);

            fputc(transmitedByte, output);
		}

        free(path1);
        free(path2);
    }

    fclose(input);
    fclose(output);

    return 0;
}