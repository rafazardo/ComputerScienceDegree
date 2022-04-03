#include <iostream>
#include <stdexcept>
#include <ctype.h>
#include <iomanip>

#include "PosicoesVetor.h"

PosicoesVetor::PosicoesVetor(int addtamanhoVetor):
    _tamanhoVetor(addtamanhoVetor) {} ;

PosicoesVetor::~PosicoesVetor() {
    delete[] _vetor;
}

int PosicoesVetor::get_tamanhoVetor() {
    return this->_tamanhoVetor;
}

void PosicoesVetor::get_vetor() {

    int vetorSuporte;

    for (vetorSuporte = 0; vetorSuporte < get_tamanhoVetor(); vetorSuporte++) {
        std::cout << "Posicao: " << vetorSuporte << " - Valor: " << this->_vetor[vetorSuporte] << std::endl;
    }
}

void PosicoesVetor::set_tamanhoVetor(int addtamanhoVetor) {
    this->_tamanhoVetor = addtamanhoVetor;
}

void PosicoesVetor::set_vetor(int addValorVetor, int addPosicao) {
    this->_vetor[addPosicao] = addValorVetor;
}

void PosicoesVetor::preencherValores() {
    
    int vetorSuporte, addVetorPosicao, addVetorValor, charSuporte;
    char addVetorPosicaoChar[256];

    this->_vetor = new int[get_tamanhoVetor()];

    for (vetorSuporte = 0; vetorSuporte < get_tamanhoVetor(); vetorSuporte++) {
        
        std::cout << "Digite a posicao: ";
        while (true) {
            try {
                std::cin >> addVetorPosicao;
                if (addVetorPosicao >= get_tamanhoVetor() || addVetorPosicao < 0) {
                    throw std::out_of_range("Erro: O vetor nao possui esta posicao \n");
                }
                else {
                    break;
                }
            } 
            catch (std::out_of_range &erro) {
                std::cerr << erro.what();
                std::cerr << "Digite novamente a posicao: ";
            }
        }

        std::cout << "Digite o valor dessa posicao: ";
            try {
                std::cin.ignore();
                std::cin.getline(addVetorPosicaoChar,256); //Digita uma string
                for (charSuporte = 0; addVetorPosicaoChar[charSuporte] != '\0'; charSuporte++) {//Verifica se alguma parte dessa string possui caracteres diferentes de numeros decimais
                    if (isdigit(addVetorPosicaoChar[charSuporte]) == 0) {
                        vetorSuporte--;
                        throw std::invalid_argument("Erro: O vetor aceita somente numeros inteiros \n");
                    }
                }
            } 
            catch (std::invalid_argument &erro) {
                std::cerr << erro.what();
            }

        addVetorValor = atoi(addVetorPosicaoChar); //Se nao encontrar caracteres nao decimais na string, transforma o string de numeros inteiros para uma variavel do tipo int
        
        std::cout << "--------" << std::endl;
        this->_vetor[addVetorPosicao] = addVetorValor;
    }
}