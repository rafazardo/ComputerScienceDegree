#ifndef INF112_CONTAPOUPANCA_H
#define INF112_CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta{
private:
    double _rendimento;
public:
    ContaPoupanca(std::string addNomeCliente, std::string addCPF, double addSaldoAtual, double addRendimento);
    ~ContaPoupanca();

    virtual double get_saldo(); //Metodo virtual para coletar o saldo no objeto
    void muda_rendimento(double addRendimento);
};

   





#endif