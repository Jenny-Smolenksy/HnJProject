//
// Created by hilla on 12/18/18.
//

#include <iostream>
#include "SleepCommand.h"
#include "../Expression.h"
#include "../../ShuntingYard.h"
#include "../../SymbolTable.h"

int SleepCommand::execute(deque<string> act) {
    SymbolsTable *s = SymbolsTable::getInstance();
    if(s->exict(act[0])){
        //if its var
        cout << "sleep for " + to_string(s->getValue(act[0])) << endl;
    } else{
        ShuntingYard *shuntingYard = ShuntingYard::getInstance();
        Expression *x = shuntingYard->stringToExpression(act[0]);
        double val = x->calculate();
        cout << "sleep for " +  to_string(val) << endl;
    }

    return 0;
}
