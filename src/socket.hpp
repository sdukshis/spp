#ifndef SPP_SOCKET_HPP
#define SPP_SOCKET_HPP

#include <sys/types.h>
#include <cstddef>

namespace spp {

class Socket {
public:
    Socket();  // create new socket
    Socket(int sd);  // use existing socket descriptor
    Socket(const Socket&);

    Socket& operator=(const Socket&);

    bool operator==(const Socket&) const;
    bool operator!=(const Socket&) const;

    virtual ~Socket();

    int get_socket_descriptor() const;  // return socket descriptor

    // TODO: write comment
    ssize_t recv(void* buffer, size_t length);  

    // TODO: write comment
    ssize_t send(const void* buffer, size_t length);

protected:
    int _sd;
};

} // namespace spp

#endif