//
// Created by hilla on 12/20/18.
//

#include "Div.h"

double Div::calculate() {
    if (left->calculate() == 0) {
        throw "division by zero is frobbiden";
    }
    return right->calculate() / left->calculate();
}

Div::Div(Expression *r, Expression *l) : BinaryExpression(r, l) {

}
