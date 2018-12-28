//
// Created by hilla on 12/20/18.
//

#include "Neg.h"

double Neg::calculate() {
    if (exp->calculate() == 0) {
        return 0;
    }
    return -exp->calculate();
}

Neg::Neg(Expression *e) : UnaryExpression(e) {

}
