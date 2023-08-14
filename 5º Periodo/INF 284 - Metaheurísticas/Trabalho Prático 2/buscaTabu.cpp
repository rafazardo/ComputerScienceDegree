/*
Traveling Salesman Problem com Busca Tabu
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
#include <algorithm>
#include <climits>
#include <thread>

struct Cidade {
    int id;
    double x, y;
};

const int NUM_THREADS = 2;
std::vector<std::vector<int> > MULTAS;
std::vector<std::vector<int> > DISTANCIAS;
std::vector<int> RESULTADOS(NUM_THREADS);

/* ========= Funções auxiliares ========= */
int calcularDistancia(Cidade &cidade1, Cidade &cidade2) {
    return DISTANCIAS[cidade1.id-1][cidade2.id-1];
}

double calcularDistanciaSmoothing(Cidade &cidade1, Cidade &cidade2, int alfa, double media, int maiorDistancia) {
    double distanciaEntreCidades = calcularDistancia(cidade1, cidade2);
    double distanciaNormalizada = distanciaEntreCidades / maiorDistancia;
    double distanciaFinal;

    if (distanciaNormalizada >= media) {
        distanciaFinal = media + pow(distanciaNormalizada - media, alfa);
    } else {
        distanciaFinal = media - pow(distanciaNormalizada - media, alfa);
    }

    return distanciaFinal;
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

    // std::cout << "Arquivo " + nomeArquivo + ".rota" + " criado com sucesso!" << std::endl;
    
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

    if (custoMelhorado < custoInicial) { // Caso a solução seja melhor que a proposta inicialmente...
        custoInicial = custoMelhorado;
        
        swapRota(rota, swapInicio, swapFim); // Fazemos de fato o swap dessa rota no vetor e a retornamos

        return rota; 
    } else {
        return rota; // Retornamos a rota proposta inicialmente
    }
}

bool checarListaTabu(std::list<std::pair<int,int> > listaTabu, std::pair<int,int> movimento) {
    while (!listaTabu.empty()) { // Verifica se o movimento de vizinho nao esta na lista tabu
        if (movimento == listaTabu.front()) return true;
        listaTabu.pop_front();
    }

    return false;
}

std::pair<int,int> criarVizinho(std::vector<Cidade> &rota, int custoInicial, std::list<std::pair<int,int> > &listaTabu, int custoMelhorSolucao) {
    std::vector<std::pair<std::pair<int,int>, int> > movimentos; 
    int menorCusto = INT_MAX;
    std::pair<int, int> vizinho;

    for (int cidadeInicio = 0; cidadeInicio < rota.size();  cidadeInicio++) {
        for (int cidadeFim = cidadeInicio + 3; cidadeFim  < rota.size(); cidadeFim++) {
            int novoCustoMelhorado = custoInicial - calcularAntigoCusto(rota,cidadeInicio,cidadeFim) + calcularNovoCusto(rota,cidadeInicio,cidadeFim);

            if (checarListaTabu(listaTabu, std::make_pair(cidadeInicio, cidadeFim)) == false || novoCustoMelhorado < custoMelhorSolucao) { // Guardamos a melhor solução das permutações
                movimentos.push_back(std::make_pair(std::make_pair(cidadeInicio, cidadeFim), novoCustoMelhorado));
            }
        }
    }

    for (std::pair<std::pair<int,int>, int> movimento : movimentos) {
        if (movimento.second < menorCusto) {
            menorCusto = movimento.second;
            vizinho.first = movimento.first.first; vizinho.second = movimento.first.second;
        }
    }

    return vizinho;
}

void gerarSolucaoCorrente(std::vector<Cidade> &rota, int &custo, std::pair<int,int> swapsVizinho) {
    custo = custo - calcularAntigoCusto(rota, swapsVizinho.first, swapsVizinho.second) + calcularNovoCusto(rota, swapsVizinho.first, swapsVizinho.second);
    swapRota(rota, swapsVizinho.first, swapsVizinho.second);
}

