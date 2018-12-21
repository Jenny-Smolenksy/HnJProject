//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_BINARYEXPRESSION_H
#define HNJPROJECT_BINARYEXPRESSION_H

#include "../Expression.h"
#include "../Var.h"
#include "../Number.h"

class BinaryExpression : public Expression {
protected:
    Expression *right = nullptr;
    Expression *left = nullptr;
public:

    explicit BinaryExpression(Expression *r, Expression *l);

    double calculate() override;

    double calculate(deque<string> p) override;


};


#endif //HNJPROJECT_BINARYEXPRESSION_H
