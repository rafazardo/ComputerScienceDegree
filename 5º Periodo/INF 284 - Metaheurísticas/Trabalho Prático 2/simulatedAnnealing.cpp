/*
Traveling Salesman Problem com Simulated Annealing
- Trabalho Prático 2 da Disciplina INF 284 - Metaheuristicas
- Objetivos: praticar conceitos de TSPP com heuristicas
- Criado por Rafael Zardo e Pedro Fiorio em 17/05/2023

Informacoes IMPORTANTES:
- Comando de compilção: g++ travelingSalesmanProblem.cpp -std=c++11 
- Relatorio final: https://docs.google.com/document/d/1FVp3NpFaoMymVW0kTZ0u7LGRL37HhmF3VF1gInjAOLY/edit?usp=sharing
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h> 
#include <fstream>
#include <exception>
#include <list>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
#include <climits>

struct Cidade {
    int id;
    double x, y;
};

int NUM_THREADS = 4;
std::vector<std::vector<int> > MULTAS;
std::vector<std::vector<int> > DISTANCIAS;
std::vector<std::pair<std::vector<Cidade>, int> > RESULTADOS(NUM_THREADS);

/* ========= Funções auxiliares ========= */
int calcularDistancia(Cidade &cidade1, Cidade &cidade2) {
    return DISTANCIAS[cidade1.id-1][cidade2.id-1];
}

std::ifstream lerArquivo(std::string nomeArquivo) {
    std::ifstream fin(nomeArquivo);

    try {
        if (!fin.is_open()) throw std::exception();
    }
    catch (std::exception &erro) {
        std::cerr << "Erro: O arquivo " << nomeArquivo << " nao foi localizado!\n";
        exit(1);
    }

    return fin;
}

void criarArquivoRota(std::vector<Cidade> &rota, std::string nomeArquivo) {
    std::ofstream arquivo("./plota-rota/" + nomeArquivo + ".rota");
  
    for(int i = 0; i < rota.size(); i++) arquivo << rota[i].id << " ";

    // std::cout << "Arquivo " + nomeArquivo +  ".rota" + " criado com sucesso!" << std::endl;

    arquivo.close();
}

void criarArquivoRota(std::list<Cidade> rota, std::string nomeArquivo) {
    std::ofstream arquivo("./plota-rota/" + nomeArquivo + ".rota");
  
    while (rota.size() != 0) {
        Cidade cidadeDaRota = rota.front();
        arquivo << cidadeDaRota.id << " ";
        rota.pop_front(); 
    } 
    
    arquivo.close();
}

void gerarDistancias(std::vector<Cidade> cidades) {
    DISTANCIAS.clear();

    for (int i = 0; i < cidades.size(); i++) {
        std::vector<int> distancias(cidades.size());

        for (int j = 0; j < cidades.size(); j++) {
            distancias[j] = llround( sqrt( pow(cidades[i].x - cidades[j].x, 2.0) + pow(cidades[i].y - cidades[j].y, 2.0))); 
        }

        DISTANCIAS.push_back(distancias);
    }
}

std::vector<Cidade> carregarCidades(std::string arqCidades, std::string arqMultas) {
    std::vector<Cidade> cidades;
    int numCidades;

    MULTAS.clear();

    std::ifstream finCidades = lerArquivo("./instancias/" + arqCidades + ".tspp");
    
    // Carrega os dados das cidades
    finCidades >> numCidades;

    for (int i = 0; i < numCidades; i++) {
        Cidade cidade;

        finCidades >> cidade.id >> cidade.x >> cidade.y;
        cidades.push_back(cidade);
    }

    finCidades.close(); // Fechando o arquivo

    if(arqMultas == "@") {
        for (int i = 0; i < numCidades; i++) {
            std::vector<int> multas(numCidades); 

            for (int j = 0; j < numCidades; j++) multas[j] = 0; // Caso nao tenha arquivo de multas, definimos o vetor de multas de cada cidade como 0

            MULTAS.push_back(multas);
        }
    } else {
        std::ifstream finMultas = lerArquivo("./instancias/" + arqMultas + ".txt");

        // Carrega os dados das multas
        finMultas >> numCidades;

        for (int i = 0; i < numCidades; i++) {
            std::vector<int> multas(numCidades); 

            for (int j = 0; j < numCidades; j++) finMultas >> multas[j];

            MULTAS.push_back(multas);
        }

        finMultas.close(); // Fechando o arquivo
    }

    gerarDistancias(cidades);
    
    return cidades;
}

