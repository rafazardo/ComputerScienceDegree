#include <iomanip>
#include <iostream>
#include <string>
#include <math.h>

#include "Circulo.h"

Circulo::Circulo(double addRaio, std::string addNome, std::string addCor):
    _raio(addRaio), _nome(addNome), _cor(addCor) {} ;

std::string Circulo::get_cor() {
    return this->_cor;
}

std::string Circulo::get_nome() {
    return this->_nome;
}

double Circulo::get_area() {
    long double pi = 3.1415926535897932384626433832795;
    return pow(this->_raio,2.0) * pi;
}

double Circulo::get_perimetro() {
    long double pi = 3.1415926535897932384626433832795;
    return 2 * this-> _raio * pi;
}