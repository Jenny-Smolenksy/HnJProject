//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_BOOLIANEXPRESSION_H
#define HNJPROJECT_BOOLIANEXPRESSION_H


#include "../Expression.h"

/**
 * simple boolean Expression class to deal with boolian Expressions
 */
class BooleanExpression : public Expression {
protected:
    Expression *right = nullptr;
    Expression *left = nullptr;
public:
    explicit BooleanExpression(string r, string l);

    double calculate() override;

    double calculate(deque<string> p) override;


};


#endif //HNJPROJECT_BOOLIANEXPRESSION_H
