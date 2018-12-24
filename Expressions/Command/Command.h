//
// Created by hilla on 12/18/18.
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