double aplicarMultaMetodoGuloso(std::vector<Cidade> &cidades, std::list<Cidade> rota) {
    double custoTotalMultas = 0;
    int ordemDeVisita = 0;

    // Ira adicionar a multa da cidade baseado na ordem de visita que ficou na rota
    while (rota.empty() != true) {
        Cidade cidadeDaRota = rota.front();
        custoTotalMultas += MULTAS[cidadeDaRota.id - 1][ordemDeVisita];
        
        rota.pop_front(); ordemDeVisita++; 
    } 
    
    return custoTotalMultas;
}

std::vector<Cidade> transformarListaParaVector(std::list<Cidade> rota) {
    std::vector<Cidade> cidades;

    while (rota.empty() != true) {
        Cidade cidadeDaRota = rota.front();
        cidades.push_back(cidadeDaRota);
        rota.pop_front();
    }

    return cidades;
}

void swapRota(std::vector<Cidade> &rota, int swapInicio, int swapFim) {
    std::reverse(rota.begin() + swapInicio + 1, rota.begin() + swapFim); // Inverte os elementos da rota a partir da posicao de inicio ate a posicao final
}

double calcularAntigoCusto(std::vector<Cidade> &rota, int &cidadeInicio, int &cidadeFim) {
    double custo = calcularDistancia(rota[cidadeInicio],rota[cidadeInicio+1]) + calcularDistancia(rota[cidadeFim-1],rota[cidadeFim]); // Adicionamos o custo das distancias das antigas rotas antes da inversao

    for (int i = cidadeInicio + 1; i <= cidadeFim-1; i++) custo += MULTAS[rota[i].id - 1][i]; // Adicionamos o custo das multas das antigas rotas antes da inversao
    
    return custo;
}

double calcularNovoCusto(std::vector<Cidade> &rota, int &cidadeInicio, int &cidadeFim) {
    double custo = calcularDistancia(rota[cidadeInicio],rota[cidadeFim-1]) + calcularDistancia(rota[cidadeInicio+1],rota[cidadeFim]); // Adicionamos o custo das distancias das novas rotas depois da inversao
    int multaInicio = cidadeInicio + 1;

    for (int i = cidadeFim-1; i >= cidadeInicio+1; i--) { // Adicionamos o custo das multas das novas rotas depois da inversao
        custo += MULTAS[rota[i].id - 1][multaInicio]; 
    
        multaInicio++;
    }

    return custo;
}

std::vector<Cidade> aplicar2opt(std::vector<Cidade> &rota, double &custoInicial) {
    double custoMelhorado = custoInicial;
    int swapInicio, swapFim;

    // Permutamos todas as opcoes de troca de rotas nao consecutivas
    for (int cidadeInicio = 0; cidadeInicio < rota.size();  cidadeInicio++) {
        for (int cidadeFim = cidadeInicio + 3; cidadeFim  < rota.size(); cidadeFim++) {
            int novoCustoMelhorado = custoInicial - calcularAntigoCusto(rota,cidadeInicio,cidadeFim) + calcularNovoCusto(rota,cidadeInicio,cidadeFim);

            if (novoCustoMelhorado < custoMelhorado) { // Guardamos a melhor solução das permutações
                custoMelhorado = novoCustoMelhorado;
                swapInicio = cidadeInicio; swapFim = cidadeFim;
            }
        }
    }

    // std::cout << "2-opt" << std::endl;
    if (custoMelhorado < custoInicial) { // Caso a solução seja melhor que a proposta inicialmente...
        custoInicial = custoMelhorado;
        
        swapRota(rota, swapInicio, swapFim); // Fazemos de fato o swap dessa rota no vetor e a retornamos

        return rota; 
    } else {
        return rota; // Retornamos a rota proposta inicialmente
    }
}

