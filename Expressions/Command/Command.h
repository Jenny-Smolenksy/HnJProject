//
// Created by Jenny && Hilla
//

#include <string>
#include <vector>
#include <deque>


#ifndef HNJPROJECT_COMMAND_H
#define HNJPROJECT_COMMAND_H


using namespace std;

/**
 * Command
 */
class Command {
public:
    virtual int execute(deque<string> act) = 0;
};

#endif //HNJPROJECT_COMMAND_H