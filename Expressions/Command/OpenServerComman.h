//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_OPENDATASERVER_H
#define HNJPROJECT_OPENDATASERVER_H


#include "Command.h"

/**
 * open server comand
 */
class OpenServerComman : public Command {
public:
    int execute(deque<string> act) override;

};


#endif //HNJPROJECT_OPENDATASERVER_H
