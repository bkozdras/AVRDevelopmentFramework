#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

add_cmocka_test(AVR_FRAMEWORK_UT_COMMUNICATION_I2C_TESTS
    SOURCES I2CTests.c
    COMPILE_OPTIONS -D_DEFAULT_SOURCE
    LINK_LIBRARIES
        ${CMOCKA_STATIC_LIBRARY}
        ${AVRFRAMEWORK_STATIC_LIBRARY})

add_cmocka_test(AVR_FRAMEWORK_UT_COMMUNICATION_SOFTWARESERIAL_TESTS
    SOURCES SoftwareSerialTests.c
    COMPILE_OPTIONS -D_DEFAULT_SOURCE
    LINK_LIBRARIES
        ${CMOCKA_STATIC_LIBRARY}
        ${AVRFRAMEWORK_STATIC_LIBRARY})

add_cmocka_test(AVR_FRAMEWORK_UT_COMMUNICATION_UART_TESTS
    SOURCES UartTests.c
    COMPILE_OPTIONS -D_DEFAULT_SOURCE
    LINK_LIBRARIES
        ${CMOCKA_STATIC_LIBRARY}
        ${AVRFRAMEWORK_STATIC_LIBRARY})
