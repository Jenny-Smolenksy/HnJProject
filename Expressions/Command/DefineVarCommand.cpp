//
// Created by hilla on 12/18/18.
//

#include <iostream>
#include "DefineVarCommand.h"
#include "../../SymbolTable.h"
#include "../../ShuntingYard.h"

int DefineVarCommand::execute(deque<string> act) {
    SymbolsTable *s = SymbolsTable::getInstance();
    if (act[1] == "bind") {
        s->addSymbol(act[0], act[2]);
        cout << act[0] + " need to bind to "+act[2] << endl;
        return 0;
    }

    ShuntingYard *shuntingYard = ShuntingYard::getInstance();
    Expression *x = shuntingYard->stringToExpression(act[1]);
    double val = x->calculate();

    s->addSymbol(act[0], to_string(val));

    cout << act[0] + "=" + to_string(val) << endl;
}
