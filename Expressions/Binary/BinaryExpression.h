//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_BINARYEXPRESSION_H
#define HNJPROJECT_BINARYEXPRESSION_H

#include "../Expression.h"
#include "../Var.h"
#include "../Number.h"

/**
 * simple abstract class to deal with binary Expressions
 */
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
