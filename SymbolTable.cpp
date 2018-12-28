#include "SymbolTable.h"
#include <iostream>

/*const params */
#define KEY_1 "/instrumentation/airspeed-indicator/indicated-speed-kt"
#define KEY_2 "/instrumentation/altimeter/indicated-altitude-ft"
#define KEY_3 "/instrumentation/altimeter/pressure-alt-ft"
#define KEY_4 "/instrumentation/attitude-indicator/indicated-pitch-deg"
#define KEY_5 "/instrumentation/attitude-indicator/indicated-roll-deg"
#define KEY_6 "/instrumentation/attitude-indicator/internal-pitch-deg"
#define KEY_7 "/instrumentation/attitude-indicator/internal-roll-deg"
#define KEY_8 "/instrumentation/encoder/indicated-altitude-ft"
#define KEY_9 "/instrumentation/encoder/pressure-alt-ft"
#define KEY_10 "/instrumentation/gps/indicated-altitude-ft"
#define KEY_11 "/instrumentation/gps/indicated-ground-speed-kt"
#define KEY_12 "/instrumentation/gps/indicated-vertical-speed"
#define KEY_13 "/instrumentation/heading-indicator/indicated-heading-deg"
#define KEY_14 "/instrumentation/magnetic-compass/indicated-heading-deg"
#define KEY_15 "/instrumentation/slip-skid-ball/indicated-slip-skid"
#define KEY_16 "/instrumentation/turn-indicator/indicated-turn-rate"
#define KEY_17 "/instrumentation/vertical-speed-indicator/indicated-speed-fpm"
#define KEY_18 "/controls/flight/aileron"
#define KEY_19 "/controls/flight/elevator"
#define KEY_20 "/controls/flight/rudder"
#define KEY_21 "/controls/flight/flaps"
#define KEY_22 "/controls/engines/engine/throttle"
#define KEY_23 "/engines/engine/rpm"
#define VALUE_SEPARATOR ','

pthread_mutex_t mutex;

/**
 * create object
 */
SymbolsTable::SymbolsTable() {

    pthread_mutex_init(&mutex, nullptr);
    //create table of path to value index
    int arrayIndex = 0;

    //create map of string path to index in array of values
    pathToValueIndexMap.insert(pair<string, int>(KEY_1, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_2, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_3, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_4, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_5, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_6, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_7, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_8, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_9, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_10, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_11, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_12, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_13, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_14, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_15, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_16, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_17, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_18, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_19, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_20, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_21, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_22, arrayIndex++));
    pathToValueIndexMap.insert(pair<string, int>(KEY_23, arrayIndex));
}

//Null, because instance will be initialized on demand
SymbolsTable *SymbolsTable::instance = nullptr;

/**
 * get instance of object
 * @return symbol table
 */
SymbolsTable *SymbolsTable::getInstance() {
    //singleton instance:
    if (instance == nullptr) {
        instance = new SymbolsTable();
    }
    return instance;
}

/**
 * check if symbol has been difine and binded
 * @param symbol
 * @return
 */
bool SymbolsTable::exist(string symbol) {
    return (symbolToPathMap.count(symbol) != 0);
}

/**
 * add symbol to path connection
 * @param symbol
 * @param path
 */
void SymbolsTable::addSymbol(string symbol, string path) {

    if (exist(path)) { //case bind to another symbol

        string wishPath = symbolToPathMap[path]; //path of other var
        if (exist(symbol)) { //case symbol has binding
            symbolToPathMap[symbol] = wishPath; //update
        } else {
            symbolToPathMap.insert(pair<string, string>(symbol, wishPath));
        }
    } else {//case bind to path

        if (exist(symbol)) {
            //update
            symbolToPathMap[symbol] = path;
        } else {
            symbolToPathMap.insert(pair<string, string>(symbol, path));
        }
    }
}

/**
 * get path of symbol
 * @param symbol
 * @return
 */
string SymbolsTable::getPath(string symbol) {
    if (!exist(symbol)) {
        throw "no symbol";
    }

    string path = (symbolToPathMap.find(symbol))->second;
    return path;

}

/**
 * update common values
 * @param dataString
 */
void SymbolsTable::updateValues(string dataString) {
    //lock this ctirical code
    pthread_mutex_lock(&mutex);

    unsigned long currentPosition = 0;
    unsigned long endPosition;
    double currentValue;
    string current;
    int arrayIndex = 0;

    //go over the string
    while ((endPosition = dataString.find(VALUE_SEPARATOR)) != string::npos) {

        //get string until separator
        current = dataString.substr(currentPosition, endPosition);
        try {
            //convert to double value
            currentValue = stod(current);
        } catch(char * s) {cout << current << endl;}
        //put in values array
        values[arrayIndex++] = currentValue;

        //cut string for next iteration
        dataString.erase(currentPosition, endPosition + sizeof(VALUE_SEPARATOR));
    }
    //convert last string to double
    currentValue = stod(dataString);
    values[arrayIndex] = currentValue;

    //release lock
    pthread_mutex_unlock(&mutex);
}

/**
 * get value of common symbol
 * @param symbol
 * @return
 */
double SymbolsTable::getCommonValue(string symbol) {

    if (!exist(symbol)) {
        throw "no such symbol";
    }

    string path = symbolToPathMap[symbol];

    return getValueFromPath(path);
}

/**
 * check if symbol is common
 * @param symbol
 * @return
 */
bool SymbolsTable::isCommonSymbol(string symbol) {
    if (!exist(symbol)) return false;
    string path = getPath(symbol);
    return (pathToValueIndexMap.count(path) != 0);
}

/**
 * get value from common path
 * @param path
 * @return
 */
double SymbolsTable::getValueFromPath(string path) {

    auto iter = pathToValueIndexMap.begin();
    bool found = false;
    while (!found && iter != pathToValueIndexMap.end()) {

        if (iter->first == path) {
            found = true;
        } else {
            iter++;
        }
    }

    if (!found) {
        throw "no such path";
    }

    int valueIndex = iter->second;

    double result;

    //lock
    pthread_mutex_lock(&mutex);

    //get
    result = values[valueIndex];

    //release
    pthread_mutex_unlock(&mutex);

    return result;
}

/**
 * check if symbol it temp symbols
 * @param symbol
 * @return
 */
bool SymbolsTable::isTempValue(string symbol) {
    return (tempValuesMap.count(symbol) != 0);
}

/**
 * get temp symbol value
 * @param symbol
 * @return
 */
double SymbolsTable::getTempValue(string symbol) {

    auto iter = tempValuesMap.find(symbol);
    if (iter == tempValuesMap.end()) {
        throw "no symbol";
    }
    return iter->second;
}

/**
 * add temp symbol value, temp = unbinded
 * @param symbol
 * @param value
 */
void SymbolsTable::addTempValue(string symbol, double value) {
    if (isTempValue(symbol)) {
        tempValuesMap[symbol] = value;
    } else {
        tempValuesMap.insert(pair<string, double>(symbol, value));
    }
}

/**
 * release properties
 */
SymbolsTable::~SymbolsTable() {
    pthread_mutex_destroy(&mutex);
    delete instance;
}