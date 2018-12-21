//
// Created by hilla on 12/18/18.
//

#include "SymbolTable.h"

/* Null, because instance will be initialized on demand. */
SymbolsTable *SymbolsTable::instance = nullptr;

SymbolsTable *SymbolsTable::getInstance() {
    //TODO: delete instance at the end
    //singleton instance:
    if (instance == nullptr) {
        instance = new SymbolsTable();

    }

    return instance;
}

void SymbolsTable::setSymbol(string symbol, double value) {
    symbolsMap[symbol] = value;
}

double SymbolsTable::getValue(string symbol) {
    return symbolsMap[symbol];
}


void SymbolsTable::updateLocalValueByPath(string path, double value) {

    std::string symbolToUpdate = pathToSymbolMap[path];
    if (!symbolToUpdate.empty())
        setSymbol(symbolToUpdate, value);

}

bool SymbolsTable::exict(string symbol) {
    return symbolsMap.count(symbol) != 0;

}

SymbolsTable::~SymbolsTable() {
    delete instance;
}

void SymbolsTable::setSymbol(string symbol, string path) {
    pathToSymbolMap[path] = symbol;
    //Todo get the actual value from the simulator
    setSymbol(symbol, 0);

}
