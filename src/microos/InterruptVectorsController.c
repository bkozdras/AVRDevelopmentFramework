/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <avrframework/microos/InterruptVectorsController.h>

#include <assert.h>
#include <stddef.h>

#if defined(BUILD_FOR_TARGET)
    #include <avr/io.h>
    #include <avr/interrupt.h>
    #include <util/atomic.h>
#else
    #include <avrframeworkstub/avrlib/AvrIo.h>
    #include <avrframeworkstub/avrlib/AvrInterrupts.h>
    #include <avrframeworkstub/avrlib/UtilAtomic.h>
#endif // defined (BUILD_FOR_TARGET)

static volatile TCallback onTIMER2_COMPA_vectCallback = NULL;

void InterruptVectorsController_callOnTIMER2_COMPA_vect(const TCallback callback)
{
    assert(callback != NULL);
    ATOMIC_BLOCK(ATOMIC_FORCEON)
    {
        onTIMER2_COMPA_vectCallback = callback;
    }
}

void InterruptVectorsController_resetTIMER2_COMPA_vect()
{
    ATOMIC_BLOCK(ATOMIC_FORCEON)
    {
        onTIMER2_COMPA_vectCallback = NULL;
    }
}

// System interrupt callbacks

ISR(TIMER2_COMPA_vect)
{
    if (onTIMER2_COMPA_vectCallback != NULL)
    {
        (*onTIMER2_COMPA_vectCallback)();
    }
}
