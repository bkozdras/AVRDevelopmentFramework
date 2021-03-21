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

#include <avrframework/macros/IOMacros.h>
#include <avrframework/types/TMcuRegister.h>

#include <cmocka.h>

static void IOMacrosShouldSetReturnCorrectDDR(void** state)
{
    (void) state;
    TMcuRegister DDRA = 0x27;
    TMcuRegister DDRB = 0x19;
    TMcuRegister DDRC = 0x63;
    TMcuRegister DDRD = 0x18;
    assert_ptr_equal(&IO_GET_DDR(A), &DDRA);
    assert_ptr_equal(&IO_GET_DDR(B), &DDRB);
    assert_ptr_equal(&IO_GET_DDR(C), &DDRC);
    assert_ptr_equal(&IO_GET_DDR(D), &DDRD);
}

static void IOMacrosShouldSetReturnCorrectPIN(void** state)
{
    (void) state;
    TMcuRegister PINA = 0x27;
    TMcuRegister PINB = 0x19;
    TMcuRegister PINC = 0x63;
    TMcuRegister PIND = 0x18;
    assert_ptr_equal(&IO_GET_PIN(A), &PINA);
    assert_ptr_equal(&IO_GET_PIN(B), &PINB);
    assert_ptr_equal(&IO_GET_PIN(C), &PINC);
    assert_ptr_equal(&IO_GET_PIN(D), &PIND);
}

static void IOMacrosShouldSetReturnCorrectPORT(void** state)
{
    (void) state;
    TMcuRegister PORTA = 0x27;
    TMcuRegister PORTB = 0x19;
    TMcuRegister PORTC = 0x63;
    TMcuRegister PORTD = 0x18;
    assert_ptr_equal(&IO_GET_PORT(A), &PORTA);
    assert_ptr_equal(&IO_GET_PORT(B), &PORTB);
    assert_ptr_equal(&IO_GET_PORT(C), &PORTC);
    assert_ptr_equal(&IO_GET_PORT(D), &PORTD);
}

int main(void)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(IOMacrosShouldSetReturnCorrectDDR),
        cmocka_unit_test(IOMacrosShouldSetReturnCorrectPIN),
        cmocka_unit_test(IOMacrosShouldSetReturnCorrectPORT)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
