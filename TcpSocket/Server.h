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
    SymbolsTable *symbolsTable;

public:

    Server(int portNumber);

    void listen();

    ~Server();
};