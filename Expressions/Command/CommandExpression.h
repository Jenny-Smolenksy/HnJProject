//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_COMMANDEXPRESSION_H
#define HNJPROJECT_COMMANDEXPRESSION_H


#include "Command.h"
#include "../Expression.h"
#include "DefineVarCommand.h"

/**
 * Command Expression
 */
class CommandExpression : public Expression {
    Command *c;
public:

    double calculate() override;

    double calculate(deque<string>) override;


    explicit CommandExpression(Command *pCommand);
};


#endif //HNJPROJECT_COMMANDEXPRESSION_H
