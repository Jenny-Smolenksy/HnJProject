//
// Created by hilla on 12/22/18.
//

#ifndef HNJPROJECT_GREATER_H
#define HNJPROJECT_GREATER_H


#include "BoolianExpression.h"

class Greater: public BoolianExpression {
public:
    double calculate() override;
    Greater(string r, string l);

};


#endif //HNJPROJECT_GREATER_H
