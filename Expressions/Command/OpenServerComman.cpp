//
// Created by hilla on 12/18/18.
//

#include <iostream>
#include "OpenServerComman.h"
#include "../../ShuntingYard.h"
#include "../Expression.h"


int OpenServerComman::execute(deque<string> act) {
    ShuntingYard *shuntingYard = ShuntingYard::getInstance();
    Expression *x = shuntingYard->stringToExpression(act[0]);
    Expression *y = shuntingYard->stringToExpression(act[1]);
    double val1 = x->calculate();
    double val2 = y->calculate();
    cout << "need to open server " + to_string(val1) + " " + to_string(val2) << endl;
    return 0;
}
