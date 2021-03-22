#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME "macros")

project(AVR_FRAMEWORK_${PACKAGE_NAME} C)

add_library(${PROJECT_NAME} OBJECT)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${HEADERS_DIR}/${PACKAGE_NAME}/ByteMacros.h
        ${HEADERS_DIR}/${PACKAGE_NAME}/GpioMacros.h
        ${HEADERS_DIR}/${PACKAGE_NAME}/IOMacros.h

target_include_directories(${PROJECT_NAME}
    PUBLIC ${INCLUDE_DIR})
