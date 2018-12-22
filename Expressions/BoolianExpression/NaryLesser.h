//
// Created by hilla on 12/22/18.
//

#ifndef HNJPROJECT_NARYLESSER_H
#define HNJPROJECT_NARYLESSER_H


#include "BoolianExpression.h"

class NaryLesser : public BoolianExpression {
public:
    double calculate() override;
    NaryLesser(string r, string l);

};



#endif //HNJPROJECT_NARYLESSER_H
