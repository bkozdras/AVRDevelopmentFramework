/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <avrframework/microos/SystemTimeController.h>

#include <assert.h>
#include <stddef.h>

#if !defined(F_CPU)
    #warning "F_CPU is not defined. Assuming default 16 MHz!"
    #define F_CPU 16000000UL
#endif  // !defined(F_CPU)

#if defined(BUILD_FOR_TARGET)
    #include <avr/io.h>
    #include <util/atomic.h>
    #include <util/delay.h>
#else
    #include <avrframeworkstub/avrlib/AvrIo.h>
    #include <avrframeworkstub/avrlib/UtilAtomic.h>
    #include <avrframeworkstub/avrlib/UtilDelay.h>
#endif // defined(BUILD_FOR_TARGET)

#include <avrframework/macros/ByteMacros.h>
#include <avrframework/microos/InterruptVectorsController.h>

typedef struct _STimerData
{
    EBoolean isIdle;
    uint8_t timerId;
    uint16_t timeDurationInMs;
    EBoolean isPeriodic;
    uint16_t elapsedTimeInMs;
    EBoolean isFired;
    TCallback onExpirationCallback;
} STimerData;

#if !defined(AVR_FRAMEWORK_MICROOS_MAX_ASYNC_TIMERS_COUNT)
    #define AVR_FRAMEWORK_MICROOS_MAX_ASYNC_TIMERS_COUNT 3
#endif  // !defined(AVR_FRAMEWORK_MICROOS_MAX_ASYNC_TIMERS_COUNT)

static void clearTimer(volatile STimerData* timerData);
static volatile STimerData* getFirstIdleTimer();
static volatile STimerData* getTimerDataById(const uint8_t timerId);
static void initializePrivateData(void);
static void initializeTimer2Registers(void);
static void on1MsTicked(void);
static void setup1msTicksForCompareMatchTimer2Mode();
static void startTimer(volatile STimerData* timerData,
    const uint16_t timeDurationInMs,
    const EBoolean isPeriodic,
    const TCallback onTimerExpirationCallback);
static void turnOnTimer2();
static void turnOffTimer2();

static volatile STimerData timerData_[AVR_FRAMEWORK_MICROOS_MAX_ASYNC_TIMERS_COUNT];
static uint8_t startedTimers_ = 0;

void SystemTimeController_initialize(void)
{
    initializePrivateData();
    initializeTimer2Registers();
    InterruptVectorsController_callOnTIMER2_COMPA_vect(on1MsTicked);
}

void SystemTimeController_processEvents(void)
{
    if (startedTimers_ == 0)
    {
        return;
    }
    uint8_t iter = 0;
    for (; iter < AVR_FRAMEWORK_MICROOS_MAX_ASYNC_TIMERS_COUNT; ++iter)
    {
        volatile STimerData* timerData = &(timerData_[iter]);
        if (timerData->isIdle == EBoolean_True)
        {
            continue;
        }
        if (timerData->isFired == EBoolean_False)
        {
            continue;
        }
        timerData->isFired = EBoolean_False;
        (*(timerData->onExpirationCallback))();
        if (timerData->isPeriodic == EBoolean_True)
        {
            continue;
        }
        clearTimer(timerData);
    }
}

uint8_t SystemTimeController_startTimer(const uint16_t timeDurationInMs,
    const EBoolean isPeriodic,
    const TCallback onTimerExpirationCallback)
{
    assert(onTimerExpirationCallback != NULL);
    volatile STimerData* timerData = getFirstIdleTimer();
    assert(timerData != NULL);
    startTimer(timerData, timeDurationInMs, isPeriodic, onTimerExpirationCallback);
    return timerData->timerId;
}

void SystemTimeController_cancelTimer(const uint8_t timerId)
{
    volatile STimerData* timerData = getTimerDataById(timerId);
    assert(timerData != NULL);
    clearTimer(timerData);
}

void SystemTimeController_waitMs(const uint16_t timeDurationInMs)
{
    uint16_t iter = 0;
    for (; iter < timeDurationInMs; ++iter)
    {
        _delay_ms(1);
    }
}

void SystemTimeController_waitUs(const uint16_t timeDurationInUs)
{
    uint16_t iter = 0;
    for (; iter < timeDurationInUs; ++iter)
    {
        _delay_us(1);
    }
}

void clearTimer(volatile STimerData* timerData)
{
    assert(timerData != NULL);
    timerData->isIdle = EBoolean_False;
    timerData->timeDurationInMs = 0;
    timerData->isPeriodic = EBoolean_False;
    timerData->elapsedTimeInMs = 0;
    timerData->isFired = EBoolean_False;
    timerData->onExpirationCallback = NULL;
    --startedTimers_;
    if (startedTimers_ == 0)
    {
        turnOffTimer2();
    }
}

