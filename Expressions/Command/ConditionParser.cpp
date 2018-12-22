//
// Created by hilla on 12/18/18.
//

#include <unordered_set>
#include <algorithm>
#include "ConditionParser.h"
#include "../BoolianExpression/Equals.h"
#include "../BoolianExpression/Greater.h"
#include "../BoolianExpression/Lesser.h"
#include "../BoolianExpression/NotEql.h"
#include "../BoolianExpression/NaryGreater.h"
#include "../BoolianExpression/NaryLesser.h"


int ConditionParser::execute(deque<string> act) {
    return 0;
}

void ConditionParser::setCondition(string condition) {
    setOperator();
    string r;
    string l;
    string op;
    bool next = false;
    for (int i = 0; i < condition.length(); i++) {
        if (exist(condition[i])) {
            next = true;
            op += condition[i];
            continue;
        }
        if (!next) {
            r += condition[i];
        } else {
            l += condition[i];
        }
    }
    finalSet(r, l, op);


}

void ConditionParser::setOperator() {
    operators.push_back('<');
    operators.push_back('>');
    operators.push_back('=');
    operators.push_back('!');

}

bool ConditionParser::exist(char op) {
    return find(operators.begin(), operators.end(), op) != operators.end();
}

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

}

void ConditionParser::setCommands(deque<string> comandsToseperate) {
    while (!comandsToseperate.empty()) {
        deque<string> command;
        while (!comandsToseperate.empty() && comandsToseperate.front() != "DIVIDER") {
            //read a single command
            command.push_back(comandsToseperate.front());
            comandsToseperate.pop_front();
        }
        if (!comandsToseperate.empty()) {
            comandsToseperate.pop_front();
        }
        //insert it to our set of comandsToseperate
        this->commands.push_back(command);

    }

}

void ConditionParser::setParser(deque<string> act) {
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





//TODO HANDLE CONDITION AND COMMAND