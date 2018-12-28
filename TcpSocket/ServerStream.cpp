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
    params->server->listen(params->socketFd);
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

    cout << "client connected, listening to client" << endl;
    pthread_create(&threadId, nullptr, threadFuncListen, params);
}
/**
 * distory object
 */
ServerStream::~ServerStream() {
    //kill or close server if needed

    pthread_t pthreadId;
    PARAMS* params = new PARAMS{server, 0};

 //   pthread_create(&pthreadId, nullptr, threadFuncWaitForConnection, params);
    delete server;
}

