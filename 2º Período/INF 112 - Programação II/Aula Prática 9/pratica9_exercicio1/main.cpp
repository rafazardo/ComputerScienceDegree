#include <iostream>

#include "Soma.h"

int main(void) {

    int m, n;
    
    std::cout << "Digite m: ";
    std::cin >> m;

    std::cout << "Digite n: ";
    std::cin >> n;    

    Soma somaObjeto(m,n);
    
    std::cout << somaObjeto.aplicaSoma(m,n) << std::endl;
}