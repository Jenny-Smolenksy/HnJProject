//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_LESSER_H
#define HNJPROJECT_LESSER_H


#include "BooleanExpression.h"

/**
 * Lesser
 */
class Lesser : public BooleanExpression {
public:
    double calculate() override;

    Lesser(string r, string l);

};


#endif //HNJPROJECT_LESSER_H
