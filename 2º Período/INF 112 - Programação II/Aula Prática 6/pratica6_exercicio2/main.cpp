#include <iostream>
#include <iomanip>
#include <string>

#include "ArtigoHigiene.h"
#include "Produto.h"
#include "Remedio.h"

int main(){

    Remedio r1(123, "Amoxilina", 500.0, 5.0, 10);
    Remedio r2(456, "Ibuprofeno", 2000.0, 7.0, 20);
    ArtigoHigiene ah1(789, "Desodorante", 1500.0);
    ArtigoHigiene ah2(112, "Shampoo", 800.0);

    std::cout << "Codigo: " << r1.get_codigo() << " - Descricao: " << r1. get_descricao() << " - % de Lucro: " << r1.get_percentualDeLucro() << " - Preco de Compra: " << r1.get_precoDeCompra() << " - Valor do desconto: " << r1.get_valorDoDesconto() << " - Preco de venda: " << r1.gerarPrecoDeVenda() << std::endl;
    std::cout << "Codigo: " << r2.get_codigo() << " - Descricao: " << r2. get_descricao() << " - % de Lucro: " << r2.get_percentualDeLucro() << " - Preco de Compra: " << r2.get_precoDeCompra() << " - Valor do desconto: " << r2.get_valorDoDesconto() << " - Preco de venda: " << r2.gerarPrecoDeVenda() << std::endl;
    std::cout << "Codigo: " << ah1.get_codigo() << " - Descricao: " << ah1 .get_descricao() << " - % de Lucro: " << ah1.get_percentualDeLucro () << " - Preco de Compra: " << ah1.get_precoDeCompra() << " - Preco de venda: " << ah1.gerarPrecoDeVenda() << std::endl;
    std::cout << "Codigo: " << ah2.get_codigo() << " - Descricao: " << ah2 .get_descricao() << " - % de Lucro: " << ah2.get_percentualDeLucro () << " - Preco de Compra: " << ah2.get_precoDeCompra() << " - Preco de venda: " << ah2.gerarPrecoDeVenda() << std::endl;

    return 0;
}