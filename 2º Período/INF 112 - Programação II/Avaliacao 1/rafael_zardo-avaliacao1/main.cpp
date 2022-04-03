#include "notas.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>

int main() {

    double nNota;
    int nQntdDiscp;
    int nCont;
    int nMatricula;

    std::cout << "Digite a quantidade de Disciplinas, Matricula e Nome\n";
    std::cin >> nQntdDiscp >> nMatricula;
    
    notas nAluno1 = notas(nQntdDiscp,nMatricula);
  
    for (nCont = 0; nCont < nQntdDiscp; nCont++) {
        std::cout << "Digite a nota da " << nCont+1 << " prova: \n";
        std::cin >> nNota;
        nAluno1.adicionarNota(nNota);
    }

    nAluno1.calcularMediaAluno();

    nAluno1.imprimeInformacoesAluno();

}