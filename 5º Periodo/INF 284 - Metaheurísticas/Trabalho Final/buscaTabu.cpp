#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <list>
using namespace std;


// ===Funções de avaliação===
vector<int> getVizinhos(vector<vector<int> > &grafo, int vertice) {
    vector<int> vizinhos;
    for(int i=0; i<grafo[vertice].size(); i++) 
        vizinhos.push_back(grafo[vertice][i]);

    return vizinhos;
}

// Retorna true caso vertice não tenha sido informado e esteja em vizinhos
bool possoEnviar(vector<int> &vizinhos, vector<bool> &auxiliar, int vertice) {
    if(auxiliar[vertice])
        return false;

    for(int i=0; i<vizinhos.size(); i++) {
        if(vizinhos[i] == vertice)
            return true;
    }

    return false;
}

// Conta o tempo total de uma solução
int funcaoAvaliacao(vector<vector<int> > &grafo, vector<int> &solucao) {
    vector<bool> auxiliar(solucao.size(), false); 
    auxiliar[solucao[0]] = true;
    int numVerticesInformados = 1;
    int tempoTotal = 0;

    vector<int> informados;
    informados.push_back(solucao[0]);

    while(numVerticesInformados < grafo.size()) {

        int pos = 0;
        int numNovosInformados = 0;
        while(pos < numVerticesInformados) {
            
            int verticeAtual = informados[pos];
            vector<int> vizinhos = getVizinhos(grafo, verticeAtual);
            bool jaEnviei = false;
            
            for(int i=0; i<solucao.size(); i++) {
                int verticePrioritario = solucao[i];

                if(possoEnviar(vizinhos, auxiliar, verticePrioritario) && jaEnviei == false) {
                    numNovosInformados++;
                    auxiliar[verticePrioritario] = true;
                    informados.push_back(verticePrioritario);
                    jaEnviei = true;
                }
            }
            pos++;
        }
        numVerticesInformados += numNovosInformados;
        tempoTotal++;
    }

    return tempoTotal;
}
// ===Fim das funções de avaliação

ifstream lerArquivo(std::string nomeArquivo) {
    ifstream fin(nomeArquivo);

    try {
        if (!fin.is_open()) throw std::exception();
    }
    catch (std::exception &erro) {
        std::cerr << "Erro: O arquivo " << nomeArquivo << " nao foi localizado!\n";
        exit(1);
    }

    return fin;
}

// Lê a instância e constói o grafo
vector<vector<int> > carregarGrafo(string arquivo) {
    int numeroVertices;
    int numeroArestas;

    ifstream finArquivo = lerArquivo("./instancias/" + arquivo + ".txt");

    finArquivo >> numeroVertices;
    finArquivo >> numeroArestas;

    vector<vector<int> > grafo(numeroVertices);

    for (int i = 0; i < numeroArestas; i++) {
        int vertice1, vertice2;

        finArquivo >> vertice1;
        finArquivo >> vertice2;
    
        grafo[vertice1].push_back(vertice2);
        grafo[vertice2].push_back(vertice1);
    }

    return grafo;
}

vector<int> gerarSolucaoTrivial(vector<vector<int> > &grafo) {
    vector<int> solucaoTrivial;

    for (int i = 0; i < grafo.size(); i++) solucaoTrivial.push_back(i);

    return solucaoTrivial;
} 

