/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Defined SPinPortData type.                                            */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_TYPES_SPINPORTDATA_H_
#define AVRFRAMEWORK_TYPES_SPINPORTDATA_H_

#include <avrframework/types/TMcuRegister.h>
#include <avrframework/types/TPinNumber.h>

typedef struct _SPinPortData
{
    volatile TMcuRegister* port;
    TPinNumber pin;
} SPinPortData;

#endif // AVRFRAMEWORK_TYPES_SPINPORTDATA_H_
