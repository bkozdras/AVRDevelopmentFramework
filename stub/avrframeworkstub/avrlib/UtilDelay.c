/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <avrframeworkstub/avrlib/UtilDelay.h>

#include <assert.h>
#include <stddef.h>

static void (*onDelayMsCallback_)(const uint16_t) = NULL;
static void (*onDelayUsCallback_)(const uint16_t) = NULL;

// STUB

void UtilDelay_setCallbackOnDelayMs(void (*callback)(const uint16_t))
{
    onDelayMsCallback_ = callback;
}

void UtilDelay_clearCallbackOnDelayMs()
{
    onDelayMsCallback_ = NULL;
}

void UtilDelay_setCallbackOnDelayUs(void (*callback)(const uint16_t))
{
    onDelayUsCallback_ = callback;
}

void UtilDelay_clearCallbackOnDelayUs()
{
    onDelayUsCallback_ = NULL;
}

// SUT

void _delay_ms(const uint16_t timeDurationInMs)
{
    assert(timeDurationInMs != 0);
    if (onDelayMsCallback_ != NULL)
    {
        (*onDelayMsCallback_)(timeDurationInMs);
    }
}

void _delay_us(const uint16_t timeDurationInUs)
{
    assert(timeDurationInUs != 0);
    if (onDelayUsCallback_ != NULL)
    {
        (*onDelayUsCallback_)(timeDurationInUs);
    }
}
