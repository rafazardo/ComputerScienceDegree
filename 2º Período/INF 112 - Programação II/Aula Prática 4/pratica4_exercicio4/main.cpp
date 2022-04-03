#include <iostream>
#include <iomanip>

#include "arquivo.hpp"



int main(void) {

    // Main. Criando duas contas.
    SavingsAccount saver1 = SavingsAccount(2000);
    SavingsAccount saver2 = SavingsAccount(3000);

    // Imprimindo o monthly balance
    std::cout << saver1.calculateMonthlyInterest() << std::endl; 
    std::cout << saver2.calculateMonthlyInterest() << std::endl;

    // Alterando atributo static publico    
    SavingsAccount::modifyInterestRate(4.00);

    // Imprimindo o monthly balance. Tem que mudar para as duas classes.
    std::cout << saver1.calculateMonthlyInterest() << std::endl;
    std::cout << saver2.calculateMonthlyInterest() << std::endl;

    return 0; 
}