std::pair<int,int> gerarSwapsVizinho(int tamanhoSolucaoCorrente) {
    tamanhoSolucaoCorrente++;
    std::pair<int,int> swapsVizinho;

    // Gera aleatoriamente, possiveis vizinhos para o movimento 2-opt
    int swapInicio = std::rand() % (tamanhoSolucaoCorrente - 3);
    int swapFim = swapInicio + 3 + (std::rand() % (tamanhoSolucaoCorrente - 3 - swapInicio));

    swapsVizinho.first = swapInicio; swapsVizinho.second = swapFim-1;

    return swapsVizinho;
}

int calcularDelta(std::vector<Cidade> &solucao, int custo, std::pair<int,int> swapsVizinho) {
    int custoVizinho = custo - calcularAntigoCusto(solucao, swapsVizinho.first, swapsVizinho.second) + calcularNovoCusto(solucao, swapsVizinho.first, swapsVizinho.second);
    int delta = custoVizinho - custo;

    return delta;
}

void gerarVizinho(std::vector<Cidade> &rota, int &custo, std::pair<int,int> swapsVizinho) {
    custo = custo - calcularAntigoCusto(rota, swapsVizinho.first, swapsVizinho.second) + calcularNovoCusto(rota, swapsVizinho.first, swapsVizinho.second);
    // rota.push_back(rota[0]);
    swapRota(rota, swapsVizinho.first, swapsVizinho.second);
    // rota.pop_back();
}

int avaliarRota(std::vector<Cidade> &rota) {
    int custoTotal = calcularDistancia(rota[0],rota[rota.size()-1]);
    custoTotal += MULTAS[0][0]; 

    // Calcula o custo total da rota (funcao de avaliacao)
    for (int i = 1; i < rota.size(); i++) custoTotal += calcularDistancia(rota[i-1],rota[i]) + MULTAS[rota[i].id - 1][i]; 
    
    return custoTotal;
}

/* ========= Fim das funções auxiliares ========= */

/* ========= Funções de métodos para cálculo de custos ========= */
/* Metódo Implementado: 
- O Metódo consiste em encontrar a cidade mais proxima a partir da primeira cidade ate visitar todas cidades
- Em seguida, irá somar ao custo total das visitas, as respectivas multas de ordem de visitas de cada cidade
*/
double usarGuloso(std::vector<Cidade> &cidades, std::list<Cidade> &rota) {
    std::vector<bool> cidadesVisitadas(cidades.size(), false);
    rota.push_back(cidades[0]); // Por padrao a cidade 1 sempre sera a primeira
    Cidade cidadeComMenorDistancia;
    int custoTotal = 0;
    
    cidadesVisitadas[rota.front().id - 1] = true; // Marca a cidade 1 como visitada

    // Enquanto nossa posicao atual nao for igual o numero de cidades significa que nao visitamos todas
    while (rota.size() != cidades.size()) {
        int menorDistancia = INT_MAX;

        // Procura a menor distancia entre as cidades restantes e a ultima cidade visitada
        for (Cidade proximaCidade : cidades) {
            if (cidadesVisitadas[proximaCidade.id - 1] == false) {
                int distanciaEntreCidades = calcularDistancia(rota.back(), proximaCidade);

                if (distanciaEntreCidades < menorDistancia) {
                    menorDistancia = distanciaEntreCidades;
                    cidadeComMenorDistancia = proximaCidade;
                }
            }
        }

        // Adicionar no final da rota a cidade com menor distancia
        rota.push_back(cidadeComMenorDistancia);

        cidadesVisitadas[cidadeComMenorDistancia.id - 1] = true;
        custoTotal += menorDistancia;
    }

    // Calcula a distancia da cidade final para a primeira
    custoTotal += calcularDistancia(rota.back(), rota.front());

    // Adiciona ao custo total, as multas de ordem de visita de cada cidade
    custoTotal += aplicarMultaMetodoGuloso(cidades,rota);

    criarArquivoRota(rota, "metodoGuloso");

    return custoTotal;
}

