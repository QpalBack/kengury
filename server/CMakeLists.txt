add_executable(server src/main.cpp)
target_link_libraries(server mathlib common)
target_include_directories(server PRIVATE include PUBLIC ../common/include ../mathlib/include)
