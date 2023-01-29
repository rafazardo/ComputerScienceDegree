/*
Produtor/consumidor com buffer limitado
- Trabalho Prático 1 da Disciplina INF 310 - Programacao concorrente e distribuida
- Objetivos: praticar mutexbegin/mutexend e block/wakeup(p)
- Criado por Rafael Zardo em 23/10/2022
*/

/*
Informacoes IMPORTANTES:
- O codigo em questao foi testado e ele esta preparado para funcionar com uma quantidade n (definida pelo usuario) de consumidores e produtores.
- O codigo por padrao possui um buffer de tamanho 5, mas pode ser aumentado alterando o valor da variavel bufferSize
- O codigo do Block() e WakeUp() continua sem alteracoes conforme exigido pelo enunciado do trabalho, somente alterei a parte visual (trocar nome de variaveis e identencao) para facilitar o intendimento.
- O comando para compilacao utilizado no SO iOS foi: g++ trabalho1.cpp -lpthread -std=c++17 
- Um item com valor 0 no buffer indica que ele foi consumido (inicialmente indica que nao foi colocado ainda)
- Cada thread produz um valor aleatorio de 0 a 9 
*/

#include <iostream>
#include <mutex>
#include <stdio.h>
#include <thread>
#include <map>
#include <pthread.h>
#include <vector>
#include <cstdlib>
#include <queue>

// === Implementacao de Block() e WakeUp() desenvolvida pelo professor ===
std::map<std::thread::id, int> arrayThreads;
pthread_mutex_t muxBuffer = PTHREAD_MUTEX_INITIALIZER;

void Block() {
    bool saidaVerifica = false;
    std::thread::id idThread = std::this_thread::get_id();

    do {
        pthread_mutex_lock(&muxBuffer);
        if(arrayThreads[idThread] > 0) {
            arrayThreads[idThread]--;
            saidaVerifica = true;
        }
        pthread_mutex_unlock(&muxBuffer);
    } while (!saidaVerifica);

}

void WakeUp(std::thread::id idThread) {
    pthread_mutex_lock(&muxBuffer);
    arrayThreads[idThread]++;
    pthread_mutex_unlock(&muxBuffer);
}
// =============================

int bufferSize = 5; // Variavel que determinar o tamanho do buffer, caso queira altera-lo basta alterar o valor inteiro atribuido
int *bufferArray = new int[bufferSize]; // Alocacao dinamica do buffer
int contInput, contOutput, contAuxiliar = 0; // Variaveis auxiliares para ganrantir o FIFO
int contStop = 0; // Contador para dar stop no programa depois de uma quantidade x de consumos e produtores (para evitar que o programa fique rodando o tempo todo)

std::mutex muxBufferEM; // Mutex para garantir exclusao mutua do produtor e consumidor
std::thread::id idThreadConsumidora;
std::thread::id idThreadProdutora;
std::queue<std::thread::id> idsThreadConsumidora;
std::queue<std::thread::id> idsThreadProdutora; 


void exibirBuffer() { // Funcao que imprime os dados dentro do Buffer

    std::cout << "Imprimindo Buffer: "; 

    for (int n = 0; n < bufferSize; n++) {
        std::cout << bufferArray[n] << " ";
    }
    std::cout << std::endl << "=-=-=-=-=\n";

}

void produzir(int dado) {
    while (true) { // Garante que o produtor sempre ira produzir

        bool temProducao = false; // Variavel que verifica se ira haver producao ou nao, para bloquear a thread

        muxBufferEM.lock(); // Inicio da exclusao mutua para RG
        if (contAuxiliar < bufferSize) { // Se o contador for menor que o tamanho do array, siginica que deve haver producao

            bufferArray[contInput] = dado; // Adiciona o dado na posicao da variavel de input, para garantir o FIFO
            std::cout << "Produzido: " << bufferArray[contInput] << std::endl;

            contInput = (contInput + 1) % bufferSize; // Atualiza a variavel de input, para garantir FIFO
            contAuxiliar++; // Adiciona mais 1 no contador, pois mais 1 item foi produzido
            temProducao = true; // Indica que houve producao, entao nao deve-se parar essa thread
            exibirBuffer(); // Exibe o estado atual do buffer

            if (idsThreadConsumidora.empty() == false) { // Garante que nao ira pegar um id vazio
                idThreadConsumidora = idsThreadConsumidora.front();
                idsThreadConsumidora.pop();
                WakeUp(idThreadConsumidora); // Acordar a thread de consumo da fila, pois ja pode haver consumo (o buffer nao esta vazio)
            }
        }

        if (temProducao == false)  { // Se nao houve producao
            idsThreadProdutora.push(std::this_thread::get_id()); // Armazena o ID da tread de producao            
        }         
        muxBufferEM.unlock(); // Fim da exclusao mutua para RG

        if (temProducao == false)  { // Se nao houve producao, deve-se travar a thread            
            Block(); // Bloqueia a tread atual, para que ela nao produza mais 
        } 
    }
}

