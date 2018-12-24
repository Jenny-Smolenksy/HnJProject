#include <utility>

//
// Created by Jenny && Hilla
//

#include "BooleanExpression.h"
#include "../../ShuntingYard.h"

BooleanExpression::BooleanExpression(string r, string l) {
    ShuntingYard *shuntingYard = ShuntingYard::getInstance();
    right = shuntingYard->stringToExpression(std::move(r));
    left = shuntingYard->stringToExpression(std::move(l));


}

double BooleanExpression::calculate() {
    return 0;
}

double BooleanExpression::calculate(deque<string> p) {
    return 0;
}
