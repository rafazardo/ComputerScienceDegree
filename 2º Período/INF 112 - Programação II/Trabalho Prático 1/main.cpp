#include "matrizquadrada.hpp"
#include <iomanip>
#include <iostream>

int main() {

    int ordemMatriz;

    std::cout << "Bem vindo! Digite a ordem da sua matriz (nxn): ";
    std::cin >> ordemMatriz; //Tamanho das colunas e linhas da matriz.

    MatrizQuadrada M1(ordemMatriz);
    MatrizQuadrada M2(ordemMatriz);
    MatrizQuadrada M3(ordemMatriz);
    MatrizQuadrada I(ordemMatriz);
    MatrizQuadrada R(ordemMatriz);
    MatrizQuadrada T(ordemMatriz);

    std::cout << "Digite cada elemento da sua matriz M1 de ordem " << ordemMatriz << "x" << ordemMatriz << ": \n";
    M1.leMatriz(M1); //Faz a leitura de cada termo da Matriz (M1).
    std::cout << std::endl;

    I.criaMatrizIdentidade(I); //Cria uma Matriz Identidade(I) de tamanho orordemMatriz x ordemMatriz.
    R.produto(M1,I,R); //Faz o produto da Matriz Identidade(I) e Matriz (M1) e armazena os resultados na Matriz Resultante(R).

    if (M1.compara(M1,R)){ //Compara se os termos da Matriz (M1) sao identicos ao da Matriz Resultante (R).
        std::cout << "Sua Matriz M1 e igual a Matriz Resultante: " << std::endl;
    }
    else {
        std::cout << "Sua Matriz M1 nao é igual a Matriz Resultante: " << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Matriz M1: \n";
    M1.imprimeMatriz(M1); 
    std::cout << std::endl;
    
    std::cout << "Matriz Resultante de Matriz M1 x MatrizIdentidade: \n";
    R.imprimeMatriz(R);
    std::cout << std::endl;

    T.criaTransposta(R,T); //Cria a matriz transposta da Matriz Resultante (R) e armazena na Matriz Transposta (T).

    std::cout << "Digite cada elemento da sua matriz M2 de ordem " << ordemMatriz << "x" << ordemMatriz << ": \n";
    M2.leMatriz(M2); //Faz a leitura de cada termo da Matriz (M2).
    std::cout << std::endl;

    M3.soma(R,M2,M3); //Faz a soma da Matriz Resultante (R) com a Matriz (M2) e armazena os valores na Matriz (M3).

    std::cout << "Matriz M2: \n";
    M2.imprimeMatriz(M2);
    std::cout << std::endl;

    std::cout << "Matriz Resultante de Matriz M2 + Matriz Resultante de Matriz M1 x MatrizIdentidade: \n";
    M3.imprimeMatriz(M3);
    std::cout << std::endl;

    return 0;   
}