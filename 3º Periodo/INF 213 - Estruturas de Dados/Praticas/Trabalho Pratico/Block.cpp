/*
Capicoin Software - Block.cpp
- Implementacao dos metodos desenvolvidos na classe Block de Block.h
- Criado por Rafael Zardo em 25/06/2022
*/

#include <iostream>
#include <string>

#include "Block.h"

Block::Block(): // Construtor sem entradas inicializando o objeto
	_quantidadeTransactions(0), _dataFirst(NULL), _dataLast(NULL), _nextBlock(NULL), _prevBlock(NULL) {} ;

Block::Block(int pos, int prevHash, int codCriador): // Construtor com entradas personalizadas inicializando o objeto
    _pos(pos), _prevHash(prevHash), _codCriador(codCriador), _quantidadeTransactions(0), _dataFirst(NULL), _dataLast(NULL), _nextBlock(NULL), _prevBlock(NULL) {} ;

Block::Block(int pos, int prevHash, int codCriador, int proofWork): // Construtor com entradas personalizadas inicializando o objeto
    _pos(pos), _prevHash(prevHash), _codCriador(codCriador), _proofWork(proofWork), _quantidadeTransactions(0), _dataFirst(NULL), _dataLast(NULL), _nextBlock(NULL), _prevBlock(NULL) {} ;   

Block::~Block() {
	destroy(); 
}

void Block::create() {
	this->_dataFirst = this->_dataLast = NULL;
	this->_quantidadeTransactions = 0;
}

void Block::destroy() {
	while (this->_dataFirst != NULL) { // Ira apagar todos elementos ate _dataFirst ser igual NULL
		Transaction *dataFirstAux = this->_dataFirst->_nextTransaction; // Variavel auxiliar que armazena a proxima transacao depois de _dataFirst
		delete this->_dataFirst;
		this->_dataFirst = dataFirstAux;
	}
}

void Block::clear() {
	destroy();
	create();
}

Block::Block(const Block &blocoBase) {
	create();
	*this = blocoBase; 
}

Block & Block::operator=(const Block &blocoBase) {

	if (this == &blocoBase) {
		return *this; 
	}

	// Passar os dados do block (blocoBase) para o outro block (this) 
	this->_pos = blocoBase._pos;
	this->_prevHash = blocoBase._prevHash;
	this->_codCriador = blocoBase._codCriador;
	this->_proofWork = blocoBase._proofWork;
	this->_quantidadeTransactions = blocoBase._quantidadeTransactions;

	clear(); // Liberar toda memoria alocada dinamicamente e em seguida criar um novo vetor vazio, para evitar erros de vazamento de memoria.

	if(blocoBase._dataFirst == NULL) {
		this->_dataFirst = this->_dataLast = NULL; // Caso nao tenha nenhuma transaction no bloco (blocoBase).
	} 
	else {
		Transaction *curr = blocoBase._dataFirst;

		while (curr != NULL) { // Percorrer a lista de Transacions e passar cada Transacion de (blocoBase) para (this).
			addTransaction(curr->_codUsuarioRemetente, curr->_codUsuarioRecebedor, curr->_valor, curr->_taxa);
			curr = curr->_nextTransaction; // Avanca para a proxima Transaction
		}
	}
	return *this;
}

const int Block::get_pos() const{
    return this->_pos;
}

const int Block::get_prevHash() const {
    return this->_prevHash;
}

const int Block::get_codCriador() const {
    return this->_codCriador;
}

const int Block::get_proofWork() const {
    return this->_proofWork;
}

const int Block::get_quantidadeTransactions() const{
	return this->_quantidadeTransactions;
}

void Block::addTransaction(int codUsuarioRemetente, int codUsuarioRecebedor, int valor, int taxa) {

	if(this->_dataFirst == NULL) { // Caso o block nao houver nenhuma Transaction, ira criar sua primeira.
		this->_dataFirst = this->_dataLast = new Transaction(codUsuarioRemetente, codUsuarioRecebedor, valor, taxa);
	} 
    else { // Caso o block ja possuir uma Transaction, ira alocar essa nova Transaction depois de _dataLast, em seguida definira essa nova Transaction como _dataLast.
		this->_dataLast->_nextTransaction = new Transaction(codUsuarioRemetente, codUsuarioRecebedor, valor, taxa);
		this->_dataLast = this->_dataLast->_nextTransaction;
	}
	this->_quantidadeTransactions++; // Aumenta o numero de Transaction do Objeto.
}

