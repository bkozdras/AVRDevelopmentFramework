#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

add_cmocka_test(AVR_FRAMEWORK_UT_MACROS_BYTEMACROSTESTS
    SOURCES ByteMacrosTests.c
    LINK_LIBRARIES ${CMOCKA_STATIC_LIBRARY})

add_cmocka_test(AVR_FRAMEWORK_UT_MACROS_GPIOMACROSTESTS
    SOURCES GpioMacrosTests.c
    LINK_LIBRARIES ${CMOCKA_STATIC_LIBRARY})

add_cmocka_test(AVR_FRAMEWORK_UT_MACROS_IOMACROSTESTS
    SOURCES IOMacrosTests.c
    LINK_LIBRARIES ${CMOCKA_STATIC_LIBRARY})
