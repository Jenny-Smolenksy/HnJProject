//
// Created by Jenny && Hilla
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

    virtual ~Expression() = default;

};

#endif //HNJPROJECT_EXPRESSION_H