//
// Created by hilla on 12/18/18.
//

#include <iostream>
#include "PrintCommand.h"
#include "../../SymbolTable.h"
#include "../../ShuntingYard.h"

int PrintCommand::execute(deque<string> act) {
    SymbolsTable *s = SymbolsTable::getInstance();
    if (act[0].at(0) == '"') {
        //simple print
        string stringHolder;
        while (!act.empty()) {
            stringHolder += act.front() + " ";
            act.pop_front();
        }
        cout << stringHolder << endl;
    } else if (s->exist(act[0])) {
        //its a variable print its value
        cout << act[0] + " = " + to_string(s->getValue(act[0])) << endl;
    } else {
        //its an expression
        ShuntingYard *shuntingYard = ShuntingYard::getInstance();
        Expression *x = shuntingYard->stringToExpression(act[0]);
        //calculate it
        double val = x->calculate();
        //print it
        cout << to_string(val) << endl;
    }
    return 0;
}
