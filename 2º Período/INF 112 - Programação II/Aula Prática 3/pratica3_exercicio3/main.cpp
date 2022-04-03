#include "arquivo.hpp"
#include <iostream>
#include <iomanip>

int main() {

    Data d1(13, 12, 2021);
    d1.exibirDataFormatoNumero();
    d1.exibirDataPorExtenso(); 
    d1.getDataEmSegundos();
    
    return 0; 
}