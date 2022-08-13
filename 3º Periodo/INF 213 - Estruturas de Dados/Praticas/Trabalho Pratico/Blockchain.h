/*
Capicoin Software - Blockchain.h
- Guardar um conjunto de blocks e aplicar operacoes com eles
- Criado por Rafael Zardo em 07/07/2022
*/

#ifndef CAPICOIN_BLOCKCHAIN_H
#define CAPICOIN_BLOCKCHAIN_H 

#include <string>

#include "Block.h"

typedef struct {
	int codUsuarioRemetente, codUsuarioRecebedor, valor, taxa;
} TransactionsTemporarias;

class TransactionsIterator;

class Blockchain {
    
private:
    Block *_dataFirst; // Ponteiro que aponta para o primeiro bloco.
    Block *_dataLast; // Ponteiro que aponta para o ultimo bloco.

    // Metodos Auxiliares
    void create();  // Metodo auxiliar para criar um novo vetor vazio.
    void destroy(); // Metodo auxiliar para liberar toda memoria alocada utilizada pelo Capicoin.
    static bool comparaTransactions(TransactionsTemporarias firstTransaction, TransactionsTemporarias secondTransaction); // Metodo para verificar se um  transacao e maior que a outra (para utilizar no sort())
   
public:
    typedef TransactionsIterator TransactionIterator;

    // Construtores da classe
    Blockchain();

    // Construtor de copia da classe 
    Blockchain(const Blockchain &);
	Blockchain & operator=(const Blockchain &);    

    // Destrutor da classe
    ~Blockchain();
    void clear(); // Libera toda memoria alocada dinamicamente e em seguida criar um novo vetor vazio.

    // Metodos especializados da classe (relacionados ao block)
    const void createBlock(TransactionsTemporarias arrayTransactions[], int qntdTransactions, int qntdMaxTransactions, int codCriador);

    // Metodos especializados da classe (relacionados ao transaction)
    const void alteraTransacao(int posBlock, int posTransation, const int codUsuarioRemetente, const int codUsuarioRecebedor, const int valor, const int taxa);

    // Metodos de exibicao de dados da classe
    const void imprimeBlockchain() const;
    const void imprimeSaldo(int blocoMax) const;

    // Metodos dos Iterators
    TransactionIterator transactionBegin() const;
	TransactionIterator transactionEnd() const;
};

class TransactionsIterator {
	friend class Blockchain;
private:
	Transaction *_ptrTransaction;
    Block *_ptrBlock;

public:
    // Construtor da classe
	TransactionsIterator(Transaction *_ptrTransaction, Block *_ptrBlock);

    // Operadores do iterator
    Transaction &operator*(); // Operador de derreferencia
	const Transaction &operator*() const; // Versao constante do operador de derreferencia
	bool operator!=(const TransactionsIterator &other) const; // Operador de diferente
    TransactionsIterator operator++(int); // Operador de posIncremento

};

#endif