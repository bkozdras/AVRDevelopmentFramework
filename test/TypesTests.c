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

#include <avrframework/GpioMacros.h>

#include <cmocka.h>

static void null_test_success(void **state)
{
    (void) state; /* unused */
}

int main(void)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(null_test_success),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
