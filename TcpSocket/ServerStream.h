#include "Server.h"

class ServerStream {

    //for singleton
    static ServerStream* instance;
    //tcp server
    Server* server;
    //id of thread
    pthread_t threadId;
    ServerStream() {  }


public:
    static ServerStream* getInstance();

    void createServer(int port, int readSpeed);

    void startListen();

    ~ServerStream();
};
