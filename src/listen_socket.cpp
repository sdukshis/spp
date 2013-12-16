#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

#include "listen_socket.hpp"
#include "client_socket.hpp"

namespace spp {

ListenSocket::ListenSocket() {
    _sd = socket(AF_INET, SOCK_STREAM, 0);
}

ListenSocket::ListenSocket(int sd): _sd(sd) { }

ListenSocket::~ListenSocket() {
    close(_sd);
}

int ListenSocket::bind(const std::string& addr, unsigned short port) {
    sockaddr_in listen_addr;
    int rv = 0;

    bzero((char*)&listen_addr, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(port);
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    rv = ::bind(_sd, reinterpret_cast<sockaddr*>(&listen_addr), sizeof(listen_addr));
    if (rv == -1) {
        std::perror("bind");
        return -1;
    }

    // TODO: listen queue length
    rv = ::listen(_sd, 1024);
    if (rv == -1) {
        std::perror("listen");
        return -1;
    }

    return 0;
}

ClientSocket ListenSocket::accept() {
    sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    int cd = ::accept(_sd, reinterpret_cast<sockaddr*>(&client_address), &client_address_len);
    if (cd == -1) {
        std::perror("accept");
        std::abort();
    }
    Sockaddr address(reinterpret_cast<sockaddr*>(&client_address), client_address_len);

    return ClientSocket(cd, address);
}

}  // namespace spp