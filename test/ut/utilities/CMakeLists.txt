#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_cmocka_test(AVR_FRAMEWORK_UT_UTILITIES_REGISTEROPERATIONS_TESTS
    SOURCES RegisterOperationsTests.c
    COMPILE_OPTIONS -D_DEFAULT_SOURCE
    LINK_LIBRARIES
        ${CMOCKA_STATIC_LIBRARY}
        ${AVRFRAMEWORK_STATIC_LIBRARY}
        Threads::Threads)
