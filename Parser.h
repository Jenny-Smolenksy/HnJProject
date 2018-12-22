//
// Created by hilla on 12/19/18.
//

#ifndef HNJPROJECT_PARSER_H
#define HNJPROJECT_PARSER_H

#include <vector>
#include <string>
#include <map>
#include <queue>
#include "Expressions/Command/CommandExpression.h"

using namespace std;

class Parser {
     //TODO ONLY AFTER BUILDING EXPRESSION
    map<string, CommandExpression *> stringToCommandMap;
    static Parser *instance;

    Parser() = default;

    void setMap();

public:
    // Static access method
    static Parser *getInstance();

    void runner(vector<deque<string>> commands);

    void runCommand(deque<string> command);


};


#endif //HNJPROJECT_PARSER_H
