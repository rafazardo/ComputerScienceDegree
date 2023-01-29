#ifndef MONITOR_H
#define MONITOR_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <mutex>
#include <stdio.h>
#include <thread>
#include <pthread.h>
#include <vector>
#include <cstdlib>

class MonitorMR {
private:
    int _capacidadeCarrinho;
    int _qntdAssentosOcupados;
    int _qntdPessoasFila;
    int _qntdVoltasDadas;
    int _qntdVoltasCarrinho;
    
    std::vector<int> _carrinho;
    std::queue<int> _filaCarrinho;

    std::condition_variable_any _conEsperaEncher;
    std::condition_variable_any _conEsperaEsvaziar;
    std::condition_variable_any _conPassageiroOcupado;
    std::mutex _mux;

    
public:
    // Construtores e Destrutores
    MonitorMR(int capacidadeCarrinho, int qntdVoltas);
    ~MonitorMR();

    // Metodos especializados
    void espera_encher();
    void espera_esvaziar();

    void entra_no_carro(int codCliente);
    void sai_do_carro(int codCliente);

    bool clienteNaFila(int codCliente);
    bool carroVazio();
    void exibirCarrinhoVolta();
    void exibirStatus();
    
};

#endif