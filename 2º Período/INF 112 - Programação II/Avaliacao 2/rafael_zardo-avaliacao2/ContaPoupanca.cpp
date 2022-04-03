#include <iostream>

#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(std::string addNomeCliente, std::string addCPF, double addSaldoAtual, double addRendimento):
    Conta(addNomeCliente, addCPF, addSaldoAtual), _rendimento(addRendimento) {} ;

ContaPoupanca::~ContaPoupanca() {}

double ContaPoupanca::get_saldo() { //Funcao que atualiza o saldo baseado no valor do rendimento
    this->_saldo_atual += this->_rendimento;
    return this->_saldo_atual;
}

void ContaPoupanca::muda_rendimento(double addRendimento) {
    this->_rendimento = addRendimento;
}