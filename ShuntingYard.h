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

    ShuntingYard() = default;

    map<string, int> operators;

public:
    static ShuntingYard *getInstance();

    deque<string> infixToPostfix(string parameters);

    Expression *stringToExpression(string parameters);

    string arangeSpaces(string parameter);

    bool exict(string c);

    bool greaterPrecedence(string token,string other);

    bool isInteger(string p);

    Expression* innerExp(deque<string> *exp);

    string charToString(char c);

    string addOprator(string buff, char op);

    string addB(string buff, char b);
};

#endif //HNJPROJECT_EXPRESSIONSCALCULATOR_H
