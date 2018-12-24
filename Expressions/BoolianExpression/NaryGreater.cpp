//
// Created by hilla on 12/22/18.
//

#include "NaryGreater.h"

NaryGreater::NaryGreater(string r, string l) : BoolianExpression(r, l) {

}

double NaryGreater::calculate() {
    if (right->calculate() >= left->calculate()) {
        return 1;
    }
    return 0;
}