const void Block::minerarBloco() {

	this->_proofWork = 0; // Define o _proofWork como 0, uma vez que a mineracao comeca de um proofWork 0 até achar um compativel.

	while (validaBlocoMinerado() != true) { // Verifica se o novo _proofWork é valido, ele ira incrementar uma unidade ao valor de _proofWork, até encontrar um _proofWork válido. 
		this->_proofWork++;
	}
}

const int Block::getHash() const {

	int arrayHash[4 + 4 * this->_quantidadeTransactions]; // Array com tamanho exato da quantidade de inteiros do bloco.
	int contadorArray = 3; // Contador auxiliar, para adicionar os inteiros das transacoes logo apos os inteiros _pos, _prevHash e _codCriador, por conta disso ele deve ser inicializado com valor 3.
	SHA256 BlockHash;
	Transaction *dataAux = this->_dataFirst;
	
	arrayHash[0] = this->_pos;
	arrayHash[1] = this->_prevHash;
	arrayHash[2] = this->_codCriador;

	while (dataAux != NULL) { // Percorre todas transacoes em ordem adicionando cada inteiro das mesmas no array
		arrayHash[contadorArray++] = dataAux->_codUsuarioRemetente;
		arrayHash[contadorArray++] = dataAux->_codUsuarioRecebedor;
		arrayHash[contadorArray++] = dataAux->_valor;
		arrayHash[contadorArray++] = dataAux->_taxa;
		dataAux = dataAux->_nextTransaction; // Avanca para proxima Transaction
	}

	arrayHash[contadorArray] = this->_proofWork; // O ultimo elemento do array é preenchido com o inteiro _proofWork.

    return BlockHash.calcula(arrayHash,(4 + 4 * this->_quantidadeTransactions)); // Retorna o valor inteiro de hash do arrayHash.
}

const std::string Block::getHashBinario() const {

	std::string numBinario = "00000000000000000000000000000000"; // Array de char para guardar os 32 bits do numero em binario
    std::string numBinarioInvertido = "00000000000000000000000000000000";
    std::string numBinarioNegativo = "00000000000000000000000000000000";
    bool vaiUm = true;
    int contadorAux = 0; 
    int addHash = getHash();

    if (addHash >= 0 ) { // Se o hash for positivo, apenas transforma o numero em binario       
    
        while (addHash > 0) { // Ira dividir o hash por 2 até chegar 0, colocando o resto de cada divisao no array
            if (addHash % 2 == 0) {
                numBinario[contadorAux] = '0';
            }
            else {
                numBinario[contadorAux] = '1';
            }
            addHash = addHash / 2;
            contadorAux++;
        }

        for (int i = 0; i < 32; i++) { // Inverte o array para o numero em binario ficar correto
            numBinarioInvertido[i] = numBinario[32-i-1];
        }

        return numBinarioInvertido; 
    } 
    else { // Se o hash for negativo, ira achar o binario do hash positivo, em seguida aplicar complemento de um, em seguida aplicar complemento de dois, e por fim deixar o primeiro elemento do array como '1' para indicar sinal de negativo.

        addHash = addHash * -1; // Deixa o valor do hash positivo
    
        while (addHash > 0) { // Ira dividir o hash por 2 até chegar 0, colocando o resto de cada divisao no array
            if (addHash % 2 == 0) {
                numBinario[contadorAux] = '0';
            }
            else {
                numBinario[contadorAux] = '1';
            }
            addHash = addHash / 2;
            contadorAux++;
        }

        for (int i = 0; i < 32; i++) { // Inverte o array para o numero em binario ficar correto
            numBinarioInvertido[i] = numBinario[32-i-1];

            // Enquanto inverte o array, aplica o complemento de um (alterar os elementos 1 para 0 e elementos 0 para 1 do numero em binario)
            if (numBinarioInvertido[i] == '1') { 
                numBinarioInvertido[i] = '0';
            }
            else if (numBinarioInvertido[i] == '0') {
                numBinarioInvertido[i] = '1';
            }
        }

        for (int i = 32 - 1; i >= 0; i--) {  // Aplicamos o complemento de dois, somamos ao complemento de um (numBinarioInvertido) o valor 1 em binario.
            if(numBinarioInvertido[i] == '1' && vaiUm == true) { // Se for necessário somar 1, ira fazer 1 + 1 = 0, e continuara o vaiUm para o proximo elemento.
                numBinarioNegativo[i] = '0';  
            } 
            else if (numBinarioInvertido[i] == '0' && vaiUm == true) { // Se for necessário somar 1, ira fazer 1 + 0 = 1, e nao sera necessário continuar o vaiUm para o proximo elemento.
                numBinarioNegativo[i] = '1'; 
                vaiUm = false; // Como tivemos 1 + 0 = 1, nao sera necessario passar o 1 para o proximo elemento, logo nao sera necessário o vaiUm.
            } 
            else { // Neste caso nao sera necessário somar 1 aos proximos elementos do vetor, pois o vaiUm deixou de ser necessário, e como os proximos elemento de 1 sao somente zero, podemos apenas copiar o restante de elementos de numBinarioInvertido para numBinarioNegativo.
                numBinarioNegativo[i] = numBinarioInvertido[i];  
            }
        }

        numBinarioNegativo[0] = '1'; // Garante que o primeiro digito em binario será '1' para representar o sinal de negativo do hash.

        return numBinarioNegativo; 
    }
}

