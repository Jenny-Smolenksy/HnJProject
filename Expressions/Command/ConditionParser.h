//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_CONDITIONPARSER_H
#define HNJPROJECT_CONDITIONPARSER_H


#include "Command.h"
#include <list>

class ConditionParser : public Command {
    bool condition;
    list<Command*> commands;
public:
    int execute(deque<string> act) override;

    bool getCondition() {
        return condition;
    }

    list<Command*> getCommands() {
        return commands;
    }

};


#endif //HNJPROJECT_CONDITIONPARSER_H
