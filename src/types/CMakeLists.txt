#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME "types")

project(AVR_FRAMEWORK_${PACKAGE_NAME} C)

add_library(${PROJECT_NAME} OBJECT)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${HEADERS_DIR}/${PACKAGE_NAME}/AllTypes.h
        ${HEADERS_DIR}/${PACKAGE_NAME}/EBoolean.h
        ${HEADERS_DIR}/${PACKAGE_NAME}/SPinPortData.h
        ${HEADERS_DIR}/${PACKAGE_NAME}/TBitNumber.h
        ${HEADERS_DIR}/${PACKAGE_NAME}/TByte.h
        ${HEADERS_DIR}/${PACKAGE_NAME}/TCallback.h
        ${HEADERS_DIR}/${PACKAGE_NAME}/TMcuRegister.h
        ${HEADERS_DIR}/${PACKAGE_NAME}/TPinNumber.h

target_include_directories(${PROJECT_NAME}
    PUBLIC ${INCLUDE_DIR})
