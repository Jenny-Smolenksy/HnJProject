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

SymbolsTable *SymbolsTable::getInstance() {
    //TODO: delete instance at the end
    //singleton instance:
    if (instance == nullptr) {
        instance = new SymbolsTable();
    }
    return instance;
}

bool SymbolsTable::exist(string symbol) {
    return (symbolToPathMap.count(symbol) != 0);
}

SymbolsTable::~SymbolsTable() {
    pthread_mutex_destroy(&mutex);
    delete instance;
}

void SymbolsTable::addSymbol(string symbol, string path) {

    if (exist(symbol)) {
        //update
        symbolToPathMap[symbol] = path;
    } else {
        symbolToPathMap.insert(pair<string, string>(symbol, path));
    }
}

void SymbolsTable::updateValues(string dataString) {
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
        //convert to double value
        currentValue = stod(current);
        //put in values array
        values[arrayIndex++] = currentValue;

        //cut string for next iteration
        dataString.erase(currentPosition, endPosition + sizeof(VALUE_SEPARATOR));
    }
    //convert last string to double
    currentValue = stod(dataString);
    values[arrayIndex] = currentValue;

    pthread_mutex_unlock(&mutex);
}

double SymbolsTable::getValue(string symbol) {

    if (!exist(symbol)) {
        throw "no such symbol";
    }

    string path = symbolToPathMap[symbol];

    //int valueIndex = (pathToValueIndexMap[path]);

    //TODO: get this ugly code changed
    map<string, int>::iterator iter = pathToValueIndexMap.begin();
    bool flag = false;
    while (!flag && iter != pathToValueIndexMap.end()) {

        if (iter->first.compare(path)) {
            flag = true;
        } else {
            iter++;
        }
    }

    int valueIndex = iter->second;

    double result;

    pthread_mutex_lock(&mutex);

    result = values[valueIndex];

    pthread_mutex_unlock(&mutex);

    return result;
}

/*
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
*/