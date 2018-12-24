#include <utility>

//
// Created by Jenny && Hilla
//

#include <iostream>
#include "DefineVarCommand.h"
#include "../../SymbolTable.h"
#include "../../ShuntingYard.h"
#include "../../TcpSocket/ClientStream.h"
#include "../../Utils.h"
#include <sstream>

int DefineVarCommand::execute(deque<string> act) {
    if (!validName(act[0])) {
        throw "not a valid name";
    }
    SymbolsTable *symbolsTable = SymbolsTable::getInstance();

    //case the command is to bind
    if (act[1] == "bind") {
        string s = Utils::removeStrStr(act[2]);
        symbolsTable->addSymbol(act[0], s);

        return 0;
    }

    ShuntingYard *shuntingYard = ShuntingYard::getInstance();
    Expression *x = shuntingYard->stringToExpression(act[1]);
    double val = x->calculate();


    //if binded value
    if (symbolsTable->exist(act[0])) {
        try {
            //get path and set new value via client
            string path = symbolsTable->getPath(act[0]);
            setValue(path, val);

        } catch (const char *message) {
            cout << message << endl;
            return -1;
        }
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

    ClientStream *clientStream = ClientStream::getInstance();

    //create message
    string message = clientStream->messageFormatSet(std::move(path), valueStr);

    //send message
    clientStream->sendMessage(message);

}

bool DefineVarCommand::validName(string name) {
    if (isSaveWord(name)) {
        //saved word
        return false;
    }
    if (isdigit(name[0])) {
        //starts with a number
        return false;
    }
    for (char i :name) {
        if (!(isdigit(i) || isalpha(i) || i == '_')) {
            //not a valid character
            return false;
        }
    }
    return true;
}

bool DefineVarCommand::isSaveWord(string name) {
    return (name == "if" || name == "var" || name == "while" || name == "print" || name == "sleep" ||
            name == "connect" || name == "exit" || name == "openDataServer");
}

