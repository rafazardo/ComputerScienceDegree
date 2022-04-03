#include <iostream>

#include "ContaCorrente.h"

ContaCorrente::ContaCorrente(std::string addNomeCliente, std::string addCPF, double addSaldoAtual):
    Conta(addNomeCliente, addCPF, addSaldoAtual) {} ;

ContaCorrente::~ContaCorrente() {}

double ContaCorrente::get_saldo() {
    return this->_saldo_atual;
}