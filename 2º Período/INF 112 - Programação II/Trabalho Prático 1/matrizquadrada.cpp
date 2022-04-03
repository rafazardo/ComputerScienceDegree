#include "matrizquadrada.hpp"
#include <iomanip>
#include <iostream>

MatrizQuadrada::MatrizQuadrada(int ordemMatriz) { //Construtor
   
    int nCont;
    _elementos = new int*[ordemMatriz](); 

    for (nCont = 0; nCont < ordemMatriz; nCont++) {
        _elementos[nCont] = new int [ordemMatriz];
    }

    _ordem = ordemMatriz;

}

MatrizQuadrada::~MatrizQuadrada() { //Destrutor
    
    int nCont;

    for (nCont = 0; nCont < _ordem; nCont++) {
        delete[] _elementos[nCont];
    }

    delete[] _elementos;

}

void MatrizQuadrada::leMatriz(MatrizQuadrada &Matriz) {

    int nCont,nCont2; //Variaveis auxiliares.

    for (nCont = 0; nCont < _ordem; nCont++) {
        for (nCont2 = 0; nCont2 < _ordem; nCont2++) {
            std::cin >> Matriz._elementos[nCont][nCont2];
        }
    }

}

void MatrizQuadrada::imprimeMatriz(MatrizQuadrada &Matriz) {

    int nCont,nCont2; //Variaveis auxiliares.

    for (nCont = 0; nCont < _ordem; nCont++) {
        for (nCont2 = 0; nCont2 < _ordem; nCont2++) {
            std::cout << Matriz._elementos[nCont][nCont2] << " ";
        }
        std::cout << std::endl;
    }

}

void MatrizQuadrada::criaMatrizIdentidade(MatrizQuadrada &Matriz) {

    int nCont,nCont2; //Variaveis auxiliares.

    for (nCont = 0; nCont < _ordem; nCont++) {
        for (nCont2 = 0; nCont2 < _ordem; nCont2++) {
           if (nCont == nCont2) { //Se o numero da posicao da coluna for igual da linha inserir 1 na posicao, caso constrario inserir 0.
                Matriz._elementos[nCont][nCont2] = 1;
            }
            else {
                Matriz._elementos[nCont][nCont2] = 0;
            }
        }
    }

}

void MatrizQuadrada::produto(MatrizQuadrada &Matriz, MatrizQuadrada &matrizIdentidade, MatrizQuadrada &matrizResultante) {
    
    int nCont,nCont2,nCont3; //Variaveis auxiliares.

    for (nCont = 0; nCont < _ordem; nCont++) {
        for (nCont2 = 0; nCont2 < _ordem; nCont2++) {
            for (nCont3 = 0; nCont3 < _ordem; nCont3++) {
                matrizResultante._elementos[nCont][nCont2] += Matriz._elementos[nCont][nCont3] * matrizIdentidade._elementos[nCont3][nCont2];
            }
        }
    }

}

bool MatrizQuadrada::compara(MatrizQuadrada &Matriz, MatrizQuadrada &matrizResultante) {

    int nCont,nCont2; //Variaveis auxiliares.

    for (nCont = 0; nCont < _ordem; nCont++) {
        for (nCont2 = 0; nCont2 < _ordem; nCont2++) {
           if (Matriz._elementos[nCont][nCont2] != matrizResultante._elementos[nCont][nCont2]) {
               return false; //Se encontrar pelo menos um valor difente, ja retorna o bool false.
           }
        }
    }

    return true;
    
}

void MatrizQuadrada::criaTransposta(MatrizQuadrada &matrizResultante, MatrizQuadrada &matrizTransposta) {

    int nCont,nCont2; //Variaveis auxiliares.

    for (nCont = 0; nCont < _ordem; nCont++) {
        for (nCont2 = 0; nCont2 < _ordem; nCont2++) {
            matrizTransposta._elementos[nCont][nCont2] = matrizResultante._elementos[nCont2][nCont];
        }
    }    

}

void MatrizQuadrada::soma(MatrizQuadrada &matrizResultante, MatrizQuadrada &matrizA, MatrizQuadrada &matrizB) {
    
    int nCont,nCont2; //Variaveis auxiliares.

    for (nCont = 0; nCont < _ordem; nCont++) {
        for (nCont2 = 0; nCont2 < _ordem; nCont2++) {
            matrizB._elementos[nCont][nCont2] = matrizResultante._elementos[nCont][nCont2] + matrizA._elementos[nCont][nCont2];
        }
    }  

}