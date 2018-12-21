//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_DIV_H
#define HNJPROJECT_DIV_H


#include "BinaryExpression.h"

class Div : public BinaryExpression{
public:
    double calculate() override;
    Div(Expression *r, Expression *l);

};


#endif //HNJPROJECT_DIV_H
