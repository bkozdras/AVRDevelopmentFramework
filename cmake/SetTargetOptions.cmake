#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

if (NOT AVR_FRAMEWORK_AVR_MCU)
    set(AVR_FRAMEWORK_AVR_MCU "atmega328p")
endif (NOT AVR_FRAMEWORK_AVR_MCU)

if (NOT AVR_FRAMEWORK_AVR_H_FUSE)
    set(AVR_FRAMEWORK_AVR_H_FUSE 0xde)
endif (NOT AVR_FRAMEWORK_AVR_H_FUSE)

if (NOT AVR_FRAMEWORK_AVR_L_FUSE)
    set(AVR_FRAMEWORK_AVR_L_FUSE 0xff)
endif (NOT AVR_FRAMEWORK_AVR_L_FUSE)

if (NOT AVR_FRAMEWORK_AVR_MCU_FREQ)
    set(AVR_FRAMEWORK_AVR_MCU_FREQ "16000000UL")
endif (NOT AVR_FRAMEWORK_AVR_MCU_FREQ)

if (NOT AVR_FRAMEWORK_AVR_LIB_ROOT_PATH)
    set(AVR_FRAMEWORK_AVR_LIB_ROOT_PATH "/usr/local/avr/avr")
endif (NOT AVR_FRAMEWORK_AVR_LIB_ROOT_PATH)

set(CMAKE_TOOLCHAIN_FILE ${ROOT_DIR}/cmake/GenericAvrCMake.cmake)

set(AVR_MCU ${AVR_FRAMEWORK_AVR_MCU})
set(AVR_H_FUSE ${AVR_FRAMEWORK_AVR_H_FUSE})
set(AVR_L_FUSE ${AVR_FRAMEWORK_AVR_L_FUSE})
set(MCU_SPEED ${AVR_FRAMEWORK_AVR_MCU_FREQ})
set(CMAKE_FIND_ROOT_PATH ${AVR_FRAMEWORK_AVR_LIB_ROOT_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_SYSTEM_INCLUDE_PATH "${CMAKE_FIND_ROOT_PATH}/include")
set(CMAKE_SYSTEM_LIBRARY_PATH "${CMAKE_FIND_ROOT_PATH}/lib")

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

if(CMAKE_BUILD_TYPE MATCHES Release)
   set(CMAKE_C_FLAGS_RELEASE "-Os")
endif(CMAKE_BUILD_TYPE MATCHES Release)

if(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
   set(CMAKE_C_FLAGS_RELWITHDEBINFO "-Os -save-temps -g -gdwarf-3 -gstrict-dwarf")
endif(CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)

if(CMAKE_BUILD_TYPE MATCHES Debug)
   set(CMAKE_C_FLAGS_DEBUG "-O0 -save-temps -g -gdwarf-3 -gstrict-dwarf")
endif(CMAKE_BUILD_TYPE MATCHES Debug)

message(STATUS "Build for AVR MCU: ${AVR_MCU}")
message(STATUS "High Fuse: ${AVR_H_FUSE}")
message(STATUS "Low Fuse: ${AVR_L_FUSE}")
message(STATUS "AVR MCU speed / frequency: ${MCU_SPEED}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "AVR lib root path: ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "AVR toolchain: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "Set CMAKE_FIND_ROOT_PATH to ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "Set CMAKE_SYSTEM_INCLUDE_PATH to ${CMAKE_SYSTEM_INCLUDE_PATH}")
message(STATUS "Set CMAKE_SYSTEM_LIBRARY_PATH to ${CMAKE_SYSTEM_LIBRARY_PATH}")

add_definitions("-DF_CPU=${MCU_SPEED}")
add_definitions("-fpack-struct")
add_definitions("-fshort-enums")
add_definitions("-Wall")
add_definitions("-Werror")
add_definitions("-pedantic")
add_definitions("-pedantic-errors")
add_definitions("-funsigned-char")
add_definitions("-funsigned-bitfields")
add_definitions("-ffunction-sections")
add_definitions("-c")
add_definitions("-std=c11")
