#include "channel.h"
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


uint8_t transmitByte(uint8_t encodedByte, uint8_t* transmittedByte){

    // get a random position
    int position = rand() % 8;

    // toggle the position
    *transmittedByte = encodedByte ^ (1 << position);

    return position;
}