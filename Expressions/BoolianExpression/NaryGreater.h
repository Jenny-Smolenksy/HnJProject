//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_NARYGREATER_H
#define HNJPROJECT_NARYGREATER_H


#include "BooleanExpression.h"

/**
 * Greater or Equal
 */
class NaryGreater : public BooleanExpression {
public:
    double calculate() override;

    NaryGreater(string r, string l);

};


#endif //HNJPROJECT_NARYGREATER_H
