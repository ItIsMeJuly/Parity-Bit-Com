#include "unity.h"
#include "decoder.h"
#include <stdint.h>

/*
 * Unity calls automatically function setUp before calling each unit tests
 * Writing code in setUp is optional but the function must exist
 */
void setUp(void)
{
     
}

/*
 * Unity calls automatically function tearDown after executing each unit tests
 * Writing code in tearDown is optional but the function must exist
 */
void tearDown(void)
{
    
}

void calc_pair(){
    uint8_t mask = 0b00111000;
    uint8_t byte = 0b01110101;

    uint8_t p = calculateParity(byte, mask);

    TEST_ASSERT_EQUAL_UINT8(0 , p);
}

void fix_corruption_byte2(){
    uint8_t expected = 0b01101000;
    uint8_t actual = 0b01111000;

    fixCorruption(&actual);

    TEST_ASSERT_EQUAL_INT8(expected, actual);
}

void fix_corruption_byte(){
    uint8_t actual = 0b00110001;  
    uint8_t expected = 0b00111001;

    fixCorruption(&actual);

    TEST_ASSERT_EQUAL_INT8(expected, actual);
}

void decode_byte(){

    uint8_t high = 0b00110001, low = 0b01101000;

    uint8_t res;
    uint8_t expected = 0b01111101;

    decodeByte(high, low, &res);

    TEST_ASSERT_EQUAL_INT8(res, expected);
}

int main(void)
{
    UnityBegin(0);

    RUN_TEST(fix_corruption_byte);
    RUN_TEST(fix_corruption_byte2);
    RUN_TEST(decode_byte);
    RUN_TEST(calc_pair);

    return UnityEnd();
}
