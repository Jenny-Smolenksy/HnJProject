//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_CONDITIONPARSER_H
#define HNJPROJECT_CONDITIONPARSER_H


#include "Command.h"
#include "../Expression.h"
#include <list>

class ConditionParser : public Command {
protected:
    Expression* condition;
    vector<deque<string>> commands;
    vector<char> operators;
public:
    /**
    * set the condition and the commands in the while scope
    * @param act all the information
    */
    void setParser(deque<string> act);

    int execute(deque<string> act) override;

    void setCondition(string condition);

    void finalSet(string r, string l, string op);

    void  setCommands(deque<string> comandsToseperate);

    void setOperator();

    bool exist(char op);
};


#endif //HNJPROJECT_CONDITIONPARSER_H
