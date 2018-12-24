//
// Created by Jenny && Hilla
//

#include "NotEql.h"
#include <utility>

NotEql::NotEql(string r, string l) : BooleanExpression(std::move(r), std::move(l)) {

}

double NotEql::calculate() {
    if (right->calculate() != left->calculate()) {
        return 1;
    }
    return 0;
}
