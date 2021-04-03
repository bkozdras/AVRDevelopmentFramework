#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME "communication")

project(AVR_FRAMEWORK_STUB_${PACKAGE_NAME} C)

add_library(${PROJECT_NAME} OBJECT)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${STUB_HEADERS_DIR}/${PACKAGE_NAME}/I2C.h
        ${STUB_HEADERS_DIR}/${PACKAGE_NAME}/SoftwareSerial.h
        ${STUB_HEADERS_DIR}/${PACKAGE_NAME}/Uart.h
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/I2C.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SoftwareSerial.c
        ${CMAKE_CURRENT_SOURCE_DIR}/Uart.c)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${INCLUDE_DIRS} ${STUB_INCLUDE_DIR})
