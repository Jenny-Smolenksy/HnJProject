//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_UNARYEXPRESSION_H
#define HNJPROJECT_UNARYEXPRESSION_H


#include "../Expression.h"

/**
 * Unary expressions
 */
class UnaryExpression : public Expression {
protected:
    Expression *exp = nullptr;
public:

    explicit UnaryExpression(Expression *e);

    double calculate() override;

    double calculate(deque<string> p) override;



};


#endif //HNJPROJECT_UNARYEXPRESSION_H
