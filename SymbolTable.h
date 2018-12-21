//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_SYMBOLTABLE_H
#define HNJPROJECT_SYMBOLTABLE_H


#include <string>
#include <map>

using namespace std;

/**
 * we would like to make it singelton so we will use private constractor and stutic instance
 */
class SymbolsTable {

private:
    static SymbolsTable *instance;

    SymbolsTable() = default;

    map<string, string> pathToSymbolMap;
    map<string, double> symbolsMap;

public:
    // Static access method
    static SymbolsTable *getInstance();

    void setSymbol(string symbol, double value);

    void setSymbol(string symbol,string path);

    void updateLocalValueByPath(string path, double value);

    double getValue(string symbol);

    bool exict(string symbol);

    virtual ~SymbolsTable();


};

#endif //HNJPROJECT_SYMBOLTABLE_H
