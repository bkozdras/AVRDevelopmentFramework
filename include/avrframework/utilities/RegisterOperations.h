/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Operations on IO registers in microcontroller.                        */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_UTILITIES_REGISTEROPERATIONS_H_
#define AVRFRAMEWORK_UTILITIES_REGISTEROPERATIONS_H_

#include <avrframework/types/TMcuRegister.h>
#include <avrframework/types/TPinNumber.h>

void RegisterOperations_waitForPinSet(const TMcuRegister* mcuRegister,
    const TPinNumber bitNumber);
void RegisterOperations_waitForPinCleared(const TMcuRegister* mcuRegister,
    const TPinNumber bitNumber);

#endif // AVRFRAMEWORK_UTILITIES_REGISTEROPERATIONS_H_
