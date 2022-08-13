//Exercicio 2

#include <string>
#include <iostream>
using namespace std;

class Pessoa {
	public: 
		Pessoa() {}
		Pessoa(string n, int c, int i): nome(n), cpf(c), idade(i) {}
		string nome;
		int cpf;
		int idade;
};

//a) Implemente um merge sort (iterativo ou recursivo) que ordene uma lista de pessoas de forma alfabética. Em caso de empates, use a idade. Em caso de empate nas idades, use o cpf.

void merge(Pessoa array[], int begin, int meio, int end) {

	int tamArray = end - begin;
	int beginAux = begin;
	int meioAux = meio;
	int k = 0;

	Pessoa *arrayAux = new Pessoa[tamArray];

	while (beginAux < meio && meioAux < end) {
		if (array[beginAux].nome != array[meioAux].nome) { // Ordena por nome
			if (array[beginAux].nome <= array[meioAux].nome) {
				arrayAux[k++] = array[beginAux++];
			}
			else {
				arrayAux[k++] = array[meioAux++];
			}
		}
		else if (array[beginAux].idade != array[meioAux].idade) {// Ordena por idade
			if (array[beginAux].idade <= array[meioAux].idade) { 
				arrayAux[k++] = array[beginAux++];
			}
			else {
				arrayAux[k++] = array[meioAux++];
			}			
		}
		else { // Ordena por cpf
			if (array[beginAux].cpf <= array[meioAux].cpf) { 
				arrayAux[k++] = array[beginAux++];
			}
			else {
				arrayAux[k++] = array[meioAux++];
			}				
		}
	}

	while (beginAux < meio) {
		arrayAux[k++] = array[beginAux++];
	}

	while (meioAux < end) {
		arrayAux[k++] = array[meioAux++];
	}

	for (k = 0; k < tamArray; k++) {
		array[begin + k] = arrayAux[k];
	}
}

void mergeSort(Pessoa array[], int size) {

	int meio;
	int right;

	for (int cur1 = 1; cur1 <= size; cur1 = cur1 * 2) {
		for (int cur2 = 0; cur2 < size; cur2 += cur1 * 2) {

			if (cur1 + cur2 < size) {
				meio = cur1 + cur2;
			}
			else {
				meio = size;
			}

			if (2 * cur1 + cur2 < size) {
				right = 2 * cur1 + cur2;
			} 
			else {
				right = size;
			}

			merge(array, cur2, meio, right);

		}
	}
}

int main() {

	Pessoa array[6] = {Pessoa("Rafael", 1345684, 18), Pessoa("Rafael", 1245634, 18), Pessoa("Rafael", 1145634, 18), Pessoa("Ana",10000, 18), Pessoa("Ana",10000, 17), Pessoa("Ana",10001, 17)};

	for (int i = 0; i < 6; i++) {
		cout << array[i].nome << endl;
		cout << array[i].cpf << endl;
		cout << array[i].idade << endl;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=- \n";
	}

	cout << endl; 

	mergeSort(array,6);

	for (int i = 0; i < 6; i++) {
		cout << array[i].nome << endl;
		cout << array[i].cpf << endl;
		cout << array[i].idade << endl;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=- \n";
	}	


	return 0;
}

//b) É necessário se preocupar com estabilidade nesse caso? Justifique. Existe algum atributo que, se não fosse usado como parâmetro de comparação, seria necessário? Justifique.
// Nao, pois nao existe CPF igual, com isso nao vai precisa ser estavel. O cpf, pois ele que defirencia um do outro