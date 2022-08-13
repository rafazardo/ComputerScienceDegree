/* Respostas do arquivo PDF:

Questao 1:
Quando utilizamos o MySet, obtemos um tempo relativamente bem mais rapido comparado ao MyVec,
pois o MySet consegu encontrar e inerir elementos de forma mais rapida.

Questao 2:
Utilizando lista por contiguidade seria mais facil para encontrar os elementos e poderiamos deixa-los ordenados.

Questao 3:
Utilizando lista por contiguidade

*/

#include <iostream>
#include <string>

#include "MySet.h"
#include "MyVecNewIterator.h"

int main(int argc, char * argv[]) {

    std::string inputInicial = argv[1];
    int qntdPalavras = 0;
    std::string text;
    
        if (inputInicial == "myvec") {
            
            MyVec<std::string> myVecAux;
            bool elementoIgual;

            while (std::cin >> text) {

                elementoIgual = false; // Reseta a variavel para verificar novamente, se o proximo string esta no myvec

                for (int n = 0; n < myVecAux.size(); n++) {
                    if (myVecAux[n] == text) {
                        elementoIgual = true; // Andou por todo myvec e encontrou o elemento igual, logo nao precisa adiciona-lo ao my vec
                        break;
                    }
                }

                if (elementoIgual == false) { // Caso nao tenha encontrado o elemento, ele ira adicionar no myVec
                    myVecAux.push_back(text);
                }

                qntdPalavras++;
                cin.ignore();
            }

            std::cout << qntdPalavras << " " << myVecAux.size() << std::endl;

        }
        else if (inputInicial == "myset") {
            MySet<std::string> mySetAux;

            while (cin >> text) {
                mySetAux.insert(text);
                qntdPalavras++;
            }

            std::cout << qntdPalavras << " " << mySetAux.size() << std::endl;

        }
}

