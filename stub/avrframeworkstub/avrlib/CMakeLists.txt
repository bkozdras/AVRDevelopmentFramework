#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME "avrlib")

project(AVR_FRAMEWORK_STUB_${PACKAGE_NAME} C)

add_library(${PROJECT_NAME} OBJECT)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${STUB_HEADERS_DIR}/${PACKAGE_NAME}/AvrInterrupts.h
        ${STUB_HEADERS_DIR}/${PACKAGE_NAME}/AvrIo.h
        ${STUB_HEADERS_DIR}/${PACKAGE_NAME}/UtilAtomic.h
        ${STUB_HEADERS_DIR}/${PACKAGE_NAME}/UtilDelay.h
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/AvrIo.c
        ${CMAKE_CURRENT_SOURCE_DIR}/UtilDelay.c)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${INCLUDE_DIRS} ${STUB_INCLUDE_DIR})
