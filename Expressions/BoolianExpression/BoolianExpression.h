//
// Created by hilla on 12/22/18.
//

#ifndef HNJPROJECT_BOOLIANEXPRESSION_H
#define HNJPROJECT_BOOLIANEXPRESSION_H


#include "../Expression.h"

class BoolianExpression : public Expression {
protected:
    Expression *right = nullptr;
    Expression *left = nullptr;
public:
    explicit BoolianExpression(string r, string l);

    double calculate() override;

    double calculate(deque<string> p) override;


};


#endif //HNJPROJECT_BOOLIANEXPRESSION_H
