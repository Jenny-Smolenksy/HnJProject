#include "ClientStream.h"
#define END_STR "\r\n"
#define GET "get"
#define SPACE " "
#define START_OF_VALUE "= '"
#define VALUE_END '\''
#define SET "set"


ClientStream *ClientStream::instance = nullptr;

/**
 * function of thread to send message
 * @param args
 * @return
 */
void* threadSendMessageFunc(void *args) {

    ClientStream::MESSAGE_PARAMS* params =
            (ClientStream::MESSAGE_PARAMS *)args;
    params->client->sendMessage(params->message);


    delete params;
}
/**
 * thread function to connect client
 * @param args
 * @return
 */
void* threadConnectFunc(void *args) {

    ClientStream::CONNECT_PARAMS* params =
            (ClientStream::CONNECT_PARAMS*)args;
    params->client->connectToServer(params->address, params->port);

    delete params;
}
/**
 * thread function to send message
 * @param args
 * @return
 */
void* threadSendMessageFeedback(void *args) {

    ClientStream::MESSAGE_PARAMS* params =
            (ClientStream::MESSAGE_PARAMS *)args;
    string result = params->client->sendMessageWithFeedback(params->message);

    params->message = "";
    params->message = result;
    return params;
}

/**
 * get object
 * @return
 */
ClientStream* ClientStream::getInstance() {
    if (instance == nullptr) {
        instance = new ClientStream();
    }
    return instance;
}

/**
 * connect client to server with gievn params
 * @param message
 * @param port
 * @return
 */
int ClientStream::connect(string message, int port) {

    CONNECT_PARAMS* params = new CONNECT_PARAMS{client, message, port};
    pthread_t threadId;
    try {
        pthread_create(&threadId, nullptr, threadConnectFunc, params);
        pthread_join(threadId, nullptr);
        cout << "client is connected" << endl;
    } catch (const char * s) {
        cout << s << endl;
        return -1;
    }
    return 0;
}
/**
 * send gievn message via client
 * @param message
 * @return
 */
int ClientStream::sendMessage(string message) {

    string messageToSend = message + END_STR;
    MESSAGE_PARAMS *params = new MESSAGE_PARAMS();
    params->client = client;
    params->message = messageToSend;

    pthread_t threadId;
    try {
        pthread_create(&threadId, nullptr, threadSendMessageFunc, params);
        pthread_join(threadId, nullptr);
    } catch (const char * s) {
        cout << s << endl;
        return -1;
    }
}
/**
 * send message via client, get response
 * @param message
 * @return
 */
string ClientStream::sendFeedbackMessage(string message) {

    string messageToSend = message + END_STR;

    MESSAGE_PARAMS *params = new MESSAGE_PARAMS();
    params->client = client;
    params->message = messageToSend;

    pthread_t threadId;
    try {
        pthread_create(&threadId, nullptr, threadSendMessageFeedback, params);
        void* returnValue;
        pthread_join(threadId, &returnValue);

    } catch (const char * s) {
        cout << s << endl;
    }
    string str = params->message;
    delete(params);
    return str;
}
/**
 * close all
 */
ClientStream::~ClientStream() {
    delete client;
}
/**
 * create message in get format
 * @param path
 * @return
 */
string ClientStream::messageFormatGet(string path) {
    string result = GET;
    result += SPACE;
    result += path;
    return result;
}
/**
 * create message in set format
 * @param path
 * @param value
 * @return
 */
string ClientStream::messageFormatSet(string path, string value) {
    string result = SET;
    result += SPACE;
    result += path;
    result += SPACE;
    result += value;
    return result;
}

/**
 * get double value according to format
 * @param message
 * @param path
 * @return
 */
double ClientStream::getValueFromMessage(string message, string path) {
    unsigned long currentPosition = 0;
    unsigned long endPosition;
    double currentValue = 0;
    string currentPath;
    int arrayIndex = 0;

    //go over the string
    (endPosition = message.find(SPACE));

    //get string until separator
    currentPath = message.substr(currentPosition, endPosition);
    message = message.erase(currentPosition, endPosition);

    if (currentPath.compare(path) != 0) {
        //not same path
        throw "wrong path from server";
    }

    if (message.find("none") != string::npos) {
        return 0; //not defined yet
    }
    //go over the string
    endPosition = message.find(START_OF_VALUE) -1;
    //get string from separator
    message = message.erase(currentPosition, endPosition + sizeof(START_OF_VALUE));
    //get end of value
    endPosition = message.find_first_of(VALUE_END);

    message = message.substr(currentPosition, endPosition);

    //convert to double value

    currentValue = stod(message);
    return currentValue;
}




