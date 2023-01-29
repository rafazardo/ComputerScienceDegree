/*
Trabalho Computacional - Parte 1
- Trabalho Prático da disciplina INF 332 - Projeto e Análise de Algoritmos
- Objetivos: Praticar algoritimo forca bruta para encontrar melhor ciclo hamiltoniano
- Criado por Rafael Zardo & Pedro Fiorio em 05/11/2022
*/

/*
Referencias:
- Algoritimo para gerar permutacao adptado pelo algoritimo disponibilizado pelo professor da Disciplina logo abaixo:
https://gist.github.com/marcoscastro/60f8f82298212e267021
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
using namespace std;

std::chrono::time_point<std::chrono::system_clock> start; 

int calculaDistancia(int X1, int X2, int Y1, int Y2) { // Funcao que calcula a distancia euclediana de dois pontos (vertices)
    return (X2 - X1)*(X2 - X1) + (Y2 - Y1)*(Y2 - Y1);
}

double calculaDistanciaMinima(vector<pair<int,int> > &grafo, vector<int> &melhorCiclo) { // Funcao que calcula aplicando a raiz da distancia euclediana, do melhor ciclo hamiltoniano
    double distancia = 0;
    for (int n = 0; n < grafo.size(); n++) {
        distancia += sqrt(calculaDistancia(grafo[melhorCiclo[n]].first, grafo[melhorCiclo[n+1]].first, grafo[melhorCiclo[n]].second, grafo[melhorCiclo[n+1]].second)); 
    }
    return distancia;
}

void exibirCicloHamiltoniano(vector<pair<int,int> > &grafo, vector<int> &melhorCiclo) { // Funcao que exibe os vertices visitados do melhor ciclo hamiltoniano
    cout << "Ciclo Hamiltoniano: ";

    for (int n = 0; n < melhorCiclo.size(); n++) {
        cout << melhorCiclo[n] + 1;
        if (n != melhorCiclo.size()-1) cout << "-";
    }       
    cout << endl;
    cout << "Distancia Minima: " << calculaDistanciaMinima(grafo, melhorCiclo) << endl;
}

void swap(vector<int> &indice, int i, int j) { //Funcao swap para alterar valor da variavel dentro de um array
	int aux = indice[i];
	indice[i] = indice[j];
	indice[j] = aux;
}

void permuta(vector<int> &indice, vector<int> &melhorCiclo, vector<pair<int,int> > &grafo, int inf, int sup, int &distancia, int &menorDistancia, int qntdPontos) { // Funcao para permutar os possiveis caminhos do ciclo Hamiltoniano
	if(inf == sup) {
		for(int i = 0; i <= sup; i++) {
            auto subTemp = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start);  // Finaliza a contagem de tempo do software para calcular o tempo gasto
            if (subTemp.count() >= 3600) { // Caso chegue no tempo maximo (1 hora), o programa sera finalizado e ira imprimir o melhor ciclo encontrado naquele momento
                cout << "Tempo de execucao (em segundos): " << subTemp.count() << endl;
                exibirCicloHamiltoniano(grafo, melhorCiclo);
                exit(0);
            }

            for (int n = 0; n < qntdPontos; n++) { // Calcula a distancia do ciclo
                distancia += calculaDistancia(grafo[indice[n]].first, grafo[indice[n+1]].first, grafo[indice[n]].second, grafo[indice[n+1]].second); 
            }

            if (distancia < menorDistancia) { // Verifica se a menor distancia encontrada ate agora, se for guarda esse ciclo encontrado
                menorDistancia = distancia;
                melhorCiclo = indice;    
            }
            distancia = 0;            
        }
	}
	else {
		for(int i = inf; i <= sup; i++) {
			swap(indice, inf, i);
			permuta(indice, melhorCiclo, grafo, inf + 1, sup, distancia, menorDistancia, qntdPontos);
			swap(indice, inf, i); // Realiza o backtracking
		}
	}
}

int main() {
    int qntdPontos, X, Y;
    int menorDistancia = 2147483647;
    int distancia = 0;

    cin >> qntdPontos;

    vector<pair<int,int> > grafo(qntdPontos);
    vector<int> indice(qntdPontos+1);
    vector<int> melhorCiclo;

    for (int n = 0; n < qntdPontos; n++) {
        cin >> X >> Y;
        grafo[n] = make_pair(X,Y);
        indice[n] = n;
    }

    indice[qntdPontos] = 0;

    start = std::chrono::system_clock::now(); // Inicia a contagem de tempo do software para calcular o tempo gasto

    permuta(indice, melhorCiclo, grafo, 1, qntdPontos-1, distancia, menorDistancia, qntdPontos);

    auto subTemp = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start); // Finaliza a contagem de tempo do software para calcular o tempo gasto

    cout << "Tempo de execucao (em segundos): " << subTemp.count() << endl;
    exibirCicloHamiltoniano(grafo, melhorCiclo);

    return 0;
}