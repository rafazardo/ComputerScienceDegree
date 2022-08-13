#include <iostream>
#include <string>
#include <sstream>

void geraDigito(std::string CPF) {
    int multiplicador = 10;
    int somaDigitos = 0;
    int valorInt, primeiroDigito, segundoDigito;
    char stringAux[1];

    for (int i = 0; i < CPF.size(); i++) {
        stringAux[0] = CPF[i];
        valorInt = std::stoi(stringAux);
        somaDigitos += valorInt * multiplicador;
        multiplicador--;
    }

    if ((10 * somaDigitos) % 11 == 10) {
        primeiroDigito = 0;
    }
    else {
        primeiroDigito = (10 * somaDigitos) % 11;
    }

    multiplicador = 11;
    somaDigitos = 0;

    for (int i = 0; i < CPF.size(); i++) {
        stringAux[0] = CPF[i];
        valorInt = std::stoi(stringAux);
        somaDigitos += valorInt * multiplicador;
        multiplicador--;
    }
    
    somaDigitos += multiplicador * primeiroDigito;

    if ((10 * somaDigitos) % 11 == 10) {
        segundoDigito = 0;
    }
    else {
        segundoDigito = (10 * somaDigitos) % 11;
    }

    std::cout << primeiroDigito << segundoDigito << std::endl;

}


int main() {

    int qntdCPFs;
    std::string CPF;

    std::cin >> qntdCPFs;

    for (int n = 0; n < qntdCPFs; n++) {
        std::cin >> CPF;
        geraDigito(CPF);
    }

    return 0;
}