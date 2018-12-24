//
// Created by hilla on 12/20/18.
//

#include <sstream>
#include "Utiies.h"

deque<string> Utiies::splitBy(string line, char c) {

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

bool Utiies::isBoolianOperator(char op) {
    return (op == '=' || op == '>' || op == '!' || op == '<');
}

bool Utiies::isMathOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

bool Utiies::isAnOperaror(char op) {
    return isMathOperator(op) || isBoolianOperator(op);
}

string Utiies::removeStrStr(string original) {

    size_t pos = std::string::npos;
    string result = "";

    for (int i = 0 ; i < original.length(); i++) {
        if(original[i] != '"')
            result += original[i];
    }
    return result;
}