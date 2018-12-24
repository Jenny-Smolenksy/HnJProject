#include "ServerStream.h"


ServerStream *ServerStream::instance = nullptr;

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
void* threadFuncServer(void* arg) {

    ((Server*)arg)->listen();
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
void ServerStream::listen() {
    pthread_create(&threadId, nullptr, threadFuncServer, server);
    isListenning = true;
}
/**
 * distory object
 */
ServerStream::~ServerStream() {
    //kill or close server if needed
    delete server;
}

