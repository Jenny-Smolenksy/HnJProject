//
// Created by hilla on 12/22/18.
//

#include "Lesser.h"

Lesser::Lesser(string r, string l) : BoolianExpression(r, l) {

}

double Lesser::calculate() {
    if (right->calculate() < left->calculate()) {
        return 1;
    }
    return 0;
}
