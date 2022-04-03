#include <iostream>

#include "power.h"

power::power(int addK, int addN):
    _k(addK), _n(addN) {} ;

power::~power() {}

int power::get_k() {
    return this->_k;
}

int power::get_n() {
    return this->_n;
}

int power::powerExponencial(int addK, int addN) {

    if (addN == 1) {
        return addK;
    }

    return addK * powerExponencial(addK, addN - 1);
}