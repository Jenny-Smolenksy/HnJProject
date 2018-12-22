//
// Created by hilla on 12/22/18.
//

#ifndef HNJPROJECT_NARYGREATER_H
#define HNJPROJECT_NARYGREATER_H


#include "BoolianExpression.h"

class NaryGreater : public BoolianExpression {
public:
    double calculate() override;
    NaryGreater(string r, string l);

};


#endif //HNJPROJECT_NARYGREATER_H
