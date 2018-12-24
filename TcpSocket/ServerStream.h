#include "Server.h"

class ServerStream {

    //for singleton
    static ServerStream* instance;
    //tcp server
    Server* server;
    //id of thread
    pthread_t threadId;
    bool isListenning;
    ServerStream() { isListenning = false; }


public:
    static ServerStream* getInstance();

    void createServer(int port, int readSpeed);

    void listen();

    ~ServerStream();
};
