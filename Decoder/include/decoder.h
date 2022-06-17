#ifndef DECODER_H
#define DECODER_H

#include <stdint.h>

void decodeByte(uint8_t transmittedByteHigh, uint8_t transmittedByteLow, uint8_t* decodedByte);

void fixCorruption(uint8_t* byte);

#endif