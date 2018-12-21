#include <iostream>
#include "Lexer.h"
#include "ShuntingYard.h"
#include "SymbolTable.h"
#include "Parser.h"

using namespace std;

int main(int arg, char *argv[]) {
    std::cout << "BSD, Hello, Hilla!" << std::endl;
    Lexer *lex = Lexer::getInstance();
    vector<deque<string>> res = lex->lexFromFile(argv[1]);
    Parser *p = Parser::getInstance();
    p->runner(res);
    ShuntingYard *calculator = ShuntingYard::getInstance();
    std::cout << "3+(4/2)*5" << endl;
    Expression *e = calculator->stringToExpression("3+(4/2)*5");
    double x = e->calculate();
    //  std::cout<< calculator->infixToPostfix("3+(4/2)*5")<<endl;

    //lets try build a lexer without loss of generality daaa


    return 0;
}

/*
int main() {

    try {

        string passed = " passed";
        string failed = " failed";
        string result;
        int count = 0;
        SymbolsTable *symbolTable = SymbolsTable::getInstance();
        symbolTable->setSymbol("x", 7);
        symbolTable->setSymbol("y", 3);
        symbolTable->setSymbol("abc", -1);
        //symbolTable->setSymbol("rt#",4);
        string str1 = "5+3-10";  // -2     works
        string str2 = "5*3*2/6";   // 5       works
        string str3 = "5*(4+3)";   // 35      works
        string str4 = "(x+y-abc)";    // 11       works
        string str5 = "((x-y)/2)";      // 2         works
        string str6 = "14+32/16+1+4";   // 21        works
        string str7 = "(1)+(-2)+(-10)";    // -11     works
        string str8 = "1.5+3/6";    // 2                works
        string str9 = "5*5/5*3";      // 15           works
        string str10 = "5*-2";    // -10           works
        string str11 = "5/-(3-2)";      // -5
        string str12 = "5+3*1-2+3+10+11-10-11-3+2-3-4+(3*3)-9";  // 1
        string str13 = "4/ab.c";       // error     works
        string str14 = "4/(abc-abc)";    // error
        string str15 = "x/0";          // error
        string str16 = "2+rt#";    // error


        ShuntingYard *sy = ShuntingYard::getInstance();

        sy->stringToExpression(str1)->calculate() == -2 ? (result = passed) : (result = failed);
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str2)->calculate() == 5 ? (result = passed) : (result = failed);
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str3)->calculate() == 35 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str4)->calculate() == 11 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str5)->calculate() == 2 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str6)->calculate() == 21 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str7)->calculate() == -11 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str8)->calculate() == 2 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str9)->calculate() == 15 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str10)->calculate() == -10 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str11)->calculate() == -5 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        sy->stringToExpression(str12)->calculate() == 1 ? result = passed : result = failed;
        count++;
        cout << count << result << endl;

        try {
            sy->stringToExpression(str13)->calculate();
            count++;
            result = failed;
            cout << count << result << endl;
        } catch (...) {
            count++;
            result = passed;
            cout << count << result << endl;
        }


        try {
            sy->stringToExpression(str14)->calculate();
            count++;
            result = failed;
            cout << count << result << endl;
        } catch (...) {
            count++;
            result = passed;
            cout << count << result << endl;
        }

        try {
            sy->stringToExpression(str15)->calculate();
            count++;
            result = failed;
            cout << count << result << endl;
        } catch (...) {
            count++;
            result = passed;
            cout << count << result << endl;
        }

        try {
            sy->stringToExpression(str16)->calculate();
            count++;
            result = failed;
            cout << count << result << endl;
        } catch (...) {
            count++;
            result = passed;
            cout << count << result << endl;
        }


    } catch (...) {
        cout << "illegal mathematical expression" << endl;
    }

    return 0;
}
*/