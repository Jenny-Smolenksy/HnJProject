//
// Created by hilla on 12/20/18.
//

#include "Plus.h"

double Plus::calculate() {
    return right->calculate() + left->calculate();
}

Plus::Plus(Expression *r, Expression *l) : BinaryExpression(r, l) {

}


