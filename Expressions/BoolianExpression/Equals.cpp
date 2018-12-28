//
// Created by Jenny && Hilla
//

#include "Equals.h"
#include <utility>

double Equals::calculate() {
    if (right->calculate() == left->calculate()) {
        return 1;
    }
    return 0;
}

Equals::Equals(string r, string l) : BooleanExpression(std::move(r), std::move(l)) {

}
