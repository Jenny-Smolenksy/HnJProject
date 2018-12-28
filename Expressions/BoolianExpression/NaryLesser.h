//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_NARYLESSER_H
#define HNJPROJECT_NARYLESSER_H


#include "BooleanExpression.h"

/**
 * Lesser or eqaul
 */
class NaryLesser : public BooleanExpression {
public:
    double calculate() override;

    NaryLesser(string r, string l);

};


#endif //HNJPROJECT_NARYLESSER_H
