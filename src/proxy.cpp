#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

Class Proxy{
    private:
        int port = 0;
        int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    public:
        void start(){
            listen(serverSocket, 128);
            int clientSocket = accept(serverSocket, nullptr, nullptr);
            char buffer[4096] = {0};
            int bytesTotal = 1;
            string buffer_str = "";
            while(bytesTotal != 0){
                bytesTotal = recv(clientSocket, buffer, sizeof(buffer), 0);

                if(bytesTotal > 0){
                    buffer_str.append(buffer, bytesTotal);
                }
            }
        }
        void stop();
        Proxy(int port){
            this.port = port;
            sockaddr_in address;
            address.sin_family = AF_INET;
            address.sin_port = htons(port);
            address.sin_addr.s_addr = INADDR_ANY;
            bind(serverSocket, (struct sockaddr*)&address, sizeOf(address));
            thread t(start);
            t.join(); //blocks until start thread returns
        }
}