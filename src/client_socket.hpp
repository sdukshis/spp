#ifndef SPP_CLIENT_SOCKET_HPP
#define SPP_CLIENT_SOCKET_HPP

#include "socket.hpp"
#include "sockaddr.hpp"

namespace spp {

class ClientSocket: public Socket {
public:
    ClientSocket(int _sd, const Sockaddr& address);
    ClientSocket(const ClientSocket&);

    ClientSocket& operator=(const ClientSocket&);

    bool operator==(const ClientSocket&) const;
    bool operator!=(const ClientSocket&) const;

    ~ClientSocket();

    Sockaddr get_addr() const;

protected:
    Sockaddr _address;
};

}  // namespace spp
#endif