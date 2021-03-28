#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

find_library(C_LIB c)
message(STATUS "avr-libc: ${C_LIB}")

add_avr_executable(test-program-macros
    ${CMAKE_CURRENT_SOURCE_DIR}/testMacros.c)
avr_target_link_libraries(test-program-macros
    ${C_LIB})

add_avr_executable(test-program-utilities
    ${CMAKE_CURRENT_SOURCE_DIR}/testUtilities.c)
avr_target_link_libraries(test-program-utilities
    AVR_FRAMEWORK_utilities
    ${C_LIB})
