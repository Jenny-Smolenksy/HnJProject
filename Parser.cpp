//
// Created by Jenny && Hilla
//

#include "Parser.h"

#include "Expressions/Command/ConnectCommand.h"
#include "Expressions/Command/PrintCommand.h"
#include "Expressions/Command/SleepCommand.h"
#include "SymbolTable.h"
#include "Expressions/Command/ConditionParser.h"
#include "Expressions/Command/LoopComand.h"
#include "Expressions/Command/OpenServerCommand.h"
#include "Expressions/Command/IfCommand.h"

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
    stringToCommandMap["var"] = new CommandExpression(new DefineVarCommand());
    expToDEL.push_back(stringToCommandMap["var"]);

    stringToCommandMap["openDataServer"] = new CommandExpression(new OpenServerComman());
    expToDEL.push_back(stringToCommandMap["openDataServer"]);

    stringToCommandMap["connect"] = new CommandExpression(new ConnectCommand());
    expToDEL.push_back(stringToCommandMap["connect"]);

    stringToCommandMap["print"] = new CommandExpression(new PrintCommand());
    expToDEL.push_back(stringToCommandMap["print"]);

    stringToCommandMap["sleep"] = new CommandExpression(new SleepCommand());
    expToDEL.push_back(stringToCommandMap["sleep"]);

    stringToCommandMap["while"] = new CommandExpression(new LoopComand());
    expToDEL.push_back(stringToCommandMap["while"]);

    stringToCommandMap["if"] = new CommandExpression(new IfCommand());
    expToDEL.push_back(stringToCommandMap["if"]);

}

/**
 *in charge of converting strings to commends and
 * execute them
 * @param commands  lexed file
 */
void Parser::runner(vector<deque<string>> commands) {
    //run each command
    for (deque<string> &command_line:commands) {
        if (command_line[0] == "exit") {
            break;
        }
        runCommand(command_line);
    }
}

/**
 * run s single lexed  command line
 * @param command
 */
void Parser::runCommand(deque<string> command) {
    CommandExpression *c = nullptr;
    SymbolsTable *s = SymbolsTable::getInstance();
    c = stringToCommandMap[command[0]];
    if (c == nullptr) {
        if (s->exist(command[0]) || s->isTempValue(command[0])) {
            //update existing var
            c = stringToCommandMap["var"];
            c->calculate(command);
        } else {
            throw "illegal command";
        }
    } else {
        //remove the defining command string
        command.pop_front();
        c->calculate(command);

    }

}

Parser::~Parser() {
    for (CommandExpression *c:expToDEL) {
        delete c;
    }
}
