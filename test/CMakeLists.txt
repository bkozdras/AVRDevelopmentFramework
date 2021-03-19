#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Purpose: To prepare AVR environment and optional run unit tests.                 #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

add_compile_options(-std=c11)

macro(addUtTestTarget UT_TEST_TARGET)
    set(UT_TEST_TARGETS ${UT_TEST_TARGETS} ${UT_TEST_TARGET} PARENT_SCOPE)
endmacro(addUtTestTarget UT_TEST_TARGET)

addUtTestTarget(ByteMacrosTests)
add_cmocka_test(ByteMacrosTests
    SOURCES ByteMacrosTests.c
    LINK_LIBRARIES ${CMOCKA_STATIC_LIBRARY})

addUtTestTarget(GpioMacrosTests)
add_cmocka_test(GpioMacrosTests
    SOURCES GpioMacrosTests.c
    LINK_LIBRARIES ${CMOCKA_STATIC_LIBRARY})

addUtTestTarget(PortMacrosTests)
add_cmocka_test(PortMacrosTests
    SOURCES PortMacrosTests.c
    LINK_LIBRARIES ${CMOCKA_STATIC_LIBRARY})

addUtTestTarget(TypesTests)
add_cmocka_test(TypesTests
    SOURCES TypesTests.c
    LINK_LIBRARIES ${CMOCKA_STATIC_LIBRARY})

add_custom_target(ALL_UT_TESTS_TARGET ALL
    DEPENDS ${UT_TEST_TARGETS})

add_custom_command(TARGET ALL_UT_TESTS_TARGET
    COMMENT "Run unit tests"
    POST_BUILD COMMAND ctest ARGS --output-on-failure --rerun-failed
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
