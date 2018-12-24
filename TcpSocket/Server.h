#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <map>
#include <iostream>
#include "../SymbolTable.h"

//TODO add if needed the seed 10
class Server {
    int sockfd;
    SymbolsTable* symbolsTable;
    int  timesPerSec;

public:

    Server(int portNumber, int timesPerSec);
    void listen();
    ~Server();
};