cmake_minimum_required(VERSION 3.10)
project(tests)

find_package(GTest REQUIRED)

add_executable(tests
    test_mathlib.cpp
    test_protocol.cpp
)

target_link_libraries(tests
    mathlib
    common
    GTest::gtest
    GTest::gtest_main
    pthread
)

target_include_directories(tests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_SOURCE_DIR}/mathlib/include
    PUBLIC ${CMAKE_SOURCE_DIR}/common/include
)

add_test(NAME MathLibTests COMMAND tests)
