//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_NUMBER_H
#define HNJPROJECT_NUMBER_H


#include "Expression.h"

/**
 * Number
 */
class Number : public Expression {
    double num;
public:
    explicit Number(double val);

    double calculate() override;

    double calculate(deque<string> p);
};


#endif //HNJPROJECT_NUMBER_H
