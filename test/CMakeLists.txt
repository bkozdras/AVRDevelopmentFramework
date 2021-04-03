#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

add_compile_options(-DF_CPU=${F_CPU})
add_compile_options(-std=c11)
add_compile_options(-fpack-struct)
add_compile_options(-fshort-enums)
add_compile_options(-Wall)
add_compile_options(-Werror)

add_subdirectory(ut)
