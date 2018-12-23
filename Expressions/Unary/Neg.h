//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_NEG_H
#define HNJPROJECT_NEG_H


#include "UnaryExpression.h"

class Neg : public UnaryExpression {
public:
    double calculate() override;

    Neg(Expression *e);


};


#endif //HNJPROJECT_NEG_H