// Gera solução com vértices de maior grau com maior prioridade
vector<int> gerarSolucaoGulosa(vector<vector<int> > &grafo) {
    vector<int> solucao;
    vector<pair<int, int> > verticesComGrau;

    for (int i = 0; i < grafo.size(); i++) {
        int grau = grafo[i].size();
        verticesComGrau.push_back(make_pair(i, grau));
    }

    //Ordena em ordem decrescente de grau
    sort(verticesComGrau.begin(), verticesComGrau.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    for(pair<int, int> vertice : verticesComGrau)
        solucao.push_back(vertice.first);

    return solucao;
}

// Retorna true caso o movimento não esteja na lista tabu ou seja melhor que a melhor solucao encontrada
bool movimentoPermitido(list<pair<int,int> > &listaTabu, pair<int, int> vizinho, int tempoMelhorSolucao, int tempoAtual) {
    list<pair<int, int>>::iterator iter;

    for (iter = listaTabu.begin(); iter != listaTabu.end(); iter++) {
        if ((*iter).first == vizinho.first && (*iter).second == vizinho.second) {
            if (tempoAtual < tempoMelhorSolucao) return true;
            else return false;
        } 
    }

    return true;
}

// Reorna o par o par (i,j) que mais melhora a solução ao fazermos swap(solucao[i], solcuao[j])
pair<int,int> encontrarMelhorVizinho(vector<vector<int> > &grafo, list<pair<int,int> > &listaTabu, vector<int> &solucaoCorrente, int custoSolucaoCorrente, int custoMelhorSolucao) {
    pair<int, int> trocaVizinho;
    int menorTempo = 987654321;

    for (int i = 0; i < solucaoCorrente.size(); i++) {
        for (int j = i + 1; j < solucaoCorrente.size(); j++) {
            swap(solucaoCorrente[i], solucaoCorrente[j]);

            int custoAtual = funcaoAvaliacao(grafo, solucaoCorrente);

            swap(solucaoCorrente[i], solucaoCorrente[j]);

            if (custoAtual < menorTempo && movimentoPermitido(listaTabu, make_pair(i,j), custoMelhorSolucao, custoAtual)) {
                menorTempo = custoAtual;
                trocaVizinho = make_pair(i,j);
            }
        }
    }

    return trocaVizinho;
}

// Faz o movimento e calcula o novo tempo
int gerarSolucaoCorrente(vector<vector<int> > &grafo, vector<int> &solucaoCorrente, pair<int,int> vizinho) {
    swap(solucaoCorrente[vizinho.first], solucaoCorrente[vizinho.second]);
    return funcaoAvaliacao(grafo, solucaoCorrente);
}

vector<int> aplicarBuscaTabu(vector<vector<int> > &grafo, vector<int> solucaoInicial, int tamanhoListaTabu, double tempoMaximo) {
    vector<int> melhorSolucao = solucaoInicial;
    int custoMelhorSolucao = funcaoAvaliacao(grafo, melhorSolucao);
    
    vector<int> solucaoCorrente = solucaoInicial;
    int custoSolucaoCorrente = custoMelhorSolucao;    
    
    list<pair<int,int> > listaTabu;

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempoTotal;    

    while (true) {
        tempoTotal = end - start;

        if (tempoTotal.count() >= tempoMaximo) break;

        pair<int,int> vizinho = encontrarMelhorVizinho(grafo, listaTabu, solucaoCorrente, custoSolucaoCorrente, custoMelhorSolucao);

        if (tamanhoListaTabu == listaTabu.size()) { // caso a lista esteja cheia
            listaTabu.pop_front();
            listaTabu.push_back(vizinho);
        } 
        else
            listaTabu.push_back(vizinho);

        custoSolucaoCorrente = gerarSolucaoCorrente(grafo, solucaoCorrente, vizinho); // realiza o melhor movimento encontrado

        if (custoSolucaoCorrente < custoMelhorSolucao) {
            custoMelhorSolucao = custoSolucaoCorrente;
            melhorSolucao = solucaoCorrente;
        }

        end = std::chrono::high_resolution_clock::now();
    }

    return melhorSolucao;
}

void exibirResultados() {
    cout << "[==== Resultados ====]" << endl;
    vector<string> arquivos;
    arquivos.push_back("H2,17");
    arquivos.push_back("H3,17");
    arquivos.push_back("H5,17");
    arquivos.push_back("H6,17");
    arquivos.push_back("H7,17");
    arquivos.push_back("H2,30");
    arquivos.push_back("H3,30");
    arquivos.push_back("H8,30");
    arquivos.push_back("H9,30");
    arquivos.push_back("H10,30");
    arquivos.push_back("H2,50");
    arquivos.push_back("H3,50");
    arquivos.push_back("H11,50");
    arquivos.push_back("H20,50");
    arquivos.push_back("H21,50");
    arquivos.push_back("H2,100");
    
    for (string arquivo : arquivos) {
        cout << "Experimento " + arquivo << endl;

        vector<vector<int> > grafo = carregarGrafo(arquivo); // Roda a heuristica para cada teste
        auto start = chrono::high_resolution_clock::now();

        // vector<int> solucaoTrivial = gerarSolucaoTrivial(grafo);
        vector<int> solucaoGulosa = gerarSolucaoGulosa(grafo);
        vector<int> solucaoFinal = aplicarBuscaTabu(grafo, solucaoGulosa, grafo.size()*0.30, 1);

        int tempoSolucao = funcaoAvaliacao(grafo, solucaoFinal);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> tempoTotal = end - start;
        
        cout << "Tempo da Solucao: " << tempoSolucao << endl; 
        cout << "Tempo gasto (segundos): " << tempoTotal.count() << std::endl;
        cout << endl;
    }

    std::cout << "[================]" << std::endl;
}

int main(void) {
    exibirResultados();
}