void consumir() {
    while (true) { // Garante que o consumidor sempre ira consumir
        
        bool temConsumo = false; // Variavel que verifica se ira haver consumo ou nao, para bloquear a thread 

        muxBufferEM.lock(); // Inicio da exclusao mutua para RG
        if (contAuxiliar > 0) { // Se o contador for maior que 0 (inicio do array), siginica que deve haver consumo

            int *var; // Variavel para armazenar o item consumido do buffer
            var = &bufferArray[contOutput];
            std::cout << "Consumido: " << *var << std::endl;

            bufferArray[contOutput] = 0; // Adiciona o dado 0 na posicao da variavel de output indicando que aquele dado foi consumido
            contOutput = (contOutput + 1) % bufferSize; // Atualiza a variavel de output, para garantir FIFO
            contAuxiliar--; // Remove 1 no contador, pois mais 1 item foi consumido
            contStop++; // Adiciona mais 1 no contador de consumos, para futuramente parar o programa depois de x consumos
            temConsumo = true; // Indica que houve consumo, entao nao deve-se parar essa thread
            exibirBuffer(); // Exibe o estado atual do buffer

            if (idsThreadProdutora.empty() == false) { // Garante que nao ira pegar um id vazio
                idThreadProdutora = idsThreadProdutora.front();
                idsThreadProdutora.pop();
                WakeUp(idThreadProdutora); // Acordar a thread de producao da fila, pois ja pode haver producao (o buffer esta vazio)                
            }

            if (contStop > 100 and contAuxiliar == 0) { std::exit(0); } // Apos fazer 100 (valor alteravel) consumos, ele ira esperar consumir todo buffer, e em seguida finalizar o programa
        }  

        if (temConsumo == false) { // Se nao houve consumo
            idsThreadConsumidora.push(std::this_thread::get_id()); // Armazena o ID da tread de consumo                           
        }            
        muxBufferEM.unlock(); // Fim da exclusao mutua para RG

        if (temConsumo == false) { // Se nao houve consumo, deve-se travar a thread                        
            Block(); // Bloqueia a tread atual, para que ela nao consuma mais pois o buffer esta vazio
        }
    }
}

int main() {

    std::vector<std::thread> vectorThreads;
    int qntdThreadsConsumidoras, qntdThreadsProdutoras, vlrProduzido;
    
    srand(time(0));

    std::cout << "Digite a quantidade de threads produtoras: " << std::endl;
    std::cin >> qntdThreadsProdutoras;

    std::cout << "Digite a quantidade de threads consumidoras: " << std::endl;
    std::cin >> qntdThreadsConsumidoras;     

    for (int n = 0; n < qntdThreadsProdutoras; n++) { // Cria as threads produtoras e adiciona elas no map 
        vectorThreads.push_back(std::thread(produzir, rand()%8 + 1)); // As threads produzim valores aleatorios de 1 a 9
        arrayThreads.insert(std::pair<std::thread::id,int>(vectorThreads[n].get_id(),0));
    }
    std::cout << std::endl;

    for (int n = 0; n < qntdThreadsConsumidoras; n++) { // Cria as threads consumidoras e adiciona elas no map 
        vectorThreads.push_back(std::thread(consumir));
        arrayThreads.insert(std::pair<std::thread::id,int>(vectorThreads[n].get_id(),0));
    } 

    for (int n = 0; n < vectorThreads.size(); n++) {
        vectorThreads[n].join();
    } 
    
    delete [] bufferArray;
    
}


