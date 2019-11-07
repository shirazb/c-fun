cmake_minimum_required(VERSION 3.15)

project(C_FUN VERSION 0.0
              DESCRIPTION "Fun in C"
              LANGUAGES C
)

set(C_FUN_VERSION_MAJOR 0)
set(C_FUN_VERSION_MINOR 0)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Let's nicely support folders in IDE's
    #set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)
endif()

message(STATUS "Building list_node library")
add_subdirectory(src)

# Testing only available if this is the main app
# Emergency override variable C_FUN_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR C_FUN_BUILD_TESTING) AND BUILD_TESTING)
    message(STATUS "Building tests")
    add_subdirectory(test)
endif()
