#**********************************************************************************#
# Copyright by @bkozdras <b.kozdras@gmail.com>                                     #
# Version: 1.0                                                                     #
# Licence: MIT                                                                     #
#**********************************************************************************#

message(STATUS "Processing: ${CMAKE_CURRENT_LIST_FILE}")

project(AvrFrameworkLibraryStub C)

add_compile_options(-std=c11)

if (BUILD_STATIC_STUB_LIBRARY)
    set(AVRFRAMEWORK_STATIC_STUB_LIBRARY
        avrframeworkstub-static
        CACHE INTERNAL "AVR framework static library with stub for impl")
endif (BUILD_STATIC_STUB_LIBRARY)

if (BUILD_SHARED_STUB_LIBRARY)
    set(AVRFRAMEWORK_SHARED_STUB_LIBRARY
        avrframeworkstub
        CACHE INTERNAL "AVR framework shared library with stub for impl")
endif (BUILD_SHARED_STUB_LIBRARY)

add_subdirectory(avrlib)
add_subdirectory(communication)
add_subdirectory(microos)
add_subdirectory(utilities)

set(STUB_LIBRARIES
    AVR_FRAMEWORK_STUB_avrlib
    AVR_FRAMEWORK_STUB_communication
    AVR_FRAMEWORK_STUB_microos
    AVR_FRAMEWORK_STUB_utilities)

if (BUILD_STATIC_STUB_LIBRARY)
    add_library(${AVRFRAMEWORK_STATIC_STUB_LIBRARY} STATIC)
    target_link_libraries(${AVRFRAMEWORK_STATIC_STUB_LIBRARY} ${STUB_LIBRARIES})
    install(TARGETS ${AVRFRAMEWORK_STATIC_STUB_LIBRARY}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT ${PROJECT_NAME})
endif (BUILD_STATIC_STUB_LIBRARY)

if (BUILD_SHARED_STUB_LIBRARY)
    add_library(${AVRFRAMEWORK_SHARED_STUB_LIBRARY} STATIC)
    target_link_libraries(${AVRFRAMEWORK_SHARED_STUB_LIBRARY} ${STUB_LIBRARIES})
    install(TARGETS ${AVRFRAMEWORK_SHARED_STUB_LIBRARY}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT ${PROJECT_NAME})
endif (BUILD_SHARED_STUB_LIBRARY)
