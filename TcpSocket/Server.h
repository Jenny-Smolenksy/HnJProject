#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <map>
#include <iostream>
#include "../SymbolTable.h"

class Server {
    int sockfd;
    SymbolsTable* symbolsTable;
    int  timesPerSec;
    bool running;

public:

    Server(int portNumber, int timesPerSec);
    void listen(int currentSocketFd);
    int waitForConnection();
    ~Server();
    void stopListen();
};