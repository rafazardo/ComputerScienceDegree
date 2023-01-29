#include <iostream>

#include "MonitorMR.h"

MonitorMR::MonitorMR(int capacidadeCarrinho, int qntdVoltas) { // Preenche os dados inicias do objeto monitor
    this->_capacidadeCarrinho = capacidadeCarrinho;
    this->_carrinho.resize(capacidadeCarrinho);
    this->_qntdVoltasCarrinho = qntdVoltas;
    this->_qntdVoltasDadas = 1;
    this->_qntdAssentosOcupados = 0;
    this->_qntdPessoasFila = 0;    
}

MonitorMR::~MonitorMR() {}

void MonitorMR::espera_encher() {
    std::unique_lock<std::mutex> lck(this->_mux); // Garantir a exclusao mutua

    while (true) {
        if (this->_qntdAssentosOcupados < _carrinho.size() and this->_qntdPessoasFila != 0) { // Se o carrinho ainda tiver vaga e haver pessoas na fila, adiciona pessoa da fila no carrinho
            this->_carrinho[_qntdAssentosOcupados] = this->_filaCarrinho.front(); // Adiciona o primeiro da fila no carrinho

            std::cout << "Entrou no carro o cliente: " << this->_carrinho[this->_qntdAssentosOcupados] << std::endl;
            this->_filaCarrinho.pop(); // Retira o primeira da fila, pois entrou no carrinho

            exibirStatus();

            this->_qntdPessoasFila--;
            this->_qntdAssentosOcupados++;
        }
        if (this->_qntdAssentosOcupados < _carrinho.size() and this->_qntdPessoasFila == 0) { // Se o carrinho tiver vaga, porem nao tem pessoas na fila trava a thread, ate uma pessoa entrar na fila
            this->_conEsperaEncher.wait(lck); 
        }
        else if (this->_qntdAssentosOcupados == this->_carrinho.size()) { // Se o carrinho estiver cheio, podemos parar de enche-lo e iniciar a volta
            break;
        }
    }

    // Carrinho inicia a volta
    exibirCarrinhoVolta(); // Exibe vagas do carrinho na volta
    // Carrinho termina a volta

    this->_conPassageiroOcupado.notify_all(); // Apos finalizar a volta, podemos avisar para thread de saida do cliente, que ele pode sair do carrinho
}

void MonitorMR::espera_esvaziar() {  
    std::unique_lock<std::mutex> lck(this->_mux); // Garantir a exclusao mutua
    while (this->_qntdAssentosOcupados != 0) { // Enquanto o carro nao esta vazio, ele  bloqueia as threads de clientes que estao de saida
        this->_conEsperaEsvaziar.wait(lck); 
    }
}

void MonitorMR::entra_no_carro(int codCliente) {
    this->_mux.lock(); // Garantir a exclusao mutua
    this->_filaCarrinho.push(codCliente); // Adiciona o cliente na fila
    this->_qntdPessoasFila++;

    std::cout << "Entrou na fila: " << codCliente << std::endl;
    exibirStatus();

    this->_conEsperaEncher.notify_all(); // Acorda a thread do carro que esta parada esperando novos clientes para entrar
    this->_mux.unlock(); // Garantir de exclusao mutua
}

void MonitorMR::sai_do_carro(int codCliente) {
    std::unique_lock<std::mutex> lck(this->_mux); // Garantir a exclusao mutua

    while (clienteNaFila(codCliente)) { // Equanto o cliente esta na fila, ele nao pode sair, pois ainda nao entrou no carro, assim que ele der e a volta ele sera liberado
        this->_conPassageiroOcupado.wait(lck);
    }

    std::cout << "Saiu do carro o cliente: " << codCliente << std::endl;
    for (int n = 0; n < this->_carrinho.size(); n++) { // Remove o cliente do carro
        if (this->_carrinho[n] == codCliente) this->_carrinho[n] = 0;
    }
    this->_qntdAssentosOcupados--;

    exibirStatus();

    if (this->_qntdVoltasCarrinho + 1 == this->_qntdVoltasDadas and carroVazio()) { // Quando o carro der a quantidade de voltas e estiver vazio, o programa sera finalizado
        std::cout << "ATENCAO!" << std::endl;
        std::cout << "O carrinho realizou as " << this->_qntdVoltasCarrinho << " voltas e o carrinho foi esvaziado, com isso podemos finalizar o programa!" << std::endl;
        exit(0);
    }

    this->_conEsperaEsvaziar.notify_all(); // Libera as threads de espera do carrinho ficar vazio
}

void MonitorMR::exibirCarrinhoVolta() { // Exibe o estado do carrinho durante a volta
    std::cout << "Dando a volta..." << std::endl;
    std::cout << "CLIENTES DA VOLTA " << _qntdVoltasDadas++ << " - [ ";
    for (int n = 0; n < this->_carrinho.size(); n++) {
        std::cout << this->_carrinho[n] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}

bool MonitorMR::clienteNaFila(int codCliente) { // Verifica se um cliente esta na fila
    std::queue<int> filaTemp = this->_filaCarrinho;
    for(int n = 0; n < this->_filaCarrinho.size(); n++) {
        if (filaTemp.front() == codCliente) return true;
        filaTemp.pop();
    }
    return false;
}

bool MonitorMR::carroVazio() { // Verifica se o carro esta vazio
    for (int n = 0; n < this->_carrinho.size(); n++) {
        if (this->_carrinho[n] != 0) return false;
    }
    return true;
}

void MonitorMR::exibirStatus() { // Exibe o status da fila e carrinho
    std::queue<int> filaTemp = this->_filaCarrinho;
    std::cout <<  "FILA - [ ";
    for (int n = 0; n < this->_filaCarrinho.size(); n++) {
        std::cout << filaTemp.front() << " ";
        filaTemp.pop();
    }
    std::cout << "]" << std::endl;

    std::cout <<  "CARRINHO - [ ";
    for (int n = 0; n < this->_carrinho.size(); n++) {
        std::cout << this->_carrinho[n] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;
}