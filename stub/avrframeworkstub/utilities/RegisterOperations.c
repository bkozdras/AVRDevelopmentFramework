/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <avrframeworkstub/utilities/RegisterOperations.h>

#include <assert.h>
#include <stddef.h>

#include <avrframework/utilities/RegisterOperations.h>

// STUB

static void (*onWaitForPinSetCallback_)(const TMcuRegister*, const TPinNumber) = NULL;
static void (*onWaitForPinClearedCallback_)(const TMcuRegister*, const TPinNumber) = NULL;

void RegisterOperationsStub_setCallbackOnWaitForPinSet(
    void (*callback)(const TMcuRegister*, const TPinNumber))
{
    onWaitForPinSetCallback_ = callback;
}

void RegisterOperationsStub_clearCallbackOnWaitForPinSet()
{
    onWaitForPinSetCallback_ = NULL;
}

void RegisterOperationsStub_setCallbackOnWaitForPinCleared(
    void (*callback)(const TMcuRegister*, const TPinNumber))
{
    onWaitForPinClearedCallback_ = callback;
}

void RegisterOperationsStub_clearCallbackOnWaitForPinCleared()
{
    onWaitForPinClearedCallback_ = NULL;
}

// SUT

void RegisterOperations_waitForPinSet(const TMcuRegister* mcuRegister,
    const TPinNumber bitNumber)
{
    assert(mcuRegister != NULL);
    if (onWaitForPinSetCallback_ != NULL)
    {
        (*onWaitForPinSetCallback_)(mcuRegister, bitNumber);
    }
}

void RegisterOperations_waitForPinCleared(const TMcuRegister* mcuRegister,
    const TPinNumber bitNumber)
{
    assert(mcuRegister != NULL);
    if (onWaitForPinClearedCallback_ != NULL)
    {
        (*onWaitForPinClearedCallback_)(mcuRegister, bitNumber);
    }
}
