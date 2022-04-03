#include "notas.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>

notas::notas(int nQntdDiscp, int nMatricula) {

    _qtde_disciplinas = nQntdDiscp;

    _notas = new double [_qtde_disciplinas]();

    _num_elementos_inseridos = 0;

    _matricula = nMatricula;

}

notas::~notas() {

    delete [] _notas;

}

void notas::adicionarNota (double nNota) {

    _notas[_num_elementos_inseridos] = nNota;
    
    _num_elementos_inseridos++;
}

void notas::calcularMediaAluno() {

    double nTotalNotas = 0;
    int nCont;

    for (nCont = 0; nCont < _num_elementos_inseridos; nCont++) {
        nTotalNotas += _notas[nCont];
    }

    media_notas = nTotalNotas/_num_elementos_inseridos;
}

void notas::imprimeInformacoesAluno() {
    
    int nCont;

    std::cout << "Nome: " << std::endl;
    std::cout << "Matricula " << _matricula << std::endl;
    std::cout << "Quantidade de disciplinas: " << _qtde_disciplinas << std::endl;
    std::cout << "Nota em cada disciplina: ";
    for (nCont = 0;nCont < _num_elementos_inseridos; nCont++) {
        std::cout << _notas[nCont] << " ";
    }
    std::cout << std::endl;
    std::cout << "Media das notas: " << media_notas << std::endl;
}
