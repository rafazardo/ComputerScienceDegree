#include <iomanip>
#include <iostream>
#include "arquivo.hpp"

int main() {

    ListaVetorInteiros l1; 
    l1.inserir_elemento(7); 
    l1.inserir_elemento(10); 
    l1.inserir_elemento(5); 
    l1.inserir_elemento(2); 
    l1.inserir_elemento(2);

    l1.imprimir();
    l1.remover_primeiro(); 
    l1.imprimir();
    l1.remover_ultimo(); 
    l1.imprimir();
    l1.inverte(); 
    l1.imprimir(); 
    
    return 0;
}