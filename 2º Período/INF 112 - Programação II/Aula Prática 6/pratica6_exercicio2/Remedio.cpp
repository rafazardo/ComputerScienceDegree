#include <iostream>
#include <iomanip>
#include <string>

#include "Remedio.h"

Remedio::Remedio(int addCodigo, std::string addDescricao, double addPrecoCompra, double addPercentualDeLucro, double addValorDoDesconto):
    Produto(addCodigo, addDescricao, addPrecoCompra), _percentualDeLucro(addPercentualDeLucro), _valorDoDesconto(addValorDoDesconto) {} ;

double Remedio::gerarPrecoDeVenda() {
    double precoProduto = Produto::get_precoDeCompra();
    return (precoProduto + ((this->_percentualDeLucro * precoProduto) / 100.00)) - this->_valorDoDesconto;
}

double Remedio::get_percentualDeLucro() {
    return this->_percentualDeLucro;
}

double Remedio::get_valorDoDesconto() {
    return this->_valorDoDesconto;
}
