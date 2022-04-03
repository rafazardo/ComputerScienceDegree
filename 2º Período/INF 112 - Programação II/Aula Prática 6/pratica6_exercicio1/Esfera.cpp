#include <iomanip>
#include <iostream>
#include <string>
#include <math.h>

#include "Esfera.h"

Esfera::Esfera(double addRaio, std::string addNome, std::string addCor):
    _raio(addRaio), _nome(addNome), _cor(addCor) {} ;

std::string Esfera::get_cor() {
    return this->_cor;
}

std::string Esfera::get_nome() {
    return this->_nome;
} 

double Esfera::get_volume() {
    long double pi = 3.1415926535897932384626433832795;
    return (4.0/3.0) * pow(this->_raio,3.0) * pi;
}