//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_EXPRESSIONSCALCULATOR_H
#define HNJPROJECT_EXPRESSIONSCALCULATOR_H

#include <string>
#include <map>
#include <deque>
#include "Expressions/Expression.h"

using namespace std;

class ShuntingYard {
private:
    static ShuntingYard *instance;
    vector<Expression*> expToDel;

    ShuntingYard() = default;

    map<string, int> operators;

public:
    static ShuntingYard *getInstance();

    /**
     * convert string to a postfix form
     * @param parameters
     * @return
     */
    deque<string> infixToPostfix(string parameters);

    /**
     * converts string to expressions
     * @param parameters
     * @return
     */
    Expression *stringToExpression(string parameters);

    /**
     * itarate a string and arrange spaces correctly
     * @param parameter
     * @return
     */
    string arrangeSpaces(string parameter);

    /**
     * check id its an operaor
     * @param c
     * @return
     */
    bool exist(string c);

    /**
     * check for priority
     * @param token
     * @param other
     * @return
     */
    bool greaterPrecedence(string token, string other);

    /**
     * check if a string is decimal
     * @param p
     * @return
     */
    bool isInteger(string p);

    /**
     * build an expression
     * @param exp
     * @return
     */
    Expression *innerExp(deque<string> *exp);

    /**
     * char to string
     * @param c
     * @return
     */
    string charToString(char c);

    /**
     * add operator carefully
     * @param buff
     * @param op
     * @return
     */
    string addOperator(string buff, char op);

    /**
     * add closing braces carefully
     * @param buff
     * @param b
     * @return
     */
    string addB(string buff, char b);

    ~ShuntingYard();
};

#endif //HNJPROJECT_EXPRESSIONSCALCULATOR_H
