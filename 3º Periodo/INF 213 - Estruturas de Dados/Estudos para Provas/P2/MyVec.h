/*
TAD MyVec
- Representa uma lista implementada por contiguidade
- Interface similar a da classe Vector do STL
- Criado por Salles Magalhaes em 19/02/2018
- Editado por Rafael Zardo em 13/06/2022
*/

#ifndef MyVec_H__
#define MyVec_H__

#include <iostream>
#include <string>
#include <ostream>


//Excessao usada pela classe MyVec
class MyVecException {
private:
	std::string msg;
public:
	MyVecException (const std::string &msg0): msg(msg0) { }
	const std::string & what() const { return msg; }
};


template<class T>
class MyVec {
public:
	template<class T2>
	friend std::ostream& operator<<(std::ostream &, const MyVec<T2> &);

	//construtores/destrutures/etc
	MyVec();
	MyVec(int n, const T&init=T());

	//destrutor
	~MyVec() { destroy(); };

	//Construtor de copia
	MyVec(const MyVec &);
	MyVec & operator=(const MyVec &);

	//funcoes de acesso
	T &operator[](int pos) {return data[pos];}
	const T &operator[](int pos) const {return data[pos];}
	void push_back(const T&);
	void resize(int newSize);
	void insert(const T&,int pos);
	void clear();
	int eraseMatchingElements(const T&);
	void sortedInsert(const T&);

	void empty() const {return size() == 0;};
	int size() const {return dataSize;};


private:
	T *data; //declare o membro de dados data, que devera armazenar os elementos da lista
	int dataSize; //quantos elementos ha na lista?
	int dataCapacity; //quantos elementos atualmente cabem na lista? 

	void create();
	void destroy();
	void resizeCapacity(int newCapacity);
};

template<class T>
void MyVec<T>::push_back(const T&elem) {

	// === INICIO DA RESPOSTA ===	

	if (size() == dataCapacity) {
		if (dataCapacity == 0) {
			resizeCapacity(1);
		}
		else {
			resizeCapacity(2*dataCapacity);
		}
	}
	data[dataSize] = elem;
	dataSize++;

	// === FIM DA RESPOSTA ===
}

template<class T>
void MyVec<T>::resize(int newSize) {
	if(newSize >= dataCapacity) { //primeiro temos que realocar o vector...
		resizeCapacity(newSize); //para o resize vamos usar o tamanho exato caso seja necessario realocar o vector..
	}
	for(int i=dataSize;i<newSize;i++) { //preencha a parte "extra" do vector com valores "em branco"
		data[i] = T();
	}
	dataSize = newSize;
}

//insere o elemento na posicao pos e move os elementos ja presentes no vetor
// pos pode ser:
//   uma posicao apos o final do vetor (para inserir na ultima posicao) 
//   ou uma posicao ja existente (nesse caso os elementos nessa posicao e apos ela serao movidos "para a frente")
template<class T>
void MyVec<T>::insert(const T&elem,int pos) {
	if(pos > dataSize || pos < 0) {
		throw MyVecException("Erro na funcao insert: posicao invalida");
	}

	if(dataSize == dataCapacity) { //preciso redimensionar?
		if(dataCapacity == 0) //Exercicio: Por que e preciso testar isso? === INICIO DA RESPOSTA === Pois se o tamanho da capacidade for 0 e dobrarmos, ele continuara 0, permanecendo a mesma capacidade // === FIM DA RESPOSTA ===
			resizeCapacity(1);
		else
			resizeCapacity(dataCapacity*2);
	}	

	for(int i=dataSize;i>pos;i--)
		data[i] = data[i-1];
	data[pos] = elem;
	dataSize++;
}

template<class T>
void MyVec<T>::clear() {
	destroy();
	create();
}


