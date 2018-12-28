//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_EQUALS_H
#define HNJPROJECT_EQUALS_H


#include "BooleanExpression.h"

/**
 * Equals
 */
class Equals : public BooleanExpression {
public:
    double calculate() override;

    Equals(string r, string l);

};


#endif //HNJPROJECT_EQUALS_H
