#include <iomanip>
#include <iostream>
#include <string>
#include <math.h>

#include "Cubo.h"

Cubo::Cubo(double addLado, std::string addNome, std::string addCor):
    _lado(addLado), _nome(addNome), _cor(addCor) {} ;

std::string Cubo::get_cor() {
    return this->_cor;
}

std::string Cubo::get_nome() {
    return this->_nome;
}

double Cubo::get_volume() {
    return pow(this->_lado,3.0);
}