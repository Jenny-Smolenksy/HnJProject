//
// Created by Jenny && Hilla
//

#include <iostream>
#include "IfCommand.h"
#include "../../Parser.h"

int IfCommand::execute(deque<string> act) {
    setParser(act);
    Parser *parser = Parser::getInstance();
    if (this->condition->calculate() > 0) {
        parser->runner(this->commands);
    }
    return 0;
}
