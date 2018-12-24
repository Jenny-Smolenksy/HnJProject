//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_NOTEQL_H
#define HNJPROJECT_NOTEQL_H


#include "BooleanExpression.h"

/**
 * Not eqal
 */
class NotEql : public BooleanExpression {
public:
    double calculate() override;

    NotEql(string r, string l);

};


#endif //HNJPROJECT_NOTEQL_H
