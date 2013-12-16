#include "client_socket.hpp"

namespace spp {

ClientSocket::ClientSocket(int sd, const Sockaddr& address):
    Socket(sd), _address(address) { }

ClientSocket::ClientSocket(const ClientSocket& S):
     Socket(S._sd), _address(S._address) { }

ClientSocket& ClientSocket::operator=(const ClientSocket& rhs) {
    if (this != &rhs) {
        _sd = rhs._sd;
        _address = rhs._address;
    }

    return *this;
}

bool ClientSocket::operator==(const ClientSocket& rhs) const {
    return (_sd == rhs._sd) && (_address == rhs._address);
}

bool ClientSocket::operator!=(const ClientSocket& rhs) const {
    return !(*this == rhs);
}

ClientSocket::~ClientSocket() {

}

Sockaddr ClientSocket::get_addr() const {
    return _address;
}

}  // namespace spp 