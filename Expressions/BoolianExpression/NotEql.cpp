//
// Created by hilla on 12/22/18.
//

#include "NotEql.h"

NotEql::NotEql(string r, string l) : BoolianExpression(r, l) {

}

double NotEql::calculate() {
    if (right->calculate() != left->calculate()) {
        return 1;
    }
    return 0;
}
