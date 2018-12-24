//
// Created by hilla on 12/20/18.
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
