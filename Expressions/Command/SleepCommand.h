//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_SLEEPCOMMAND_H
#define HNJPROJECT_SLEEPCOMMAND_H


#include "Command.h"

class SleepCommand : public Command {
public:
    int execute(deque<string> act) override;

};


#endif //HNJPROJECT_SLEEPCOMMAND_H
