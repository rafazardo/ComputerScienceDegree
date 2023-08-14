/*
Traveling Salesman Problem
- Trabalho Prático 1 da Disciplina INF 284 - Metaheuristicas
- Objetivos: praticar conceitos de TSP
- Criado por Rafael Zardo em 09/04/2023

Informacoes IMPORTANTES:
- Comando de compilção: g++ travelingSalesmanProblem.cpp -std=c++11
- Parte 0: Implementação e entendimento da leitura de arquivos tspp, 
bem como implementação do método simples.
- Parte 1: Implementação do método guloso 1 e metodo guloso 2
- Parte 2: Implementação do método busca local 1 e busca local 2
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h> 
#include <fstream>
#include <exception>
#include <list>

struct Cidade {
    int id;
    std::pair<double, double> cordenadas;
    std::vector<int> multa; 
};

/* ========= Funções auxiliares ========= */
double calcularDistancia(Cidade &cidade1, Cidade &cidade2) {
    return llround( sqrt( pow(cidade1.cordenadas.first - cidade2.cordenadas.first, 2.0) + pow(cidade1.cordenadas.second - cidade2.cordenadas.second, 2.0)));
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

void criarArquivoRota(std::vector<Cidade> rota, std::string nomeArquivo) {
    std::ofstream arquivo("./plota-rota/" + nomeArquivo + ".rota");
  
    for(int i = 0; i < rota.size(); i++) arquivo << rota[i].id << " ";

    std::cout << "Arquivo " + nomeArquivo +  ".rota" + " criado com sucesso!" << std::endl;

    arquivo.close();
}

void criarArquivoRota(std::list<Cidade> rota, std::string nomeArquivo) {
    std::ofstream arquivo("./plota-rota/" + nomeArquivo + ".rota");
  
    while (rota.size() != 0) {
        Cidade cidadeDaRota = rota.front();
        arquivo << cidadeDaRota.id << " ";
        rota.pop_front(); 
    } 

    std::cout << "Arquivo " + nomeArquivo + ".rota" + " criado com sucesso!" << std::endl;
    
    arquivo.close();
}

std::vector<Cidade> carregarCidades() {
    std::vector<Cidade> cidades;
    std::string arqCidades, arqMultas;
    int numCidades;

    std::cout << "Digite o arquivo de cidades (sem .tspp no final)" << std::endl; std::cin >> arqCidades;
    std::ifstream finCidades = lerArquivo("./instancias/" + arqCidades + ".tspp");
    
    // Carrega os dados das cidades
    finCidades >> numCidades;

    for (int i = 0; i < numCidades; i++) {
        Cidade cidade;

        finCidades >> cidade.id >> cidade.cordenadas.first >> cidade.cordenadas.second;
        cidades.push_back(cidade);
    }

    finCidades.close(); // Fechando o arquivo

    std::cout << "Digite o arquivo de multas (sem .txt no final), caso nao tenha digite: @" << std::endl; std::cin >> arqMultas;

    if(arqMultas == "@") {
        for (int i = 0; i < numCidades; i++) {
            for (int j = 0; j < numCidades; j++) {
                cidades[i].multa.push_back(0); // Caso nao tenha arquivo de multas, definimos o vetor de multas de cada cidade como 0
            }    
        }
    } else {
        std::ifstream finMultas = lerArquivo("./instancias/" + arqMultas + ".txt");

        // Carrega os dados das multas
        finMultas >> numCidades;

        for (int i = 0; i < numCidades; i++) {
            for (int j = 0; j < numCidades; j++) {
                int multa;

                finMultas >> multa;
                cidades[i].multa.push_back(multa);
            }    
        }

        finMultas.close(); // Fechando o arquivo
    }
    
    return cidades;
}

double aplicarMultaMetodoGuloso(std::vector<Cidade> &cidades, std::list<Cidade> rota) {
    double custoTotalMultas = 0;
    int ordemDeVisita = 0;

    // Ira adicionar a multa da cidade baseado na ordem de visita que ficou na rota
    while (rota.empty() != true) {
        Cidade cidadeDaRota = rota.front();
        custoTotalMultas += cidades[cidadeDaRota.id-1].multa[ordemDeVisita];
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

bool verificarMesmaRota(std::vector<Cidade> &rota1, std::vector<Cidade> &rota2) {
    if (rota1.size() != rota2.size()) { // Caso as rotas tenha tamanho difente, ambas não sao iguais
        std::cerr << "Erro! ambas rotas deviam ter mesmo tamanho!" << std::endl;
        return false; 
    }

    for (int i = 0; i < rota1.size(); i++) if (rota1[i].id != rota2[i].id) return false; // Caso as rotas tenha um elemento difente, ambas não sao iguais

    return true; // Caso passe por essas duas verifações elas sao iguais, ou seja, retornamos verdadeiro
}

void swapRota(std::vector<Cidade> &rota, int swapInicio, int swapFim) {
    std::reverse(rota.begin() + swapInicio + 1, rota.begin() + swapFim); // Inverte os elementos da rota a partir da posicao de inicio ate a posicao final
}

double calcularAntigoCusto(std::vector<Cidade> &rota, int &cidadeInicio, int &cidadeFim) {
    double custo = calcularDistancia(rota[cidadeInicio],rota[cidadeInicio+1]) + calcularDistancia(rota[cidadeFim-1],rota[cidadeFim]); // Adicionamos o custo das distancias das antigas rotas antes da inversao

    for (int i = cidadeInicio + 1; i <= cidadeFim-1; i++) custo += rota[i].multa[i]; // Adicionamos o custo das multas das antigas rotas antes da inversao

    return custo;
}

double calcularNovoCusto(std::vector<Cidade> &rota, int &cidadeInicio, int &cidadeFim) {
    double custo = calcularDistancia(rota[cidadeInicio],rota[cidadeFim-1]) + calcularDistancia(rota[cidadeInicio+1],rota[cidadeFim]); // Adicionamos o custo das distancias das novas rotas depois da inversao
    int multaInicio = cidadeInicio + 1;

    for (int i = cidadeFim-1; i >= cidadeInicio+1; i--) { // Adicionamos o custo das multas das novas rotas depois da inversao
        custo += rota[i].multa[multaInicio]; 
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

/* ========= Fim das funções auxiliares ========= */

/* ========= Funções de métodos para cálculo de custos ========= */
/* Metódo Implementado na Parte 0: 
- O Metódo consiste em calcular o custo da rota que visita as cidades em sequência de seus ids, ou seja, 1, 2, 3, 4 até n
- O Metódo não utiliza nenhuma tecnica para encontrar um possivel melhor caminho, apenas segue as sequências de ids
*/
double usarMetodoNormal(std::vector<Cidade> cidades, std::vector<Cidade> &rota) {
    Cidade primeiraCidade = cidades[0];
    Cidade ultimaCidade = cidades[cidades.size()-1];
    int ordemDeVisita = 0; 
    int custoTotal = calcularDistancia(ultimaCidade, primeiraCidade); // Calcular a distancia de voltar para primeira cidade a partir da ultima
    
    // Adiciona a primeira cidade na rota (por padrao a cidade 1 sempre sera a primeira) e adiciona a multa por ela ser a primeira
    rota.push_back(cidades[ordemDeVisita]); custoTotal += cidades[0].multa[ordemDeVisita]; ordemDeVisita++;

    for (int i = 0; i < cidades.size() - 1; i++) {
        custoTotal += calcularDistancia(cidades[i], cidades[i+1]) + cidades[i+1].multa[ordemDeVisita];
        rota.push_back(cidades[ordemDeVisita]); ordemDeVisita++;
    } 

    criarArquivoRota(rota, "metodoNormal");

    return custoTotal;
}

/* Metódo Implementado na Parte 1: 
- O Metódo consiste em encontrar a cidade mais proxima a partir da primeira cidade ate visitar todas cidades
- Em seguida, irá somar ao custo total das visitas, as respectivas multas de ordem de visitas de cada cidade
*/
double usarMetodoGuloso1(std::vector<Cidade> cidades, std::list<Cidade> &rota) {
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

    criarArquivoRota(rota, "metodoGuloso1");

    return custoTotal;
}

/* Metódo Implementado na Parte 1: 
- O Metódo consiste em encontrar a cidade mais proxima de algum dos extremos da rota a partir da primeira cidade ate visitar todas cidades
- Em seguida, irá somar ao custo total das visitas, as respectivas multas de ordem de visitas de cada cidade
*/
double usarMetodoGuloso2(std::vector<Cidade> cidades, std::list<Cidade> &rota) {
    std::vector<bool> cidadesVisitadas(cidades.size(), false);
    rota.push_back(cidades[0]); // Por padrao a cidade 1 sempre sera a primeira
    int custoTotal = 0;

    cidadesVisitadas[rota.front().id - 1] = true; // Marca a cidade 1 como visitada

    // Enquanto nossa lista de rota for diferente do numero de cidades, significa que ainda existe cidade nao visitada
    while (rota.size() != cidades.size()) {
        double menorDistancia = INT_MAX;
        double distanciaDoExtremo1;
        double distanciaDoExtremo2;
        Cidade cidadeComMenorDistancia;

        // Procura a menor distancia entre as cidades restantes e as extremidades
        for (Cidade proximaCidade : cidades) {
            if (cidadesVisitadas[proximaCidade.id - 1] == false) {
                distanciaDoExtremo1 = calcularDistancia(rota.front(), proximaCidade); 
                distanciaDoExtremo2 = calcularDistancia(rota.back(), proximaCidade);

                // Verifica qual extremo esta mais perto de uma cidade
                if (distanciaDoExtremo1 < distanciaDoExtremo2) {
                    if (distanciaDoExtremo1 < menorDistancia) { // Verifica se e o extremo 1 menor de todos os extremos 1 visitados
                        menorDistancia = distanciaDoExtremo1;
                        cidadeComMenorDistancia = proximaCidade;
                    }
                } else {
                    if (distanciaDoExtremo2 < menorDistancia) { // Verifica se e o extremo 2 menor de todos os extremos 2 visitados
                        menorDistancia = distanciaDoExtremo2;
                        cidadeComMenorDistancia = proximaCidade;
                    }
                }
            }
        }

        // Verifica em qual extremo ira adicionar a cidade mais proxima
        distanciaDoExtremo1 = calcularDistancia(rota.front(), cidadeComMenorDistancia);
        distanciaDoExtremo2 = calcularDistancia(rota.back(), cidadeComMenorDistancia);

        if (distanciaDoExtremo1 < distanciaDoExtremo2) rota.push_front(cidadeComMenorDistancia); 
        else rota.push_back(cidadeComMenorDistancia);

        cidadesVisitadas[cidadeComMenorDistancia.id - 1] = true; 
        custoTotal += menorDistancia;
    }

    // Calcula a distancia da cidade final para a primeira
    custoTotal += calcularDistancia(rota.back(), rota.front());

    // Adiciona ao custo total, as multas de ordem de visita de cada cidade
    custoTotal += aplicarMultaMetodoGuloso(cidades,rota);

    criarArquivoRota(rota, "metodoGuloso2");

    return custoTotal;
}

/* Metódo Implementado na Parte 2: 
- O Metodo consiste em melhorar uma rota inicial qualquer, a partir da busca local, no caso, 2-opt
- A rota inicial definida é a encontrada na função usarMetodoNormal
*/
double usarMetodoBuscaLocal1(std::vector<Cidade> rotaMetodoNormal, std::vector<Cidade> &rota, double custoMetodoNormal) {
    double custoTotal = custoMetodoNormal;

    rotaMetodoNormal.push_back(rotaMetodoNormal[0]); // Adicionamos a rota inicial, no final do vetor de rotas, para facilitar as permutações
    rota = aplicar2opt(rotaMetodoNormal, custoTotal); // Realizamos a primeira busca local
    double menorCusto = custoTotal; 

    while (true) {
        aplicar2opt(rota, custoTotal); // Aplicamos o 2-opt novamente

        if (custoTotal < menorCusto) menorCusto = custoTotal; // Caso o custo do 2-opt tenha melhorado, continuamos o loop
        else break; // Caso contrario, podemos para-lo
    }

    rota.pop_back(); // Removemos a rota inicial, no final do vetor de rotas, pois o mesmo não é mais necessário

    criarArquivoRota(rota, "metodoBuscaLocal1");

    return custoTotal;
}

/* Metódo Implementado na Parte 2: 
- O Metodo consiste em melhorar uma rota inicial qualquer, a partir da busca local, no caso, 2-opt
- A rota inicial definida é a encontrada na função usarMetodoGuloso1
*/
double usarMetodoBuscaLocal2(std::list<Cidade> &rotaMetodoGuloso1, std::vector<Cidade> &rota, double custoMetodoGuloso1) {
    std::vector<Cidade> rotaMetodoGuloso = transformarListaParaVector(rotaMetodoGuloso1);
    double custoTotal = custoMetodoGuloso1;

    rotaMetodoGuloso.push_back(rotaMetodoGuloso[0]); // Adicionamos a rota inicial, no final do vetor de rotas, para facilitar as permutações
    rota = aplicar2opt(rotaMetodoGuloso, custoTotal); // Realizamos a primeira busca local
    double menorCusto = custoTotal;

    while (true) {
        aplicar2opt(rota, custoTotal); // Aplicamos o 2-opt novamente

        if (custoTotal < menorCusto) menorCusto = custoTotal; // Caso o custo do 2-opt tenha melhorado, continuamos o loop
        else break; // Caso contrario, podemos para-lo
    }

    rota.pop_back(); // Removemos a rota inicial, no final do vetor de rotas, pois o mesmo não é mais necessário

    criarArquivoRota(rota, "metodoBuscaLocal2");

    return custoTotal;
}

void calcularCustoDaMelhorRota(std::vector<Cidade> cidades) {
    std::cout << "[==== Avisos ====]" << std::endl;

    std::vector<Cidade> rotaMetodoNormal;
    double custoMetodoNormal = usarMetodoNormal(cidades, rotaMetodoNormal);
    
    std::list<Cidade> rotaMetodoGuloso1;
    double custoMetodoGuloso1 = usarMetodoGuloso1(cidades, rotaMetodoGuloso1);

    std::list<Cidade> rotaMetodoGuloso2;
    double custoMetodoGuloso2 = usarMetodoGuloso2(cidades, rotaMetodoGuloso2);

    std::vector<Cidade> rotaMetodoBuscaLocal1;
    double custoMetodoBuscaLocal1 = usarMetodoBuscaLocal1(rotaMetodoNormal, rotaMetodoBuscaLocal1, custoMetodoNormal); 

    std::vector<Cidade> rotaMetodoBuscaLocal2;
    double custoMetodoBuscaLocal2 = usarMetodoBuscaLocal2(rotaMetodoGuloso1, rotaMetodoBuscaLocal2, custoMetodoGuloso1);    

    std::cout << "[================]" << std::endl; std::cout << std::endl;

    std::cout << "[==== Custos ====]" << std::endl;

    std::cout << std::fixed << std::setprecision(2) << "Custo usando Método Normal: " << custoMetodoNormal << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Custo usando Método Guloso 1: " << custoMetodoGuloso1 << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Custo usando Método Guloso 2: " << custoMetodoGuloso2 << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Custo usando Método Busca Local (2-opt) 1: " << custoMetodoBuscaLocal1 << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Custo usando Método Busca Local (2-opt) 2: " << custoMetodoBuscaLocal2 << std::endl;

    std::cout << "[================]" << std::endl;
}
/* ========= Fim das funções de métodos para cálculo de custos ========= */

int main(void) {
    std::vector<Cidade> cidades = carregarCidades();

    calcularCustoDaMelhorRota(cidades);
}