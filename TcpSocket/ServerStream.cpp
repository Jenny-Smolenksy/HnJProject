#include "ServerStream.h"


ServerStream *ServerStream::instance = nullptr;

struct PARAMS {
    Server* server;
    int socketFd;
};

/**
 * get object
 * @return
 */
ServerStream* ServerStream::getInstance() {
    if (instance == nullptr) {
        instance = new ServerStream();
    }
    return instance;
}

/**
 * thread function for server listen
 * @param arg
 * @return
 */
void* threadFuncWaitForConnection(void* arg) {

    PARAMS* params = (PARAMS*)arg;
    int socketFd = params->server->waitForConnection();

    params->socketFd = socketFd;
    return params;

}
/**
 * thread function for server listen
 * @param arg
 * @return
 */
void* threadFuncListen(void* arg) {

    PARAMS* params = (PARAMS*)arg;
    try {
        params->server->listen(params->socketFd);
    } catch (invalid_argument& e) {
        throw "server disconnected";
    }
    delete params;

}

/**
 * thread function for server listen
 * @param arg
 * @return
 */
void* threadFuncStopListen(void* arg) {

    PARAMS* params = (PARAMS*)arg;
    params->server->stopListen();
}

/**
 * create server with given params
 * @param port
 * @param readSpeed
 */
void ServerStream::createServer(int port, int readSpeed) {
    this->server = new Server(port, readSpeed);
}

/**
 * open new thread to listen
 */
void ServerStream::startListen() {

    pthread_t threadIdWait;
    int sockId = 0;
    PARAMS* params = new PARAMS{server, sockId};
    void* result;

    cout << "opening server.." << endl;
    pthread_create(&threadIdWait, nullptr, threadFuncWaitForConnection, params);
    pthread_join(threadIdWait, &result);
    params = (PARAMS*)result;

    pthread_create(&threadId, nullptr, threadFuncListen, params);
}
/**
 * distory object
 */
ServerStream::~ServerStream() {
    //kill or close server if needed

    pthread_t pthreadIdClose;
    PARAMS* params = new PARAMS{server, 0};

   pthread_create(&pthreadIdClose, nullptr, threadFuncStopListen, params);
   pthread_join(pthreadIdClose, nullptr);
   pthread_join(threadId, nullptr);
   delete params;
   delete server;
}