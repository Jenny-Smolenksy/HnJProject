#include <string>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

using namespace std;

class Client {
    int sockfd;
    struct sockaddr_in serverAddr;
    struct hostent *server;

public:

    Client(std::string serverAddress, int portNumber);

    void sendMessage(string message);

    ~Client();
};