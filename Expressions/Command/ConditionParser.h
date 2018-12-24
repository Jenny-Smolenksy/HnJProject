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
    Expression *condition;
    vector<deque<string>> commands;
public:
    /**
    * set the condition and the commands in the while scope
    * @param act all the information
    */
    void setParser(deque<string> act);

    /**
     * execute
     * @param act
     * @return
     */
    int execute(deque<string> act) override;

    /**
     * set condition
     * @param condition
     */
    void setCondition(string condition);

    /**
     * set condition according to the operator
     * @param r  right string
     * @param l   left string
     * @param op ther operator
     */
    void finalSet(string r, string l, string op);

    /**
     * set commands
     * @param comandsToseperate
     */
    void setCommands(deque<string> comandsToseperate);


};


#endif //HNJPROJECT_CONDITIONPARSER_H