int obterMaiorDistancia(std::vector<Cidade> &rota) {
    int maiorDistancia = INT_MIN;
    int distancia;

    for (int i = 0; i < rota.size() - 1; i++) {
        for (int j = i + 1; j < rota.size(); j++) {
            distancia = calcularDistancia(rota[i],rota[j]);

            if (distancia > maiorDistancia) maiorDistancia = distancia;
        }
    }

    return maiorDistancia;
}

double obterMedia(std::vector<Cidade> &cidades, int maiorDistancia) {
    int distanciaTotal = 0;
    
    for (int i = 0; i < cidades.size() - 1; i++) {
        for (int j = i; j < cidades.size(); j++) {
            distanciaTotal += calcularDistancia(cidades[i],cidades[j]);
        }
    }

    double media = distanciaTotal/(cidades.size()*(cidades.size()-1));
    media = media/maiorDistancia; // Normalizamos a media

    return media;
}

double calcularCustoSmoothing(std::vector<Cidade> &rota, double media, int maiorDistancia, int alfa) {
    double custoTotal = calcularDistanciaSmoothing(rota[0],rota[rota.size()-1],alfa,media,maiorDistancia);

    for (int i = 0; i < rota.size() - 1; i++) custoTotal += calcularDistanciaSmoothing(rota[i],rota[i+1],alfa,media,maiorDistancia);

    return custoTotal;
}

double calcularAntigoCustoSmoothing(std::vector<Cidade> &rota, int cidadeInicio, int cidadeFim, double media, int maiorDistancia, int alfa) {
    double custo = calcularDistanciaSmoothing(rota[cidadeInicio],rota[cidadeInicio+1],alfa,media,maiorDistancia) + calcularDistanciaSmoothing(rota[cidadeFim-1],rota[cidadeFim],alfa,media,maiorDistancia); // Adicionamos o custo das distancias das antigas rotas antes da inversao

    return custo;
}

double calcularNovoCustoSmoothing(std::vector<Cidade> &rota, int cidadeInicio, int cidadeFim, double media, int maiorDistancia, int alfa) {
    double custo = calcularDistanciaSmoothing(rota[cidadeInicio],rota[cidadeFim-1],alfa,media,maiorDistancia) + calcularDistanciaSmoothing(rota[cidadeInicio+1],rota[cidadeFim],alfa,media,maiorDistancia); // Adicionamos o custo das distancias das novas rotas depois da inversao

    return custo;
}

std::vector<Cidade> aplicar2optSmoothing(std::vector<Cidade> &rota, double &custoInicial, double media, int maiorDistancia, int alfa) {
    double custoMelhorado = custoInicial;
    int swapInicio, swapFim;

    // Permutamos todas as opcoes de troca de rotas nao consecutivas
    for (int cidadeInicio = 0; cidadeInicio < rota.size();  cidadeInicio++) {
        for (int cidadeFim = cidadeInicio + 3; cidadeFim  < rota.size(); cidadeFim++) {
            double novoCustoMelhorado = custoInicial - calcularAntigoCustoSmoothing(rota,cidadeInicio,cidadeFim,media,maiorDistancia,alfa) + calcularNovoCustoSmoothing(rota,cidadeInicio,cidadeFim,media,maiorDistancia,alfa);

            if (novoCustoMelhorado < custoMelhorado) { // Guardamos a melhor solução das permutações
                custoMelhorado = novoCustoMelhorado;
                swapInicio = cidadeInicio; swapFim = cidadeFim;
            }
        }
    }

    if (custoMelhorado < custoInicial) { // Caso a solução seja melhor que a proposta inicialmente...
        custoInicial = custoMelhorado;
        
        swapRota(rota, swapInicio, swapFim); // Fazemos de fato o swap dessa rota no vetor e a retornamos

        return rota; 
    } else {
        return rota; // Retornamos a rota proposta inicialmente
    }
}

