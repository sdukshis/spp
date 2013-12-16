CPP = g++
CFLAGS = -Wall
LFLAGS =

.PHONY: all clean

all:echo

echo:echo.o spp.a
	$(CPP) $(LFLAGS) -o $@ $^

echo.o:echo.cpp listen_socket.hpp client_socket.hpp
	$(CPP) -c $(CFLAGS) -o $@ $<

spp.a:socket.o listen_socket.o client_socket.o sockaddr.o
	ar rcs $@ $^

socket.o:socket.cpp socket.hpp
	$(CPP) -c $(CFLAGS) -o $@ $<

listen_socket.o:listen_socket.cpp listen_socket.hpp client_socket.hpp sockaddr.hpp
	$(CPP) -c $(CFLAGS) -o $@ $<

client_socket.o:client_socket.cpp client_socket.hpp socket.hpp sockaddr.hpp
	$(CPP) -c $(CFLAGS) -o $@ $<

sockaddr.o:sockaddr.cpp sockaddr.hpp
	$(CPP) -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -f echo
	rm -f spp.a