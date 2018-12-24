//
// Created by Jenny && Hilla
//

#include "Greater.h"
#include <utility>

double Greater::calculate() {
    if (right->calculate() > left->calculate()) {
        return 1;
    }
    return 0;
}

Greater::Greater(string r, string l) : BooleanExpression(std::move(r), std::move(l)) {

}
