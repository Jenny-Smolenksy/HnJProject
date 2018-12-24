//
// Created by Jenny && Hilla
//

#include "Lesser.h"
#include <utility>

Lesser::Lesser(string r, string l) : BooleanExpression(std::move(r), std::move(l)) {

}

double Lesser::calculate() {
    if (right->calculate() < left->calculate()) {
        return 1;
    }
    return 0;
}
