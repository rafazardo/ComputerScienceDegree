#include "arquivo.hpp"
#include <iostream>
#include <iomanip>

Cubo::Cubo(float fLad) {
    _fLad = fLad;
}

Cubo::~Cubo() {
}

float Cubo::calculaAreaCubo() {
    return 6*(_fLad*_fLad);
}  

float Cubo::calculaVolumeCubo() {
    return (_fLad*_fLad*_fLad);
}   