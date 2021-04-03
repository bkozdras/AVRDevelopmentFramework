#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

add_cmocka_test(AVR_FRAMEWORK_UT_TYPES_TYPESTESTS
    SOURCES TypesTests.c
    LINK_LIBRARIES ${CMOCKA_STATIC_LIBRARY})
