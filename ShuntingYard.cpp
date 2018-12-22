#include <utility>

//
// Created by hilla on 12/20/18.
//

#include <list>
#include <stack>
#include "ShuntingYard.h"
#include "Utiies.h"
#include "Expressions/Binary/Plus.h"
#include "Expressions/Binary/Multiply.h"
#include "Expressions/Binary/Minus.h"
#include "Expressions/Binary/Div.h"
#include "Expressions/Unary/Neg.h"

#define DIV ","
#define RIGHT_B "("
#define LEFT_B ")"

/* Null, because instance will be initialized on demand. */
ShuntingYard *ShuntingYard::instance = nullptr;

ShuntingYard *ShuntingYard::getInstance() {
    //TODO: delete instance at the end
    //singleton instance:
    if (instance == nullptr) {
        instance = new ShuntingYard();
        instance->operators["+"] = 1;
        instance->operators["-"] = 1;
        instance->operators["*"] = 2;
        instance->operators["/"] = 2;

    }

    return instance;
}

deque<string> ShuntingYard::infixToPostfix(string parameters) {
    parameters = arrangeSpaces(parameters);
    deque<string> splited = Utiies::splitBy(parameters, ',');
    deque<string> output;
    deque<string> stack;
    string tmp;
    for (const string &token:splited) {
        if (!exist(token) && token != RIGHT_B && token != LEFT_B) {
            output.push_back(token);
        } else if (exist(token)) {
            while (!stack.empty() && greaterPrecedence(token, stack.front())) {
                tmp = stack.front();
                output.push_back(tmp);
                stack.pop_front();
            }
            stack.push_front(token);
        } else if (token == RIGHT_B) {
            stack.push_front(token);
        } else if (token == LEFT_B) {
            while (stack.front() != RIGHT_B) {
                tmp = stack.front();
                output.push_back(tmp);
                stack.pop_front();
                if (stack.empty()) {
                    throw "mismatch braces";
                }
            }
            stack.pop_front();
        }

    }
    while (!stack.empty()) {
        if (stack.front() == LEFT_B) {
            throw "mismatch braces";
        }
        tmp = stack.front();
        output.push_back(tmp);
        stack.pop_front();
    }
    return output;
}

Expression *ShuntingYard::stringToExpression(string parameters) {
    deque<string> postfix = infixToPostfix(std::move(parameters));
    if (!postfix.empty()) {
        return innerExp(&postfix);
    }
    return nullptr;
}

string ShuntingYard::arrangeSpaces(string parameter) {
    string buff;
    for (char i : parameter) {
        if (exist(charToString(i))) {
            buff = addOperator(buff, i);
        } else if (charToString(i) == RIGHT_B || charToString(i) == LEFT_B) {
            buff = addB(buff, i);
        } else if (i != ' ') {
            buff += i;
        }
    }
    return buff;
}

bool ShuntingYard::exist(string c) {
    return operators.count(c) != 0;
}

bool ShuntingYard::greaterPrecedence(string token, string other) {
    return (exist(other) && operators[other] >= operators[token]);
}

Expression *ShuntingYard::innerExp(deque<string> *exp) {
    stack<Expression *> stack;
    Expression *result = nullptr;
    while (!exp->empty()) {
        string token = exp->front();
        exp->pop_front();
        // operator
        if (exist(token) && token != "~") {
            Expression *b = stack.top();
            stack.pop();
            Expression *a = stack.top();
            stack.pop();
            if (token == "+") {
                result = new Plus(a, b);
            } else if (token == "*") {
                result = new Multiply(a, b);
            } else if (token == "-") {
                result = new Minus(a, b);
            } else if (token == "/") {
                result = new Div(a, b);
            }
        } else if (token == "~") {
            string neg = exp->front();
            exp->pop_front();
            if (isInteger(neg)) { // digit
                result = new Number(stod(neg));
            } else {
                result = new Var(neg);
            }
            result = new Neg(result);
        } else if (isInteger(token)) { // digit
            result = new Number(stod(token));
        } else {
            result = new Var(token);
        }
        if (result == nullptr) {
            throw "illegal math expression";
        }
        stack.push(result);
    }
    return stack.top();
}

bool ShuntingYard::isInteger(string p) {
    return p[0] <= '9' && p[0] >= 0;
}

string ShuntingYard::charToString(char c) {
    string p;
    p += c;
    return p;
}

string ShuntingYard::addOperator(string buff, char op) {
    unsigned long length = buff.size();
    string c;
    if (length >= 2) {
        c = charToString(buff[length - 2]);
    }
    if (buff.empty() || c == RIGHT_B || exist(c)) {
        //start of the string || first after braces || after an operator
        if (op == '-') {
            if (c == "+") {
                buff[length - 2] = op;
                return buff;
            }
            ///special unary flag
            buff += '~';
            buff += DIV;
        }
        return buff;
    }
    buff += DIV;
    buff += op;
    buff += DIV;
    return buff;
}

string ShuntingYard::addB(string buff, char b) {
    unsigned long length = buff.size();
    string c;
    if (length >= 2) {
        c = charToString(buff[length - 2]);
    }
    if (charToString(b) == RIGHT_B) {
        if (c == "~") {
            buff += '1';
            buff = addOperator(buff, '*');

        }
    }
    buff += DIV;
    buff += b;
    buff += DIV;
    return buff;
}

