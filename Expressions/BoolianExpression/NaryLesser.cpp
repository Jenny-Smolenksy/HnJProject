//
// Created by hilla on 12/22/18.
//

#include "NaryLesser.h"

NaryLesser::NaryLesser(string r, string l) : BoolianExpression(r, l) {

}

double NaryLesser::calculate() {
    if (right->calculate() <= left->calculate()) {
        return 1;
    }
    return 0;
}
