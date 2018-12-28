//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_DIV_H
#define HNJPROJECT_DIV_H


#include "BinaryExpression.h"

/**
 * simple Div class to calculate Div Expressions
 */
class Div : public BinaryExpression {
public:
    double calculate() override;

    Div(Expression *r, Expression *l);

};


#endif //HNJPROJECT_DIV_H
