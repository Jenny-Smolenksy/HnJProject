//
// Created by Jenny && Hilla
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
    map<string, CommandExpression *> stringToCommandMap;
    static Parser *instance;
    vector<CommandExpression *> expToDEL;

    Parser() = default;

    void setMap();

public:
    // Static access method
    static Parser *getInstance();

    /**
     *in charge of converting strings to commends and
     * execute them
     * @param commands  lexed file
     */
    void runner(vector<deque<string>> commands);

    /**
     * run a single lexed command line
     * @param command
     */
    void runCommand(deque<string> command);

    /***
     * erase allocated memory
     */
    virtual ~Parser();


};


#endif //HNJPROJECT_PARSER_H
