#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>

class Server
{
public:
    Server(int port = 8080);
    void print_help() const;
    void print_version() const;
    bool start();

private:
    int port;
    std::string get_version() const;
};

#endif
