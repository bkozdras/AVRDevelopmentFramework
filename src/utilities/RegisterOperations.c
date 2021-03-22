/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <avrframework/utilities/RegisterOperations.h>

#include <assert.h>
#include <stddef.h>

#include <avrframework/macros/ByteMacros.h>

void RegisterOperations_waitForPinSet(const TMcuRegister* mcuRegister,
    const TPinNumber bitNumber)
{
    assert(mcuRegister != NULL);
    while (BYTE_IS_BIT_CLEARED(*mcuRegister, bitNumber))
    {
        ;
    }
}

void RegisterOperations_waitForPinCleared(const TMcuRegister* mcuRegister,
    const TPinNumber bitNumber)
{
    assert(mcuRegister != NULL);
    while (BYTE_IS_BIT_SET(*mcuRegister, bitNumber))
    {
        ;
    }
}
