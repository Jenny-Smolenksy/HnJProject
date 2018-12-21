//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_VAR_H
#define HNJPROJECT_VAR_H


#include "Expression.h"

class Var : public Expression {
    string var;
public:
    explicit Var(string val);

    double calculate() override;

    double calculate(deque<string> p) override;


};


#endif //HNJPROJECT_VAR_H
