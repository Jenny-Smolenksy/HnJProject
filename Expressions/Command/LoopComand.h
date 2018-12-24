//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_LOOPCOMAND_H
#define HNJPROJECT_LOOPCOMAND_H


#include "ConditionParser.h"

/**
 * while command
 */
class LoopComand : public ConditionParser {
public:
    int execute(deque<string> act) override;


};


#endif //HNJPROJECT_LOOPCOMAND_H
