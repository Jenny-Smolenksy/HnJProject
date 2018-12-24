//
// Created by jenny on 12/24/18.
//

#include "Client.h"

class ClientStream {

    static ClientStream* instance;
    Client* client;
    ClientStream() {
        client = new Client();
    }


public:
    struct MESSAGE_PARAMS {
        Client* client;
        string message;
    };
    struct CONNECT_PARAMS {
        Client* client;
        string address;
        int port;
    };

    static ClientStream* getInstance();
    int connect(string address, int port);
    int sendMessage(string message);
    string sendFeedbackMessage(string message);
    string messageFormatSet(string path, string value);
    string messageFormatGet(string path);
    double getValueFromMessage(string message, string path);
    ~ClientStream();

};