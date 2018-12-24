//
// Created by Jenny && Hilla
//

#include "NaryLesser.h"
#include <utility>

NaryLesser::NaryLesser(string r, string l) : BooleanExpression(std::move(r), std::move(l)) {

}

double NaryLesser::calculate() {
    if (right->calculate() <= left->calculate()) {
        return 1;
    }
    return 0;
}
