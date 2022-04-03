#include "arquivo.hpp"
#include <iostream>
#include <iomanip>

ListaVetorInteiros::ListaVetorInteiros() {

    _elementos = new int[TAMANHO]();
    _num_elementos_inseridos = 0;

}

void ListaVetorInteiros::inserir_elemento(int elemento) {

    if (_num_elementos_inseridos == TAMANHO) {
        std::cerr << "Erro, lista cheia" << std::endl;
        exit(1);
    }
    
    _elementos[_num_elementos_inseridos] = elemento;
    _num_elementos_inseridos++;

}

void ListaVetorInteiros::imprimir() {

    for (int i = 0; i < _num_elementos_inseridos; i++) {
        std::cout << _elementos[i] << " ";
    }
    std::cout << std::endl;
    
}

ListaVetorInteiros::~ListaVetorInteiros() {

    delete[] _elementos;

}

void ListaVetorInteiros::remover_primeiro() {

    int *nSup = new int [_num_elementos_inseridos-1];
    int nCont;

    for (nCont = 1 ; nCont < _num_elementos_inseridos; nCont++) {
        nSup[nCont - 1] = _elementos[nCont];
    }

    delete [] _elementos;

    _elementos = nSup;
    _num_elementos_inseridos--;
}

void ListaVetorInteiros::remover_ultimo() {

    int *nSup2 = new int [_num_elementos_inseridos-1];
    int nCont;

    for (nCont = 0; nCont < _num_elementos_inseridos-1; nCont++) {
        nSup2[nCont] = _elementos[nCont];
    }

    delete [] _elementos;

    _elementos = nSup2;
    _num_elementos_inseridos--;    

}

void ListaVetorInteiros::inverte() {
    
    int *nSup = new int[_num_elementos_inseridos];
    int nCont;
    int nInicio = 0;

    for (nCont = 0; nCont < _num_elementos_inseridos; nCont++) {
        nSup[nCont] = _elementos[nCont];
    }

    for (nCont = _num_elementos_inseridos - 1; nCont >= 0 ; nCont--) {
        _elementos[nInicio] = nSup[nCont];
        nInicio++;
    }
    
}