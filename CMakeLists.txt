# mathlib/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(mathlib)

set(APP_VERSION_MAJOR $ENV{APP_VERSION_MAJOR})
set(APP_VERSION_MINOR $ENV{APP_VERSION_MINOR})
set(APP_VERSION_PATCH $ENV{APP_VERSION_PATCH})

if(NOT APP_VERSION_MAJOR)
    set(APP_VERSION_MAJOR 1)
endif()
if(NOT APP_VERSION_MINOR)
    set(APP_VERSION_MINOR 0)
endif()
if(NOT APP_VERSION_PATCH)
    set(APP_VERSION_PATCH 0)
endif()

set(VERSION "${APP_VERSION_MAJOR}.${APP_VERSION_MINOR}.${APP_VERSION_PATCH}")
message(STATUS "Building mathlib version ${VERSION}")

add_library(mathlib SHARED mathlib.cpp)
target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(mathlib PROPERTIES
    VERSION ${VERSION}
    SOVERSION ${APP_VERSION_MAJOR}
)

install(TARGETS mathlib
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
