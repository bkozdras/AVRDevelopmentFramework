/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: AVR framework tests.                                                  */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>

#include <avrframework/types/AllTypes.h>
#include <avrframework/types/EBoolean.h>
#include <avrframework/types/SPinPortData.h>
#include <avrframework/types/TBitNumber.h>
#include <avrframework/types/TByte.h>
#include <avrframework/types/TMcuRegister.h>
#include <avrframework/types/TPinNumber.h>

#include <cmocka.h>

static void TypesShouldPassThisFakeTest(void **state)
{
    (void) state;
    assert_false(EBoolean_False);
    assert_true(EBoolean_True);
    _Static_assert(sizeof(TBitNumber) == sizeof(uint8_t));
    _Static_assert(sizeof(TByte) == sizeof(uint8_t));
    _Static_assert(sizeof(TMcuRegister) == sizeof(uint8_t));
    _Static_assert(sizeof(TPinNumber) == sizeof(uint8_t));
}

int main(void)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(TypesShouldPassThisFakeTest),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
