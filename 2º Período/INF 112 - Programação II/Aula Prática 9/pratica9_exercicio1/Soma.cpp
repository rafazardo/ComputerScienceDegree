#include <iostream>

#include "Soma.h"

Soma::Soma(int addM, int addN):
    _m(addM), _n(addN) {} ;

Soma::~Soma() {}

int Soma::get_m() {
    return this->_m;
}

int Soma::get_n() {
    return this->_n;
}

int Soma::aplicaSoma(int addM, int addN) {

    if (addM == addN) {
        return addN;
    }

    return addM + aplicaSoma(addM + 1, addN);
}