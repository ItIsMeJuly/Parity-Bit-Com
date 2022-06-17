/*
 *	Description: 
 *		This VS code project:
 *         - is meant to be used as start-up project for installing/configuring the Unity framework
 *         - consists of the following three modules:
 *             1) Module "simple_math" implements a (very) simple math operation
 *             2) Module "main" implementing a (very) simple console operation to let a user perform the math operation of module "simple_math"
 *             3) Module "main_test" is meant to implement unit tests to verify the behavior of module "simple_math"
 *		
 *	Author : Brice Guayrin, b.guayrin@fontys.nl
 * 	Date: 12 April 2022
 */

#include "unity.h"
#include "encoder.h"

/*
 * Unity calls automatically function setUp before calling each unit tests
 * Writing code in setUp is optional but the function must exist
 */
void setUp(void)
{
     
}

void set_parity0(){
    uint8_t expected = 0b01101000;
    uint8_t actual = 0b01101000;

    set_p0(&actual);

    TEST_ASSERT_EQUAL_INT8(expected, actual);
}

void set_parity1(){
    uint8_t expected = 0b00101010;
    uint8_t actual = 0b00101000;

    set_p1(&actual);

    TEST_ASSERT_EQUAL_INT8(expected, actual);
}

void set_parity2(){
    uint8_t expected = 0b00010100;
    uint8_t actual = 0b00010000;

    set_p2(&actual);

    TEST_ASSERT_EQUAL_INT8(expected, actual);
}

void get_high_func(){
    uint8_t actual = 0b01010000;
    uint8_t expected = 0b00000101;

    actual = get_high(actual);

    TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void get_low_func(){
    uint8_t actual = 0b01010111;
    uint8_t expected = 0b00000111;

    actual = get_low(actual);

    TEST_ASSERT_EQUAL_INT16(expected, actual);
}

void add_parity_func(){
    uint8_t actual = 0b00001011;
    uint8_t expected = 0b01011010;

    actual = add_parity(actual);

    TEST_ASSERT_EQUAL_INT16(expected, actual);
}



/*
 * Unity calls automatically function tearDown after executing each unit tests
 * Writing code in tearDown is optional but the function must exist
 */
void tearDown(void)
{
    
}




int main(void)
{
    UnityBegin(0);

    RUN_TEST(set_parity0);
    RUN_TEST(set_parity1);
    RUN_TEST(set_parity2);
    RUN_TEST(get_high_func);
    RUN_TEST(get_low_func);
    RUN_TEST(add_parity_func);

    return UnityEnd();
}
