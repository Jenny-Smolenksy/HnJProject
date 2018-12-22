#include <utility>

//
// Created by hilla on 12/20/18.
//

#include "Var.h"
#include "../SymbolTable.h"

Var::Var(string val) {
    var = std::move(val);

}

double Var::calculate() {
    SymbolsTable *s = SymbolsTable::getInstance();
    if (s->exist(var)) {
        return s->getValue(var);
    } else {
        //TODO: bring back later and check this
        //throw "this variable is not in the system";
    }
}

double Var::calculate(deque<string> p) {
    return 0;
}

