#include <utility>

#include <iostream>
#include "Lexer.h"
#include "ShuntingYard.h"
#include "SymbolTable.h"
#include "Parser.h"

using namespace std;

/**
 * get a while scope from the user
 * @return
 */
deque<string> getScope() {
    deque<string> lines;
    string line;
    bool inner = false;
    while (getline(cin, line)) {
        if (line.empty()) {
            continue;
        }
        if (line[line.length() - 1] == '{') {
            inner = true;
        }
        if (line[line.length() - 1] == '}') {
            //makes sure closing scope brace will only be in a new line
            line.erase(line.length() - 1, line.length());
            lines.emplace_back("}");
            if (inner) {
                //finish reading inner scope
                inner = false;
            } else {
                lines.push_back(line);
                break;
            }
        }
        lines.push_back(line);

    }
    return lines;


}

/**
 * read from CMd
 */
void runFromCommandLine() {
    string line;
    while (true) {
        getline(cin, line);
        Lexer *lex = Lexer::getInstance();
        Parser *p = Parser::getInstance();
        deque<string> command = lex->splitCommand(line);
        if (command[0] == "while" || command[0] == "if") {
            //read a scope and them execute it
            deque<string> scope = getScope();
            lex->getScope(&scope, &command);
        }
        p->runCommand(command);
    }

}

/**
 * read from script file
 * @param fileName
 */
void runFromFile(string fileName) {

    Lexer *lex = Lexer::getInstance();
    vector<deque<string>> res;
    res = lex->lexFromFile(std::move(fileName));
    Parser *p = Parser::getInstance();
    p->runner(res);


}

int main(int arg, char *argv[]) {
    vector<deque<string>> res;
    if (arg == 2) {
        runFromFile(argv[1]);
    } else {
        runFromCommandLine();
    }

    return 0;
}
