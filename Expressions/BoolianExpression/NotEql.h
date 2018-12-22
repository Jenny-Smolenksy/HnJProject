//
// Created by hilla on 12/22/18.
//

#ifndef HNJPROJECT_NOTEQL_H
#define HNJPROJECT_NOTEQL_H


#include "BoolianExpression.h"

class NotEql : public BoolianExpression {
public:
    double calculate() override;
   NotEql(string r, string l);

};


#endif //HNJPROJECT_NOTEQL_H
