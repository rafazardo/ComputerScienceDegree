#ifndef INF112_CONTA_H
#define INF112_CONTA_H

#include <iostream>
#include <string>

class Conta {
protected:
    std::string _nome_cliente;
    std::string _cpf;
    double _saldo_atual;
    
public:
    Conta(std::string addNomeCliente, std::string addCPF, double addSaldoAtual);
    ~Conta();

    void set_saldo(double addAsaldoAtual);

    virtual double get_saldo() = 0; //Metodo virtual para coletar o saldo no objeto
};







#endif