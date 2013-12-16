#ifndef SPP_SOCKADDR_HPP
#define SPP_SOCKADDR_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <string>

namespace spp {


class Sockaddr {
public:
    Sockaddr(const sockaddr*, socklen_t);
    Sockaddr(const Sockaddr&);

    Sockaddr& operator=(const Sockaddr&);

    bool operator==(const Sockaddr&) const;
    bool operator!=(const Sockaddr&) const;

    ~Sockaddr();

    std::string get_sin_addr() const;
    unsigned short get_sin_port() const;
private:
    sockaddr* _address;
    socklen_t _address_len;
};

}  // namespace spp
#endif