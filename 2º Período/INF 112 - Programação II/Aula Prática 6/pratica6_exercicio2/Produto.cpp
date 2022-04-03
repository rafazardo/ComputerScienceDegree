#include <iostream>
#include <iomanip>
#include <string>

#include "Produto.h"

Produto::Produto(int addCodigo, std::string addDescricao, double addPrecoDeCompra):
    _codigo(addCodigo), _descricao(addDescricao), _precoDeCompra(addPrecoDeCompra) {} ;

int Produto::get_codigo() {
    return this->_codigo;
}

std::string Produto::get_descricao() {
    return this->_descricao;
}

double Produto::get_precoDeCompra() {
    return this->_precoDeCompra;
}


