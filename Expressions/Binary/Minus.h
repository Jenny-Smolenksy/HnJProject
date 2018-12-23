//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_MINUS_H
#define HNJPROJECT_MINUS_H


#include "BinaryExpression.h"

/**
 * simple minus class to calculate minus Expressions
 */
class Minus : public BinaryExpression {
public:
    double calculate() override;

    Minus(Expression *r, Expression *l);

};


#endif //HNJPROJECT_MINUS_H
