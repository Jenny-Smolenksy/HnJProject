//
// Created by hilla on 12/20/18.
//

#include "Minus.h"

double Minus::calculate() {
    return right->calculate() - left->calculate();
}

Minus::Minus(Expression *r, Expression *l) : BinaryExpression(r, l) {

}
