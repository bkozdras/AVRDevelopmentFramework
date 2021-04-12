#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

add_avr_executable(TEST_PROGRAM_MACROS
    ${CMAKE_CURRENT_SOURCE_DIR}/TestProgramMacros.c)
avr_target_link_libraries(TEST_PROGRAM_MACROS c)

add_avr_executable(TEST_PROGRAM_UTILITIES
    ${CMAKE_CURRENT_SOURCE_DIR}/TestProgramUtilities.c)
avr_target_link_libraries(TEST_PROGRAM_UTILITIES
    AVR_FRAMEWORK_utilities c)
