//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_PRINTCOMMAND_H
#define HNJPROJECT_PRINTCOMMAND_H


#include "Command.h"

/**
 * print command
 */
class PrintCommand : public Command {
public:
    int execute(deque<string> act) override;

};


#endif //HNJPROJECT_PRINTCOMMAND_H
