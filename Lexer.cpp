#include <utility>

//
// Created by hilla on 12/19/18.
//

#include <fstream>
#include <sstream>
#include <algorithm>
#include "Lexer.h"
#include "Utiies.h"

#define DIV ','


Lexer *Lexer::instance = nullptr;

Lexer *Lexer::getInstance() {
    //TODO: delete instance at the end
    //singleton instance:
    if (instance == nullptr) {
        instance = new Lexer();
    }

    return instance;
}

/**
 * lexer action - from file to vector of deque of strings
 * @param fileName
 * @return
 */
vector<deque<string>> Lexer::lexFromFile(string fileName) {
    vector<deque<string>> result;
    deque<string> lines = getLines(std::move(fileName));
    deque<string> command;
    while (!lines.empty()) {
        //each line into a splited command
        command = splitCommand(lines.front());
        if (command[0] == "while") {
            //gets scope
            lines.pop_front();
            getScope(&lines, &command);
        }
        result.push_back(command);
        lines.pop_front();
    }
    return result;
}

/**
 * separate a line to command parts
 * @param line
 * @return deque of strings
 */
deque<string> Lexer::splitCommand(string line) {
    //initial work on the string to take it to significant peaces
    line = separateLine(line);
    return Utiies::splitBy(line, DIV);
}


/**
 * initial work on the string to take it to significant peaces
 * mark them using the DIV flag
 * @param line
 * @return seperated line
 */
string Lexer::separateLine(string line) {
    string buff;
    char space = ' ';
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '=') {
            buff += DIV;
        } else if (line[i] != space) {
            buff += line[i];
        } else if (line[i] == space && ((Utiies::isMathOperator(line[i-1])) || Utiies::isMathOperator(line[i+1]))) {
            //space before  or after operator - skip it
            continue;
        } else if (line[i] == space && !buff.empty()) {
            buff += DIV;
        }


    }
    return buff;
}




/**
 * initial take of the command lines from the script file
 * @param fileName
 * @return deque of string- lines of command
 */
deque<string> Lexer::getLines(string fileName) {
    deque<string> result;
    ifstream fin;
    fin.open(fileName);
    string line;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            if (line.empty()) {
                continue;
            }
            if (line[line.length()] == '}') {
                //makes sure closing scope brace will only be in a new line
                line.erase(line.length() - 1, line.length());
                result.emplace_back("}");
            }
            result.push_back(line);

        }
        fin.close();
    }
    return result;
}



/**
 * Arrange for a scope to be as one command deque with a DIVIDER flag
 * separates the commands from each other
 * @param lines -info from file
 * @param scopeCommand the final scope command
 */
void Lexer::getScope(deque<string> *lines, deque<string> *scopeCommand) {
    deque<string> singleCommand;
    //while we didnt reach the end of the scope
    while (lines->front() != "}") {
        //flag start of a new scopeCommand
        scopeCommand->push_back("DIVIDER");

        //separate the line to scopeCommand parts
        singleCommand = splitCommand(lines->front());

        if (singleCommand[0] == "while" || singleCommand[0] == "if") {
            //a scope with in a scope
            getScope(lines, scopeCommand);

        }
        //each scopeCommand part insert to the scope scopeCommand
        for (const string &c:singleCommand) {

            scopeCommand->push_back(c);
        }
        //remove this line
        lines->pop_front();
        if (lines->empty()) {
            //ended file without closing scope
            throw "ERROR! missing closing } to end the scope";
        }
    }


}










