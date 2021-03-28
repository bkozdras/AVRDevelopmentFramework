#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

project(AvrFrameworkLibrary C)

add_compile_options(-std=c11)

if (BUILD_STATIC_LIBRARY)
    set(AVRFRAMEWORK_STATIC_LIBRARY
        avrframework-static
        CACHE INTERNAL "AVR framework static library")
endif (BUILD_STATIC_LIBRARY)
fdsfgsdgd
if (BUILD_SHARED_LIBRARY)
    set(AVRFRAMEWORK_SHARED_LIBRARY
        avrframework
        CACHE INTERNAL "AVR framework shared library")
endif (BUILD_SHARED_LIBRARY)

add_subdirectory(utilities)

set(LIBRARIES
    #AVR_FRAMEWORK_macros
    #AVR_FRAMEWORK_types
    AVR_FRAMEWORK_utilities)

if (BUILD_STATIC_LIBRARY)
    add_library(${AVRFRAMEWORK_STATIC_LIBRARY} STATIC)
    target_link_libraries(${AVRFRAMEWORK_STATIC_LIBRARY} ${LIBRARIES})
    install(TARGETS ${AVRFRAMEWORK_STATIC_LIBRARY}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT ${PROJECT_NAME})
endif (BUILD_STATIC_LIBRARY)

if (BUILD_SHARED_LIBRARY)
    add_library(${AVRFRAMEWORK_SHARED_LIBRARY} STATIC)
    target_link_libraries(${AVRFRAMEWORK_STATIC_LIBRARY} ${LIBRARIES})
    install(TARGETS ${AVRFRAMEWORK_SHARED_LIBRARY}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT ${PROJECT_NAME})
endif (BUILD_SHARED_LIBRARY)
