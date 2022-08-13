#include <iostream>
#include <string>

#include "MySet.h"

int main() {

    std::string inputInicial;
    int dateBD;
    MySet<int> myBD;

    while (std::cin >> inputInicial) {

        if (inputInicial == "C") {

            std::cin >> dateBD;
            
            myBD.insert(dateBD);
        }
        else if (inputInicial == "S") {
            std::cin >> dateBD;

            if (myBD.find(dateBD) == 0) {
                std::cout << "FALHA\n";
            }
            else {
                MySet<int>::iterator it = myBD.find(dateBD);
                it++;
                if (it != NULL) {
                    std::cout << *(it) << std::endl;
                }
                else {
                    std::cout << "FALHA\n";
                }
            }
            
        }
    }
    cin.ignore();
}

