//
// Created by hilla on 12/18/18.
//

#include <iostream>
#include "ConnectCommand.h"
#include "../../ShuntingYard.h"
#include "../../TcpSocket/ClientStream.h"


int ConnectCommand::execute(deque<string> act) {

        ShuntingYard *shuntingYard = ShuntingYard::getInstance();

        string serverAddress = act[0];
        Expression *y = shuntingYard->stringToExpression(act[1]);
        double val2 = y->calculate();

        ClientStream *clientStream = ClientStream::getInstance();

        //create client with given params
        clientStream->connect(serverAddress, (int) val2);


    return 0;
}