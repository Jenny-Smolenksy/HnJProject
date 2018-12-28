#include <utility>

//
// Created by Jenny && Hilla
//

#include "Var.h"
#include "../SymbolTable.h"
#include "../TcpSocket/ClientStream.h"


/**
 * create val
 * @param val
 */
Var::Var(string val) {
    var = std::move(val);

}


double Var::calculate() {
    SymbolsTable *s = SymbolsTable::getInstance();

    //check if var in temp values
    if(s->isTempValue(var)) {
        return s->getTempValue(var);
    }

    //check if var is common symbol
    if(s->isCommonSymbol(var)) {
        return s->getCommonValue(var);
    }

    //get from server
    if (s->exist(var)) {

        ClientStream* clientStream = ClientStream::getInstance();

        string path = s->getPath(var);
        //create message
        string message = clientStream->messageFormatGet(path);
        //send message
        string result = clientStream->sendFeedbackMessage(message);

        //get value from message
        double value = clientStream->getValueFromMessage(result, path);
        return value;

    }
    throw "this variable is not in the system";
}

double Var::calculate(deque<string> p) {
    return 0;
}

