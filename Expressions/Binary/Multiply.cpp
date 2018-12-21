//
// Created by hilla on 12/20/18.
//

#include "Multiply.h"

double Multiply::calculate() {
    return right->calculate() * left->calculate();
}

Multiply::Multiply(Expression *r, Expression *l) : BinaryExpression(r, l) {

}
