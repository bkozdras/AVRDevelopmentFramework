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

#include <avrframework/GpioMacros.h>
#include <avrframework/types/TMcuRegister.h>

#include <cmocka.h>

static void GpioMacrosShouldSetRequestedInputLines(void** state)
{
    (void) state;
    {
        TMcuRegister DDRA = 0b11111111;
        GPIO_SET_INPUT_LINE(A, 0);
        assert_int_equal(DDRA, 0b11111110);
        GPIO_SET_INPUT_LINE(A, 1);
        assert_int_equal(DDRA, 0b11111100);
        GPIO_SET_INPUT_LINE(A, 2);
        assert_int_equal(DDRA, 0b11111000);
        GPIO_SET_INPUT_LINE(A, 3);
        assert_int_equal(DDRA, 0b11110000);
        GPIO_SET_INPUT_LINE(A, 4);
        assert_int_equal(DDRA, 0b11100000);
        GPIO_SET_INPUT_LINE(A, 5);
        assert_int_equal(DDRA, 0b11000000);
        GPIO_SET_INPUT_LINE(A, 6);
        assert_int_equal(DDRA, 0b10000000);
        GPIO_SET_INPUT_LINE(A, 7);
        assert_int_equal(DDRA, 0b00000000);
    }
    {
        TMcuRegister DDRB = 0b11111111;
        GPIO_SET_INPUT_LINE(B, 0);
        assert_int_equal(DDRB, 0b11111110);
        GPIO_SET_INPUT_LINE(B, 1);
        assert_int_equal(DDRB, 0b11111100);
        GPIO_SET_INPUT_LINE(B, 2);
        assert_int_equal(DDRB, 0b11111000);
        GPIO_SET_INPUT_LINE(B, 3);
        assert_int_equal(DDRB, 0b11110000);
        GPIO_SET_INPUT_LINE(B, 4);
        assert_int_equal(DDRB, 0b11100000);
        GPIO_SET_INPUT_LINE(B, 5);
        assert_int_equal(DDRB, 0b11000000);
        GPIO_SET_INPUT_LINE(B, 6);
        assert_int_equal(DDRB, 0b10000000);
        GPIO_SET_INPUT_LINE(B, 7);
        assert_int_equal(DDRB, 0b00000000);
    }
    {
        TMcuRegister DDRC = 0b11111111;
        GPIO_SET_INPUT_LINE(C, 0);
        assert_int_equal(DDRC, 0b11111110);
        GPIO_SET_INPUT_LINE(C, 1);
        assert_int_equal(DDRC, 0b11111100);
        GPIO_SET_INPUT_LINE(C, 2);
        assert_int_equal(DDRC, 0b11111000);
        GPIO_SET_INPUT_LINE(C, 3);
        assert_int_equal(DDRC, 0b11110000);
        GPIO_SET_INPUT_LINE(C, 4);
        assert_int_equal(DDRC, 0b11100000);
        GPIO_SET_INPUT_LINE(C, 5);
        assert_int_equal(DDRC, 0b11000000);
        GPIO_SET_INPUT_LINE(C, 6);
        assert_int_equal(DDRC, 0b10000000);
        GPIO_SET_INPUT_LINE(C, 7);
        assert_int_equal(DDRC, 0b00000000);
    }
    {
        TMcuRegister DDRD = 0b11111111;
        GPIO_SET_INPUT_LINE(D, 0);
        assert_int_equal(DDRD, 0b11111110);
        GPIO_SET_INPUT_LINE(D, 1);
        assert_int_equal(DDRD, 0b11111100);
        GPIO_SET_INPUT_LINE(D, 2);
        assert_int_equal(DDRD, 0b11111000);
        GPIO_SET_INPUT_LINE(D, 3);
        assert_int_equal(DDRD, 0b11110000);
        GPIO_SET_INPUT_LINE(D, 4);
        assert_int_equal(DDRD, 0b11100000);
        GPIO_SET_INPUT_LINE(D, 5);
        assert_int_equal(DDRD, 0b11000000);
        GPIO_SET_INPUT_LINE(D, 6);
        assert_int_equal(DDRD, 0b10000000);
        GPIO_SET_INPUT_LINE(D, 7);
        assert_int_equal(DDRD, 0b00000000);
    }
}

