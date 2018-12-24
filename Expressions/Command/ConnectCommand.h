//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_CONNECT_H
#define HNJPROJECT_CONNECT_H


#include "Command.h"

class ConnectCommand : public Command {
public:
    int execute(deque<string> act) override;

};


#endif //HNJPROJECT_CONNECT_H
