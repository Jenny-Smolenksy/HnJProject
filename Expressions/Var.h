//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_VAR_H
#define HNJPROJECT_VAR_H


#include "Expression.h"

/**
 * Var
 */
class Var : public Expression {
    string var;
public:
    explicit Var(string val);

    double calculate() override;

    double calculate(deque<string> p) override;


};


#endif //HNJPROJECT_VAR_H
