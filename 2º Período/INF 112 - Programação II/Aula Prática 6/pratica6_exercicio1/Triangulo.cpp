#include <iomanip>
#include <iostream>
#include <string>

#include "Triangulo.h"

Triangulo::Triangulo(double addLado1, double addLado2, double addLado3, double addAltura, std::string addNome, std::string addCor):
    _lado1(addLado1), _lado2(addLado2), _lado3(addLado3), _altura(addAltura), _nome(addNome), _cor(addCor) {} ;

Triangulo::Triangulo(double addLado1eLado2, double addLado3, double addAltura, std::string addNome, std::string addCor):
    _lado1(addLado1eLado2), _lado2(addLado1eLado2), _lado3(addLado3), _altura(addAltura), _nome(addNome), _cor(addCor) {} ;

Triangulo::Triangulo(double addLado1eLado2eLado3, double addAltura, std::string addNome, std::string addCor):
    _lado1(addLado1eLado2eLado3), _lado2(addLado1eLado2eLado3), _lado3(addLado1eLado2eLado3),  _altura(addAltura), _nome(addNome), _cor(addCor) {} ;

std::string Triangulo::get_cor() {
    return this->_cor;
}

std::string Triangulo::get_nome() {
    return this->_nome;
}    

double Triangulo::get_area() {
    return (this->_lado3 * this->_altura)/2.0;
}

double Triangulo::get_perimetro() {
    return this->_lado1 + this->_lado2 + this->_lado3;
}