#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Purpose: To prepare AVR environment and optional run unit tests.                 #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

execute_process(COMMAND uname -m
    COMMAND tr -d '\n'
    OUTPUT_VARIABLE THIS_ARCH)

set(UNIT_TESTING_ENABLED OFF CACHE BOOL "Enabled unit tests")

message(STATUS "Is Unit Testing enabled: ${UNIT_TESTING_ENABLED}")

set(PROJECT_NAME AvrDevelopmentFramework)

project(${PROJECT_NAME} VERSION 1.0)

message(STATUS "Project name: ${PROJECT_NAME}")
message(STATUS "Target architecture: AVR")
message(STATUS "This architecture \(used for tests\): ${THIS_ARCH}")

enable_language(C)

include_directories(include)
if (UNIT_TESTING_ENABLED)
    enable_testing()
    include(cmake/FetchCMocka.cmake)
    add_subdirectory(test)
endif (UNIT_TESTING_ENABLED)
