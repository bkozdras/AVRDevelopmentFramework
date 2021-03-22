/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Operations on IO registers in microcontroller - stub.                 */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORKSTUB_UTILITIES_REGISTEROPERATIONS_H_
#define AVRFRAMEWORKSTUB_UTILITIES_REGISTEROPERATIONS_H_

#include <avrframework/types/TMcuRegister.h>
#include <avrframework/types/TPinNumber.h>

void RegisterOperationsStub_setCallbackOnWaitForPinSet(
    void (*callback)(const TMcuRegister*, const TPinNumber));
void RegisterOperationsStub_unsetCallbackOnWaitForPinSet();

void RegisterOperationsStub_setCallbackOnWaitForPinCleared(
    void (*callback)(const TMcuRegister*, const TPinNumber));
void RegisterOperationsStub_unsetCallbackOnWaitForPinCleared();

#endif // AVRFRAMEWORKSTUB_UTILITIES_REGISTEROPERATIONS_H_
