#include <cstring>
#include <cstdlib>
#include <cassert>

#include "sockaddr.hpp"

#include <sys/socket.h>
#include <arpa/inet.h>

namespace spp {

Sockaddr::Sockaddr(const sockaddr* address, socklen_t address_len) {
    _address_len = address_len;
    _address = (sockaddr*)std::malloc(_address_len);
    std::memcpy(_address, address, _address_len);
}

Sockaddr::Sockaddr(const Sockaddr& addr) {
    _address_len = addr._address_len;
    _address = (sockaddr*)std::malloc(_address_len);
    std::memcpy(_address, addr._address, _address_len);
}

Sockaddr& Sockaddr::operator=(const Sockaddr& rhs) {
    if (this != &rhs) {
        _address_len = rhs._address_len;
        _address = (sockaddr*)std::malloc(_address_len);
        std::memcpy(_address, rhs._address, _address_len);
    }

    return *this;
}

bool Sockaddr::operator==(const Sockaddr& rhs) const {
    return (_address_len == rhs._address_len) &&
           !(std::memcmp(_address, rhs._address, _address_len));
}

bool Sockaddr::operator!=(const Sockaddr& rhs) const {
    return !(*this == rhs);
}

Sockaddr::~Sockaddr() {
    std::free(_address);
}

std::string Sockaddr::get_sin_addr() const {
    sockaddr_in *addr_in = reinterpret_cast<sockaddr_in*>(_address);
    char tmp[INET_ADDRSTRLEN];
    if (!inet_ntop(addr_in->sin_family, &(addr_in->sin_addr), tmp, INET_ADDRSTRLEN)) {
        return std::string();
    }
    return std::string(tmp);
}

unsigned short Sockaddr::get_sin_port() const {
    sockaddr_in *addr_in = reinterpret_cast<sockaddr_in*>(_address);
    assert(addr_in->sin_family == AF_INET);
    return ntohs(addr_in->sin_port);
}

}  // namespace spp