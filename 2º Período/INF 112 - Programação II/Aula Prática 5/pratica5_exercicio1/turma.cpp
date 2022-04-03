#include <iomanip>
#include <iostream>
#include <string>

#include "turma.h"

Turma::Turma(std::string addCodigo, int addAno):
    _codigo(addCodigo), _ano(addAno) {};

std::string Turma::get_codigo() {
    return this->_codigo;
}

int Turma::get_ano() {
    return this->_ano;
}

void Turma::set_codigo(std::string setCodigo) {
    _codigo = setCodigo;
}

void Turma::set_ano(int setAno) {
    _ano = setAno;
}