/* Metódo Implementado: 
- O Metodo consiste em melhorar uma rota inicial qualquer, a partir da busca local, no caso, 2-opt
- A rota inicial definida é a encontrada na função usarMetodoGuloso1
*/
double usarBuscaLocal(std::vector<Cidade> &rotaMetodoGuloso, std::vector<Cidade> &rota, double custoMetodoGuloso) {
    std::vector<Cidade> rotaMetodoGulosoTemp = rotaMetodoGuloso;
    double custoTotal = custoMetodoGuloso;

    rotaMetodoGulosoTemp.push_back(rotaMetodoGulosoTemp[0]); // Adicionamos a rota inicial, no final do vetor de rotas, para facilitar as permutações
    rota = aplicar2opt(rotaMetodoGulosoTemp, custoTotal); // Realizamos a primeira busca local
    double menorCusto = custoTotal;

    while (true) {
        aplicar2opt(rota, custoTotal); // Aplicamos o 2-opt novamente

        if (custoTotal < menorCusto) menorCusto = custoTotal; // Caso o custo do 2-opt tenha melhorado, continuamos o loop
        else break; // Caso contrario, podemos para-lo
    }

    rota.pop_back(); // Removemos a rota inicial, no final do vetor de rotas, pois o mesmo não é mais necessário

    criarArquivoRota(rota, "metodoBuscaLocal");

    return custoTotal;
}

/* Metódo Implementado: 
- O Metodo consiste em melhorar uma rota inicial qualquer, a partir da uma tecnica de otimizacao estocatisca que aceita
movimentos de piora com probabilidade decrescente.
*/
int usarSimulatedAnnealing(std::vector<Cidade> &melhorSolucao, std::vector<Cidade> &rotaInicial, int custoInicial, double temperaturaInicial, double alfa, int numIteracaoMax) {
    rotaInicial.push_back(rotaInicial[0]); // Adiciona a cidade 1 no final temporariamente para os swaps do 2-opt

    std::vector<Cidade> solucaoCorrente = rotaInicial;
    int custoCorrente = custoInicial;
    double temperaturaCorrente = temperaturaInicial;

    melhorSolucao = rotaInicial;
    int custoMelhorSolucao = custoInicial;

    while (temperaturaCorrente > 1) {
        for (int numIteracao = 0; numIteracao < numIteracaoMax; numIteracao++) {
            std::pair<int,int> swapsVizinho = gerarSwapsVizinho(solucaoCorrente.size());
            int delta = calcularDelta(solucaoCorrente, custoCorrente, swapsVizinho);

            if (delta < 0) {
                gerarVizinho(solucaoCorrente, custoCorrente, swapsVizinho); // Transforma solucao corrente em seu vizinho

                if (custoCorrente < custoMelhorSolucao) { 
                    melhorSolucao = solucaoCorrente;
                    custoMelhorSolucao = custoCorrente;
                }

            } else {
                double numAleatorio = double(std::rand()%101)/100; // Escolhe um numero aleatorio entre 0-1

                if (numAleatorio < pow(2.71,(-delta*1.0)/temperaturaCorrente)) { 
                    gerarVizinho(solucaoCorrente, custoCorrente, swapsVizinho); // Transforma solucao corrente em seu vizinho
                }
            }
        }

        temperaturaCorrente *= alfa;
    }

    melhorSolucao.pop_back(); // Remove a cidade 1 no final que foi colocada temporariamente para os swaps do 2-opt
    rotaInicial.pop_back(); // Remove a cidade 1 no final que foi colocada temporariamente para os swaps do 2-opt

    criarArquivoRota(melhorSolucao, "metodoSimulatedAnnealing");

    return custoMelhorSolucao;
}

void paralelizar(int id, std::vector<Cidade> rotaInicial, int custoGuloso, int numCidades) {
    int melhorCustoSimulatedAnnealing = INT_MAX;
    int custoBuscaLocal = 0;
    int custoSimulatedAnnealing;
    std::vector<Cidade> melhorRotaSimulatedAnnealing;
    std::vector<Cidade> rotaMetodoBuscaLocal;
    
    for (int i = 0; i < 50; i++) { // Roda repetidamente os mesmos parametros em busca de gerar uma melhor solucao
        std::vector<Cidade> rotaSimulatedAnnealing;
        
        custoSimulatedAnnealing = usarSimulatedAnnealing(rotaSimulatedAnnealing, rotaInicial, custoGuloso, 700000, 0.995, 750);

        if (custoSimulatedAnnealing < melhorCustoSimulatedAnnealing) {
            melhorCustoSimulatedAnnealing = custoSimulatedAnnealing;
            melhorRotaSimulatedAnnealing = rotaSimulatedAnnealing;
        }
    }

    custoBuscaLocal = usarBuscaLocal(melhorRotaSimulatedAnnealing, rotaMetodoBuscaLocal, melhorCustoSimulatedAnnealing);   

    RESULTADOS[id] = std::make_pair(rotaMetodoBuscaLocal, custoBuscaLocal);
}

