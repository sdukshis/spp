#include <iostream>

#include "listen_socket.hpp"
#include "client_socket.hpp"

const int BUFF_SIZE = 1024;

void handler(spp::ClientSocket client)
{
    char buff[BUFF_SIZE];
    int rv = 0;

    spp::Sockaddr client_addr = client.get_addr();

    std::cout << "Client " << client_addr.get_sin_addr() << ":" << 
                 client_addr.get_sin_port() << " connected" << std::endl;

    while ((rv = client.recv(buff, BUFF_SIZE - 1)) > 0) {
        client.send(buff, rv);
    }

    std::cout << "Client " << client_addr.get_sin_addr() << ":" << 
                 client_addr.get_sin_port() << " disconnected" << std::endl;

}

int main()
{
    spp::ListenSocket s;

    s.bind("", 8080);

    while (true) {
        spp::ClientSocket client = s.accept();
        handler(client);
    }


    return 0;
}
