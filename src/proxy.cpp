#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

Class proxy{
    int port = 0;
    void start();
    void stop();
    proxy(int port){
        this.port = port;
        this.start();
    }
}