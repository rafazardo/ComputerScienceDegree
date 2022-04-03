#include <iostream>

#include "mdc.h"

int main(void) {
    
    int x,y;

    std::cout << "Digite x: ";
    std::cin >> x;

    std::cout << "Digite y: ";
    std::cin >> y;

    mdc objetoMDC(x,y);

    std::cout << objetoMDC.encontraMDC(x,y) << std::endl;

}