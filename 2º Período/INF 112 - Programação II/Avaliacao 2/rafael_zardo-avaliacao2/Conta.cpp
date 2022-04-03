#include <iostream>

#include "Conta.h"

Conta::Conta(std::string addNomeCliente, std::string addCPF, double addSaldoAtual):
    _nome_cliente(addNomeCliente), _cpf(addCPF), _saldo_atual(addSaldoAtual) {} ;

Conta::~Conta() {}

void Conta::set_saldo(double addAsaldoAtual) {
    this->_saldo_atual = addAsaldoAtual;
}