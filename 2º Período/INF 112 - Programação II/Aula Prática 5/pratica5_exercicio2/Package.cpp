#include <iomanip>
#include <iostream>
#include <string>

#include "Package.h"

Package::Package(std::string addNome, std::string addEndereco, unsigned int addPeso, unsigned int addCustoPorKG):
    _nome(addNome), _endereco(addEndereco), _peso(addPeso), _custoPorKG(addCustoPorKG) {};

std::string Package::get_nome() {
    return this->_nome;
}

std::string Package::get_endereco() {
    return this->_endereco;
}

unsigned int Package::get_peso() {
    return this->_peso;
}

unsigned int Package::get_custoPorKG() {
    return this->_custoPorKG;
}

double Package::calculateCost() {
    return _custoPorKG*_peso;
}