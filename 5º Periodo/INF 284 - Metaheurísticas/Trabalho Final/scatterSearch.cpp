#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

int TOTAL_INDIVIDUOS_GERADOS = 0;
vector<vector<int> > GRAFO;

int fatorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fatorial(n - 1);
}

// ===Funções de avaliação===
vector<int> getVizinhos(int vertice) {
    vector<int> vizinhos;
    for(int i=0; i<GRAFO[vertice].size(); i++) 
        vizinhos.push_back(GRAFO[vertice][i]);

    return vizinhos;
}

bool possoEnviar(vector<int> &vizinhos, vector<bool> &auxiliar, int vertice) {
    if(auxiliar[vertice])
        return false;

    for(int i=0; i<vizinhos.size(); i++) {
        if(vizinhos[i] == vertice)
            return true;
    }

    return false;
}

int funcaoAvaliacao(vector<int> &solucao) {
    vector<bool> auxiliar(solucao.size(), false); 
    auxiliar[solucao[0]] = true;
    int numVerticesInformados = 1;
    int tempoTotal = 0;

    vector<int> informados;
    informados.push_back(solucao[0]);

    while(numVerticesInformados < GRAFO.size()) {

        int pos = 0;
        int numNovosInformados = 0;
        while(pos < numVerticesInformados) {
            
            int verticeAtual = informados[pos];
            vector<int> vizinhos = getVizinhos(verticeAtual);
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

bool comparadorCromossomo(pair<int,double> &item1, pair<int,double> &item2) {
    return item1.second < item2.second;
}

class Individuo {
public:
    int id;
    vector<double> cromossomo;
    vector<int> solucao;
    int tempo;

    Individuo(vector<double> cromossomo) {
        this->id = TOTAL_INDIVIDUOS_GERADOS;
        this->cromossomo = cromossomo;

        // Gera solução codificada pelo cromossomo
        vector<int> solucao(cromossomo.size());
        vector<pair<int, double> > parPrioridades(cromossomo.size()); 

        for (int i = 0; i < cromossomo.size(); i++) 
            parPrioridades[i] = make_pair(i, cromossomo[i]); // first = vértice, second = prioridade
        
        sort(parPrioridades.begin(), parPrioridades.end(), comparadorCromossomo);

        for (int i = 0; i < parPrioridades.size(); i++)
            solucao[i] = parPrioridades[i].first; // adiciona os vértices por ordem de prioridade
        
        this->solucao = solucao;

        this->tempo = funcaoAvaliacao(solucao);
    }

    Individuo() { }

    void print() {
        cout << "Individuo " << this->id << endl;

        cout << "Cromossomo: " << endl;
        for(double gene : this->cromossomo)
            cout << gene << " ";
        cout << endl;

        cout << "Solucao: " << endl;
        for(int vertice : this->solucao)
            cout << vertice << " ";
        cout << endl;

        cout << "Tempo: " << this->tempo << endl << endl;
    }
    
};

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

// Carrega a instância para a memória
void carregarGrafo(string arquivo) {
    int numeroVertices;
    int numeroArestas;

    ifstream finArquivo = lerArquivo("./instancias/" + arquivo + ".txt");

    finArquivo >> numeroVertices;
    GRAFO.resize(numeroVertices);
    finArquivo >> numeroArestas;
    
    for (int i = 0; i < numeroArestas; i++) {
        int vertice1, vertice2;

        finArquivo >> vertice1;
        finArquivo >> vertice2;
    
        GRAFO[vertice1].push_back(vertice2);
        GRAFO[vertice2].push_back(vertice1);
    }
}

// Estamos gerando direto o cromossomo, podemos pensar em passar a solução pronta e gerar o cromossomo a partir dela
Individuo gerarIndividuo(vector<pair<int, int> > grupos, vector<int> permutacoesGrupos, vector<double> &cromossomoGuloso, int opcao) {
    vector<double> cromossomo;

    if (opcao == 0) {
        for (int permutacao : permutacoesGrupos) {
            pair<int,int> sequencia = grupos[permutacao];

            for (int i = sequencia.first; i <= sequencia.second; i++)
                cromossomo.push_back(i);
        }
    }
    else if(opcao == 1) {
        for (int permutacao : permutacoesGrupos) {
            pair<int,int> sequencia = grupos[permutacao];

            for (int i = sequencia.second; i >= sequencia.first; i--)
                cromossomo.push_back(i);
        }
    }
    else if(opcao == 2) {
        for (int permutacao : permutacoesGrupos) {
            pair<int,int> sequencia = grupos[permutacao];

            for (int i = sequencia.first; i <= sequencia.second; i++)
                cromossomo.push_back(cromossomoGuloso[i]);
        }
    }

    Individuo individuo(cromossomo);
    return individuo;
}

// Gera cromossomo com vértices de maior grau com maior prioridade
vector<double> gerarCromossomoGuloso() {
    vector<int> solucao;
    vector<pair<int, int> > verticesComGrau; // First = vertice, second = grau

    for (int i = 0; i < GRAFO.size(); i++) {
        int grau = GRAFO[i].size();
        verticesComGrau.push_back(make_pair(i, grau));
    }

    //Ordena em ordem decrescente de grau
    sort(verticesComGrau.begin(), verticesComGrau.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    for(pair<int, int> vertice : verticesComGrau)
        solucao.push_back(vertice.first);

    vector<double> cromossomo(solucao.size());

    for(int i = 0; i < solucao.size(); i++)
        cromossomo[solucao[i]] = i;

    return cromossomo;
}

vector<Individuo> gerarPopulacao(int tamanhoPopulacao) {
    vector<Individuo> populacao;
    vector<pair<int, int> > grupos; //first e second representam posições inicial e final do grupo
    vector<int> permutacoesGruposTrivial;
    vector<int> permutacoesGruposGuloso;
    vector<double> cromossomoGuloso = gerarCromossomoGuloso();
    
    int numGrupos = 1;

    while(true) {
        if (tamanhoPopulacao <= fatorial(numGrupos)) break;
        numGrupos++;
    }

    int iteracao = GRAFO.size() / numGrupos;

    int posicao = 0;
    for (int i = 0; i < numGrupos; i++) {
        if ((posicao + iteracao - 1) >= GRAFO.size()) grupos.push_back(make_pair(posicao, GRAFO.size() - 1));
        else grupos.push_back(make_pair(posicao, posicao + iteracao - 1));
        posicao += iteracao;
    }

    //Caso elementos tenham ficado fora do último grupo
    if (grupos[grupos.size()-1].second < GRAFO.size()-1)
        grupos[grupos.size()-1].second = GRAFO.size()-1;

    for (int i = 0; i < grupos.size(); i++) {
        permutacoesGruposTrivial.push_back(i);
        permutacoesGruposGuloso.push_back(i);
    }

    vector<int> permutacoesGruposReverso = permutacoesGruposTrivial;
    reverse(permutacoesGruposReverso.begin(), permutacoesGruposReverso.end());

    do { // Cria os indivíduos a partir das permutações de grupos do cromossomo trivial
        if (populacao.size() == tamanhoPopulacao/3) break;

        Individuo individuo = gerarIndividuo(grupos, permutacoesGruposTrivial, cromossomoGuloso, 0);
        populacao.push_back(individuo);
        TOTAL_INDIVIDUOS_GERADOS++;

    } while (next_permutation(permutacoesGruposTrivial.begin(), permutacoesGruposTrivial.end()));
    
    do { // Cria os indivíduos a partir das permutações de grupos do cromossomo trivial reverso
        if (populacao.size() == (tamanhoPopulacao/3)*2) break;

        Individuo individuo = gerarIndividuo(grupos, permutacoesGruposReverso, cromossomoGuloso, 1);
        populacao.push_back(individuo);
        TOTAL_INDIVIDUOS_GERADOS++;

    } while (prev_permutation(permutacoesGruposReverso.begin(), permutacoesGruposReverso.end()));    

    do { // Cria os indivíduos a partir das permutações de grupos do cromossomo guloso
        if (populacao.size() == tamanhoPopulacao) break;

        Individuo individuo = gerarIndividuo(grupos, permutacoesGruposGuloso, cromossomoGuloso, 2);
        populacao.push_back(individuo);
        TOTAL_INDIVIDUOS_GERADOS++;

    } while (next_permutation(permutacoesGruposGuloso.begin(), permutacoesGruposGuloso.end()));

    return populacao;
}

bool comparadorIndividuos(Individuo i1, Individuo i2) {
    return i1.tempo < i2.tempo;
}

// Retorna true caso individuo estaja no conjunto de referência
bool estaNoConjuntoReferencia(vector<Individuo> &conjuntoReferencia, Individuo &individuo) {
    for (Individuo tempIndividuo : conjuntoReferencia)
        if (tempIndividuo.id == individuo.id)
            return true;
    return false;
}

// Retorna o número de posições diferentes entre a solução de indivíduo e a solução mais parecida do conjunto de referência
int gerarMinDist(Individuo &individuo, vector<Individuo> &conjuntoReferencia) {
    int menorDist = 987654321;

    for (Individuo tempIndividuo : conjuntoReferencia) {
        int numDiferentes = 0;

        for (int i = 0; i < individuo.solucao.size(); i++)
            if (individuo.solucao[i] != tempIndividuo.solucao[i])
                numDiferentes++;

        if(numDiferentes < menorDist)
            menorDist = numDiferentes;
    }

    return menorDist;
}

vector<Individuo> encontrarConjuntoReferencia(vector<Individuo> &populacao, int tamanhoConjuntoReferencia) {
    vector<Individuo> conjuntoReferencia;
    vector<Individuo> individuosOrdenadosTempo;

    for (Individuo individuo : populacao)
        individuosOrdenadosTempo.push_back(individuo);

    // Ordena indivíduos por qualidade da solução
    sort(individuosOrdenadosTempo.begin(), individuosOrdenadosTempo.end(), comparadorIndividuos);

    // Primeira metade do conjunto de referência recebe os melhores indivíduos
    for (int i = 0; i < tamanhoConjuntoReferencia / 2; i++)
        conjuntoReferencia.push_back(individuosOrdenadosTempo[i]);

    // Segunda metade do conjunto de refeência recebe os indivíduos mais diversos
    while (tamanhoConjuntoReferencia != conjuntoReferencia.size()) {
        int maior = -1;
        Individuo individuoMaisDiverso;

        for (int i = 0; i < populacao.size(); i++) {
            Individuo individuo = individuosOrdenadosTempo[i];

            if (!estaNoConjuntoReferencia(conjuntoReferencia, individuo)) {
                int minDist = gerarMinDist(individuo, conjuntoReferencia);

                if (minDist > maior) {
                    maior = minDist;
                    individuoMaisDiverso = individuo;
                }
            }
        }
        conjuntoReferencia.push_back(individuoMaisDiverso);
    }

    sort(conjuntoReferencia.begin(), conjuntoReferencia.end(), comparadorIndividuos);

    return conjuntoReferencia;
}

vector<pair<Individuo, Individuo> > gerarPais(vector<Individuo> &conjuntoReferencia) {
    vector<pair<Individuo, Individuo> > pais;

    for (int i = 0; i < conjuntoReferencia.size(); i++) {
        for (int j = i + 1; j < conjuntoReferencia.size(); j++) {
            pais.push_back(make_pair(conjuntoReferencia[i], conjuntoReferencia[j]));
        }
    }

    return pais;
}

// Retorna com a primeira melhora obtida
pair<vector<int>, int> buscaLocal(vector<int> solucao, int tempo) {
        int menorTempo = tempo;
        
        for (int i = 0; i < solucao.size() - 1; i++) {
            bool teveMelhora = false;

            for (int j = i + 1; j < solucao.size(); j++) {
                swap(solucao[i], solucao[j]);
                int tempoGasto = funcaoAvaliacao(solucao);

                if (tempoGasto < menorTempo) {
                    menorTempo = tempoGasto;
                    return make_pair(solucao, menorTempo);
                }
                
                swap(solucao[i], solucao[j]);
            }

            if (!teveMelhora)
                break;
        }
        
        return make_pair(solucao, menorTempo);
    }

vector<Individuo> gerarFilhos(vector<pair<Individuo, Individuo> > &pais, int cntIteracoesSemMelhora) {
    vector<Individuo> filhos;

    if (cntIteracoesSemMelhora == 0) { // Crossover por média aritmética

        for (int i = 0; i < pais.size(); i++) {
            vector<double> cromossomoFilho;
            for (int j = 0; j < pais[i].first.cromossomo.size(); j++) {
                double media = ((pais[i].first.cromossomo[j] + pais[i].second.cromossomo[j])/2.0);
                cromossomoFilho.push_back(media);
            }

            Individuo filho(cromossomoFilho);
            filhos.push_back(filho);
            TOTAL_INDIVIDUOS_GERADOS++;
        }

    } else if(cntIteracoesSemMelhora == 1) { // Crossover por média geométrica
        
        for (int i = 0; i < pais.size(); i++) {
            vector<double> cromossomoFilho;
            for (int j = 0; j < pais[i].first.cromossomo.size(); j++) {
                double mediaGeometrica = sqrt((pais[i].first.cromossomo[j] * pais[i].second.cromossomo[j]));
                cromossomoFilho.push_back(mediaGeometrica);
            }

            Individuo filho(cromossomoFilho);
            filhos.push_back(filho);
            TOTAL_INDIVIDUOS_GERADOS++;
        }

    } else if (cntIteracoesSemMelhora == 2) { // Crossover alternando genes dos pais
       
        for (int i = 0; i < pais.size(); i++) {
            vector<double> cromossomoFilho;
            for (int j = 0; j < pais[i].first.cromossomo.size(); j++) {
                if (j % 2 == 0)
                    cromossomoFilho.push_back(pais[i].first.cromossomo[j]);
                else
                    cromossomoFilho.push_back(pais[i].second.cromossomo[j]);
            }

            Individuo filho(cromossomoFilho);
            filhos.push_back(filho);
            TOTAL_INDIVIDUOS_GERADOS++;
        }

    } else if (cntIteracoesSemMelhora == 3) { // Crossover por quadrado da distância

        for (int i = 0; i < pais.size(); i++) {
            vector<double> cromossomoFilho;
            for (int j = 0; j < pais[i].first.cromossomo.size(); j++) {
                double distanciaEuclediana = (pais[i].first.cromossomo[j] - pais[i].second.cromossomo[j]) * (pais[i].first.cromossomo[j] - pais[i].second.cromossomo[j]);
                cromossomoFilho.push_back(distanciaEuclediana);
            }

            Individuo filho(cromossomoFilho);
            filhos.push_back(filho);
            TOTAL_INDIVIDUOS_GERADOS++;
        }    
    } else if (cntIteracoesSemMelhora == 4) { // Crossover com busca local
        // Fazer busca local com a solução dos pais
        for(int i = 0; i < pais.size(); i++) {
            pair<vector<int>, int> solucaoMelhorada1 = buscaLocal(pais[i].first.solucao, pais[i].first.tempo);

            // Escolhe a melhor solucao
            vector<double> cromossomoFilho(solucaoMelhorada1.first.size());
            if(solucaoMelhorada1.second < pais[i].second.tempo)
                for(int j = 0; j < solucaoMelhorada1.first.size(); j++)
                    cromossomoFilho[solucaoMelhorada1.first[j]] = j;
            else
                 for(int j = 0; j < pais[i].second.cromossomo.size(); j++)
                    cromossomoFilho[pais[i].second.cromossomo[j]] = j;

            Individuo filho(cromossomoFilho);
            filhos.push_back(filho);
            TOTAL_INDIVIDUOS_GERADOS++;
        }   
    }

    sort(filhos.begin(), filhos.end(), comparadorIndividuos);    
    return filhos;
}

// Se algum filho for melhor que solução no conjunto de referência, ele entra para o conjunto na posição mais elevada que conseguir, retirando o indivíduo que lá estava
void atualizarConjuntoReferencia(vector<Individuo> &conjuntoReferencia, vector<Individuo> &filhos) {
    for (Individuo filho : filhos) {
        bool achou = false;

        for (int i = 0; i < conjuntoReferencia.size(); i++) {
            if (conjuntoReferencia[i].tempo > filho.tempo) {
                conjuntoReferencia[i] = filho;
                achou = true;
                break;
            }
        }
        if (!achou) break;
    }
}

vector<int> aplicarScatterSearch(int tamanhoPopulacao, int tamanhoConjuntoReferencia) {

    vector<Individuo> populacao = gerarPopulacao(tamanhoPopulacao);

    vector<Individuo> conjuntoReferencia = encontrarConjuntoReferencia(populacao, tamanhoConjuntoReferencia);
    vector<int> solucao;
    int cntIteracaoSemMelhora = 0;

    while (cntIteracaoSemMelhora < 5) {
        vector<pair<Individuo, Individuo> > pais = gerarPais(conjuntoReferencia);

        vector<Individuo> filhos = gerarFilhos(pais, cntIteracaoSemMelhora);

        int idMelhorIndividuoAntes = conjuntoReferencia[0].id;

        atualizarConjuntoReferencia(conjuntoReferencia, filhos);

        int idMelhorIndividuoDepois = conjuntoReferencia[0].id;

        if (idMelhorIndividuoAntes != idMelhorIndividuoDepois)
            cntIteracaoSemMelhora = 0;
        else
            cntIteracaoSemMelhora++;
    }

    return conjuntoReferencia[0].solucao;
}

int main() {
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

    cout << "[==== Resultados ====]" << endl;
    
    for (string arquivo : arquivos) {
        cout << "Experimento " + arquivo << endl;
        TOTAL_INDIVIDUOS_GERADOS = 0;
        GRAFO.clear();
        carregarGrafo(arquivo);

        auto start = chrono::high_resolution_clock::now();

        vector<int> solucao = aplicarScatterSearch(800, 15);
    
        int tempoSolucao = funcaoAvaliacao(solucao);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> tempoTotal = end - start;
        
        cout << "Tempo da Solucao: " << tempoSolucao << endl; 
        cout << "Tempo gasto (segundos): " << tempoTotal.count() << std::endl;
        cout << endl;
    }

    std::cout << "[================]" << std::endl;
    return 0;
}