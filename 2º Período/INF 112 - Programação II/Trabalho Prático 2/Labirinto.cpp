#include <iomanip>
#include <iostream>

#include "Labirinto.h"

Labirinto::Labirinto(int n) {

    this->_ordem = n;

    _maze = new int*[n](); //Aloca dinamicamente a matriz, quando o construtor é chamado

    for (int k = 0; k < n; k++) {
        _maze[k] = new int [n];
    }

}

Labirinto::~Labirinto() {

    for (int n = 0; n < this->_ordem; n++) { //Destroi a matriz alocada dinamicamente
        delete[] _maze[n];
    }
    delete[] _maze;    

}

int Labirinto::get_ordem() {
    return this->_ordem;
}
    
void Labirinto::set_ordem(int addOrdem) {
    this->_ordem = addOrdem;
}

void Labirinto::leMatriz(Labirinto &labirintoMatriz) { //Faz a leitura dos elementos da matriz alocada dinamicamente

    for (int n = 0; n < this->_ordem; n++) {
        for (int m = 0; m < this->_ordem; m++) {
            std::cin >> labirintoMatriz._maze[n][m];
        }
    }

}

void Labirinto::imprimeLabirinto(Labirinto &labirintoMatriz) { //Exibe os elementos da matriz alocada dinamicamente

    for (int n = 0; n < this->_ordem; n++) {
        for (int m = 0; m < this->_ordem; m++) {
            std::cout << labirintoMatriz._maze[n][m];
        }
        std::cout << std::endl;
    }

}

bool Labirinto::validaPosicao(int posicaoI, int posicaoJ) { //Valida se a posicao na matriz é valida para encontrar o caminho

    if (posicaoI == -1 || posicaoJ == -1 || posicaoI == this->_ordem || posicaoJ == this->_ordem || this->_maze[posicaoI][posicaoJ] == 1) {
        return false;
    }
    else {
        return true;
    }

}

bool Labirinto::verificaSaidaLabirinto(int posicaoI, int posicaoJ) {

    bool existeSaida = false;

    for (int n = 0; n < this->_ordem; n++) { //Verifica se existe saida (numero 7) na matriz
        for (int m = 0; m < this->_ordem; m++) {
            if (_maze[n][m] == 7) {
                existeSaida = true;
                break;
            }
        }
    }    

    if (existeSaida == false) { //Se a matriz nao tiver a saida (7) retorna erro
        return false;
    }

    if (_maze[posicaoI][posicaoJ] == 7) { //Se encontrar o (7) retorna true
        return true;
    }

    if (_maze[posicaoI][posicaoJ] != 0) { //Caso a posicao atual for diferente de 0 retorna false
        return false;
    }

    if (validaPosicao(posicaoI, posicaoJ + 1)) {
        _maze[posicaoI][posicaoJ] = 5; // Define todas posicoes andadas com 5        
        if (verificaSaidaLabirinto(posicaoI, posicaoJ + 1)) { //Utilizacao do BackTracking para avancar na posicao direita ate encontrar o 7
            return true;
        }
    }

    if (validaPosicao(posicaoI, posicaoJ - 1)) {
        _maze[posicaoI][posicaoJ] = 5; // Define todas posicoes andadas com 5   
        if (verificaSaidaLabirinto(posicaoI, posicaoJ - 1)) { //Utilizacao do BackTracking para avancar na posicao esquerda ate encontrar o 7
            return true;
        }
    }

    if (validaPosicao(posicaoI + 1, posicaoJ)) {
        _maze[posicaoI][posicaoJ] = 5; // Define todas posicoes andadas com 5          
        if (verificaSaidaLabirinto(posicaoI + 1, posicaoJ)) { //Utilizacao do BackTracking para avancar na posicao baixo ate encontrar o 7
            return true;
        } 
    }

    if (validaPosicao(posicaoI - 1, posicaoJ)) {
        _maze[posicaoI][posicaoJ] = 5; // Define todas posicoes andadas com 5         
        if (verificaSaidaLabirinto(posicaoI - 1, posicaoJ)) { //Utilizacao do BackTracking para avancar na posicao cima ate encontrar o 7
            return true;
        } 
    }   

    return false; //Caso nenhum dos backtrackins encontre o 7 retorna false
}