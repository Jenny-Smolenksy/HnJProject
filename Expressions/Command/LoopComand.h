//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_LOOPCOMAND_H
#define HNJPROJECT_LOOPCOMAND_H


#include "ConditionParser.h"

class LoopComand : public ConditionParser{
public:
    int execute(deque<string> act) override;

};


#endif //HNJPROJECT_LOOPCOMAND_H
