//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_DEDINEVARCOMMAND_H
#define HNJPROJECT_DEDINEVARCOMMAND_H


#include "Command.h"

class DefineVarCommand : public Command {
public:
    virtual int execute(deque<string> act);

    int setValue(string symbol, double value);

};


#endif //HNJPROJECT_DEDINEVARCOMMAND_H
