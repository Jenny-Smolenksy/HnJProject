#include <utility>

//
// Created by hilla on 12/20/18.
//

#include "UnaryExpression.h"
#include "../Var.h"
#include "../Number.h"


UnaryExpression::UnaryExpression(Expression *e) {
    exp = e;

}



double UnaryExpression::calculate() {
    return 0;
}

double UnaryExpression::calculate(deque<string> p) {
    return 0;
}
