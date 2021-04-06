/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Test program with used library utilities.                             */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <avr/io.h>
#include <util/delay.h>

#include <avrframework/macros/ByteMacros.h>
#include <avrframework/macros/GpioMacros.h>
#include <avrframework/macros/IOMacros.h>
#include <avrframework/types/AllTypes.h>
#include <avrframework/utilities/RegisterOperations.h>

int main(void)
{
    // Test setup
    GPIO_SET_INPUT_LINE(D, 7);
    GPIO_SET_OUTPUT_LINE(B, 5);

    while (1)
    {
        RegisterOperations_waitForPinSet(&IO_GET_PIN(D), 7);
        GPIO_SET_HIGH_LEVEL_ON_LINE(B, 5);
        RegisterOperations_waitForPinCleared(&IO_GET_PIN(D), 7);
        GPIO_SET_LOW_LEVEL_ON_LINE(B, 5);
    }

    return 0;
}
