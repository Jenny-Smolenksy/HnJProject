//
// Created by hilla on 12/18/18.
//

#ifndef HNJPROJECT_SYMBOLTABLE_H
#define HNJPROJECT_SYMBOLTABLE_H


#include <string>
#include <map>

#define VALUES_SIZE 23

using namespace std;

/**
 * we would like to make it singelton so we will use private constractor and stutic instance
 */
class SymbolsTable {

private:
    static SymbolsTable *instance;

    SymbolsTable();

    map<string, string> symbolToPathMap;
    map<string, int> pathToValueIndexMap;
    double values[VALUES_SIZE] = {0};


public:
    // Static access method
    static SymbolsTable *getInstance();

    void addSymbol(string symbol, string path);

    bool exist(string symbol);

    virtual ~SymbolsTable();

    void updateValues(string data);

    double getValue(string symbol);

    //   void updateLocalValueByPath(string path, double value);
    //  void setSymbol(string symbol, double value);
};

#endif //HNJPROJECT_SYMBOLTABLE_H
