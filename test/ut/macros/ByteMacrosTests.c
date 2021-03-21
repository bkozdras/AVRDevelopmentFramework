/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: AVR framework tests.                                                  */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <avrframework/macros/ByteMacros.h>
#include <avrframework/types/TByte.h>

#include <cmocka.h>

static void ByteMacrosShouldSetRequestedBitsInByte(void** state)
{
    (void) state;
    TByte testedByte = 0b00000000;
    BYTE_SET_BIT(testedByte, 0);
    BYTE_SET_BIT(testedByte, 2);
    BYTE_SET_BIT(testedByte, 3);
    BYTE_SET_BIT(testedByte, 7);
    assert_int_equal(testedByte, 0b10001101);
}

static void ByteMacrosShouldClearRequestedBitsInByte(void** state)
{
    (void) state;
    TByte testedByte = 0b11111111;
    BYTE_CLEAR_BIT(testedByte, 1);
    BYTE_CLEAR_BIT(testedByte, 5);
    BYTE_CLEAR_BIT(testedByte, 6);
    BYTE_CLEAR_BIT(testedByte, 7);
    assert_int_equal(testedByte, 0b00011101);
}

static void ByteMacrosShouldReturnCorrectBoolStatusesForIsBitSet(void** state)
{
    (void) state;
    TByte testedByte = 0b00110011;
    assert_true(BYTE_IS_BIT_SET(testedByte, 0));
    assert_true(BYTE_IS_BIT_SET(testedByte, 1));
    assert_false(BYTE_IS_BIT_SET(testedByte, 2));
    assert_false(BYTE_IS_BIT_SET(testedByte, 3));
    assert_true(BYTE_IS_BIT_SET(testedByte, 4));
    assert_true(BYTE_IS_BIT_SET(testedByte, 5));
    assert_false(BYTE_IS_BIT_SET(testedByte, 6));
    assert_false(BYTE_IS_BIT_SET(testedByte, 7));
}

static void ByteMacrosShouldReturnCorrectBoolStatusesForIsBitCleared(void** state)
{
    (void) state;
    TByte testedByte = 0b00110011;
    assert_false(BYTE_IS_BIT_CLEARED(testedByte, 0));
    assert_false(BYTE_IS_BIT_CLEARED(testedByte, 1));
    assert_true(BYTE_IS_BIT_CLEARED(testedByte, 2));
    assert_true(BYTE_IS_BIT_CLEARED(testedByte, 3));
    assert_false(BYTE_IS_BIT_CLEARED(testedByte, 4));
    assert_false(BYTE_IS_BIT_CLEARED(testedByte, 5));
    assert_true(BYTE_IS_BIT_CLEARED(testedByte, 6));
    assert_true(BYTE_IS_BIT_CLEARED(testedByte, 7));
}

int main(void)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(ByteMacrosShouldSetRequestedBitsInByte),
        cmocka_unit_test(ByteMacrosShouldClearRequestedBitsInByte),
        cmocka_unit_test(ByteMacrosShouldReturnCorrectBoolStatusesForIsBitSet),
        cmocka_unit_test(ByteMacrosShouldReturnCorrectBoolStatusesForIsBitCleared)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