volatile STimerData* getFirstIdleTimer()
{
    uint8_t iter = 0;
    for (; iter < AVR_FRAMEWORK_MICROOS_MAX_ASYNC_TIMERS_COUNT; ++iter)
    {
        volatile STimerData* timerData = &(timerData_[iter]);
        if (timerData->isIdle == EBoolean_True)
        {
            return timerData;
        }
    }
    return NULL;
}

volatile STimerData* getTimerDataById(const uint8_t timerId)
{
    uint8_t iter = 0;
    for (; iter < AVR_FRAMEWORK_MICROOS_MAX_ASYNC_TIMERS_COUNT; ++iter)
    {
        volatile STimerData* timerData = &(timerData_[iter]);
        if (timerData->timerId == timerId)
        {
            return timerData;
        }
    }
    return NULL;
}

void initializePrivateData(void)
{
    uint8_t iter = 0;
    for (; iter < AVR_FRAMEWORK_MICROOS_MAX_ASYNC_TIMERS_COUNT; ++iter)
    {
        volatile STimerData* timerData = &(timerData_[iter]);
        timerData->isIdle = EBoolean_True;
        timerData->timerId = iter;
        timerData->timeDurationInMs = 0;
        timerData->isPeriodic = EBoolean_False;
        timerData->elapsedTimeInMs = 0;
        timerData->isFired = EBoolean_False;
        timerData->onExpirationCallback = NULL;
    }
}

void initializeTimer2Registers(void)
{
    turnOffTimer2();
    {
        // Timer / Counter mode of Operation - Waveform generation mode - CTC
        BYTE_CLEAR_BIT(TCCR2A, WGM20);
        BYTE_SET_BIT(TCCR2A, WGM21);
        BYTE_CLEAR_BIT(TCCR2A, WGM22);
    }
    {
        // Normal port operation - OC2A disconnected
        BYTE_CLEAR_BIT(TCCR2A, COM2A0);
        BYTE_CLEAR_BIT(TCCR2A, COM2A1);
    }
    {
        // Normal port operation - OC2B disconnected
        BYTE_CLEAR_BIT(TCCR2A, COM2B0);
        BYTE_CLEAR_BIT(TCCR2A, COM2B1);
    }
    setup1msTicksForCompareMatchTimer2Mode();
}

void on1MsTicked(void)
{
    if (startedTimers_ == 0)
    {
        return;
    }
    uint8_t iter = 0;
    for (; iter < 0; ++iter)
    {
        volatile STimerData* timerData = &(timerData_[iter]);
        if (timerData->isIdle == EBoolean_True)
        {
            continue;
        }
        ++(timerData->elapsedTimeInMs);
        if (timerData->elapsedTimeInMs == timerData->timeDurationInMs)
        {
            timerData->isFired = EBoolean_True;
            timerData->elapsedTimeInMs = 0;
        }
    }
}

void setup1msTicksForCompareMatchTimer2Mode()
{
    #if F_CPU == 16000000UL
        {
            // Timer2 clock selector - clk / 128
            // Prescaler 128: 16 MHz / 128 = 125 kHz
            BYTE_SET_BIT(TCCR2B, CS20);
            BYTE_CLEAR_BIT(TCCR2B, CS21);
            BYTE_SET_BIT(TCCR2B, CS22);
        }
        {
            // Compare match - OCR2A
            // 125 kHz / 125 = 1 kHz (1 ms ticks)
            OCR2A = 125;
        }
    #else
        #error "Add implementation for chosen AVR clock (F_CPU)!"
    #endif
}

void startTimer(volatile STimerData* timerData,
    const uint16_t timeDurationInMs,
    const EBoolean isPeriodic,
    const TCallback onTimerExpirationCallback)
{
    ++startedTimers_;
    timerData->isIdle = EBoolean_False;
    timerData->timeDurationInMs = timeDurationInMs;;
    timerData->isPeriodic = isPeriodic;
    timerData->elapsedTimeInMs = 0;
    timerData->isFired = EBoolean_False;
    timerData->onExpirationCallback = onTimerExpirationCallback;
    if (startedTimers_ == 1)
    {
        turnOnTimer2();
    }
}

void turnOnTimer2()
{
    // Clear current TCNT2 value
    TCNT2 = 0;
    // Timer2 output compare match interrupt enabled
    BYTE_SET_BIT(TIMSK2, OCIE2A);
}

void turnOffTimer2()
{
    // Timer2 output compare match interrupt disabled
    BYTE_CLEAR_BIT(TIMSK2, OCIE2A);
    // Clear current TCNT2 value
    TCNT2 = 0;
}
