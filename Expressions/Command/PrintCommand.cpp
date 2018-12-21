//
// Created by hilla on 12/18/18.
//

#include <iostream>
#include "PrintCommand.h"
#include "../../SymbolTable.h"

int PrintCommand::execute(deque<string> act) {
    SymbolsTable *s = SymbolsTable::getInstance();
    if (s->exict(act[0])) {
        cout << act[0] + " = " + to_string(s->getValue(act[0])) << endl;
    } else {
        cout << act[0] << endl;
    }
    return 0;
}
