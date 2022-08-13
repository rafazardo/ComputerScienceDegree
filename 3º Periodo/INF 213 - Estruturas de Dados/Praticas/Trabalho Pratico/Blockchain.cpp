/*
Capicoin Software - Block.cpp
- Implementacao dos metodos desenvolvidos na classe Block de Blockchain.h
- Criado por Rafael Zardo em 07/07/2022
*/

#include <iostream>
#include <string>
#include <algorithm>

#include "Blockchain.h"
#include "MyVec.h"

// Metodos da classe Blockchain
Blockchain::Blockchain():
    _dataFirst(NULL), _dataLast(NULL) {} ;

Blockchain::~Blockchain() {
    destroy();
}

void Blockchain::create() {
	this->_dataFirst = this->_dataLast = NULL;
}

void Blockchain::destroy() {
    while (_dataFirst != NULL) { // Ira apagar todos elementos ate _dataFirst ser igual NULL
        Block *blockAux = this->_dataFirst->_nextBlock; // Variavel auxiliar que armazena o proximo block depois de _dataFirst
        delete this->_dataFirst;
        this->_dataFirst = blockAux;
    }
}

bool Blockchain::comparaTransactions(TransactionsTemporarias firstTransaction, TransactionsTemporarias secondTransaction) {
    return firstTransaction.taxa > secondTransaction.taxa;
}

void Blockchain::clear() {
	destroy();
	create();
}

Blockchain::Blockchain(const Blockchain &blocoBase) {
	create();
	*this = blocoBase; 
}

Blockchain & Blockchain::operator=(const Blockchain &blockchainBase) {

	if (this == &blockchainBase) {
		return *this; 
	}

	clear(); // Liberar toda memoria alocada dinamicamente e em seguida criar um novo vetor vazio, para evitar erros de vazamento de memoria.

	if(blockchainBase._dataFirst == NULL) {
		this->_dataFirst = this->_dataLast = NULL; // Caso nao tenha nenhuma transaction no bloco (blockchainBase).
	} 
	else {
		Block *currBlock = blockchainBase._dataFirst;

		while (currBlock != NULL) { // Percorrer a lista de blocks e passar cada block de (blockchainBase) para (this).

            if (_dataFirst == NULL) {
                Block *blockAux = new Block(*currBlock); // Aloca dinamicamente uma variavel do tipo block, utilizando o construtor de copia de block
                _dataFirst = _dataLast = blockAux;
            }
            else {
                Block *blockAux = new Block(*currBlock); // Aloca dinamicamente uma variavel do tipo block, utilizando o construtor de copia de block
                this->_dataLast->_nextBlock = blockAux;
                this->_dataLast->_nextBlock->_prevBlock = this->_dataLast;
                this->_dataLast = this->_dataLast->_nextBlock; 
            }

			currBlock = currBlock->_nextBlock; // Avanca para o proximo bloco
		}
	}
	return *this;
}

const void Blockchain::createBlock(TransactionsTemporarias arrayTransactions[], int qntdTransactions, int qntdMaxTransactions, int codCriador) {
    if (this->_dataFirst == NULL) { // Caso nao tenha nenhum bloco do blockchain 

        Block *blockAux = new Block(1, 0, codCriador); // Defini o primeiro bloco no blockchain e por definicao ele possui pos 1, prevhash 0 e nenhuma transaction
        
        blockAux->minerarBloco();

        this->_dataFirst = this->_dataLast = blockAux;

    }
    else { // Caso ja tenha mais de 1 block no blockchain
        Block *blockAux = new Block(this->_dataLast->get_pos() + 1, this->_dataLast->getHash(), codCriador); // Como ja possui mais de um bloco, ele pegara a posicao do ultimo e acrescentara 1 e pegara o hash do ultimo, e em seguida passara a ser o ultimo bloco
        int maiorTaxa;

        if (qntdTransactions > 0) { // So ira adicionar transaction, caso a quantidade de transactions for maior que 0
            std::stable_sort(arrayTransactions,arrayTransactions+qntdTransactions,comparaTransactions); // Ordena o as taxas das transactions de ordem descrecente

            for (int k = 0; k < qntdMaxTransactions; k++) { // Pegamos na ordem que foi ordenado até a quantidade maxima de transactions do bloco, uma vez que o sort do c++ é estavel
                blockAux->addTransaction(arrayTransactions[k].codUsuarioRemetente, arrayTransactions[k].codUsuarioRecebedor, arrayTransactions[k].valor, arrayTransactions[k].taxa);
            }   
        }

        blockAux->minerarBloco(); // Minera o block antes dele ser adicionado ao blockchain

        // Adiciona o block na lista duplamente encadeada
        this->_dataLast->_nextBlock = blockAux; // Define como o proximo elemento (depois do dataLast)
        this->_dataLast->_nextBlock->_prevBlock = this->_dataLast; // Define que o novo block, tera como anterior a ele o dataLast
        this->_dataLast = this->_dataLast->_nextBlock; // Define o novo block como dataLast
    }
}

