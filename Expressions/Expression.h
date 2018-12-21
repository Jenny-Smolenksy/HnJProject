//
// Created by hilla on 12/19/18.
//
#include <string>
#include <vector>
#include <deque>

#ifndef HNJPROJECT_EXPRESSION_H
#define HNJPROJECT_EXPRESSION_H


using namespace std;

class Expression {

public:
    virtual double calculate() = 0;

    virtual double calculate(deque<string> p) = 0;

};

#endif //HNJPROJECT_EXPRESSION_H