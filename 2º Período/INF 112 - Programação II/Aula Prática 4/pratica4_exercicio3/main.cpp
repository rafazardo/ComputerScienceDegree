#include <iostream>
#include <iomanip>

#include "arquivo.hpp"

int main() { 

    Aquecedor aq1;
    Aquecedor aq2(20);
    Aquecedor aq3(38,1);

    // Temperatura de cada um dos aquecedores
    std::cout << aq1.getTemperatura() << std::endl;
    std::cout << aq2.getTemperatura() << std::endl;
    std::cout << aq3.getTemperatura() << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    aq1.aquecer();
    aq2.aquecer(); 
    aq3.aquecer();

    // Temperatura de cada um dos aquecedores
    std::cout << aq1.getTemperatura() << std::endl;
    std::cout << aq2.getTemperatura() << std::endl;
    std::cout << aq3.getTemperatura() << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    aq1.setFatorDeIncrementoDaTemperatura(10);
    aq2.setFatorDeIncrementoDaTemperatura(25);
    aq3.setFatorDeIncrementoDaTemperatura(2);
    aq1.aquecer();
    aq2.esfriar(); 
    aq3.aquecer();

    // Temperatura de cada um dos aquecedores
    std::cout << aq1.getTemperatura() << std::endl;
    std::cout << aq2.getTemperatura() << std::endl;
    std::cout << aq3.getTemperatura() << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    return 0;
}