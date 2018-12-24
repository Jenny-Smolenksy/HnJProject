//
// Created by hilla on 12/18/18.
//

#include <iostream>
#include "SleepCommand.h"
#include "../Expression.h"
#include "../../ShuntingYard.h"
#include "../../SymbolTable.h"
#include <pthread.h>

#include <unistd.h>

int SleepCommand::execute(deque<string> act) {
    SymbolsTable *s = SymbolsTable::getInstance();

    ShuntingYard *shuntingYard = ShuntingYard::getInstance();
    Expression *x = shuntingYard->stringToExpression(act[0]);
    double val = x->calculate();
    cout << "sleep for " +  to_string(val) << endl;
    sleep((int)val);


    return 0;
}
