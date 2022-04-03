#include <iomanip>
#include <iostream>

#include "Labirinto.h"

int main() {

    int tamanhoLabirinto;
    
    std::cout << "Digite o tamanho n do labirinto: (nxn) \n";
    std::cin >> tamanhoLabirinto;

    Labirinto labirinto(tamanhoLabirinto); //Criando o objeto labirinto

    std::cout << "Digite cada elemento do seu labirinto de ordem " << tamanhoLabirinto << "x" << tamanhoLabirinto << ": \n";
    labirinto.leMatriz(labirinto); //Cria a matriz

    std::cout << "O mapa do labirinto foi criado com sucesso! Veja o resultado: \n";
    labirinto.imprimeLabirinto(labirinto); //Faz a leitura da matriz
    
    std::cout << "Estamos verificando se existe uma saida do labirinto... Aguarde um momento! \n";
    
    if (labirinto.verificaSaidaLabirinto(1,0) == true) { //Verifica se o caminho foi encontrada
        std::cout << "O labirinto possui uma saida! \n";
    }
    else {
        std::cout << "O labirinto nao possui uma saida! \n";
    }

    return 0;
}