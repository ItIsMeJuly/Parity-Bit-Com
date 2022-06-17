#ifndef ENCODER_H
#define ENCODER_H

#include "stdint.h"
#include <stdio.h>

uint8_t get_high(uint8_t);
uint8_t get_low(uint8_t);
uint8_t add_parity(uint8_t);

void encodeByte(uint8_t inputByte, uint8_t* encodedByteHigh, uint8_t* encodedByteLow) ;

void write_data_in_binary(FILE*, uint8_t);

#endif