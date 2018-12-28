#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

using namespace std;

class Client {
    int sockfd;
    struct sockaddr_in serverAddr;
    struct hostent *server;
    bool isConnected;

public:

    Client() = default;

    void connectToServer(string serverAddress, int portNumber);
    void sendMessage(string message);
    string sendMessageWithFeedback(string message);

    ~Client();
};