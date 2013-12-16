#ifndef SPP_LISTEN_SOCKET_HPP
#define SPP_LISTEN_SOCKET_HPP

#include <string>

#include "client_socket.hpp"
#include "sockaddr.hpp"

namespace spp {

class ListenSocket {
public:
    ListenSocket();
    ListenSocket(int sd);

    virtual ~ListenSocket();

    int bind(const std::string& addr, unsigned short port);

    ClientSocket accept();
private:
    ListenSocket(const ListenSocket&) {};
    void operator=(const Socket&) {};

    int _sd;
    // TODO: addr _address
    //Sockaddr _address
};

} // namespace spp
#endif