//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_IFCOMMAND_H
#define HNJPROJECT_IFCOMMAND_H


#include "ConditionParser.h"

class IfCommand : public ConditionParser{
public:
    int execute(deque<string> act) override;

};


#endif //HNJPROJECT_IFCOMMAND_H
