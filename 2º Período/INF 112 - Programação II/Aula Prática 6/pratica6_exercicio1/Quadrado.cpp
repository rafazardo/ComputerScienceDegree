#include <iomanip>
#include <iostream>
#include <string>
#include <math.h>

#include "Quadrado.h"

Quadrado::Quadrado(double addLado, std::string addNome, std::string addCor):
    _lado(addLado), _nome(addNome), _cor(addCor) {} ;

std::string Quadrado::get_cor() {
    return this->_cor;
}

std::string Quadrado::get_nome() {
    return this->_nome;
}    

double Quadrado::get_area() {
    return pow(this->_lado,2.0);
}

double Quadrado::get_perimetro() {
    return this->_lado * 4;
}