const void Blockchain::alteraTransacao(int posBlock, int posTransation, const int codUsuarioRemetente, const int codUsuarioRecebedor, const int valor, const int taxa) {

    Block *currBlock = this->_dataFirst; // Ponteiro que aponta para o primeiro bloco do blockchain
    
    int contadorTransactions = 1; // Contador para saber qual o numero da respectiva trasacao do bloco

    while (currBlock != NULL) { // Ira rodar ate chegar no final da lista de blocks

        if (currBlock->get_pos() == posBlock) {  // Se o valor da posicao do bloco no blockchain for igual ao posblock, encontramos o bloco que queremos
            Transaction *currTransaction = currBlock->_dataFirst; // Ponteiro que aponta para a primeira transaction do block
 
            while (currTransaction != NULL) { // Ira rodar ate chegar no final da lista de transactions
                if (contadorTransactions == posTransation) { // Se o valor do contador for igual ao posTransaction, encontramos a transaction que queremos
                   currTransaction->_codUsuarioRemetente = codUsuarioRemetente;
                   currTransaction->_codUsuarioRecebedor = codUsuarioRecebedor;
                   currTransaction->_valor = valor;
                   currTransaction->_taxa = taxa;
                   break; // Apos encontrar a transaction de interesse nao precisa continuar olhando
                }
                currTransaction = currTransaction->_nextTransaction; // Passa para a transaction seguinte da lista
                contadorTransactions++; // Incrementa o contador para garantir que ele acompanhe o numero da transacao
            }
            currBlock->minerarBloco();
            break; // Apos encontrar o block de interesse nao precisa continuar olhando
        }
        currBlock = currBlock->_nextBlock; // Passa para o bloco seguinte da lista
    }
}

