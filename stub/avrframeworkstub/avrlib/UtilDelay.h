/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORKSTUB_AVRLIB_UTILDELAY_H_
#define AVRFRAMEWORKSTUB_AVRLIB_UTILDELAY_H_

#include <stdint.h>

void _delay_ms(const uint16_t timeDurationInMs);
void _delay_us(const uint16_t timeDurationInUs);

void UtilDelay_setCallbackOnDelayMs(void (*callback)(const uint16_t));
void UtilDelay_clearCallbackOnDelayMs();

void UtilDelay_setCallbackOnDelayUs(void (*callback)(const uint16_t));
void UtilDelay_clearCallbackOnDelayUs();

#endif // AVRFRAMEWORKSTUB_AVRLIB_UTILDELAY_H_
