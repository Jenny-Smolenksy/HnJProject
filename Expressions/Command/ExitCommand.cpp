#include "ExitCommand.h"
#include "../../TcpSocket/ClientStream.h"
#include "../../TcpSocket/ServerStream.h"

int ExitCommand::execute(deque<string> act) {

    ClientStream* clientStream = ClientStream::getInstance();
    delete(clientStream);
    ServerStream* serverStream = ServerStream::getInstance();
    delete(serverStream);
}