/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: AVR framework tests.                                                  */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>

#include <pthread.h>
#include <stddef.h>
#include <unistd.h>

#include <avrframework/macros/ByteMacros.h>
#include <avrframework/types/TMcuRegister.h>
#include <avrframework/types/TPinNumber.h>
#include <avrframework/utilities/RegisterOperations.h>

#include <cmocka.h>

typedef struct _ThreadArgs
{
    TMcuRegister* mcuRegister;
    TPinNumber* pinNumber;
} ThreadArgs;

static void* clearRegisterBitThread(void* args)
{
    usleep(10);
    ThreadArgs* threadArgs = (ThreadArgs*)(args);
    assert_true(BYTE_IS_BIT_SET(*(threadArgs->mcuRegister), *(threadArgs->pinNumber)));
    BYTE_CLEAR_BIT(*(threadArgs->mcuRegister), *(threadArgs->pinNumber));
    return NULL;
}

static void* setRegisterBitThread(void* args)
{
    usleep(10);
    ThreadArgs* threadArgs = (ThreadArgs*)(args);
    assert_true(BYTE_IS_BIT_CLEARED(*(threadArgs->mcuRegister), *(threadArgs->pinNumber)));
    BYTE_SET_BIT(*(threadArgs->mcuRegister), *(threadArgs->pinNumber));
    return NULL;
}

static void RegisterOperationsShouldImmediatelyPassWhenRequestedPinInRegisterIsAlreadySet(void** state)
{
    (void) state;
    const TMcuRegister PINA = 0b10101010;
    RegisterOperations_waitForPinSet(&PINA, 7);
    RegisterOperations_waitForPinSet(&PINA, 5);
    RegisterOperations_waitForPinSet(&PINA, 3);
    RegisterOperations_waitForPinSet(&PINA, 1);
}

static void RegisterOperationsShouldPassWhenSimulatedProcessorOperationsSetPinInRegister(void** state)
{
    (void) state;
    TMcuRegister PINA = 0b00000000;
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 0;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            setRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinSet(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b00000001);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 1;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            setRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinSet(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b00000011);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 2;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            setRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinSet(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b00000111);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 3;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            setRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinSet(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b00001111);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 4;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            setRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinSet(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b00011111);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 5;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            setRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinSet(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b00111111);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 6;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            setRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinSet(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b01111111);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 7;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            setRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinSet(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b11111111);
    }
}

static void RegisterOperationsShouldImmediatelyPassWhenRequestedPinInRegisterIsAlreadyCleared(void** state)
{
    (void) state;
    const TMcuRegister PINA = 0b10101010;
    RegisterOperations_waitForPinCleared(&PINA, 6);
    RegisterOperations_waitForPinCleared(&PINA, 4);
    RegisterOperations_waitForPinCleared(&PINA, 2);
    RegisterOperations_waitForPinCleared(&PINA, 0);
}

static void RegisterOperationsShouldPassWhenSimulatedProcessorOperationsClearPinInRegister(void** state)
{
    (void) state;
    TMcuRegister PINA = 0b11111111;
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 0;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            clearRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinCleared(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b11111110);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 1;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            clearRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinCleared(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b11111100);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 2;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            clearRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinCleared(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b11111000);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 3;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            clearRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinCleared(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b11110000);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 4;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            clearRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinCleared(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b11100000);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 5;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            clearRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinCleared(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b11000000);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 6;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            clearRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinCleared(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b10000000);
    }
    {
        pthread_t simulatedProcessorThreadId = 0;
        TPinNumber pinNumber = 7;
        ThreadArgs threadArgs;
        threadArgs.mcuRegister = &PINA;
        threadArgs.pinNumber = &pinNumber;
        int result = pthread_create(&simulatedProcessorThreadId,
            NULL,
            clearRegisterBitThread,
            (void*)(&threadArgs));
        assert_int_equal(result, 0);
        RegisterOperations_waitForPinCleared(&PINA, pinNumber);
        pthread_join(simulatedProcessorThreadId, NULL);
        assert_int_equal(PINA, 0b00000000);
    }
}

int main(void)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(RegisterOperationsShouldImmediatelyPassWhenRequestedPinInRegisterIsAlreadySet),
        cmocka_unit_test(RegisterOperationsShouldPassWhenSimulatedProcessorOperationsSetPinInRegister),
        cmocka_unit_test(RegisterOperationsShouldImmediatelyPassWhenRequestedPinInRegisterIsAlreadyCleared),
        cmocka_unit_test(RegisterOperationsShouldPassWhenSimulatedProcessorOperationsClearPinInRegister)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
