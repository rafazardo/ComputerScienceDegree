#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

struct Pessoa {
	string nome;
	int cpf;
	double altura;
};

void ordenaNome(Pessoa *pessoas,int n) {
    for (int i = 1; i < n; i++) {
        // o arranjo entre as posicoes [0,i) já está ordenado
        Pessoa elemInserir = pessoas[i];
        int j = i-1;
        while(j >= 0 && pessoas[j].nome > elemInserir.nome) {
            pessoas[j+1] = pessoas[j];
            j--;
        }
        pessoas[j+1] = elemInserir;
    }
}

void ordenaCPF(Pessoa *pessoas,int n) {
    for (int i = 1; i < n; i++) {
        // o arranjo entre as posicoes [0,i) já está ordenado
        Pessoa elemInserir = pessoas[i];
        int j = i-1;
        while(j >= 0 && pessoas[j].cpf > elemInserir.cpf) {
            pessoas[j+1] = pessoas[j];
            j--;
        }
        pessoas[j+1] = elemInserir;
    }
}

void ordenaPessoas(Pessoa *pessoas,int n) {

	ordenaCPF(pessoas, n);

	ordenaNome(pessoas, n);

}

/*
Exemplo de entrada:
5
Dbc 123 1.8
Abc 194 1.7
Abc 125 1.9
Teste 100 1.1
Alto 300 3.2

Saida esperada:
Abc 125 1.9
Abc 194 1.7
Alto 300 3.2
Dbc 123 1.8
Teste 100 1.1
*/


//Não modifique nada daqui para baixo...
int main(int argc, char **argv) {
	//O arquivo de entrada contém um numero n. 
	//A seguir, há n linhas cada uma contendo o nome, cpf e altura de uma pessoa (separados por um espaço em branco)
	//O nome eh sempre composto de um unico token
	int n;
	cin >> n;
	Pessoa *pessoas = new Pessoa[n];
	for(int i=0;i<n;i++) {
		cin >> pessoas[i].nome >> pessoas[i].cpf >> pessoas[i].altura;
	}

	ordenaPessoas(pessoas,n);

	//imprime a saída ordenada
	for(int i=0;i<n;i++) {
		cout << pessoas[i].nome << " " <<  pessoas[i].cpf << " " <<  pessoas[i].altura << '\n';
	}


	delete []pessoas;
	return 0;
}