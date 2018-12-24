//
// Created by Jenny && Hilla
//

#include "Div.h"

double Div::calculate() {
    if (left->calculate() == 0) {
        throw "division by zero is not legal";
    }
    return right->calculate() / left->calculate();
}

Div::Div(Expression *r, Expression *l) : BinaryExpression(r, l) {

}
