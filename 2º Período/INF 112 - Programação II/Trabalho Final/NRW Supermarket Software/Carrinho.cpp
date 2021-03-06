#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Carrinho.h"
#include "Produto.h"
#include "Estoque.h"

unsigned int codigo_suporte = 1;  // Variavel suporte para criar um novo codigo (codigo atual + 1) para todo carrinho criado

Carrinho::Carrinho() { //Construtor que gera um codigo novo para todo novo carrinho criado
    this->_codigo = codigo_suporte;
    codigo_suporte++;
}

Carrinho::~Carrinho() {
    
}

unsigned int Carrinho::get_codigo() {
    return this->_codigo;
}

double Carrinho::get_preco_total() {
    return this->_preco_total;
}

void Carrinho::set_codigo(unsigned int codigo) {
    this->_codigo = codigo;
}

void Carrinho::set_preco_total(double preco_total) {
    this->_preco_total = preco_total;
}

void Carrinho::adicionar_produto(Produto *produto, int quantidade, Estoque *estoque) {
    int quantidade_produtos;
    
    // Impede a adicao no carrinho de uma quantidade maior que a presente no estoque
    for (int i=0; i < estoque->get_produtos().size(); i++) {
        if (produto->get_codigo() == estoque->get_produtos()[i].get_codigo()) {
            quantidade_produtos = i;
            break;
        }
    }

    if (estoque->get_quantidade()[quantidade_produtos] < quantidade) {
        std::cout << "O produto nao foi adicionado no carrinho \n";
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        this->_produtos.push_back(*produto);
    }
    calculo_preco_total(); // Toda vez que é adicionado um novo produto no carrinho, ele reconta o valor total dos produtos dentro do carrinho

}

void Carrinho::remover_produto(Produto *produto, int quantidade) {
    int quantidade_produtos = 0;

    for (int i=0; i < _produtos.size(); i++) {
        if (produto->get_codigo() == this->_produtos[i].get_codigo()) {
            quantidade_produtos++;
        }
    }
    
    // Impede a remocao de uma quantidade maior que a presente no carrinho
    if (quantidade_produtos < quantidade) {
        std::cout << "Erro: Esse produto possui apenas " << quantidade_produtos << " unidades no carrinho \n" << std::endl;
        return;
    }

    for (int i = 0; i < quantidade; i++) { //Remove a quantidade solicitada de produtos
        for (int j = 0; j < _produtos.size(); j++) {
            if (this->_produtos[j].get_codigo() == produto->get_codigo()) { 
                _produtos.erase(_produtos.begin() + (j)); // Utiliza o erase para remover o produto alocado em _produtos
                break;
            }
        }
    }
    calculo_preco_total(); // Toda vez que é adicionado um novo produto no carrinho, ele reconta o valor total dos produtos dentro do carrinho

}

void Carrinho::exibir_produtos() {

    for (int i = 0; i < this->_produtos.size(); i++) {
        std::cout << "Nome: " << this->_produtos[i].get_nome() << std::fixed << std::setprecision(2) << " - Preco: R$ " << this->_produtos[i].get_preco() << std::endl; 
    }

}

void Carrinho::calculo_preco_total() {

    double preco_total_suporte;

    this->set_preco_total(0); // Zera o preco total, para fazer a recontagem de todos produtos do carrinho

    for (int i = 0; i < this->_produtos.size(); i++) {
        preco_total_suporte += this->_produtos[i].get_preco(); 
    }
    
    this->set_preco_total(preco_total_suporte);

}   