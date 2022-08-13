#include <iostream>
#include <string>
using namespace std;


// Insira aqui o codigo para a etapa 1....
//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"
#include "MyQueue.h"
#include "MyStack.h"
void etapa1() {

	MyStack<int> nPilha;
	MyQueue<int> nFila;
	int input;

	for (int i = 0; i < 6; i++) {
		cin >> input;
		nPilha.push(input);
		nFila.push(input);
	}

	while(!nPilha.empty()) {
		cout << nPilha.top() << " "; 
		nPilha.pop();
	}
	cout << endl;

	while(!nFila.empty()) {
		cout << nFila.front() << " "; 
		nFila.pop();
 	}
	cout << endl;

}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....
#include "MyStack.h"

bool validaInput(const string &input) {
	MyStack<char> nPilha;

	for(char caracter:input) {
		switch(caracter) {
			case '(':
				nPilha.push(caracter);
				break;
			case '[':
				nPilha.push(caracter);
				break;
			case '{':
				nPilha.push(caracter);
				break;
			case ')':
				if(nPilha.empty() || nPilha.top()!='(') {
					return false;
				}
				nPilha.pop();
				break;
			case ']':
				if(nPilha.empty() || nPilha.top()!='[') {
					return false;
				}
				nPilha.pop();
				break;
			case '}':
				if(nPilha.empty() || nPilha.top()!='{') {
					return false;
				}
				nPilha.pop();
				break;
		}
	}

	return nPilha.empty();
}

void etapa2() {

	std::string input;

	cin.ignore();
	getline(cin,input);
	if(validaInput(input)) {
		cout << "Consistente" << endl;
	} else {
		cout << "Inconsistente" << endl;
	}
}

//---------------------------------------

// Insira aqui o codigo para a etapa 3....


// #include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	//descomente o codigo abaixo ao fazer a etapa 3
	Mediana medianaA;
	int n,elem;	

	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		medianaA.insere(elem);
		cout << medianaA.getMediana() << " ";
	}
	cout << endl;
}

//---------------------------------------




int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
	}
}