//
// Created by hilla on 12/18/18.
//

#include <iostream>
#include "DefineVarCommand.h"
#include "../../SymbolTable.h"
#include "../../ShuntingYard.h"
#include "../../TcpSocket/ClientStream.h"
#include "../../Utiies.h"
#include <sstream>


int DefineVarCommand::execute(deque<string> act) {
    SymbolsTable *symbolsTable = SymbolsTable::getInstance();

    //case the command is to bind
    if (act[1] == "bind") {


        string secondParam = act[2];

        if (!symbolsTable->exist(secondParam)) {
            //check if in quotes
            if (secondParam[0] != '"' || secondParam[secondParam.length()-1] != '"') {
                throw "cannot bind to unknown value";
            }
            secondParam = Utiies::removeStrStr(act[2]);
        }

        symbolsTable->addSymbol(act[0], secondParam);

        return 0;
    }

    ShuntingYard *shuntingYard = ShuntingYard::getInstance();
    Expression *x = shuntingYard->stringToExpression(act[1]);
    double val = x->calculate();


    //if binded value
    if (symbolsTable->exist(act[0])) {
            //get path and set new value via client
            string path = symbolsTable->getPath(act[0]);
            setValue(path, val);
        return 0;
    }
    //temp value
    symbolsTable->addTempValue(act[0], val);

}

/**
 * set value
 * @param path
 * @param value
 * @return
 */
int DefineVarCommand::setValue(string path, double value) {


    //get double value to string
    std::ostringstream strs;
    strs << value;
    string valueStr = strs.str();

    ClientStream* clientStream = ClientStream::getInstance();

    //create message
    string message = clientStream->messageFormatSet(path, valueStr);

    //send message
    clientStream->sendMessage(message);

}

