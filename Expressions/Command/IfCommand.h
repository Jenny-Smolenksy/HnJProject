//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_IFCOMMAND_H
#define HNJPROJECT_IFCOMMAND_H


#include "ConditionParser.h"

/**
 * If command
 */
class IfCommand : public ConditionParser {

public:
    int execute(deque<string> act) override;


};


#endif //HNJPROJECT_IFCOMMAND_H
