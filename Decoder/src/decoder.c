#include "decoder.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// calculate a parity bit by masking the data bits
uint8_t calculateParity(uint8_t byte, uint8_t maskOfParityData){

    byte &= maskOfParityData;
    int count = 0;

    // count the toggled data bits
    for (int x = 1; x <= byte; x = x<<1){
        if ((x & byte) != 0){
            count++;    
        }
    }
    
    if(count == 2 || count == 0){
        return 0;
    }
    else{
        return 1;
    }
}

void fixCorruption(uint8_t* byte){
    uint8_t copy = *byte;

    // get the parity bits of the corrupted byte
    uint8_t inputP0 = (copy & 0b00000001);  
    uint8_t inputP1 = (copy & 0b00000010) >> 1;
    uint8_t inputP2 = (copy & 0b00000100) >> 2; 

    // calculate the proper parity bits of the corrupted data
    uint8_t p0 = calculateParity(copy, 0b00111000);
    uint8_t p1 = calculateParity(copy, 0b01011000);
    uint8_t p2 = calculateParity(copy, 0b01110000);


    if(p0 != inputP0 && p1 != inputP1 && p2 != inputP2){  // if all three are wrong, b1 is wrong
        copy ^= 0x10;
    }
    else if(p0 != inputP0 && p1 != inputP1){  // if p0 and p1 are incorrect, b0 is wrong
        copy ^= 0x08;
    }
    else if(p1 != inputP1 && p2 != inputP2){  // if p1 and p2 are incorrect, b4 is wrong
        copy ^= 0x40;
    }
    else if(p0 != inputP0 && p2 != inputP2){  // if p0 and p2 are incorrect, b3 is wrong
        copy ^= 0x20;
    }

    
    copy &= 0b01111111;  //ensure msb is 0
    *byte = copy;
}


void decodeByte(uint8_t transmittedByteHigh, uint8_t transmittedByteLow, uint8_t* decodedByte){

    fixCorruption(&transmittedByteHigh);
    fixCorruption(&transmittedByteLow);

    // concat high and low
    uint8_t fullByte = (transmittedByteHigh >> 3);
    fullByte <<= 4;
    fullByte |= (transmittedByteLow >> 3);

    *decodedByte = fullByte;
}