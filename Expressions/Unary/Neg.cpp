//
// Created by hilla on 12/20/18.
//

#include "Neg.h"

double Neg::calculate() {
    return -exp->calculate();
}

Neg::Neg(Expression *e) : UnaryExpression(e) {

}