const std::string Block::getHashBinario(int addHash) const { 

	std::string numBinario = "00000000000000000000000000000000"; // Array de char para guardar os 32 bits do numero em binario
    std::string numBinarioInvertido = "00000000000000000000000000000000";
    std::string numBinarioNegativo = "00000000000000000000000000000000";
    bool vaiUm = true;
    int contadorAux = 0; 

    if (addHash >= 0 ) { // Se o hash for positivo, apenas transforma o numero em binario       
    
        while (addHash > 0) { // Ira dividir o hash por 2 até chegar 0, colocando o resto de cada divisao no array
            if (addHash % 2 == 0) {
                numBinario[contadorAux] = '0';
            }
            else {
                numBinario[contadorAux] = '1';
            }
            addHash = addHash / 2;
            contadorAux++;
        }

        for (int i = 0; i < 32; i++) { // Inverte o array para o numero em binario ficar correto
            numBinarioInvertido[i] = numBinario[32-i-1];
        }

        return numBinarioInvertido; 
    } 
    else { // Se o hash for negativo, ira achar o binario do hash positivo, em seguida aplicar complemento de um, em seguida aplicar complemento de dois, e por fim deixar o primeiro elemento do array como '1' para indicar sinal de negativo.

        addHash = addHash * -1; // Deixa o valor do hash positivo
    
        while (addHash > 0) { // Ira dividir o hash por 2 até chegar 0, colocando o resto de cada divisao no array
            if (addHash % 2 == 0) {
                numBinario[contadorAux] = '0';
            }
            else {
                numBinario[contadorAux] = '1';
            }
            addHash = addHash / 2;
            contadorAux++;
        }

        for (int i = 0; i < 32; i++) { // Inverte o array para o numero em binario ficar correto
            numBinarioInvertido[i] = numBinario[32-i-1];

            // Enquanto inverte o array, aplica o complemento de um (alterar os elementos 1 para 0 e elementos 0 para 1 do numero em binario)
            if (numBinarioInvertido[i] == '1') { 
                numBinarioInvertido[i] = '0';
            }
            else if (numBinarioInvertido[i] == '0') {
                numBinarioInvertido[i] = '1';
            }
        }

        for (int i = 32 - 1; i >= 0; i--) {  // Aplicamos o complemento de dois, somamos ao complemento de um (numBinarioInvertido) o valor 1 em binario.
            if(numBinarioInvertido[i] == '1' && vaiUm == true) { // Se for necessário somar 1, ira fazer 1 + 1 = 0, e continuara o vaiUm para o proximo elemento.
                numBinarioNegativo[i] = '0';  
            } 
            else if (numBinarioInvertido[i] == '0' && vaiUm == true) { // Se for necessário somar 1, ira fazer 1 + 0 = 1, e nao sera necessário continuar o vaiUm para o proximo elemento.
                numBinarioNegativo[i] = '1'; 
                vaiUm = false; // Como tivemos 1 + 0 = 1, nao sera necessario passar o 1 para o proximo elemento, logo nao sera necessário o vaiUm.
            } 
            else { // Neste caso nao sera necessário somar 1 aos proximos elementos do vetor, pois o vaiUm deixou de ser necessário, e como os proximos elemento de 1 sao somente zero, podemos apenas copiar o restante de elementos de numBinarioInvertido para numBinarioNegativo.
                numBinarioNegativo[i] = numBinarioInvertido[i];  
            }
        }

        numBinarioNegativo[0] = '1'; // Garante que o primeiro digito em binario será '1' para representar o sinal de negativo do hash.

        return numBinarioNegativo; 
    }
}

