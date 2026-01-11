#include "server.hpp"
#include "mathlib.hpp"
#include "protocol.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

Server::Server(int port) : port(port) {}

std::string Server::get_version() const {
    const char* major = std::getenv("APP_VERSION_MAJOR");
    const char* minor = std::getenv("APP_VERSION_MINOR");
    const char* patch = std::getenv("APP_VERSION_PATCH");
    
    if (!major) major = "1";
    if (!minor) minor = "0";
    if (!patch) patch = "0";
    
    return std::string(major) + "." + minor + "." + patch;
}

void Server::print_help() const {
    std::cout << "Kenguru Server v" << get_version() << "\n";
    std::cout << "Usage: server [OPTIONS]\n";
    std::cout << "Options:\n";
    std::cout << "  -p, --port PORT    Server port (default: 8080)\n";
    std::cout << "  -h, --help         Show this help\n";
    std::cout << "  -v, --version      Show version\n";
    std::cout << "\nAuthor: Student\n";
}

void Server::print_version() const {
    std::cout << "Kenguru Server v" << get_version() << std::endl;
}

bool Server::start() {
    std::cout << "Server started on port " << port << std::endl;
    std::cout << "Test: 21 -> tens digit: " << MathLib::get_tens_digit(21) << std::endl;
    std::cout << "Test: has_unique_digits(123): " << MathLib::has_unique_digits(123) << std::endl;
    std::cout << "Test: solve_kenguru_problem(100, 2): " << MathLib::solve_kenguru_problem(100, 2) << std::endl;
    return true;
}

int main(int argc, char* argv[]) {
    int port = 8080;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            Server server;
            server.print_help();
            return 0;
        }
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
            Server server;
            server.print_version();
            return 0;
        }
        if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--port") == 0) {
            if (i + 1 < argc) port = atoi(argv[++i]);
        }
    }
    
    Server server(port);
    return server.start() ? 0 : 1;
}
