//
// Created by hilla on 12/22/18.
//

#include "Greater.h"

double Greater::calculate() {
    if(right->calculate()>left->calculate()){
        return 1;
    }
    return 0;
}

Greater::Greater(string r, string l) : BoolianExpression(r, l) {

}
