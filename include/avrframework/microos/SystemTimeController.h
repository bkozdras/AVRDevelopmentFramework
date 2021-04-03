/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_MICROOS_SYSTEMTIMECONTROLLER_H_
#define AVRFRAMEWORK_MICROOS_SYSTEMTIMECONTROLLER_H_

#include <stdint.h>

#include <avrframework/types/EBoolean.h>
#include <avrframework/types/TCallback.h>

void SystemTimeController_initialize(void);
void SystemTimeController_processEvents(void);
uint8_t SystemTimeController_startTimer(const uint16_t timeDurationInMs,
    const EBoolean isPeriodic,
    const TCallback onTimerExpirationCallback);
void SystemTimeController_cancelTimer(const uint8_t timerId);
void SystemTimeController_waitMs(const uint16_t timeDurationInMs);
void SystemTimeController_waitUs(const uint16_t timeDurationInUs);

#endif // AVRFRAMEWORK_MICROOS_SYSTEMTIMECONTROLLER_H_
