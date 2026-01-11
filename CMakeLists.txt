cmake_minimum_required(VERSION 3.10)
project(KenguruProject VERSION 1.0.0)

# Версия из переменных окружения
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
message(STATUS "Building Kenguru Project v${VERSION}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подпроекты
add_subdirectory(mathlib)
add_subdirectory(common)
add_subdirectory(server)
add_subdirectory(client)

# Документация
find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(doc
        COMMAND doxygen docs/Doxyfile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating documentation"
    )
endif()
