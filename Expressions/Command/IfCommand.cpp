//
// Created by hilla on 12/18/18.
//

#include <iostream>
#include "IfCommand.h"

int IfCommand::execute(deque<string> act) {
    if (getCondition()) {
        for (Command *c:getCommands()) {
          //  c->execute();
        }
    }
    cout << "implement if" << endl;
}
