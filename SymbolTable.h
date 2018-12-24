#include <string>
#include <map>

#define VALUES_SIZE 23

using namespace std;

/**
 * we would like to make it singelton so we will use private constractor and static instance
 */
class SymbolsTable {

private:
    static SymbolsTable *instance;

    map<string, string> symbolToPathMap;

    map<string, int> pathToValueIndexMap;
    double values[VALUES_SIZE] = {0};

    //table of non binded values
    map<string, double> tempValuesMap;


    SymbolsTable();
    double getValueFromPath(string path);




public:
    // Static access method
    static SymbolsTable *getInstance();

    void addSymbol(string symbol, string path);
    bool exist(string symbol);
    virtual ~SymbolsTable();
    void updateValues(string data);
    double getCommonValue(string symbol);
    string getPath(string symbol);
    void addTempValue(string symbol, double value);
    bool isTempValue(string symbol);
    double getTempValue(string symbol);
    bool isCommonSymbol(string symbol);

};