const void Blockchain::imprimeBlockchain() const {
    if (this->_dataFirst == NULL) { // Caso nao tenha nenhum block 
        std::cout << "=====================" << std::endl;
        std::cout << std::endl; // Quando nao possui nenhum block no blockchain precisamos deixar somente essa linha em branco
        std::cout << "=====================" << std::endl;
    }
    else if (this->_dataFirst == this->_dataLast) { // So possui 1 block
        std::cout << "=====================" << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << "Pos: " << this->_dataFirst->get_pos() << std::endl;
        std::cout << "Prev hash: " << _dataFirst->get_prevHash() << std::endl;
        std::cout << "Criador: " << this->_dataFirst->get_codCriador() << std::endl; 
        std::cout << "Transacoes:\n"; // O primeiro elemento a ser mostrado, tambem nai possui nenhuma transaction
        std::cout << "Proof of work: " << this->_dataFirst->get_proofWork() << std::endl;
        std::cout << "Hash: " << this->_dataFirst->getHash() << std::endl;
        std::cout << "---------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "=====================" << std::endl;   
    }     
    else { // Possui mais de 1 blockchain
        std::cout << "=====================" << std::endl;

        Block *currBlock = _dataFirst; // Variavel auxiliar para passar na lista de blocks do blockchain

        while (currBlock != NULL) { // Ira rodar ate chegar no final da lista de blocks

            std::cout << "---------------------" << std::endl;
            std::cout << "Pos: " << currBlock->get_pos() << std::endl;
            std::cout << "Prev hash: " << currBlock->get_prevHash() << std::endl;
            std::cout << "Criador: " << currBlock->get_codCriador() << std::endl;

            std::cout << "Transacoes:\n";

            Transaction *currTransaction = currBlock->_dataFirst; // Variavel auxiliar para passar na lista de transactions do bloco

            while (currTransaction != NULL) { // Ira rodar ate chegar no final da lista de transactions

                std::cout << currTransaction->_codUsuarioRemetente << " -> " << currTransaction->_codUsuarioRecebedor;
                std::cout << " (valor: " << currTransaction->_valor << " , taxa: " << currTransaction->_taxa << ")\n";

                currTransaction = currTransaction->_nextTransaction; // Passa para proxima transaction
            }

            std::cout << "Proof of work: " << currBlock->get_proofWork() << std::endl;
            std::cout << "Hash: " << currBlock->getHash() << std::endl;

            if (currBlock->_nextBlock != NULL) { // Caso o proximo elemento for o final da lista, ele nao imprime as setas, pois nao tera mais itens posteriormente
                std::cout << "---------------------" << std::endl;
                std::cout << "          ^" << std::endl;
                std::cout << "          |" << std::endl;
                std::cout << "          v" << std::endl;
            }
            currBlock = currBlock->_nextBlock; // Passa para o proximo bloco
        }
        std::cout << "---------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "=====================" << std::endl;   
    }
}

const void Blockchain::imprimeSaldo(int blocoMax) const {

    MyVec<int> arraySaldos;
    Block *currBlock = _dataFirst;
    int maiorUsuario = 0;

    while (currBlock->get_pos() <= blocoMax) { // Ira rodar ate chegar no blockMax para tentar encontrar o maior usuario de todos os blocos

        if (currBlock->get_codCriador() > maiorUsuario) {  // Verifica o criador do bloco se e o maior usuario
            maiorUsuario = currBlock->get_codCriador();
        }        

        Transaction *currTransaction = currBlock->_dataFirst; // Variavel auxiliar para passar na lista de transactions do bloco

        while (currTransaction != NULL) { // Ira rodar ate chegar no final da lista de transactions

            if (currTransaction->_codUsuarioRemetente > maiorUsuario) { // Verifica o remetente se e o maior usuario
                maiorUsuario = currTransaction->_codUsuarioRemetente;
            }

            if (currTransaction->_codUsuarioRecebedor > maiorUsuario) { // Verifica o recebedor se e o maior usuario
                maiorUsuario = currTransaction->_codUsuarioRecebedor;
            }            

            currTransaction = currTransaction->_nextTransaction; // Passa para proxima transaction
        }

        if (currBlock->_nextBlock == NULL) { // Se o proximo elemnto dos blocks for NULL ele para de andar pela lista
            break;
        }
        else { // Caso nao for, passa para o proximo block da lista
            currBlock = currBlock->_nextBlock; 
        }
    }

    for (int n = 0; n <= maiorUsuario; n++) { // Preenche o vector de 0 ate o valor do maior usuario encontrado
        arraySaldos.push_back(0);
    }

    currBlock = _dataFirst; // Define como datafirst novamente, para passar de novo na lista de blocks 

    while (currBlock->get_pos() <= blocoMax) { // Ira rodar ate chegar no blockMax 

        arraySaldos[currBlock->get_codCriador()] += 256 >> (currBlock->get_pos()-1); // Adiciona ao criador do bloco, o valor ganho por minerar o bloco

        Transaction *currTransaction = currBlock->_dataFirst; // Variavel auxiliar para passar na lista de transactions do bloco

        while (currTransaction != NULL) { // Ira rodar ate chegar no final da lista de transactions

            arraySaldos[currBlock->get_codCriador()] += currTransaction->_taxa; // Adiciona o criado do bloco todas taxas envolvidas na transacation
            arraySaldos[currTransaction->_codUsuarioRemetente] -= (currTransaction->_valor + currTransaction->_taxa); // Remove do saldo do remetente o valor da taxa mais o valor envido para o recebedor
            arraySaldos[currTransaction->_codUsuarioRecebedor] += currTransaction->_valor; // Adiciona ao recebedor o valor que recebeu de remetente

            currTransaction = currTransaction->_nextTransaction; // Passa para proxima transaction
        }

        if (currBlock->_nextBlock == NULL) { // Se o proximo elemnto dos blocks for NULL ele para de andar pela lista
            break;
        }
        else { // Caso nao for, passa para o proximo block da lista
            currBlock = currBlock->_nextBlock; 
        }
    }

    std::cout << "====================="  << std::endl;
    std::cout << "Saldo apos bloco " << blocoMax << std::endl;

    for (int n = 0; n < arraySaldos.size(); n++) { // Ira mostrar ate o tamanho do myVec, ou seja, ate o maior usuario encontrado
        std::cout << n << " : " << arraySaldos[n] << std::endl;
    }

    std::cout << "====================="  << std::endl;
}

