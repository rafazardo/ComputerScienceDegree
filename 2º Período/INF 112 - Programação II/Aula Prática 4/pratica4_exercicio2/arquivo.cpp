#include <iostream>
#include <iomanip>

#include "arquivo.hpp"

Aquecedor::Aquecedor() {
    _temperatura = 20.00;
}

double Aquecedor::getTemperatura() {
    return _temperatura;
}

void Aquecedor::aquecer() {
    _temperatura += 5;
}

void Aquecedor::esfriar() {
    _temperatura -= 5;
}