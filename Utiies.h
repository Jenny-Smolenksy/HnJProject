//
// Created by hilla on 12/20/18.
//

#ifndef HNJPROJECT_UTIIES_H
#define HNJPROJECT_UTIIES_H

#include <vector>
#include <string>
#include <deque>

using namespace std;


class Utiies {
public:
    /**
     * split a string according to specific char
     * @param line
     * @param c
     * @return
     */
    static deque<string> splitBy(string line, char c);

    /**
     * check if valid operator
     * @param op
     * @return
     */
    static bool isBoolianOperator(char op);

    /**
     * check if valid operator
     * @param op
     * @return
     */
    static bool isMathOperator(char op);

    /**
     * check id its boolian or math operator
     * @param op
     * @return
     */
    static bool isAnOperaror(char op);

    static string removeStrStr(string original);

};


#endif //HNJPROJECT_UTIIES_H