TransactionsIterator Blockchain::transactionBegin() const {

    if (_dataFirst->_dataFirst == NULL) { // Verifica se o primeiro block da blockchain nao possui transacoes

        Block *currBlock = _dataFirst; // Variavel auxiliar para passar na lista de blocks do blockchain

        while (currBlock != NULL) {  // Passa pela lista de blocks, ate chega no final
            if (currBlock->_dataFirst != NULL) { // O primeiro block que encontrar que possua uma transaction
                return TransactionIterator(currBlock->_dataFirst,currBlock); // Ira retorna a primeira transaction desse bloco e o bloco
            }
            currBlock = currBlock->_nextBlock; // Avanca para o proximo bloco
        }

        return TransactionIterator(NULL,NULL); // Se chegou até aqui, e por que acabou toda lista de blocks, e logo nao possui nenhum block com transaction e retorna NULL
    }
    else { // Caso o primeiro bloco tenha transacoes, podemos retorna-lo
        return TransactionIterator(_dataFirst->_dataFirst,_dataFirst);
    }
}

TransactionsIterator Blockchain::transactionEnd() const {
    return TransactionIterator(NULL,NULL);
}

// Metodos da classe TransactionIterator
TransactionsIterator::TransactionsIterator(Transaction *ptrTransaction, Block *ptrBlock): 
    _ptrTransaction(ptrTransaction), _ptrBlock(ptrBlock) {} ;

Transaction &TransactionsIterator::operator*() {
    return *this->_ptrTransaction;
}   

const Transaction &TransactionsIterator::operator*() const {
    return *this->_ptrTransaction;
}

bool TransactionsIterator::operator!=(const TransactionsIterator &other) const {
    return (this->_ptrTransaction != other._ptrTransaction);
}

TransactionsIterator TransactionsIterator::operator++(int) {
	TransactionsIterator itAux = *this;

    _ptrTransaction = _ptrTransaction->_nextTransaction; // Passa para a proxima transaction

    while (_ptrTransaction == NULL) { // Se essa transaction for igual a NULL, tentara encontrar um proximo bloco que nao tenha trasnaction como NULL
        if (_ptrBlock->_nextBlock != NULL ) { // Caso o proximo bloco for diferente de null, podemos incrementa-lo
            _ptrBlock = _ptrBlock->_nextBlock; // Avanca para o proximo bloco
        }  
        else {
            return itAux; // Caso o proximo bloco for igual a null podemos retornar pois vai ser o final dos blocos, e logo final das transactions
        }
        _ptrTransaction = _ptrBlock->_dataFirst; // Define a transaction como a primeira transaction do novo bloco
    }

	return itAux;
}