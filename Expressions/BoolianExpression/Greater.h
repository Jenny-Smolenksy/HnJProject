//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_GREATER_H
#define HNJPROJECT_GREATER_H


#include "BooleanExpression.h"

/***
 * Greater
 */
class Greater : public BooleanExpression {
public:
    double calculate() override;

    Greater(string r, string l);

};


#endif //HNJPROJECT_GREATER_H
