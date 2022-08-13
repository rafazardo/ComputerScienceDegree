/*
Capicoin Software - Transaction.h
- Representa uma lista implementada por encadeamento simples
- Criado por Rafael Zardo em 25/06/2022
*/

#ifndef CAPICOIN_TRANSACTION_H 
#define CAPICOIN_TRANSACTION_H 

class Transaction { 

public:
	int _codUsuarioRemetente;
    int _codUsuarioRecebedor;
    int _valor;
    int _taxa;
	Transaction *_nextTransaction; // Ponteiro que aponta para a proxima transaction

    // Construtor da classe
    Transaction(const int &codUsuarioRemetente, const int &codUsuarioRecebedor, const int &valor, const int &taxa);

    // Metodo de exibicao de dados da classe 
    const void imprime() const;
};

#endif