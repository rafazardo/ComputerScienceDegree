#include <iostream>
#include <stdexcept>

#include "ExcecaoSoma.h"
#include "ExcecaoAcimaDeX.h"

int main() { 
    
    ExcecaoSoma es;

    es.somaValores();

    return 0; 
}

//Para compilar o programa corretamente deve-se usar:  g++ main.cpp ExcecaoAcimaDeX.cpp ExcecaoSoma.cpp -std=c++11