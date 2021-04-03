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

#include <cmocka.h>

static void FakeTest(void **state)
{
    (void) state;
}

int main(void)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(FakeTest),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
