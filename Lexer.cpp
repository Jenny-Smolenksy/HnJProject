//
// Created by hilla on 12/19/18.
//

#include <fstream>
#include <sstream>
#include <algorithm>
#include "Lexer.h"
#include "Utiies.h"

#define DIV '_'


Lexer *Lexer::instance = nullptr;

vector<deque<string>> Lexer::lexFromFile(string fileName) {
    vector<deque<string>> result;
    ifstream fin;
    fin.open(fileName);
    string line;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            if (line.empty()) {
                continue;
            }
            deque<string> command = splitCommand(line);
            result.push_back(command);

        }
        fin.close();
    }
    return result;
}

deque<string> Lexer::splitCommand(string line) {
    line = seperateLine(line);
    return Utiies::splitBy(line, DIV);
}

Lexer *Lexer::getInstance() {
    //TODO: delete instance at the end
    //singleton instance:
    if (instance == nullptr) {
        instance = new Lexer();
        instance->operators.push_back('+');
        instance->operators.push_back('-');
        instance->operators.push_back('*');
        instance->operators.push_back('/');
    }

    return instance;
}

string Lexer::seperateLine(string line) {
    string buff;
    char space = ' ';
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '=') {
            buff += DIV;
        }
        else if (line[i] != space) {
            buff += line[i];
        } else if (line[i] == space && find(operators.begin(), operators.end(), line[i + 1]) != operators.end()) {
            //space before operator - skip it
            continue;
        } else if (line[i] == space && !buff.empty()) {
            buff += DIV;
        }


    }
    return buff;
}







