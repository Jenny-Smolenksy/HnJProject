#include <utility>

#include <utility>

//
// Created by hilla on 12/22/18.
//

#include "BoolianExpression.h"
#include "../../ShuntingYard.h"

BoolianExpression::BoolianExpression(string r, string l) {
    ShuntingYard *shuntingYard = ShuntingYard::getInstance();
    right = shuntingYard->stringToExpression(std::move(r));
    left = shuntingYard->stringToExpression(std::move(l));


}

double BoolianExpression::calculate() {
    return 0;
}

double BoolianExpression::calculate(deque<string> p) {
    return 0;
}
