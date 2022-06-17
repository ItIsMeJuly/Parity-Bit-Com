
#include "channel.h"
#include "unity.h"
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

void test_transmit_byte_ref(){
    uint8_t actual = 0b01010101;
    uint8_t expected = 0;

    int pos = transmitByte(actual, &expected);

    actual ^= (1 << pos);

    TEST_ASSERT_EQUAL_INT8(expected, actual);
}


int main(void)
{
    UnityBegin(0);

    RUN_TEST(test_transmit_byte_ref);

    return UnityEnd();
}
