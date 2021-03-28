#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(AVR_ROOT_PATH $ENV{AVR_INSTALL_DIR})

if (NOT AVR_ROOT_PATH)
    message(FATAL_ERROR
        "Not set environment variable AVR_INSTALL_DIR. Call cmake for build target from docker container!")
endif (NOT AVR_ROOT_PATH)

set(INPUT_DIR ${AVR_ROOT_PATH}/avr/include)
set(OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/avr-libc)

if (NOT EXISTS ${OUTPUT_DIR})
    message(STATUS "Copying AVR libc includes from ${INPUT_DIR} to ${OUTPUT_DIR}")
    execute_process(
        COMMAND cp -r ${INPUT_DIR} ${OUTPUT_DIR}
        OUTPUT_VARIABLE COPY_RESULT)
else ()
    message(STATUS "Already copied AVR libc includes from ${INPUT_DIR} to ${OUTPUT_DIR}")
endif (NOT EXISTS ${OUTPUT_DIR})
