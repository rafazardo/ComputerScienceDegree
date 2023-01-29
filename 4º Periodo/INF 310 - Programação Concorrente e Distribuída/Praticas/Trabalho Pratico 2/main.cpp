/*
Monitor para Montanha Russa
- Trabalho Prático 2 da Disciplina INF 310 - Programacao concorrente e distribuida
- Objetivos: praticar monitores
- Criado por Rafael Zardo em 06/11/2022
*/

/*
Informacoes IMPORTANTES:
- A quantidade de voltas, assentos e clientes deve ser definida nas variaveis globais do main.cpp
- Para atender os requisitos do programa, a QNTD_ASSENTOS < QNTD_CLIENTES, para que o carrinho seja cheio e possa sair
- Para atender os requisitos do programa, a QNTD_ASSENTOS deve ser multipla de QNTD_CLIENTES
- O carrinho ira parar apos ralizar QNTD_VOLTAS, caso tenham threads de clientes que ainda nao executaram ou clientes esperando na fila 
elas serao finalizadas.
- So existira uma thread para o carrinho
- As vagas de numero 0 siginificam que o carro nao esta com a vaga ocupada.
- Comando utilizado para compilacao: g++ main.cpp MonitorMR.cpp -lpthread -std=c++11
*/

#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>

#include "MonitorMR.h"

const int QNTD_VOLTAS = 10; // Altere aqui a quantidade de voltas dada pelo carrinho
const int QNTD_ASSENTOS = 5; // Altere aqui a quantidade de assentos do carrinho
const int QNTD_CLIENTES = 10; // Altere aqui a quantidade de clientes utilizando o servico de montanha russa

MonitorMR montanharussa(QNTD_ASSENTOS, QNTD_VOLTAS); // Cria o objeto monitor

void carro() { // Funcao utilizadora dos monitores para threads de carro
    for(int i = 0; i < QNTD_VOLTAS; i++) {
        montanharussa.espera_encher();
        montanharussa.espera_esvaziar();
    }
}

void cliente(int codCliente) { // Funcao utilizadora dos monitores para threads de clientes
    for(int i = 0; i < QNTD_VOLTAS; i++) {
        montanharussa.entra_no_carro(codCliente);
        montanharussa.sai_do_carro(codCliente);
    }
}

int main() {
    std::vector<std::thread> threads;

    std::thread Carrinho(carro);

    sleep(1); // Utilizado para garantir que a thread de carro seja executada primeiro, antes das de cliente

    for (int n = 1; n <= QNTD_CLIENTES; n++) {
        threads.push_back(std::thread(cliente,n));
    }
    Carrinho.join();

    for (int n = 0; n < threads.size(); n++) {
        threads[n].join();
    }

}