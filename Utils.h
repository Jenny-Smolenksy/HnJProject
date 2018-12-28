//
// Created by Jenny && Hilla
//

#ifndef HNJPROJECT_UTIIES_H
#define HNJPROJECT_UTIIES_H

#include <vector>
#include <string>
#include <deque>

using namespace std;


class Utils {
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
    static bool isBooleanOperator(char op);

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
    static bool isAnOperator(char op);


    /**
     * remove unnecessary quote
     * @param original
     * @return
     */
    static string removeStrStr(string original);

};


#endif //HNJPROJECT_UTIIES_H
