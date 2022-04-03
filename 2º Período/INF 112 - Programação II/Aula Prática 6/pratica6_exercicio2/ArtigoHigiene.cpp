#include <iostream>
#include <iomanip>
#include <string>

#include "ArtigoHigiene.h"

ArtigoHigiene::ArtigoHigiene(int addCodigo, std::string addDescricao, double addPrecoCompra):
    Produto(addCodigo, addDescricao, addPrecoCompra) {} ;

double ArtigoHigiene::gerarPrecoDeVenda() {
    double precoProduto = Produto::get_precoDeCompra();
    return precoProduto + ((this->_percentualDeLucro * precoProduto) / 100.00);
}

double ArtigoHigiene::get_percentualDeLucro() {
    return this->_percentualDeLucro;
}