int usarBuscaLocalSmoothing(std::vector<Cidade> &rota, std::vector<Cidade> &rotaInicial, int custoInicial, double media, int maiorDistancia, int alfa) {
    std::vector<Cidade> rotaInicialTemp = rotaInicial;
    double custoTotal = custoInicial;
    double menorCusto = custoTotal;

    rotaInicialTemp.push_back(rotaInicialTemp[0]); // Adicionamos a rota inicial, no final do vetor de rotas, para facilitar as permutações
    rota = aplicar2optSmoothing(rotaInicialTemp, custoTotal, media, maiorDistancia, alfa); // Realizamos a primeira busca local

    while (true) {
        aplicar2optSmoothing(rota, custoTotal, media, maiorDistancia, alfa); // Aplicamos o 2-opt novamente

        if (custoTotal < menorCusto) menorCusto = custoTotal; // Caso o custo do 2-opt tenha melhorado, continuamos o loop
        else break; // Caso contrario, podemos para-lo
    }

    rota.pop_back(); // Removemos a rota inicial, no final do vetor de rotas, pois o mesmo não é mais necessário

    criarArquivoRota(rota, "metodoBuscaLocal");

    return custoTotal;
}

int avaliarRota(std::vector<Cidade> &rota) {
    int custoTotal = calcularDistancia(rota[0],rota[rota.size()-1]);
    custoTotal += MULTAS[0][0]; 

    // Calcula o custo total da rota (funcao de avaliacao)
    for (int i = 1; i < rota.size(); i++) {
        custoTotal += calcularDistancia(rota[i-1],rota[i]) + MULTAS[rota[i].id - 1][i];
    }

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
- O Metodo consiste em realizar uma busca local com uma lista de movimentos proibidos para evitar ficar preso em otimos locais
*/
int usarBuscaTabu(std::vector<Cidade> &melhorSolucao, std::vector<Cidade> &rotaInicial, int custoInicial, int tempoMax, int tamanhoTabu) {
    rotaInicial.push_back(rotaInicial[0]); // Adiciona a cidade 1 no final temporariamente para os swaps do 2-opt

    melhorSolucao = rotaInicial;
    int custoMelhorSolucao = custoInicial;
    int custoCorrente = custoInicial;
    std::list<std::pair<int,int> > listaTabu;
    std::vector<Cidade> solucaoCorrente = rotaInicial;

    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempoTotal;

    while (true) { 
        tempoTotal = end - start;

        if (tempoTotal.count() >= tempoMax) break;

        std::pair<int,int> vizinho = criarVizinho(solucaoCorrente, custoCorrente, listaTabu, custoMelhorSolucao); // Ja considera funcao de aspiracao na escolha do vizinho

        if (listaTabu.size() == tamanhoTabu) {
            listaTabu.pop_front(); // Remove o primeiro elemento (mais antigo) da lista tabu
            listaTabu.push_back(vizinho); 
        }
        else {
            listaTabu.push_back(vizinho);
        }

        gerarSolucaoCorrente(solucaoCorrente, custoCorrente, vizinho); // Gera a rota da solucao corrente

        if (custoCorrente < custoMelhorSolucao) {
            melhorSolucao = solucaoCorrente;
            custoMelhorSolucao = custoCorrente;
        }

        end = std::chrono::high_resolution_clock::now();
    }

    melhorSolucao.pop_back(); // Remove a cidade 1 no final que foi colocada temporariamente para os swaps do 2-opt
    rotaInicial.pop_back(); // Remove a cidade 1 no final que foi colocada temporariamente para os swaps do 2-opt

    criarArquivoRota(melhorSolucao, "metodoBuscaTabu");

    return custoMelhorSolucao;
}

/* Metódo Implementado: 
- O Metodo consiste em realizar repitidas buscas locais com funcoes de avaliacao com suavidade decrescente
*/
int usarSmoothing(std::vector<Cidade> &melhorSolucao, std::vector<Cidade> &rotaInicial, int alfa) {
    std::vector<Cidade> solucaoCorrente = rotaInicial;
    int maiorDistancia = obterMaiorDistancia(rotaInicial); // A maior distancia de todo grafo
    double media = obterMedia(rotaInicial, maiorDistancia); // Media normalizada com base no maiorDistancia
    double custoMelhorSolucao;

    while (alfa > 1) {
        double custoCorrente = calcularCustoSmoothing(solucaoCorrente, media, maiorDistancia, alfa); // Avalia rota usando distancias suavizadas
        custoMelhorSolucao = usarBuscaLocalSmoothing(melhorSolucao, solucaoCorrente, custoCorrente, media, maiorDistancia, alfa); // Busca local com distancias suavizadas
        solucaoCorrente = melhorSolucao;

        alfa--;
    }

    criarArquivoRota(melhorSolucao, "metodoSmoothing");

    return avaliarRota(melhorSolucao); // Retorna a funcao avalicao da melhor rota, sem a normalizacao
}

void paralelizar(int id, std::vector<Cidade> solucaoInicial, int alfaSmoothing, int tempoTabu, int tamanhoListaTabu) {
    int custo;
    std::vector<Cidade> rota;

    if (id == 0) {
        std::list<Cidade> rotaMetodoGuloso;
        custo = usarGuloso(solucaoInicial, rotaMetodoGuloso);
        rota = transformarListaParaVector(rotaMetodoGuloso);
    }
    else if (id == 1) {
        custo = usarSmoothing(rota, solucaoInicial, alfaSmoothing);
    } 
    else {
        std::list<Cidade> rotaMetodoGuloso;
        custo = usarGuloso(solucaoInicial, rotaMetodoGuloso);
        std::vector<Cidade> rotaGuloso = transformarListaParaVector(rotaMetodoGuloso);     

        custo = usarSmoothing(rota, rotaGuloso, alfaSmoothing-5);      
    }

    std::vector<Cidade> rotaBuscaTabu;
    int custoBuscaTabu = usarBuscaTabu(rotaBuscaTabu, rota, custo, tempoTabu, tamanhoListaTabu);

    std::vector<Cidade> rotaMetodoBuscaLocal;
    int custoBuscaLocal = usarBuscaLocal(rotaBuscaTabu, rotaMetodoBuscaLocal, custoBuscaTabu);  

    RESULTADOS[id] = custoBuscaLocal;
}

int obterCustoTotal(std::vector<Cidade> &solucaoInicial, int alfaSmoothing, int tempoTabu, int tamanhoListaTabu) {
    std::thread threadMetodoGuloso(paralelizar, 0, solucaoInicial, alfaSmoothing, tempoTabu, tamanhoListaTabu);
    std::thread threadSmoothing(paralelizar, 1, solucaoInicial, alfaSmoothing, tempoTabu, tamanhoListaTabu);
    std::thread threadSmoothingGuloso(paralelizar, 2, solucaoInicial, alfaSmoothing, tempoTabu, tamanhoListaTabu);

    threadMetodoGuloso.join(); threadSmoothing.join(); threadSmoothingGuloso.join();

    return std::min(std::min(RESULTADOS[0], RESULTADOS[1]), RESULTADOS[2]); // Retorna o melhor valor das 3 possiveis solucoes inicias com o TS
}

void calcularCustoDaMelhorRota(std::vector<Cidade> &cidades, int selector) {
    int numCidades = cidades.size();
    std::vector<Cidade> solucaoTrivial = cidades;
    int custoTotal;

    if (numCidades <= 30) custoTotal = obterCustoTotal(solucaoTrivial, 9, 30, 50); 
    else if (numCidades <= 60) custoTotal = obterCustoTotal(solucaoTrivial, 9, 180, 100);
    else if (numCidades <= 100) custoTotal = obterCustoTotal(solucaoTrivial, 9, 240, 125); 
    else if (numCidades <= 300) custoTotal = obterCustoTotal(solucaoTrivial, 9, 540, 150); 
    else if (numCidades <= 700) custoTotal = obterCustoTotal(solucaoTrivial, 10, 600, 225);
    else if (numCidades <= 15000) custoTotal = obterCustoTotal(solucaoTrivial, 10, 3600, 150); 

    std::cout << custoTotal << std::endl;
}

void exibirResultados() {
    std::cout << "[==== Resultados ====]" << std::endl;
    std::vector<std::pair<std::string,std::string> > arquivos; // Armazena os arquivos que serão testados

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
        std::vector<Cidade> cidades = carregarCidades(arquivos[i].first, arquivos[i].second); // Roda a heuristica para cada teste

        calcularCustoDaMelhorRota(cidades, 1);
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