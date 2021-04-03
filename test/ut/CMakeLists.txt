#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

#add_subdirectory(communication)
add_subdirectory(macros)
#add_subdirectory(microos)
add_subdirectory(types)
add_subdirectory(utilities)

setup_target_for_coverage_lcov(
    NAME ut-code-coverage
    EXECUTABLE ctest -j ${PROCESSOR_COUNT}
    DEPENDENCIES ${AVRFRAMEWORK_STATIC_LIBRARY}
    EXCLUDE "build*/" "mock/*" "stub/*" "test/*" "test-programs/*"
    LCOV_ARGS --no-external)
