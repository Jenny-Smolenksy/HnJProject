//
// Created by hilla on 12/22/18.
//

#ifndef HNJPROJECT_LESSER_H
#define HNJPROJECT_LESSER_H


#include "BoolianExpression.h"

class Lesser: public BoolianExpression {
public:
    double calculate() override;
    Lesser(string r, string l);

};


#endif //HNJPROJECT_LESSER_H
