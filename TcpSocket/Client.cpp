#include <strings.h>
#include "Client.h"

#define ZERO 0
#define PACKET_SIZE 256

/**
 * create tcp client
 * @param serverAddress to connect to
 * @param portNumber to connect to
 */
Client::Client(string serverAddress, int portNumber) {

    // open socket AF_INET for IPv4 protocol, SOCK_STREAM for TCP protocol
    sockfd = socket(AF_INET, SOCK_STREAM, ZERO);

    //check if error on opening
    if (sockfd < ZERO) {
        throw "error opening socket";
    }

    //set server address as given
    server = gethostbyname(serverAddress.c_str());

    if (server == nullptr) {
        throw "ERROR, no such host";
    }

    //set socket params for tcp, ip adress and port as given
    bzero((char *) &this->serverAddr, sizeof(this->serverAddr));
    this->serverAddr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&this->serverAddr.sin_addr.s_addr, (size_t )server->h_length);
    this->serverAddr.sin_port = htons((u_int16_t )portNumber);

    /* connect to the server */
    if (connect(sockfd, (struct sockaddr*)&this->serverAddr, sizeof(this->serverAddr)) < ZERO) {
        throw "wrong server ip";
    }
}
/**
 * send message to server
 * @param message string to send
 */
void Client::sendMessage(string message) {

    //Send message to the server
    int resultCode = (int)write(sockfd, message.c_str(), message.length());

    //case failed
    if (resultCode < ZERO) {

        //try to reconnect
        if (connect(sockfd, (struct sockaddr*)&this->serverAddr, sizeof(this->serverAddr)) < ZERO) {
            //failed to reconnect
            throw "ERROR writing to socket";
        } else {
            //reconnected successfully - resend message
            resultCode = (int)write(sockfd, message.c_str(), message.length());
        }
    }

    //check message sent
    if (resultCode < ZERO) {
        throw "ERROR writing to socket";
    }

    /* read response for server - optional
    char buffer[PACKET_SIZE];
    // Now read server response
    bzero(buffer,PACKET_SIZE);
    resultCode =  (int)read(sockfd, buffer, PACKET_SIZE);
    std::cout << buffer << std::endl;

    if (resultCode < 0) {
        throw "ERROR reading from socket";
    }
     */
}
/**
 * destructor for client
 */
Client::~Client() {
    //close connection to server
    close(sockfd);
}