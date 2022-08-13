/*
Capicoin Software - Block.h
- Simular um bloco utilizado na tecnica de BlockChain
- Criado por Rafael Zardo em 25/06/2022
*/

#ifndef CAPICOIN_BLOCK_H
#define CAPICOIN_BLOCK_H 

#include <string>

#include "Transaction.h"
#include "SHA256.h"

class Block {
    friend class Blockchain; // Define a class blockchain como amiga, para podermos utilizar os metodos privados da classe Block
    friend class TransactionsIterator;
private:
    int _pos;
    int _prevHash;
    int _codCriador;
    int _proofWork;
    int _quantidadeTransactions;
    Transaction *_dataFirst; // Ponteiro que aponta para a primeira transaction do bloco.
    Transaction *_dataLast; // Ponteiro que aponta para a ultima transaction do bloco.

    // Metodos Auxiliares
    void destroy(); // Metodo auxiliar para liberar toda memoria alocada utilizada pelo Capicoin.
	void create();  // Metodo auxiliar para criar um novo vetor vazio.

public:
    Block *_nextBlock; // Ponteiro que aponta para o proximo block
    Block *_prevBlock; // Ponteiro que aponta para o block anterior

    // Construtores da classe
    Block();
    Block(int pos, int prevHash, int codCriador);
    Block(int pos, int prevHash, int codCriador, int proofWork);

    // Construtor de copia da classe 
    Block(const Block &);
	Block & operator=(const Block &);

    // Destrutor da classe
    ~Block();
    void clear(); // Libera toda memoria alocada dinamicamente e em seguida criar um novo vetor vazio.

    // Metodos get dos atributos privados da classe
    const int get_pos() const;
    const int get_prevHash() const;
    const int get_codCriador() const;
    const int get_proofWork() const;
    const int get_quantidadeTransactions() const;

    // Metodos especializados da classe (relacionados as transacoes)
    void addTransaction(int codUsuarioRemetente, int codUsuarioRecebedor, int valor, int taxa); 

    // Metodos especializados da classe (relacionados a mineracao)
    const void minerarBloco(); // Testa todos proofWork a partir de 0 até encontrar um que faça com que a hash do bloco tenha os 10 primeiros bits sendo 0.
    const int getHash() const; // Metodo para calcular (e retornar) o hash desse bloco.
    const std::string getHashBinario() const; // Metodo para transformar o hash em binario, utilizando dados do objeto.
    const std::string getHashBinario(int addHash) const; // Metodo para transformar o hash em binario, utilizando dados personalizados.
    const bool validaBlocoMinerado() const; // Metodo que verifica se proofWork está válido para esse bloco, ou seja, esse método verificará se o bloco foi “minerado”, utilizando dados do objeto.
    const bool validaBlocoMinerado(std::string addHashBinario) const; // Metodo que verifica se proofWork está válido para esse bloco, ou seja, esse método verificará se o bloco foi “minerado”, utilizando dados personalizados.

    // Metodos de exebicao de dados da classe
    const void exibirValidarBloco() const; // Metodo para exibir dados de forma a atender a exigencia do exercicio.
    const void exibirMinerarBlocoQuiet(); // Metodo para exibir dados de forma a atender a exigencia do exercicio.
    const void exibirMinerarBlocoVerbose(); // Metodo para exibir dados de forma a atender a exigencia do exercicio.
};

#endif