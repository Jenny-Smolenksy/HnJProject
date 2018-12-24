#include <iostream>
#include "OpenServerCommand.h"
#include "../../ShuntingYard.h"
#include "../Expression.h"
#include <pthread.h>
#include "../../TcpSocket/ServerStream.h"


int OpenServerComman::execute(deque<string> act) {
    ShuntingYard *shuntingYard = ShuntingYard::getInstance();
    Expression *x = shuntingYard->stringToExpression(act[0]);
    Expression *y = shuntingYard->stringToExpression(act[1]);
    double val1 = x->calculate();
    double val2 = y->calculate();

    try {

        //create server
       ServerStream* serverStream = ServerStream::getInstance();
       serverStream->createServer((int)val1, (int)val2);
       serverStream->startListen();

    } catch (const char* s) {
        cout << s << endl;
        return -1;
    }

    return 0;
}