static void GpioMacrosShouldSetRequestedOutputLines(void** state)
{
    (void) state;
    {
        TMcuRegister DDRA = 0b00000000;
        GPIO_SET_OUTPUT_LINE(A, 0);
        assert_int_equal(DDRA, 0b00000001);
        GPIO_SET_OUTPUT_LINE(A, 1);
        assert_int_equal(DDRA, 0b00000011);
        GPIO_SET_OUTPUT_LINE(A, 2);
        assert_int_equal(DDRA, 0b00000111);
        GPIO_SET_OUTPUT_LINE(A, 3);
        assert_int_equal(DDRA, 0b00001111);
        GPIO_SET_OUTPUT_LINE(A, 4);
        assert_int_equal(DDRA, 0b00011111);
        GPIO_SET_OUTPUT_LINE(A, 5);
        assert_int_equal(DDRA, 0b00111111);
        GPIO_SET_OUTPUT_LINE(A, 6);
        assert_int_equal(DDRA, 0b01111111);
        GPIO_SET_OUTPUT_LINE(A, 7);
        assert_int_equal(DDRA, 0b11111111);
    }
    {
        TMcuRegister DDRB = 0b00000000;
        GPIO_SET_OUTPUT_LINE(B, 0);
        assert_int_equal(DDRB, 0b00000001);
        GPIO_SET_OUTPUT_LINE(B, 1);
        assert_int_equal(DDRB, 0b00000011);
        GPIO_SET_OUTPUT_LINE(B, 2);
        assert_int_equal(DDRB, 0b00000111);
        GPIO_SET_OUTPUT_LINE(B, 3);
        assert_int_equal(DDRB, 0b00001111);
        GPIO_SET_OUTPUT_LINE(B, 4);
        assert_int_equal(DDRB, 0b00011111);
        GPIO_SET_OUTPUT_LINE(B, 5);
        assert_int_equal(DDRB, 0b00111111);
        GPIO_SET_OUTPUT_LINE(B, 6);
        assert_int_equal(DDRB, 0b01111111);
        GPIO_SET_OUTPUT_LINE(B, 7);
        assert_int_equal(DDRB, 0b11111111);
    }
    {
        TMcuRegister DDRC = 0b00000000;
        GPIO_SET_OUTPUT_LINE(C, 0);
        assert_int_equal(DDRC, 0b00000001);
        GPIO_SET_OUTPUT_LINE(C, 1);
        assert_int_equal(DDRC, 0b00000011);
        GPIO_SET_OUTPUT_LINE(C, 2);
        assert_int_equal(DDRC, 0b00000111);
        GPIO_SET_OUTPUT_LINE(C, 3);
        assert_int_equal(DDRC, 0b00001111);
        GPIO_SET_OUTPUT_LINE(C, 4);
        assert_int_equal(DDRC, 0b00011111);
        GPIO_SET_OUTPUT_LINE(C, 5);
        assert_int_equal(DDRC, 0b00111111);
        GPIO_SET_OUTPUT_LINE(C, 6);
        assert_int_equal(DDRC, 0b01111111);
        GPIO_SET_OUTPUT_LINE(C, 7);
        assert_int_equal(DDRC, 0b11111111);
    }
    {
        TMcuRegister DDRD = 0b00000000;
        GPIO_SET_OUTPUT_LINE(D, 0);
        assert_int_equal(DDRD, 0b00000001);
        GPIO_SET_OUTPUT_LINE(D, 1);
        assert_int_equal(DDRD, 0b00000011);
        GPIO_SET_OUTPUT_LINE(D, 2);
        assert_int_equal(DDRD, 0b00000111);
        GPIO_SET_OUTPUT_LINE(D, 3);
        assert_int_equal(DDRD, 0b00001111);
        GPIO_SET_OUTPUT_LINE(D, 4);
        assert_int_equal(DDRD, 0b00011111);
        GPIO_SET_OUTPUT_LINE(D, 5);
        assert_int_equal(DDRD, 0b00111111);
        GPIO_SET_OUTPUT_LINE(D, 6);
        assert_int_equal(DDRD, 0b01111111);
        GPIO_SET_OUTPUT_LINE(D, 7);
        assert_int_equal(DDRD, 0b11111111);
    }
}

int main(void)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(GpioMacrosShouldSetRequestedInputLines),
        cmocka_unit_test(GpioMacrosShouldSetRequestedOutputLines)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
