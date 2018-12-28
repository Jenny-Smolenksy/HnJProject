#include "Command.h"

class ExitCommand: public Command {
public:
    virtual int execute(deque<string> act);

};
