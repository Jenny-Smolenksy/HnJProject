//
// Created by hilla on 12/22/18.
//

#include "Equals.h"

double Equals::calculate() {
    if (right->calculate() == left->calculate()) {
        return 1;
    }
    return 0;
}

Equals::Equals(string r, string l) : BoolianExpression(r, l) {

}
