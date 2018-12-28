//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_DEDINEVARCOMMAND_H
#define HNJPROJECT_DEDINEVARCOMMAND_H


#include "Command.h"

class DefineVarCommand : public Command {
public:
    int execute(deque<string> act) override;

    int setValue(string symbol, double value);

    bool validName(string name);

    bool isSaveWord(string name);

};


#endif //HNJPROJECT_DEDINEVARCOMMAND_H
