#include <cstddef>

#include "socket.hpp"

namespace spp {

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

Socket::Socket() {
    _sd = spp::socket(PF_INET, SOCK_STREAM, 0);
}

Socket::Socket(int sd): _sd(dup(sd)) { }

Socket::Socket(const Socket& S): _sd(dup(S._sd)) { }

bool Socket::operator==(const Socket& rhs) const {
    return _sd == rhs._sd;
}

bool Socket::operator!=(const Socket& rhs) const {
    return !(*this == rhs);
}

Socket::~Socket() {
    spp::close(_sd);
}

int Socket::get_socket_descriptor() const {
    return _sd;
}

ssize_t Socket::recv(void* buffer, size_t length) {
    return spp::recv(_sd, buffer, length, 0);
}

ssize_t Socket::send(const void* buffer, size_t length) {
    return spp::send(_sd, buffer, length, 0);
}

}  // namespace spp