//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_MULTIPLY_H
#define HNJPROJECT_MULTIPLY_H


#include "BinaryExpression.h"

/**
 * simple Multiply class to calculate Muliply Expressions
 */
class Multiply : public BinaryExpression {
public:
    double calculate() override;

    Multiply(Expression *r, Expression *l);

};


#endif //HNJPROJECT_MULTIPLY_H
