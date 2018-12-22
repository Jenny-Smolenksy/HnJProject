//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_PLUS_H
#define HNJPROJECT_PLUS_H


#include "BinaryExpression.h"

/**
 * simple plus class to calculate Plus Expressions
 */
class Plus : public BinaryExpression {
public:
    double calculate() override;

    Plus(Expression *r, Expression *l);


};


#endif //HNJPROJECT_PLUS_H
