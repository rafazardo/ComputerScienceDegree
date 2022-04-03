#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "ExcecaoSoma.h"
#include "ExcecaoAcimaDeX.h"

ExcecaoSoma::ExcecaoSoma() {}

double ExcecaoSoma::get_x() {
    return this->_x;
}

int ExcecaoSoma::get_n() {
    return this->_n;
}

void ExcecaoSoma::set_x(double AddX) {
    this->_x = AddX;
}

void ExcecaoSoma::set_n(int addN) {
    this->_n = addN;
}

void ExcecaoSoma::somaValores() throw (ExcecaoAcimaDeX) {

    double variavelSuporteX, addNumero;
    int variavelSuporteN;
    double somaNumeros = 0;
    int quantidadeNumerosSomados = 0;

    std::cout << "Digite o valor de X: " << std::endl;
    while (true) {
        try {
            std::cin >> variavelSuporteX;
            if (variavelSuporteX > 100 || variavelSuporteX <= 0) {
                throw std::exception();
            }
            else {
                break;
            }
        }
        catch (std::exception &error) {
           std::cerr << "Erro: Nao é aceito valores maiores que 100 ou menores ou igual a 0 na variavel X!\n";
           std::cerr << "Digite novamente o valor de X:\n";
        }
    }
    set_x(variavelSuporteX);
    
    std::cout << "Digite o valor de N: " << std::endl;
    while (true) {
        try {
            std::cin >> variavelSuporteN;
            if (variavelSuporteN <= 0) {
                throw std::exception();
            }
            else {
                break;
            }
        }
        catch (std::exception &error) {
            std::cerr << "Erro: Nao é aceito valores menores ou igual a 0 na variavel N!\n";
            std::cerr << "Digite novamente o valor de N:\n";
        }
    }    
    set_n(variavelSuporteN);

    for (variavelSuporteN = 0; variavelSuporteN < get_n(); variavelSuporteN++) {
        std::cout << "Digite o valor do " << variavelSuporteN+1 << " numero: ";
        std::cin >> addNumero;
        try {
            if (somaNumeros + addNumero > get_x()) {
                throw ExcecaoAcimaDeX();
            }
            else {
                somaNumeros += addNumero;
                quantidadeNumerosSomados++;
            }
        }
        catch (ExcecaoAcimaDeX &error) {
            std::cerr << error.what() << std::endl;
            break;            
        }
    }
    
    std::cout << "Soma dos numeros: " << somaNumeros << std::endl;
    std::cout << "Quantidade de numeros somados: " << quantidadeNumerosSomados << std::endl;
    std::cout << "Media: " << somaNumeros/quantidadeNumerosSomados << std::endl;
}