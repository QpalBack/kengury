#include <iostream>
#include <fstream>

int main() {
    std::ofstream log("test.log");
    log << "{\"timestamp\": \"2024-01-11 22:40:00\", \"level\": \"INFO\", \"message\": \"Test\"}\n";
    log.close();
    std::cout << "Log file created\n";
    return 0;
}
