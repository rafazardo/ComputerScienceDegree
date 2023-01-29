/*
Trabalho Computacional - Parte 2
- Trabalho Prático da disciplina INF 332 - Projeto e Análise de Algoritmos
- Objetivos: Praticar algoritimo forca bruta para encontrar melhor ciclo hamiltoniano
- Criado por Rafael Zardo & Pedro Fiorio em 19/11/2022
*/

/*
Referencias:
- Site para auxiliar para plotar/desenhar grafos: https://graphonline.ru/pt/create_graph_by_edge_list
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <climits>
using namespace std;

std::chrono::time_point<std::chrono::system_clock> start;

bool sortSup(pair<int,int> p1, pair<int,int> p2) { // Funcao auxiliar para ordenar array
    return (p1.first < p2.first);
}

double dist(pair<int,int> p1, pair<int,int> p2) { // Calcula distancia euclediana de dois pontos
    return sqrt(pow((p2.first - p1.first), 2) + pow((p2.second - p1.second), 2));
}

// Funcao do enunciado da parte 2 do trabalho
pair<vector<pair<pair<int,int>, pair<int,int> > >, double> CombinaCiclos(vector<pair<pair<int,int>, pair<int,int> > > S1, vector<pair<pair<int,int>, pair<int,int> > > S2, double distS1, double distS2) {
    
    int valor1 = INT_MAX;
    int valor2 = INT_MAX;
    pair<int,int> pairV1; 
    pair<int,int> pairV2;

    for (int i = 0; i < S1.size(); i++) {
        for (int j = 0; j < S2.size(); j++) { 
            int tempV1 = dist(S1[i].first, S2[j].second) + dist(S1[i].second, S2[j].first) - 
            dist(S1[i].first, S1[i].second) - dist(S2[j].first, S2[j].second);
            int tempV2 = dist(S1[i].first, S2[j].first) + dist(S1[i].second, S2[j].second) - 
            dist(S1[i].first, S1[i].second) - dist(S2[j].first, S2[j].second);
            if (tempV1 < valor1) {
                pairV1.first = i; 
                pairV1.second = j;
                valor1 = tempV1;
            } 
            if (tempV2 < valor2) {
                pairV2.first = i; 
                pairV2.second = j;
                valor2 = tempV2;
            }             
        }
    }

    vector<pair<pair<int,int>, pair<int,int> > > tempS1, tempS2;
    double distS;

    tempS1 = S1;
    tempS2 = S2;
    
    tempS1.insert(tempS1.end(), tempS2.begin(), tempS2.end());

    if (valor1 < valor2) {

        tempS1.push_back(make_pair(S1[pairV1.first].first, S2[pairV1.second].second)); // S = + (a,d)
        tempS1.push_back(make_pair(S1[pairV1.first].second, S2[pairV1.second].first)); // S = + (b,c)

        tempS1.erase(find(tempS1.begin(), tempS1.end(), make_pair(S1[pairV1.first].first, S1[pairV1.first].second))); // S = - (a,b)
        tempS1.erase(find(tempS1.begin(), tempS1.end(), make_pair(S2[pairV1.second].first, S2[pairV1.second].second)));; // S = - (c,d)     

        distS = distS1 + distS2 + valor1;
    }
    else {
        tempS1.push_back(make_pair(S1[pairV2.first].first, S2[pairV2.second].first)); // S = + (a,c)
        tempS1.push_back(make_pair(S1[pairV2.first].second, S2[pairV2.second].second)); // S = + (b,d)        

        tempS1.erase(find(tempS1.begin(), tempS1.end(), make_pair(S1[pairV2.first].first, S1[pairV2.first].second))); // S = - (a,b)
        tempS1.erase(find(tempS1.begin(), tempS1.end(), make_pair(S2[pairV2.second].first, S2[pairV2.second].second)));; // S = - (c,d)      

        distS = distS1 + distS2 + valor2;        
    }
    
    return make_pair(tempS1, distS);
}

// Funcao do enunciado da parte 2 do trabalho
pair<vector<pair<pair<int,int>, pair<int,int> > >, double> DivConqPCV(vector<pair<int,int> > &p, int l, int r) {
    if (r - l <= 2) {
        pair<vector<pair<pair<int,int>, pair<int,int> > >, double> S;
        if (r - l == 1) {
            S.first.push_back(make_pair(p[l],p[r]));
            S.first.push_back(make_pair(p[r],p[l]));
            S.second = 2 * dist(p[r],p[l]);
            return S;
        } 
        if (r - l == 2) {
            S.first.push_back(make_pair(p[l],p[l+1]));
            S.first.push_back(make_pair(p[l+1],p[r]));
            S.first.push_back(make_pair(p[r],p[l]));
            S.second = dist(p[l],p[l+1]) + dist(p[l+1],p[r]) + dist(p[r],p[l]);
            return S;
        }
    }
    else {
        int m = (l+r)/2;

        pair<vector<pair<pair<int,int>, pair<int,int> > >, double> div1 = DivConqPCV(p,l,m);
        pair<vector<pair<pair<int,int>, pair<int,int> > >, double> div2 = DivConqPCV(p,m+1,r);
        pair<vector<pair<pair<int,int>, pair<int,int> > >, double> S = CombinaCiclos(div1.first, div2.first, div1.second, div2.second);
        
        return S;
    }
}

int main() {
    int qntdPontos, X, Y;
    int menorDistancia = 2147483647;
    int distancia = 0;
    pair<vector<pair<pair<int,int>, pair<int,int> > >, double> S;

    cin >> qntdPontos;

    vector<pair<int,int> > p(qntdPontos);

    for (int n = 0; n < qntdPontos; n++) {
        cin >> X >> Y;
        p[n] = make_pair(X,Y);
    }

    start = std::chrono::system_clock::now(); // Inicia a contagem de tempo do software para calcular o tempo gasto
    sort(p.begin(),p.end(), sortSup); // Ordena o array

    
    S = DivConqPCV(p, 0, p.size() - 1); 

    // Mensagens de output do terminal
    cout << "Lista de Arestas: " << endl;
    for (int i = 0; i < S.first.size(); i++)
        cout << "(" << S.first[i].first.first << "," << S.first[i].first.second <<  ")-(" << S.first[i].second.first << "," << S.first[i].second.second << ")" << endl;
    cout << endl;
    auto subTemp = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start); // Finaliza a contagem de tempo do software para calcular o tempo gasto

    cout << "Informacoes: " << endl;
    cout << "Tempo de execucao (em segundos): " << subTemp.count() << endl;
    cout << "Distancia Minima: " << S.second << endl;
    cout << endl;
   
    cout << "ATENCAO!" << endl;
    cout << "Para plotar o grafo, basta copiar a lista de arestas impressa anteriormente, do jeito que foi impressa e colar no seguinte site: ";
    cout << "https://graphonline.ru/pt/create_graph_by_edge_list" << endl;

    return 0;
}