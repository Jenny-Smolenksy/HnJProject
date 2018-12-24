//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_CONNECT_H
#define HNJPROJECT_CONNECT_H


#include "Command.h"

class ConnectCommand : public Command {
public:
    virtual int execute(deque<string> act);

};


#endif //HNJPROJECT_CONNECT_H
