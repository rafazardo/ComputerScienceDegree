#include <iostream> 
#include <stdexcept>

#include "PosicoesVetor.h"

int main() {

    int y = 0;

    std::cout << "Digite o tamanho do vetor: " << std::endl;
    std::cin >> y;

    PosicoesVetor v(y);

    v.preencherValores();

    return 0; 
}