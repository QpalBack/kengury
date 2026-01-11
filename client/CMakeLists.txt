add_executable(client src/main.cpp)
target_link_libraries(client common)
target_include_directories(client PRIVATE include PUBLIC ../common/include)