const bool Block::validaBlocoMinerado() const {

	std::string valorHashBin = getHashBinario(getHash()); // Coleta o valor de Hash em binario

	for (int i = 32 - 1; i >= 22; i--) { // Percorre os 10 primeiros elementos do valor em binario
		if (valorHashBin[i] == '1') { 
			return false; // Se possuir um elemento 1 nos 10 primeiros, ele é um hash invalido, e por isso retorna false.
		}
	}

	return true; // Se o programa chegou até aqui, nao foi encontrado nenhum elemento 1 nos 10 primeiros, logo é um hash valido, e por isso retorna true.

}

const bool Block::validaBlocoMinerado(std::string addHashBinario) const {

	std::string valorHashBin = addHashBinario; // Coleta o valor de Hash em binario.

	for (int i = 32 - 1; i >= 22; i--) { // Percorre os 10 primeiros elementos do valor em binario
		if (valorHashBin[i] == '1') { 
			return false; // Se possuir um elemento 1 nos 10 primeiros, ele é um hash invalido, e por isso retorna false.
		}
	}

	return true; // Se o programa chegou até aqui, nao foi encontrado nenhum elemento 1 nos 10 primeiros, logo é um hash valido, e por isso retorna true.
}

const void Block::exibirValidarBloco() const {

	std::cout << getHash() << std::endl;
    std::cout << getHashBinario() << std::endl;

    if (validaBlocoMinerado() == true) {
        std::cout << "OK" << std::endl;
    }   
    else {
        std::cout << "Nao minerado" << std::endl;
    }

}

const void Block::exibirMinerarBlocoQuiet() {

	minerarBloco();

    std::cout << get_proofWork() << std::endl;
    std::cout << getHash() << std::endl;
    std::cout << getHashBinario() << std::endl;

}

const void Block::exibirMinerarBlocoVerbose() {

	int arrayHash[4 + 4 * this->_quantidadeTransactions]; // Array com tamanho exato da quantidade de inteiros do bloco.
	int contadorArray = 3; // Contador auxiliar, para adicionar os inteiros das transacoes logo apos os inteiros _pos, _prevHash e _codCriador, por conta disso ele deve ser inicializado com valor 3.
	SHA256 BlockHas;
	Transaction *dataAux = this->_dataFirst;
	std::string valorHashBin;
		 
	this->_proofWork = 0; // Define o _proofWork como 0, uma vez que a mineracao comeca de um proofWork 0 até achar um compativel.

	arrayHash[0] = this->_pos;
	arrayHash[1] = this->_prevHash;
	arrayHash[2] = this->_codCriador;

	while (dataAux != NULL) { // Percorre todas transacoes em ordem adicionando cada inteiro das mesmas no array
		arrayHash[contadorArray++] = dataAux->_codUsuarioRemetente;
		arrayHash[contadorArray++] = dataAux->_codUsuarioRecebedor;
		arrayHash[contadorArray++] = dataAux->_valor;
		arrayHash[contadorArray++] = dataAux->_taxa;
		dataAux = dataAux->_nextTransaction; // Avanca para proxima Transaction
	}

	while (true) { // Ira continuar até encontrar um valor de _proofWork válido.
		arrayHash[contadorArray] = this->_proofWork; // Adiciona ao array de inteiros, na ultima posicao, o novo valor de _proofWork.

		for (int i = 0; i < 4 + 4 * this->_quantidadeTransactions; i++) { // Exibe todo array de Hash.
			std::cout << arrayHash[i] << " ";
		}
		std::cout << std::endl;

		valorHashBin = getHashBinario(BlockHas.calcula(arrayHash,(4 + 4 * this->_quantidadeTransactions))); // Coleta o valor do hash em binario, com o novo _proofWork.

		std::cout << valorHashBin << std::endl;
		std::cout << std::endl;

		if (validaBlocoMinerado(valorHashBin) == true) { // Caso o hash em binario seja valido com o novo _proofWork o looping e finalizado.
			break;
		}
		else { // Caso o hash em binario nao seja valido com o novo _proofWork o looping continua e incrementa uma unidade ao valor de _proofWork.
			this->_proofWork++;
		}
	}

	std::cout << this->_proofWork << std::endl;
	std::cout << getHash() << std::endl;
	std::cout << getHashBinario() << std::endl;

}