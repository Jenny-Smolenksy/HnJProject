//
// Created by hilla on 12/19/18.
//

#ifndef HNJPROJECT_LEXER_H
#define HNJPROJECT_LEXER_H

#include <vector>
#include <string>
#include <list>
#include <deque>

using namespace std;

class Lexer {
    static Lexer *instance;
    vector<char> operators;

    Lexer() = default;

public:
    // Static access method
    static Lexer *getInstance();

    vector<deque<string>> lexFromFile(string fileName);

    string seperateLine(string line);

    deque<string> splitCommand(string line);


};


#endif //HNJPROJECT_LEXER_H
