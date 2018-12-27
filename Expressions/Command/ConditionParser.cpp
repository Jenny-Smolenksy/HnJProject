//
// Created by Jenny && Hilla
//

#include <unordered_set>
#include "ConditionParser.h"
#include "../BoolianExpression/Equals.h"
#include "../BoolianExpression/Greater.h"
#include "../BoolianExpression/Lesser.h"
#include "../BoolianExpression/NotEql.h"
#include "../BoolianExpression/NaryGreater.h"
#include "../BoolianExpression/NaryLesser.h"
#include "../../Utils.h"
#include "../../Lexer.h"


int ConditionParser::execute(deque<string> act) {
    return 0;
}

/**
 * set condition from a string
 * @param condition
 */
void ConditionParser::setCondition(string condition) {
    string r;
    string l;
    string op;
    bool next = false;
    for (char i : condition) {
        if (Utils::isBooleanOperator(i)) {
            //build operator/move on to next string
            next = true;
            op += i;
            continue;
        }
        if (!next) {
            //build first string
            r += i;
        } else {
            //build second
            l += i;
        }
    }
    finalSet(r, l, op);


}

/**
* set condition according to the operator
* @param r  right string
* @param l   left string
* @param op the operator
 */
void ConditionParser::finalSet(string r, string l, string op) {
    if (op == "==") {
        this->condition = new Equals(r, l);
    }
    if (op == ">") {
        this->condition = new Greater(r, l);
    }
    if (op == "<") {
        this->condition = new Lesser(r, l);
    }
    if (op == "!=") {
        this->condition = new NotEql(r, l);
    }
    if (op == ">=") {
        this->condition = new NaryGreater(r, l);
    }
    if (op == "<=") {
        this->condition = new NaryLesser(r, l);
    }
    if (this->condition == nullptr) {
        throw "how to compare";
    }

}

/**
 * set commands
 * @param commandsToseperate
 */
void ConditionParser::setCommands(deque<string> commandsToseperate) {
    while (!commandsToseperate.empty()) {
        deque<string> command;
        while (!commandsToseperate.empty() && commandsToseperate.front() != "DIVIDER") {
            if(commandsToseperate.front()=="if"||commandsToseperate.front()=="while"){
                command.push_back(commandsToseperate.front());
                commandsToseperate.pop_front();
                getScope(&commandsToseperate,&command);
                continue;
            }
            //read a single command
            command.push_back(commandsToseperate.front());
            commandsToseperate.pop_front();
        }
        if (!commandsToseperate.empty()) {
            commandsToseperate.pop_front();
        }
        //insert it to our set of comandsToseperate
        this->commands.push_back(command);

    }

}


/**
* set the condition and the commands in the while scope
* @param act all the information
 */
void ConditionParser::setParser(deque<string> act) {
    condition= nullptr;
    commands.clear();
    string conditionHolder;
    while (act.front() != "{") {
        //the condition is written until the scope starts
        conditionHolder += act.front();
        act.pop_front();
    }
    act.pop_front();
    //sets condition
    setCondition(conditionHolder);
    //removes "}"
    act.pop_front();
    //set commands
    setCommands(act);

}

void ConditionParser::getScope(deque<string> *lines, deque<string> *scopeCommand) {
    //while we didnt reach the end of the scope
    while (lines->front() != "}") {
        string commandPart=lines->front();
        if (commandPart == "while" || commandPart == "if") {
            lines->pop_front();
            scopeCommand->push_back(commandPart);
            //a scope with in a scope
            getScope(lines, scopeCommand);
            continue;

        }
        scopeCommand->push_back(commandPart);
        //remove this line
        lines->pop_front();
        if (lines->empty()) {
            //ended file without closing scope
            throw "ERROR! missing closing } to end the scope";
        }
    }
    scopeCommand->push_back(lines->front());
    lines->pop_front();
}




