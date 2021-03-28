#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

set(PACKAGE_NAME "utilities")

project(AVR_FRAMEWORK_${PACKAGE_NAME} C)

set(LIB_HEADERS
    ${HEADERS_DIR}/${PACKAGE_NAME}/RegisterOperations.h)
set(LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/RegisterOperations.c)

if (BUILD_LIBRARY)
    add_library(${PROJECT_NAME} OBJECT)
    target_sources(${PROJECT_NAME}
        PUBLIC ${LIB_HEADERS}
        PRIVATE ${LIB_SOURCES})
    target_include_directories(${PROJECT_NAME}
        PUBLIC ${INCLUDE_DIR})
endif (BUILD_LIBRARY)

if (BUILD_FOR_TARGET)
    add_avr_library(${PROJECT_NAME}
        ${LIB_HEADERS}
        ${LIB_SOURCES})
    avr_target_include_directories(${PROJECT_NAME}
        PUBLIC ${INCLUDE_DIR})
endif (BUILD_FOR_TARGET)
