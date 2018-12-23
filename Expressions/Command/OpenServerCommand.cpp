
#include <iostream>
#include "OpenServerCommand.h"
#include "../../ShuntingYard.h"
#include "../Expression.h"
#include <pthread.h>
#include "../../TcpSocket/Server.h"

void* thread_func(void* arg) {

    ((Server*)arg)->listen();
}


int OpenServerComman::execute(deque<string> act) {
    ShuntingYard *shuntingYard = ShuntingYard::getInstance();
    Expression *x = shuntingYard->stringToExpression(act[0]);
    Expression *y = shuntingYard->stringToExpression(act[1]);
    double val1 = x->calculate();
    double val2 = y->calculate();

    try {

        Server *server = new Server((int)val1);
        //TODO: check if nedded speed params also
        pthread_t threadId;
        pthread_create(&threadId, nullptr, thread_func, server);
    } catch (const char* s) { }

    cout << "need to open server " + to_string(val1) + " " + to_string(val2) << endl;
    return 0;
}
