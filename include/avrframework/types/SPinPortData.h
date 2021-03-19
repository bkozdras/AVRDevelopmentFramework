/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Defined SPinPortData type.                                            */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_TYPES_SPINPORTDATA_H_
#define AVRFRAMEWORK_TYPES_SPINPORTDATA_H_

#include <avrframework/types/TPinNumber.h>
#include <avrframework/types/TPort.h>

typedef struct _SPinPortData
{
    volatile TPort* port;
    TPinNumber pinNumber;
} SPinPortData;

#endif // AVRFRAMEWORK_TYPES_SPINPORTDATA_H_
