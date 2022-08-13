/*
Capicoin Software - Transaction.cpp
- Implementacao dos metodos desenvolvidos na classe Transaction de Transaction.h
- Criado por Rafael Zardo em 25/06/2022
*/

#include <iostream>

#include "Transaction.h"

// Metodos da classe Transaction

Transaction::Transaction(const int &codUsuarioRemetente, const int &codUsuarioRecebedor, const int &valor, const int &taxa):
    _codUsuarioRemetente(codUsuarioRemetente), _codUsuarioRecebedor(codUsuarioRecebedor), _valor(valor), _taxa(taxa), _nextTransaction(NULL) {} ;

const void Transaction::imprime() const {
    std::cout << this->_codUsuarioRemetente << " -> " << this->_codUsuarioRecebedor;
    std::cout << " (valor: " << this->_valor << " , taxa: " << this->_taxa << ")\n";
}


