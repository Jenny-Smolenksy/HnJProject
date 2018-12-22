//
// Created by hilla on 12/22/18.
//

#ifndef HNJPROJECT_EQUALS_H
#define HNJPROJECT_EQUALS_H


#include "BoolianExpression.h"

class Equals: public BoolianExpression {
public:
    double calculate() override;
    Equals(string r, string l);

};


#endif //HNJPROJECT_EQUALS_H
