#include "encoder.h"
#include <stdint.h>
#include <stdio.h>


// set the p0 bit 
void set_p0(uint8_t *data)
{
	uint8_t copy_data = *data;
	int sum = 0;
	int first = ((copy_data & (1 << (3))) >> 3);  // get the data bits
	int second = ((copy_data & (1 << (4))) >> 4);
	int third = ((copy_data & (1 << (5))) >> 5);
	sum = first + second + third; // check if the sum of the bits is odd
	if (sum % 2 != 0)
	{
		copy_data ^= 1;  // if it is odd toggle the p0 bit
	}
	*data = copy_data;
}

// set the p1 bit
void set_p1(uint8_t *data)
{
	uint8_t copy_data = *data;
	int sum = 0;
	int first = ((copy_data & (1 << (3))) ? 1 : 0);  // get the data bits
	int second = ((copy_data & (1 << (4))) ? 1 : 0);
	int third = ((copy_data & (1 << (6))) ? 1 : 0);
	sum = first + second + third; // check if their sum is odd
	if (sum % 2 != 0)
	{
		copy_data ^= (1 << 1); // if odd toggle p1
	}
	*data = copy_data;
}

// set the p2 bit
void set_p2(uint8_t *data)
{
	uint8_t copy_data = *data;
	int sum = 0;
	int first = ((copy_data & (1 << (4))) ? 1 : 0);  // get the data bits
	int second = ((copy_data & (1 << (5))) ? 1 : 0);
	int third = ((copy_data & (1 << (6))) ? 1 : 0);
	sum = first + second + third; // check if their sum is odd
	if (sum % 2 != 0)
	{
		copy_data ^= (1 << 2); // if odd toggle p2 bit
	}
	*data = copy_data;
}

// get the high nibble
uint8_t get_high(uint8_t data)
{
	return (data & 0xf0) >> 4;
}

// get the low nibble
uint8_t get_low(uint8_t data)
{
	return data & 0x0f;
}

// simplified call to update the byte
uint8_t add_parity(uint8_t data)
{
	data <<= 3;
	set_p0(&data);
	set_p1(&data);
	set_p2(&data);
	return data;
}

// encode the byte and update the low and hight parameters 
void encodeByte(uint8_t inputByte, uint8_t *encodedByteHigh, uint8_t *encodedByteLow)
{
	*encodedByteHigh = add_parity(get_high(inputByte));
	*encodedByteLow = add_parity(get_low(inputByte));
}
