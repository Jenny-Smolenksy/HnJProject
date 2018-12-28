#include "Server.h"
#include <iostream>
#include <sstream>
#include <strings.h>

#define BUFFER_SIZE 256
#define MAX_WAITING 5
#define ZERO 0
#define MILISEC 1000

using namespace std;
pthread_mutex_t serverRunningMutex;
/**
 * create new tcp server
 * @param portNumber to listen to
 */
Server::Server(int portNumber, int timesPerSec) {
    struct sockaddr_in serv_addr = {};

    //AF_INET = ipv4 , SOCK_STREAM = tcp
    sockfd = socket(AF_INET, SOCK_STREAM, ZERO);

    if (sockfd < ZERO) {
        throw "ERROR opening socket";
    }

    //Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    //set socket params
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port =  htons((u_int16_t )portNumber);

    //Now bind the host address using bind() call.
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < ZERO) {
        throw "ERROR on binding";
    }
    symbolsTable = SymbolsTable::getInstance();
    this->timesPerSec = timesPerSec / MILISEC;
    this->running = false;
    pthread_mutex_init(&serverRunningMutex, nullptr);
}
/**
 * server waiting for connection, stop when a client enters
 * @return
 */
int Server::waitForConnection() {
    int currentSocketFd, clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in cli_addr = {};
    int  n;

    ::listen(sockfd, MAX_WAITING);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    currentSocketFd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (currentSocketFd < ZERO) {
        throw "ERROR on accept";
    }

    bzero(buffer, BUFFER_SIZE);
    //read bytes
    n = (int)read(currentSocketFd, buffer, (BUFFER_SIZE - sizeof(char)));

    //empty packet - lost connection
    if (n < ZERO){
        return -1;
    }

    this->running = true;
    //cout << "simulator connected" << endl;

    //update values
    symbolsTable->updateValues(buffer);

    return currentSocketFd;
}


/**
 * start listening on given port
 */
void Server::listen(int currentSocketFd) {

    char buffer[BUFFER_SIZE];
    int  n;
    if(currentSocketFd == -1) {
        return; //nothing to listen to
    }

    /* If connection is established then start communicating */
    while(true) {
        bzero(buffer, BUFFER_SIZE);
        //read bytes
        n = (int)read(currentSocketFd, buffer, (BUFFER_SIZE - sizeof(char)));

        //empty packet - lost connection
        if (n < ZERO){
            running = false;
            //pthread_exit(nullptr);
        }

       // cout << "data from simulator:" << endl;
       // cout << buffer << endl;

        //update values
        symbolsTable->updateValues(buffer);
        sleep((unsigned int)timesPerSec);

        pthread_mutex_lock(&serverRunningMutex);
        if (running == false) {
            //release lock
            pthread_mutex_unlock(&serverRunningMutex);
            break;
        }
        //release lock
        pthread_mutex_unlock(&serverRunningMutex);
    }
}

void Server::stopListen() {

    pthread_mutex_lock(&serverRunningMutex);
    running = false;
    //release lock
    pthread_mutex_unlock(&serverRunningMutex);
}
/**
 * destructor for server
 */
Server::~Server() {
    //close socket
    close(sockfd);
}
