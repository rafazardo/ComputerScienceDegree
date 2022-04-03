#ifndef INF112_CONTACORRENTE_H
#define INF112_CONTACORRENTE_H

#include "Conta.h"

class ContaCorrente : public Conta {
private:
   
public:
    ContaCorrente(std::string addNomeCliente, std::string addCPF, double addSaldoAtual);
    ~ContaCorrente();

    virtual double get_saldo(); //Metodo virtual para coletar o saldo no objeto
};

#endif