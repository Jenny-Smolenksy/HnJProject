//
// Created by Jenny && Hilla
//

#include <sstream>
#include "Utils.h"

deque<string> Utils::splitBy(string line, char c) {

    stringstream easy2split(line);
    string part;
    deque<string> allparts;

    while (getline(easy2split, part, c)) {
        if (part.empty()) {
            continue;
        }
        allparts.push_back(part);
    }
    return allparts;
}

bool Utils::isBooleanOperator(char op) {
    return (op == '=' || op == '>' || op == '!' || op == '<');
}

bool Utils::isMathOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

bool Utils::isAnOperator(char op) {
    return isMathOperator(op) || isBooleanOperator(op);
}

string Utils::removeStrStr(string original) {
    string result;

    for (char i : original) {
        if(i != '"')
            result += i;
    }
    return result;
}