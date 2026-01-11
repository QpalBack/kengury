#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client
{
public:
    Client(const std::string& server_addr = "127.0.0.1:8080");
    void print_help() const;
    void print_version() const;
    bool run(const std::string& config_file);

private:
    std::string server_addr;
    std::string get_version() const;
};

#endif