template<class T>
void MyVec<T>::resizeCapacity(int newCapacity) {

	//implemente esta funcao
	//Ela deve redimensionar o vetor de modo que ele tenha capacidade newCapacity
	//Se newCapacity for menor do que a capacidade atual voce devera ignorar a chamada a esta funcao (i.e., nunca reduziremos a capacidade do vetor)
	//Nao se esqueca de liberar (deletar) a memoria que nao for mais necessaria (para evitar vazamentos de memoria)
	//Exemplo de execucao:
	//data=[1,2,3,,], dataSize=3, dataCapacity=5 (vetor de capacidade 5, com 3 elementos ocupados)
	//se chamarmos resizeCapacity(10), os membros de dados deverao ter os seguintes valores:
	//data=[1,2,3,,,,,,,], dataSize=3, dataCapacity=10

	// === INICIO DA RESPOSTA ===

	if (newCapacity > dataCapacity) {

		T *auxData = data; //Cria um vetor para apontar temporariamente pro vetor "antigo"

		data = new T[newCapacity]; //Transforma o vetor "antgo" em um novo, com tamanho renovado

		for (int i = 0; i < dataSize; i++) {
			data[i] = auxData[i];
		}

		delete []auxData;

		dataCapacity = newCapacity;
	}

	// === FIM DA RESPOSTA ===

}

template<class T>
void MyVec<T>::destroy() {
	delete []data;
	dataSize = dataCapacity = 0;
}

template<class T>
void MyVec<T>::create() {
	data = NULL;
	dataSize = dataCapacity = 0;
}

template<class T>
MyVec<T>::MyVec() {
	create();
}

template<class T>
MyVec<T>::MyVec(int n, const T&init) {
	//Implemente esta funcao:
	//Cria um vetor de tamanho e capacidade n, onde todos os n elementos valem "init"

	// === INICIO DA RESPOSTA ===

	data = new T[n]; //Inicia alocando esse vetor de tamanho n
	dataCapacity = n;
	dataSize = n;

	for (int i = 0; i < dataSize; i++) {
		data[i] = init;
	}

	// === FIM DA RESPOSTA ===

}


//Construtor de copia
template<class T>
MyVec<T>::MyVec(const MyVec &other) {
	//Implemente esta funcao
	//Dica: nao duplique codigo! (esta funcao deve ser escrita utilizando apenas 2 linhas de codigo!)

	// === INICIO DA RESPOSTA ===

	create();
	*this = other;

	// === FIM DA RESPOSTA ===

}

template<class T>
MyVec<T> & MyVec<T>::operator=(const MyVec &other) {
	if(this==&other) return *this; 
	destroy(); //Exercicio: por que precisamos disso? === INICIO DA RESPOSTA === Pois é necessário destruir o vetor para nao ocorrer vazamento de memoria === FIM DA RESPOSTA ===
	dataCapacity = other.dataCapacity;
	dataSize = other.dataSize;
	//data = other.data; //por que nao podemos fazer isso? === INICIO DA RESPOSTA === Pois precisamos passar cada posicao do data, em vez de passar o ponteiro === FIM DA RESPOSTA ===
	data = new T[dataCapacity];
	for(int i=0;i<dataSize;i++) data[i] = other.data[i];
	return *this;
}

template<class T2>
std::ostream& operator<<(std::ostream &out, const MyVec<T2> &v) {
	out << "Size: " << v.size() << "\n";
	out << "Capacity: " << v.dataCapacity << "\n";
	for(int i=0;i<v.size();i++) out << v.data[i] << " ";
	out << "\n";
	return out;
}

// === INICIO DA RESPOSTA ===

//Respostas PDF:
//Pior caso: Seria ter que percorrer por toda lista e encontrar o elemento desejado somente no ultimo elemnto do do vetor, ou nao encontrar o elemento.
//Seria possível melhorar utilizando algum metodo de busca mais eficiente.

template<class T>
int MyVec<T>::eraseMatchingElements(const T&element) {
	int qntdElements = 0;

	for (int i = 0; i < dataCapacity; i++) {
		if (element == data[i]) {
			data[i] = T();
			qntdElements++;
		}
	}

	for (int i = 0; i < dataCapacity; i++) {
		if (data[i] == T()) {
			int j = i + 1;
			while (j < dataCapacity) {
				if (data[j] != T()) {
					data[i] = data[j];
					data[j] = T();
					break;
				}
				j++;
			}
		}
	}

	dataSize = dataSize - qntdElements;

	return qntdElements;

}

template<class T>
void MyVec<T>::sortedInsert(const T&element) {

	for (int i = 0; i < size(); i++) {
		if (element <= data[i]) {
			insert(element,i);
			return;
		}
	}

	push_back(element);

}

// === FIM DA RESPOSTA ===


#endif