void calcularCustoDaMelhorRota(std::vector<Cidade> &cidades) {
    std::list<Cidade> rotaMetodoGuloso;
    int custoGuloso = usarGuloso(cidades, rotaMetodoGuloso);
    int numCidades = cidades.size();

    int melhorCustoSimulatedAnnealing = INT_MAX;
    std::vector<Cidade> rotaMetodoGulosoTemp = transformarListaParaVector(rotaMetodoGuloso);
    std::vector<Cidade> melhorRotaSimulatedAnnealing;
    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; i++) threads.push_back(std::thread(paralelizar, i, rotaMetodoGulosoTemp, custoGuloso, numCidades));

    for (int i = 0; i < NUM_THREADS; i++) threads[i].join();

    for (int i = 0; i < NUM_THREADS; i++) { // Encontra o melhor resultado das threads
        if (RESULTADOS[i].second < melhorCustoSimulatedAnnealing) {
            melhorRotaSimulatedAnnealing = RESULTADOS[i].first;
            melhorCustoSimulatedAnnealing = RESULTADOS[i].second;
        }
    }

    std::cout << melhorCustoSimulatedAnnealing << std::endl;

}

void exibirResultados() {
    std::cout << "[==== Resultados ====]" << std::endl;
    std::vector<std::pair<std::string, std::string> > arquivos; // Armazena os arquivos que serão testados

    // Adiciona os casos de teste para serem testados
    arquivos.push_back(std::make_pair("burma14","burma14-zero"));
    arquivos.push_back(std::make_pair("burma14","burma14-cedo"));
    arquivos.push_back(std::make_pair("burma14","burma14-mix"));

    arquivos.push_back(std::make_pair("berlin52","berlin52-zero"));
    arquivos.push_back(std::make_pair("berlin52","berlin52-cedo"));
    arquivos.push_back(std::make_pair("berlin52","berlin52-cedo2"));
    arquivos.push_back(std::make_pair("berlin52","berlin52-mix"));
    arquivos.push_back(std::make_pair("berlin52","berlin52-mix2"));

    arquivos.push_back(std::make_pair("st70","st70-zero"));
    arquivos.push_back(std::make_pair("st70","st70-cedo"));
    arquivos.push_back(std::make_pair("st70","st70-cedo2"));
    arquivos.push_back(std::make_pair("st70","st70-cedo3"));
    arquivos.push_back(std::make_pair("st70","st70-mix"));
    arquivos.push_back(std::make_pair("st70","st70-mix2"));

    arquivos.push_back(std::make_pair("gil262","@"));
    arquivos.push_back(std::make_pair("gr666","@"));
    arquivos.push_back(std::make_pair("dsj1000","@"));

    // Resultaos sem calibragem previa, somente com a calibragem estudada pelos anteriores
    arquivos.push_back(std::make_pair("gil262","gil262-cedo"));
    arquivos.push_back(std::make_pair("gil262","gil262-mix"));
    arquivos.push_back(std::make_pair("gr666","gr666-cedo"));
    arquivos.push_back(std::make_pair("gr666","gr666-mix"));
    arquivos.push_back(std::make_pair("dsj1000","dsj1000-cedo"));
    arquivos.push_back(std::make_pair("dsj1000","dsj1000-mix"));

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < arquivos.size(); i++) {
        std::vector<Cidade> cidades = carregarCidades(arquivos[i].first, arquivos[i].second);

        calcularCustoDaMelhorRota(cidades); // Roda a heuristica para cada teste
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempoTotal = end - start;

    std::cout << "[================]" << std::endl;
    std::cout << "Tempo gasto (segundos): " << tempoTotal.count() << std::endl;
    
}
/* ========= Fim das funções de métodos para cálculo de custos ========= */

int main(void) {
    std::srand(std::time(0));

    exibirResultados();
}