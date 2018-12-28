//
// Created by Jenny && Hilla
//

#include <iostream>
#include "LoopComand.h"
#include "../../Parser.h"

int LoopComand::execute(deque<string> act) {
    setParser(act);
    Parser *parser = Parser::getInstance();
    /*this loop will run all the commends using the parser runner
     * only if the condition is met                           */
    while (this->condition->calculate() > 0) {
        parser->runner(this->commands);
    }
    return 0;
}





