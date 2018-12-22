//
// Created by hilla on 12/19/18.
//

#include "Parser.h"
#include "Expressions/Command/DefineVarCommand.h"
#include "Expressions/Command/OpenServerComman.h"
#include "Expressions/Command/ConnectCommand.h"
#include "Expressions/Command/PrintCommand.h"
#include "Expressions/Command/SleepCommand.h"
#include "SymbolTable.h"
#include "Expressions/Command/ConditionParser.h"
#include "Expressions/Command/LoopComand.h"

Parser *Parser::instance = nullptr;

Parser *Parser::getInstance() {
    //singleton instance:
    if (instance == nullptr) {
        instance = new Parser();
        instance->setMap();

    }

    return instance;
}

void Parser::setMap() {
    //TODO ERASE
    //TODO REPLACE FOR EXPRESSION
    stringToCommandMap["var"] = new CommandExpression(new DefineVarCommand());
    stringToCommandMap["openDataServer"] = new CommandExpression(new OpenServerComman());
    stringToCommandMap["connect"] = new CommandExpression(new ConnectCommand());
    stringToCommandMap["print"] = new CommandExpression(new PrintCommand());
    stringToCommandMap["sleep"] = new CommandExpression(new SleepCommand());
    stringToCommandMap["sleep"] = new CommandExpression(new SleepCommand());
    stringToCommandMap["while"] = new CommandExpression(new LoopComand());
}

void Parser::runner(vector<deque<string>> commands) {
    for (deque<string> &command_line:commands) {
        runCommand(command_line);
    }
}

void Parser::runCommand(deque<string> command) {
    CommandExpression *c = nullptr;
    SymbolsTable *s = SymbolsTable::getInstance();
    c = stringToCommandMap[command[0]];
    if (c == nullptr) {
        if (s->exict(command[0])) {
            //update existing var
            c = stringToCommandMap["var"];
            c->calculate(command);
        } else{
            throw "unsepported command";
        }
    } else {
        command.pop_front();
        c->calculate(command);

    }

}
