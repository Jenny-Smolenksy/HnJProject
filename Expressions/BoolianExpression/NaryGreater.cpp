//
// Created by Jenny && Hilla
//

#include "NaryGreater.h"
#include <utility>

NaryGreater::NaryGreater(string r, string l) : BooleanExpression(std::move(r), std::move(l)) {

}

double NaryGreater::calculate() {
    if (right->calculate() >= left->calculate()) {
        return 1;
    }
    return 0;
}
