//
// Created by Jenny && Hilla
//

#include "CommandExpression.h"

double CommandExpression::calculate() {
    return 0;
}


CommandExpression::CommandExpression(Command *pCommand) {
    c = pCommand;

}

double CommandExpression::calculate(deque<string> commands) {
    return c->execute(commands);
}
