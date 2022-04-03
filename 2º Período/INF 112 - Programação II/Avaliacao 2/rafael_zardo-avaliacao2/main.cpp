#include <iostream>

#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"

int main() {

    ContaCorrente conta1("Rafael Zardo", "158.205.907-60", 100.00);
    ContaPoupanca conta2("Rafael Zardo", "158.205.907-60", 100.00, 10.00);

    std::cout << "Saldo da Conta Corrente (conta1): " << conta1.get_saldo() << std::endl;
    std::cout << "Saldo da Conta Poupanca (conta2): " << conta2.get_saldo() << std::endl;
    std::cout << "Alteramos o valor do rendimento da Conta Poupanca (conta2) para 15 reais" << std::endl;
    conta2.muda_rendimento(15.00); 
    std::cout << "Saldo da Conta Poupanca (conta2): " << conta2.get_saldo() << std::endl;

    return 0;
}