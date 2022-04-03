#include <iostream>

#include "power.h"

int main(void) {

    int k,n;

    std::cout << "Digite k: ";
    std::cin >> k;

    std::cout << "Digite n: ";
    std::cin >> n;

    power powerObjeto(k,n);

    std::cout << powerObjeto.powerExponencial(k, n) << std::endl;
}