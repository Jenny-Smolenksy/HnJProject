#include "Server.h"
#include <iostream>
#include <sstream>
#include <strings.h>

#define PACKET_SIZE 256
#define MAX_WAITING 5
#define ZERO 0
#define MILISEC 1000

using namespace std;

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
}
/**
 * start listening on given port
 */
void Server::listen() {

    int newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in cli_addr = {};
    int  n;

    ::listen(sockfd, MAX_WAITING);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < ZERO) {
        throw "ERROR on accept";
    }

    /* If connection is established then start communicating */
    while(true) {
        bzero(buffer, PACKET_SIZE);
        //read bytes
        n = (int)read(newsockfd, buffer, (PACKET_SIZE - sizeof(char)));

        //empty packet - lost connection
        if (n < ZERO){
            return;
        }

        cout << "data from simulator:" << endl;
        cout << buffer << endl;

        //update values
        symbolsTable->updateValues(buffer);
        sleep(timesPerSec);
    }
}
/**
 * destructor for server
 */
Server::~Server() {
    //close socket
    close(sockfd);
}
