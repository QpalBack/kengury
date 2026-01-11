#include "client.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

Client::Client(const std::string& server_addr) : server_addr(server_addr) {}

std::string Client::get_version() const {
    const char* major = std::getenv("APP_VERSION_MAJOR");
    const char* minor = std::getenv("APP_VERSION_MINOR");
    const char* patch = std::getenv("APP_VERSION_PATCH");
    
    if (!major) major = "1";
    if (!minor) minor = "0";
    if (!patch) patch = "0";
    
    return std::string(major) + "." + minor + "." + patch;
}

void Client::print_help() const {
    std::cout << "Kenguru Client v" << get_version() << "\n";
    std::cout << "Usage: client [OPTIONS]\n";
    std::cout << "Options:\n";
    std::cout << "  -s, --server ADDR    Server address (default: 127.0.0.1:8080)\n";
    std::cout << "  -p, --params FILE    JSON config file\n";
    std::cout << "  -h, --help           Show this help\n";
    std::cout << "  -v, --version        Show version\n";
    std::cout << "\nExample config.json:\n";
    std::cout << "{\n";
    std::cout << "  \"max_number\": 100,\n";
    std::cout << "  \"word_count\": 2,\n";
    std::cout << "  \"language\": \"ru\"\n";
    std::cout << "}\n";
}

void Client::print_version() const {
    std::cout << "Kenguru Client v" << get_version() << std::endl;
}

bool Client::run(const std::string& config_file) {
    std::cout << "Connecting to server: " << server_addr << std::endl;
    std::cout << "Using config: " << config_file << std::endl;
    
    // Просто демонстрация
    std::ifstream file(config_file);
    if (file) {
        std::string content((std::istreambuf_iterator<char>(file)), 
                           std::istreambuf_iterator<char>());
        std::cout << "Config content:\n" << content << std::endl;
    }
    
    std::cout << "Client executed successfully (TCP simulation)" << std::endl;
    return true;
}

int main(int argc, char* argv[]) {
    std::string server_addr = "127.0.0.1:8080";
    std::string config_file;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            Client client;
            client.print_help();
            return 0;
        }
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
            Client client;
            client.print_version();
            return 0;
        }
        if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--server") == 0) {
            if (i + 1 < argc) server_addr = argv[++i];
        }
        if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--params") == 0) {
            if (i + 1 < argc) config_file = argv[++i];
        }
    }
    
    if (config_file.empty()) {
        std::cerr << "Error: Config file required. Use -p option.\n";
        Client client;
        client.print_help();
        return 1;
    }
    
    Client client(server_addr);
    return client.run(config_file) ? 0 : 1;
}
