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

    Lexer() = default;

public:
    // Static access method
    static Lexer *getInstance();

    /**
    * lexer action - from file to vector of deque of strings
    * @param fileName
    * @return
    */
    vector<deque<string>> lexFromFile(string fileName);

    /**
    * initial work on the string to take it to significant peaces
    * mark them using the DIV flag
    * @param line
    * @return seperated line
    */
    string separateLine(string line);

    /**
    * separate a line to command parts
    * @param line
    * @return deque of strings
    */
    deque<string> splitCommand(string line);


    /**
    * initial take of the command lines from the script file
    * @param fileName
    * @return deque of string- lines of command
    */
    deque<string> getLines(string fileName);


    /**
    * Arrange for a scope to be as one command deque with a DIVIDER flag
    * separates the commands from each other
    * @param lines -info from file
    * @param scopeCommand the final scope command
     */
    void getScope(deque<string> *lines, deque<string> *scopeCommand);


};


#endif //HNJPROJECT_LEXER_H
